N = int(input())
table = [0, 0, 0]
for _ in range(N):
    r, g, b = map(int, input().split())
    temp = []
    temp.append(r + min(table[1], table[2]))
    temp.append(g + min(table[0], table[2]))
    temp.append(b + min(table[0], table[1]))
    table = temp
print(min(table))