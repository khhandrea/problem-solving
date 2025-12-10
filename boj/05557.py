N = int(input())
nums = list(map(int, input().split()))

table = [0] * 21
table[nums[0]] = 1
for i in range(1, N - 1):
    prev = [ item for item in table ]
    table = [0] * 21
    for idx, item in enumerate(prev):
        if item:
            if idx + nums[i] <= 20:
                table[idx + nums[i]] += item
            if idx - nums[i] >= 0:
                table[idx - nums[i]] += item

print(table[nums[-1]])