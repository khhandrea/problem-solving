n = int(input())
table = [0] * n
for row in range(n):
    nums = list(map(int, input().split()))
    for idx, num in enumerate(nums):
        if idx == 0:
            temp = table[idx]
            table[idx] += num
        elif idx == len(nums) - 1:
            table[idx] += num + temp
        else:
            if temp > table[idx]:
                table[idx], temp = temp, table[idx]
            else:
                temp = table[idx]
            table[idx] += num
    # print(table)
print(max(table))