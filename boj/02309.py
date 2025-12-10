heights = []

for i in range(9):
    heights.append(int(input()))

heights_sum = sum(heights)

for height in heights:
    pair = heights_sum - height - 100
    if (pair in heights) and (pair != height):
        heights.remove(height)
        heights.remove(heights_sum - height- 100)
        break

for height in sorted(heights):
    print(height)