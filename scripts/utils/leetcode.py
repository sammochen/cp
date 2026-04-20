from typing import Optional, List
import re


def count_char(s: str, c: str):
    return len(list(t for t in s if t == c))


def get_dec_line(source_lines: List[str])->str:
    """Returns the declaring line"""
    seen_class = False
    opens = 0
    candidate_fns = []

    for line in source_lines:
        line = line.strip()
        line = line.replace("const", " ").replace("&", " ").replace("long long", "ll")

        if "class Solution {" in line:
            seen_class = True
            continue

        if not seen_class:
            continue

        if opens == 0:
            # check if it is a declaration
            match = re.search(r"^ *([a-zA-Z<>]*) ([a-zA-Z_]+)\(.*\) {.*", line)
            if match:
                name = match.group(2)
                if name[0] == "_":
                    print(f"ignoring {name}")
                else:
                    candidate_fns.append((match.group(2), line))

        # count {/}
        opens += count_char(line, "{")
        opens -= count_char(line, "}")

    if len(candidate_fns) == 0:
        print("could not find a candidate fn, bug")
        assert False
    if len(candidate_fns) > 1:
        print(
            f"found multiple candidate fns, taking the last one: {candidate_fns[-1][0]}"
        )

    return candidate_fns[-1]


def create_leetcode_main(source_file: str, template_file: str):
    with open(source_file) as f:
        source_lines = f.readlines()

    dec_line = get_dec_line(source_lines)[1]


    # Clean dec_line
    dec_line_stripped = [s for s in re.split(r"[\(\), ]", dec_line) if len(s)]
    brace_index = dec_line_stripped.index("{")
    dec_line_stripped = dec_line_stripped[:brace_index]

    return_type = dec_line_stripped[0]
    method_name = dec_line_stripped[1]
    print(f"\nleetcode method_name: {method_name}\n")
    args = []
    for i in range(2, len(dec_line_stripped), 2):
        arg_type = dec_line_stripped[i]
        arg_name = dec_line_stripped[i + 1]
        args.append((arg_type, arg_name))

    with open(template_file) as f:
        template_lines = f.readlines()

    main_lines = []
    for line in template_lines:
        if "// code here" in line:
            main_lines += source_lines
        elif "// args here" in line:
            # First check the count of args
            main_lines.append(
                f"""
                if (lines.size() % {len(args)} != 0) 
                {{ std::cout << "wrong number of arguments" << std::endl; exit(1);}}\n
                """
            )

            main_lines.append("Solution sol;\n")
            for arg_type, arg_name in args:
                main_lines.append(" " * 8 + f"{arg_type} {arg_name};\n")
                main_lines.append(" " * 8 + f"IO::parse(lines[ind++], {arg_name});\n")
            main_lines.append(
                " " * 8
                + f"{return_type} ans = sol.{method_name}({', '.join([a[1] for a in args])});\n"
            )
            main_lines.append(" " * 8 + f"cout << IO::dump(ans) << endl;\n")
        else:
            main_lines.append(line)

    with open("main.cpp", "w") as f:
        for line in main_lines:
            f.write(line)
