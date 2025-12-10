n = int(input())
stair = []
for _ in range(n):
    stair.append(int(input()))

if n < 3:
    print(sum(stair))
else:
    table = []
    table.append(stair[0])
    table.append(sum(stair[:2]))
    table.append(max(stair[0] + stair[2],\
                    stair[1] + stair[2]))

    for i in range(3, n):
        table.append(stair[i] + max(table[i - 3] + stair[i - 1],\
                                    table[i - 2]))
    print(table[n - 1])