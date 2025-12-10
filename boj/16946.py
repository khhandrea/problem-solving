h, w = map(int, input().split())
matrix = [list(map(int, list(input()))) for _ in range(h)]
answer = []
counts = []
table = {}


def get_dfs_dp(start_y, start_x, dir):
    if (start_y + dir[0], start_x + dir[1]) in table:
        return table[(start_y + dir[0], start_x + dir[1])]

    count = len(counts)
    table[(start_y + dir[0], start_x + dir[1])] = count
    discovered = [(start_y + dir[0], start_x + dir[1])]
    stack = [(start_y + dir[0], start_x + dir[1])]
    while stack:
        y, x = stack.pop()
        if y < h - 1 and matrix[y + 1][x] == 0 and (y + 1, x) not in discovered:
            table[(y + 1, x)] = count
            discovered.append((y + 1, x))
            stack.append((y + 1, x))

        if y > 0 and matrix[y - 1][x] == 0 and (y - 1, x) not in discovered:
            table[(y - 1, x)] = count
            discovered.append((y - 1, x))
            stack.append((y - 1, x))

        if x < w - 1 and matrix[y][x + 1] == 0 and (y, x + 1) not in discovered:
            table[(y, x + 1)] = count
            discovered.append((y, x + 1))
            stack.append((y, x + 1))

        if x > 0 and matrix[y][x - 1] == 0 and (y, x - 1) not in discovered:
            table[(y, x - 1)] = count
            discovered.append((y, x - 1))
            stack.append((y, x - 1))

    counts.append(len(discovered))
    return count


def point(start_y, start_x):
    groups = set()
    result = 1
    if start_y < h - 1 and matrix[start_y + 1][start_x] == 0:
        groups.add(get_dfs_dp(start_y, start_x, (+1, 0)))
    if start_y > 0 and matrix[start_y - 1][start_x] == 0:
        groups.add(get_dfs_dp(start_y, start_x, (-1, 0)))
    if start_x < w - 1 and matrix[start_y][start_x + 1] == 0:
        groups.add(get_dfs_dp(start_y, start_x, (0, +1)))
    if start_x > 0 and matrix[start_y][start_x - 1] == 0:
        groups.add(get_dfs_dp(start_y, start_x, (0, -1)))
    for group in groups:
        result += counts[group]
    return result


for y in range(h):
    answer.append([x for x in matrix[y]])

for y in range(h):
    for x in range(w):
        if matrix[y][x] == 1:
            answer[y][x] = point(y, x)

print(answer)
print(counts)
