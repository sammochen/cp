from math import gcd
import random
from sys import stderr, stdout


def rand_char():
    return chr(ord("a") + random.randint(0, 25))


def rand_str(n: int):
    return "".join([rand_char() for _ in range(n)])


def print_flush(*args):
    print(*args)
    stdout.flush()


def print_err(*args, **kwargs):
    print(*args, file=stderr, **kwargs)
    stderr.flush()


def is_prime(x):
    for i in range(2, x):
        if x % i == 0:
            return False
    return True


def testcase():
    x = random.randint(2, 100)
    print_err(x)

    for q in range(20):
        s = input()
        if s == "composite":
            assert not is_prime(x), "Wrong guess"
            return
        elif s == "prime":
            assert is_prime(x), "Wrong guess"
            return
        else:
            y = int(s)
            if x % y == 0:
                print_flush("yes")
            else:
                print_flush("no")

    assert False, "Used 20 guesses"


def judge():
    multi_testcase = False
    if multi_testcase:
        T = 100
        print_flush(T)

        for _ in range(T):
            testcase()
    else:
        testcase()


if __name__ == "__main__":
    judge()
