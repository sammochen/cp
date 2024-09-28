import argparse
import os


def get_args():
    parser = argparse.ArgumentParser(description="new.py")
    parser.add_argument("-g", "--google", action="store_true")
    parser.add_argument("-rm", "--remove", action="store_true")
    return parser.parse_args()


def build_main(args):
    os.system("cp body/top.cpp main.cpp")

    if args.google:
        os.system("cat body/bottom-goog.cpp >> main.cpp")
    else:
        os.system("cat body/bottom.cpp >> main.cpp")


def clear_files():
    cases = 4
    for i in range(1, cases + 1):
        os.system(f"> io/{i}.in")
        os.system(f"> io/{i}.ex")
        os.system(f"> io/{i}.actual")
        os.system(f"> io/{i}.tmp")


def reset(args):
    build_main(args)
    if args.remove:
        clear_files()


if __name__ == "__main__":
    args = get_args()
    reset(args)
