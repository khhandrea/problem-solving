n = int(input())
memo = [0, 0, 1, 1]
for i in range(4, n + 1):
    temp = memo[i - 1] + 1
    if i % 2 == 0:
        temp = min(temp, memo[i // 2] + 1)
    if i % 3 == 0:
        temp = min(temp, memo[i // 3] + 1)
    memo.append(temp)

print(memo[n])
