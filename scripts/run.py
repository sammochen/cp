import argparse
import glob
import os
from time import time


def get_args():
    parser = argparse.ArgumentParser(description="run.py")
    parser.add_argument("-i", "--input", nargs="+")
    parser.add_argument("-q", "--quiet", action="store_true")
    parser.add_argument("--fast", action="store_true")
    parser.add_argument("-ia", "--interactive", action="store_true")
    return parser.parse_args()


def compile(args):
    flags = []
    if not args.quiet:
        flags.append("-DDEBUG")
    if args.fast:
        flags.append("-O3")

    compile_cmd = f"g++ --std=c++17 -fsanitize=address -DLOCAL {' '.join(flags)} main.cpp -o compiled.out"
    return os.system(compile_cmd)


def run(args):
    input_files = args.input if args.input else glob.glob("*.in")
    input_files.sort()
    for input_file in input_files:
        # Check if the input_file is empty
        with open(input_file) as f:
            x = f.read().strip()
            if len(x) == 0:
                continue

        output_file = input_file.replace(".in", ".out")
        print(f">>>>> running {input_file}")
        start_time = time()
        os.system(f"./compiled.out < {input_file}")
        end_time = time()

        # Also write to file
        os.system(f"./compiled.out < {input_file} &> {output_file}")
        print(f">>>>> time: {end_time - start_time:.4f}s")


if __name__ == "__main__":
    os.environ["MallocNanoZone"] = "0"  # Mac bug: nano zone abandoned
    os.system("rm compiled.out 2> /dev/null")  # Remove previous code
    args = get_args()

    if compile(args) != 0:
        exit()

    if args.interactive:
        print(">>>>> interactive mode:")
        os.system("./compiled.out")
    else:
        run(args)
