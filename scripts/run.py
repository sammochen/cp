import argparse
import glob
import os
import re

from utils.utils import is_empty, compare_answer
from utils.leetcode import create_leetcode_main


def get_args():
    parser = argparse.ArgumentParser(description="run.py")
    parser.add_argument("-i", "--input", nargs="+")
    parser.add_argument("-c", "--compile-only", action="store_true")
    parser.add_argument("-q", "--quiet", action="store_true") # No debug statements
    parser.add_argument("-lc", "--leetcode", action="store_true")
    return parser.parse_args()


def compile(args) -> int:
    flags = [
        "--std=c++20",
        "-Wall",
        "-Wno-unused-variable",
        "-Wno-unused-const-variable",
        "-fsanitize=address,undefined",
        # "-O3",
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
    run_code = os.system(f"./program < {input_file} &> {actual_file}")

    with open(actual_file) as f:
        lines = f.readlines()
        for line in lines:
            print(line, end="")

    if run_code != 0:
        print(">>>>> 😬 RTE")
        return

    # Compare against expected file if it is not empty
    if not is_empty(expected_file):
        verdict = compare_answer(actual_file, expected_file)
        print(f">>>>> {verdict}")


def run(args):
    input_files = args.input if args.input else glob.glob("io/*.in")
    input_files.sort()
    for input_file in input_files:
        run_one_file(input_file)




def main():
    os.environ["MallocNanoZone"] = "0"  # Mac bug: nano zone abandoned
    os.system(f"rm program 2> /dev/null")  # Remove previous code

    args = get_args()

    if args.leetcode:
        create_leetcode_main("leetcode/fake.cpp", "leetcode/template.cpp")

    if compile(args) != 0:
        exit(1)

    if args.compile_only:
        print(">>>>> Successfully compiled.")
        exit()
    else:
        run(args)


if __name__ == "__main__":
    main()
