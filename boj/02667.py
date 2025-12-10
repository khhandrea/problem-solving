N = int(input())
matrix = []
for _ in range(N):
    matrix.append(list(input()))
result = [0]

for start_y in range(N):
    for start_x in range(N):
        if matrix[start_y][start_x] == '1':
            matrix[start_y][start_x] = len(result)
            count = 1
            stack = [(start_y, start_x)]
            while stack:
                y, x = stack.pop()

                if y > 0 and matrix[y - 1][x] == '1':
                    matrix[y - 1][x] = len(result)
                    count += 1
                    stack.append((y - 1, x))
                if y < N - 1 and matrix[y + 1][x] == '1':
                    matrix[y + 1][x] = len(result)
                    count += 1
                    stack.append((y + 1, x))
                if x > 0 and matrix[y][x - 1] == '1':
                    matrix[y][x - 1] = len(result)
                    count += 1
                    stack.append((y, x - 1))
                if x < N - 1 and matrix[y][x + 1] == '1':
                    matrix[y][x + 1] = len(result)
                    count += 1
                    stack.append((y, x + 1))
            result.append(count)

print(matrix)

if len(result) == 1:
    print(0)
else:
    print(len(result) - 1)
    for i in sorted(result[1:]):
        print(i)