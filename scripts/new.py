import argparse
import glob
import os


def get_args():
    parser = argparse.ArgumentParser(description="new.py")
    parser.add_argument("-t", "--template", nargs="+")
    parser.add_argument("-g", "--google", action="store_true")
    parser.add_argument("-k", "--keep", action="store_true")
    return parser.parse_args()


def build_main(args):
    os.system("cp body/top.cpp main.cpp")

    if args.template:
        os.system(f"cat templates/{args.template[0]}.cpp >> main.cpp")

    if args.google:
        os.system("cat body/bottom-goog.cpp >> main.cpp")
    else:
        os.system("cat body/bottom.cpp >> main.cpp")


def clear_files():
    # Delete .actual
    os.system("rm *.actual 2> /dev/null")

    # Clear .in and .expected
    cases = glob.glob("io/*.in") + glob.glob("io/*.expected")
    for input_file in cases:
        os.system(f"> {input_file}")


def reset(args):
    build_main(args)
    if not args.keep:
        clear_files()


if __name__ == "__main__":
    args = get_args()
    reset(args)
