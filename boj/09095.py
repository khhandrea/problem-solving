n = int(input())
nums = []
for _ in range(n):
    nums.append(int(input()))

table = [0, 1, 2, 4]
for num in nums:
    if num > len(table) - 1:
        for i in range(len(table), num + 1):
            table.append(table[i - 1] + table[i - 2] + table[i - 3])
    print(table[num])