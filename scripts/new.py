import argparse
import glob
import os


def get_args():
    parser = argparse.ArgumentParser(description="new.py")
    parser.add_argument("-t", "--template", nargs="+")
    parser.add_argument("-g", "--google", action="store_true")
    parser.add_argument("-k", "--keep", action="store_true")
    return parser.parse_args()


def make_main(args):
    os.system("cp body/top.cpp main.cpp")

    if args.template:
        os.system(f"cat templates/{args.template[0]}.cpp >> main.cpp")

    if args.google:
        os.system("cat body/bottom-goog.cpp >> main.cpp")
    else:
        os.system("cat body/bottom.cpp >> main.cpp")


def delete_in_out():
    os.system("rm *.out 2> /dev/null")

    input_files = glob.glob("*.in")
    for input_file in input_files:
        os.system(f"> {input_file}")


def reset(args):
    make_main(args)
    if not args.keep:
        delete_in_out()


if __name__ == "__main__":
    args = get_args()
    reset(args)
