import argparse
import glob
from os import system
from time import time

if __name__ == "__main__":
    system("rm compiled.out")

    parser = argparse.ArgumentParser(description="cp runner")
    parser.add_argument("-i", "--input", nargs=1)
    parser.add_argument("-q", "--quiet", action="store_true")
    args = parser.parse_args()

    flags = "" if args.quiet else "-DTEST"
    compile_cmd = f"g++ -std=c++14 -O2 -fsanitize=address {flags} main.cpp -o compiled.out"
    compile_result = system(compile_cmd)

    if compile_result != 0:
        exit()

    input_files = args.input if args.input else glob.glob("*.in")
    input_files.sort()
    for input_file in input_files:
        print(f">>>>> running {input_file}")
        start_time = time()
        system(f"./compiled.out < {input_file}")
        end_time = time()
        print(f">>>>> time: {end_time - start_time:.4f}s")
