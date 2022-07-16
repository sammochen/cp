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
    n = 1000
    print_flush(n)
    s = "".join("T" if random.randint(1, 2) == 1 else "F" for _ in range(n))

    for _ in range(675):
        Q = input().strip()
        assert len(Q) == len(s) == n, "invalid query size"

        correct = 0
        for i in range(n):
            if Q[i] == s[i]:
                correct += 1

        print_err(Q, s, correct)
        print_flush(correct)

        if correct == n:
            return

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
