import argparse
import glob
import os
import re

from utils.utils import is_empty, compare_answer


def get_args():
    parser = argparse.ArgumentParser(description="run.py")
    parser.add_argument("-i", "--input", nargs="+")
    parser.add_argument("-c", "--compile-only", action="store_true")
    parser.add_argument("-q", "--quiet", action="store_true")
    parser.add_argument("-ia", "--interactive", action="store_true")
    parser.add_argument("-j", "--judge", nargs="?", const=1, default=0)
    parser.add_argument("-lc", "--leetcode", action="store_true")
    return parser.parse_args()


def compile(args) -> int:
    flags = [
        "--std=c++17",
        "-Wall",
        "-Wno-unused-variable",
        "-Wno-unused-const-variable",
        "-fsanitize=address",
        "-O3",
    ]
    if not args.quiet:
        flags.append("-DDEBUG")

    cmd = f"g++ {' '.join(flags)} main.cpp -o program"
    print(f"running <{cmd}>...")
    return os.system(cmd)


def run_one_file(input_file: str):
    if is_empty(input_file):
        return

    print(f">>>>> {input_file}")

    actual_file = input_file.replace(".in", ".actual")
    expected_file = input_file.replace(".in", ".ex")

    # Write to temp file and re-output, catch seg fault
    run_code = os.system(f"./program < {input_file} > {actual_file} 2> /dev/null")

    # Going to hack this: if line contains `AddressSanitizer` chop the rest off
    with open(actual_file) as f:
        lines = f.readlines()
        for line in lines:
            print(line, end="")

    if run_code != 0:
        print(">>>>> 😬 RTE")
        return

    if not is_empty(expected_file):
        verdict = compare_answer(actual_file, expected_file)
        print(f">>>>> {verdict}")


def run(args):
    input_files = args.input if args.input else glob.glob("io/*.in")
    input_files.sort()
    for input_file in input_files:
        run_one_file(input_file)


def create_leetcode_main():
    with open("leetcode/fake.cpp") as f:
        code_lines = f.readlines()
        decs = [line for line in code_lines if "// !" in line]
        if len(decs) != 1:
            print("Error: // ! does not exist in leetcode/fake.cpp")
            exit(1)

    dec_line = (
        decs[0].replace("const", " ").replace("&", " ").replace("long long", "ll")
    )

    # Clean dec_line
    dec_line_stripped = [s for s in re.split(r"[\(\), ]", dec_line) if len(s)]
    brace_index = dec_line_stripped.index("{")
    dec_line_stripped = dec_line_stripped[:brace_index]

    ret_type = dec_line_stripped[0]
    method_name = dec_line_stripped[1]
    args = []
    for i in range(2, len(dec_line_stripped), 2):
        arg_type = dec_line_stripped[i]
        arg_name = dec_line_stripped[i + 1]
        arg_type = arg_type.replace("const", "").replace("&", "")
        args.append((arg_type, arg_name))

    with open("leetcode/template.cpp") as f:
        template_lines = f.readlines()

    main_lines = []
    for line in template_lines:
        if "// code here" in line:
            main_lines += code_lines
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
                + f"{ret_type} ans = sol.{method_name}({', '.join([a[1] for a in args])});\n"
            )
            main_lines.append(" " * 8 + f"cout << IO::dump(ans) << endl;\n")
        else:
            main_lines.append(line)

    with open("main.cpp", "w") as f:
        for line in main_lines:
            f.write(line)


def main():
    os.environ["MallocNanoZone"] = "0"  # Mac bug: nano zone abandoned
    os.system(f"rm program 2> /dev/null")  # Remove previous code

    args = get_args()

    if args.leetcode:
        create_leetcode_main()

    if compile(args) != 0:
        exit(1)

    if args.compile_only:
        print(">>>>> Successfully compiled.")
        exit()
    elif args.interactive:
        print(">>>>> Interactive mode:")
        os.system(f"./program")
    elif args.judge:
        print(f">>>>> Running against judge {args.judge} times:")
        for _ in range(int(args.judge)):
            ret = os.system(
                "python3 interactive/runner.py python3 interactive/judge.py 0 -- ./program"
            )
            if ret != 0:
                break
    else:
        run(args)


if __name__ == "__main__":
    main()
