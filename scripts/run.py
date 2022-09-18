import argparse
import glob
import os

from utils.utils import read_output, is_empty


def get_args():
    parser = argparse.ArgumentParser(description="run.py")
    parser.add_argument("-i", "--input", nargs="+")
    parser.add_argument("-c", "--compile-only", action="store_true")
    parser.add_argument("--quiet", action="store_true")
    parser.add_argument("-ia", "--interactive", action="store_true")
    parser.add_argument("-j", "--judge", nargs="?", const=1, default=0)
    parser.add_argument("-lc", "--leetcode", action="store_true")
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


def run_one_file(input_file):
    if is_empty(input_file):
        return

    print(f">>>>> {input_file}")

    actual_file = input_file.replace(".in", ".actual")
    expected_file = input_file.replace(".in", ".expected")
    tmp_file = input_file.replace(".in", ".tmp")

    # Write to temp file and re-output, catch seg fault
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
        return

    # Write to file
    run_code = os.system(f"./program < {input_file} > {actual_file} 2> /dev/null")

    if not is_empty(expected_file):
        actual = read_output(actual_file)
        expected = read_output(expected_file)
        if actual == expected:
            print(">>>>> ✅ AC")
        else:
            print(">>>>> 😥 WA")


def run(args):
    input_files = args.input if args.input else glob.glob("io/*.in")
    input_files.sort()
    for input_file in input_files:
        run_one_file(input_file)


def main():
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


if __name__ == "__main__":
    main()
