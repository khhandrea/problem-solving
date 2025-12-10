N, K = map(int, input().split())
W =[]
V =[]
for _ in range(N):
    w, v = map(int, input().split())
    W.append(w)
    V.append(v)

table = []
for n in range(N + 1):
    table.append([])
    for k in range(K + 1):
        if n == 0 or k == 0:
            table[n].append(0)
        elif k < W[n - 1]:
            table[n].append(table[n - 1][k])
        else:
            table[n].append(max(table[n - 1][k],\
                                V[n - 1] + table[n - 1][k - W[n - 1]]))

print(table[n][k])