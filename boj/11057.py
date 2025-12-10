N = int(input())
table = [1] * 10
for _ in range(N):
    for i in range(1, 10):
        table[i] = (table[i - 1] + table[i]) % 10007
print(table[-1])