import argparse
import glob
from os import system
from time import time


def getArgs():
    parser = argparse.ArgumentParser(description="cp runner")
    parser.add_argument("-i", "--input", nargs=1)
    parser.add_argument("-q", "--quiet", action="store_true")
    return parser.parse_args()


def compile(args):
    flags = "" if args.quiet else "-DTEST"
    compile_cmd = (
        f"g++ -std=c++14 -O2 -fsanitize=address {flags} main.cpp -o compiled.out"
    )
    return system(compile_cmd)


def run(args):
    input_files = args.input if args.input else glob.glob("*.in")
    input_files.sort()
    for input_file in input_files:
        print(f">>>>> running {input_file}")
        start_time = time()
        system(f"./compiled.out < {input_file}")
        end_time = time()
        print(f">>>>> time: {end_time - start_time:.4f}s")


if __name__ == "__main__":
    system("rm compiled.out")
    args = getArgs()

    if compile(args) != 0:
        exit()

    run(args)
