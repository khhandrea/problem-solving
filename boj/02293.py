n, target = map(int, input().split())
ks = [0]
for _ in range(n):
    ks.append(int(input()))
    
table = [1] + ([0] * target)
for coin in range(1, n + 1):
    for t in range(ks[coin], target + 1):
        table[t] += table[t - ks[coin]]
        
print(table[-1])