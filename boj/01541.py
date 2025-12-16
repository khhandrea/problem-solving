import sys
input = sys.stdin.readline


def get_sum(expression):
    return sum(map(int, expression.split("+")))

def main():
    expressions = input().rstrip().split("-")

    result = get_sum(expressions[0])
    for i in range(1, len(expressions)):
        result -= get_sum(expressions[i])
    print(result)


if __name__ == "__main__":
    main()