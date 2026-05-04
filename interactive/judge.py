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


def sum_digits(x):
    return sum(int(x) for x in str(x))


def testcase():
    N, M = random.randint(2, 100), random.randint(2, 100)
    S = set()
    while len(S) < 2:
        S.add((random.randint(1, N), random.randint(1, M)))

    print_err(N, M)
    print_err(S)
    print_flush(N, M)

    # query_counts = 0
    while True:
        Q = input().strip().split()
        Q = [q.strip() for q in Q]
        x, y = Q[1], Q[2]
        x = int(x)
        y = int(y)

        if Q[0] == "?":
            ans = 1e9
            for s in S:
                ans = min(ans, abs(x - s[0]) + abs(y - s[1]))
                print_err(x, y, s, ans)
            print_flush(ans)

        else:
            assert (x, y) in S, f"WA guessed {(x, y)} when {S=}"
            break


def judge():
    random.seed(0)

    multi_testcase = True
    if multi_testcase:
        T = 1000
        print_flush(T)
    else:
        T = 1

    for _ in range(T):
        testcase()


if __name__ == "__main__":
    judge()
