import argparse
import glob
import os
import subprocess
import threading

from utils.utils import is_empty, compare_answer
from utils.leetcode import create_leetcode_main


# Colors
RESET = "\033[0m"
GREEN = "\033[32m"
RED = "\033[31m"
BLUE = "\033[34m"
YELLOW = "\033[33m"
CYAN = "\033[36m"


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
        "--std=c++23",
        "-Wall",
        "-Wno-unused-variable",
        "-Wno-unused-const-variable",
        "-g",  # debug symbols
        "-D_GLIBCXX_DEBUG",
        # "-O2",
    ]
    if not args.quiet:
        flags.append("-DDEBUG")

    cmd = f"g++-15 {' '.join(flags)} main.cpp -o program"
    print(f"running <{cmd}>...")
    return os.system(cmd)


def stream_reader(stream, is_err: bool, buffer: list[tuple[bool, str]]):
    """Read a stream line-by-line and store in buffer."""
    for line in iter(stream.readline, ""):
        buffer.append((is_err, line))
    stream.close()


def run_test(input_file: str) -> tuple[list[str], int]:
    """Returns the stdout text, return code"""

    print(f"\n{CYAN}Running {input_file}{RESET}")

    buffer = []
    with open(input_file, "r") as inp:
        proc = subprocess.Popen(
            ["./program"],
            stdin=inp,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=1,  # line buffered
        )

        t_out = threading.Thread(
            target=stream_reader,
            args=(proc.stdout, False, buffer),
        )
        t_err = threading.Thread(
            target=stream_reader,
            args=(proc.stderr, True, buffer),
        )

        t_out.start()
        t_err.start()

        try:
            t_out.join(timeout=1)
            t_err.join(timeout=1)

            proc.wait(timeout=1)
        except subprocess.TimeoutExpired:
            print("caught timeout")
            proc.kill()

    for is_err, s in buffer:
        c = YELLOW if is_err else RESET
        print(f"{c}{s.rstrip()}{RESET}")

    stdout_buffer = [s for (is_err, s) in buffer if not is_err]
    return stdout_buffer, proc.returncode


def run(args):
    input_files = args.input if args.input else glob.glob("io/*.in")
    input_files.sort()
    for input_file in input_files:
        if is_empty(input_file):
            continue
        actual_lines, rc = run_test(input_file)
        if rc != 0:
            print(f"{RED}💥 Runtime Error (code {rc}){RESET}")

            if rc == 139:
                print(f"{RED}Segmentation fault detected{RESET}")
            elif rc == 134:
                print(f"{RED}Assertion failure / abort{RESET}")
            elif rc == -1:
                print(f"{RED}TLE{RESET}")

            continue

            # compare answers
        expected_file = input_file.replace(".in", ".ex")
        if not is_empty(expected_file):
            with open(expected_file) as f:
                expected_lines = f.readlines()

            verdict, reason = compare_answer(actual_lines, expected_lines)
            print(f"{GREEN if verdict else RED}>>>>> {reason}{RESET}")


def main():
    # os.environ["MallocNanoZone"] = "0"  # Mac bug: nano zone abandoned
    os.system("rm program 2> /dev/null")  # Remove previous code

    args = get_args()

    if args.leetcode:
        create_leetcode_main("leetcode/fake.cpp", "leetcode/template.cpp")

    if compile(args) != 0:
        exit(1)

    if args.compile_only:
        print(">>>>> Successfully compiled.")
        exit()
    elif args.interactive:
        print(">>>>> Interactive mode:")
        os.system("./program")
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
