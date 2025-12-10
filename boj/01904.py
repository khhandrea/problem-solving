N = int(input())
if N <= 2:
    print(N)
else:
    prev, cur = 1, 2
    for i in range(3, N + 1):
        prev, cur = cur, (prev + cur) % 15746
    print(cur)