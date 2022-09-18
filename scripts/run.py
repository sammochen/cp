import argparse
import glob
import os


def get_args():
    parser = argparse.ArgumentParser(description="run.py")
    parser.add_argument("-i", "--input", nargs="+")
    parser.add_argument("-c", "--compile-only", action="store_true")
    parser.add_argument("-q", "--quiet", action="store_true")
    parser.add_argument("-ia", "--interactive", action="store_true")
    parser.add_argument("-j", "--judge", nargs="?", const=1, default=0)
    return parser.parse_args()


def compile(args):
    flags = [
        "--std=c++20",
        "-Wall",
        "-Wno-unused-variable",
        "-Wno-unused-const-variable",
        "-fsanitize=address",
        "-DDEBUG",
    ]

    cmd = f"g++ {' '.join(flags)} main.cpp -o program"
    return os.system(cmd)


def is_empty(filename):
    # Check if the input_file is empty
    with open(filename) as f:
        x = f.read().strip()
    return len(x) == 0


def read_output(filename):
    with open(filename) as f:
        text = f.read()

    # Remove trailing space(s) before new lines
    lines = text.split("\n")
    lines = [line.rstrip() for line in lines]

    return "\n".join(lines)


def run(args):
    input_files = args.input if args.input else glob.glob("io/*.in")
    input_files.sort()
    for input_file in input_files:
        if is_empty(input_file):
            continue

        actual_file = input_file.replace(".in", ".actual")
        expected_file = input_file.replace(".in", ".expected")
        tmp_file = input_file.replace(".in", ".tmp")

        # Write to temp file and re-output, catch seg fault
        print(f">>>>> {input_file}")
        run_code = os.system(f"./program < {input_file} &> {tmp_file}")

        # Going to hack this: if line contains `AddressSanitizer` chop the rest off
        with open(tmp_file) as f:
            lines = f.readlines()
            for line in lines:
                if "AddressSanitizer" in line:
                    break
                print(line, end="")

        if run_code != 0:
            print(">>>>> 😬 RTE")
            continue

        # Write to file
        run_code = os.system(f"./program < {input_file} > {actual_file} 2> /dev/null")

        if not is_empty(expected_file):
            actual = read_output(actual_file)
            expected = read_output(expected_file)
            if actual == expected:
                print(">>>>> ✅ AC")
            else:
                print(">>>>> 😥 WA")


if __name__ == "__main__":
    os.environ["MallocNanoZone"] = "0"  # Mac bug: nano zone abandoned
    os.system(f"rm program 2> /dev/null")  # Remove previous code
    args = get_args()

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
