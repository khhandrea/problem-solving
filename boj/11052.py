N = int(input())
P = [0] + list(map(int, input().split()))
table = [0] * (N + 1)
for card in range(1, N + 1):
    for i in range(card, N + 1):
        table[i] = max(table[i], table[i - card] + P[card])
print(table[-1])