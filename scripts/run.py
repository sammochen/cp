import argparse
import glob
import os
from time import time


BINARY_NAME = "program"


def get_args():
    parser = argparse.ArgumentParser(description="run.py")
    parser.add_argument("-i", "--input", nargs="+")
    parser.add_argument("-q", "--quiet", action="store_true")
    parser.add_argument("--fast", action="store_true")
    parser.add_argument("-ia", "--interactive", action="store_true")
    parser.add_argument("-t", "--time", action="store_true")
    return parser.parse_args()


def compile(args):
    flags = []
    if not args.quiet:
        flags.append("-DDEBUG")
    if args.fast:
        flags.append("-O3")

    compile_cmd = f"g++ --std=c++17 -fsanitize=address {' '.join(flags)} main.cpp -o {BINARY_NAME}"
    return os.system(compile_cmd)


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
    input_files = args.input if args.input else glob.glob("*.in")
    input_files.sort()
    for input_file in input_files:
        if is_empty(input_file):
            continue

        # Write to terminal
        print(f">>>>> running {input_file}")
        start_time = time()
        os.system(f"./{BINARY_NAME} < {input_file}")
        end_time = time()

        if args.time:
            print(f">>>>> time: {end_time - start_time:.4f}s")

        # Write stdout to file
        actual_file = input_file.replace(".in", ".actual")
        os.system(f"./{BINARY_NAME} < {input_file} > {actual_file} 2> /dev/null")

        expected_file = input_file.replace(".in", ".expected")
        if not is_empty(expected_file):
            actual = read_output(actual_file)
            expected = read_output(expected_file)
            if actual == expected:
                print(">>>>> ✅ AC")
            else:
                print(">>>>> 😥 WA")


if __name__ == "__main__":
    os.environ["MallocNanoZone"] = "0"  # Mac bug: nano zone abandoned
    os.system(f"rm {BINARY_NAME} 2> /dev/null")  # Remove previous code
    args = get_args()

    if compile(args) != 0:
        exit()

    if args.interactive:
        print(">>>>> interactive mode:")
        os.system(f"./{BINARY_NAME}")
    else:
        run(args)
