N, K = map(int, input().split())
table = [1] + [0] * N
for _ in range(K):
    for i in range(1, N + 1):
        table[i] = (table[i] + table[i - 1]) % 1000000000
print(table[-1])