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
    n = random.randint(500, 1000)

    print_flush(n)
    x = random.randint(1, n - 1)

    for _ in range(11):
        Q = input().strip().split()
        y = int(Q[1])

        if Q[0] == "!":
            assert x == y, f"Wrong guess: {x=} {y=}"
            return

        x += y
        print_flush(x // n)

    assert False, "Too many queries"


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
