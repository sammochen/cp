import argparse
import glob
import os
from time import time


def get_args():
    parser = argparse.ArgumentParser(description="new.py")
    parser.add_argument("-t", "--template", nargs="+")
    parser.add_argument("-g", "--google", action="store_true")
    return parser.parse_args()


def reset(args):
    os.system("cp body/top.cpp main.cpp")

    if args.template:
        os.system(f"cat templates/{args.template[0]}.cpp >> main.cpp")

    if args.google:
        os.system("cat body/bottom-goog.cpp >> main.cpp")
    else:
        os.system("cat body/bottom.cpp >> main.cpp")


if __name__ == "__main__":
    args = get_args()
    reset(args)
