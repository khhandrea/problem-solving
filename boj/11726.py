n = int(input())

table = [0, 1, 2]
for i in range(3, n + 1):
    table.append((table[i - 1] + table[i - 2]) % 10007)

print(table[n])