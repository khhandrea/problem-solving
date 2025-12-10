t = int(input())

for i in range(t):
    n = int(input())
    for idx, char in enumerate(bin(n)[::-1][:-2]):
        if char == '1':
            print(idx, end=' ')