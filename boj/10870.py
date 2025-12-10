n = int(input())

if n == 0:
    print(0)
else:
    f1 = 0
    f2 = 0
    f3 = 1

    for i in range(2, n + 1):
        f1 = f2
        f2 = f3
        f3 = f1 + f2

    print(f3)