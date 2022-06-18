from math import gcd
import random
from sys import stdout


def rand_char():
    return chr(ord("a") + random.randint(0, 25))


def rand_str(n: int):
    return "".join([rand_char() for _ in range(n)])


def print_flush(args):
    print(args)
    stdout.flush()


def judge():
    T = 100
    print_flush(T)
    for _ in range(T):
        x = random.randint(1, 1000000000)

        while True:
            q = input().split()
            if q[0] == "?":
                a, b = int(q[1]), int(q[2])
                print_flush(gcd(x + a, x + b))
            else:
                a = int(q[1])
                assert a == x, f"Wrong guess: {a} != {x=}"
                break


if __name__ == "__main__":
    judge()
