import sys
from copy import deepcopy

input = sys.stdin.readline

R, C, T = map(int, input().split())
A = [ list(map(int, input().split())) for _ in range(R) ]

purifier = -1
for row in range(R):
    if A[row][0] == -1:
        purifier = row
        break

for _ in range(T):
    temp_A = deepcopy(A)

    # 확산
    for row in range(R):
        for col in range(C):
            cur = temp_A[row][col]
            dust = cur // 5
            if dust > 0:
                if row > 0 and temp_A[row - 1][col] != -1:
                    A[row - 1][col] += dust
                    A[row][col] -= dust
                if row < R - 1 and temp_A[row + 1][col] != -1:
                    A[row + 1][col] += dust
                    A[row][col] -= dust
                if col > 0 and temp_A[row][col - 1] != -1:
                    A[row][col - 1] += dust
                    A[row][col] -= dust
                if col < C - 1 and temp_A[row][col + 1] != -1:
                    A[row][col + 1] += dust
                    A[row][col] -= dust
                
    # 순환
    ## 반시계 - 아래
    for row in range(purifier - 1, 0, -1):
        A[row][0] = A[row - 1][0]
    ## 반시계 - 왼쪽
    for col in range(C - 1):
        A[0][col] = A[0][col + 1]
    ## 반시계 - 위
    for row in range(purifier):
        A[row][C - 1] = A[row + 1][C - 1]
    ## 반시계 - 오른쪽
    for col in range(C - 1, 1, -1):
        A[purifier][col] = A[purifier][col - 1]
    A[purifier][1] = 0

    ## 반시계 - 위
    for row in range(purifier + 2, R - 1):
        A[row][0] = A[row + 1][0]
    ## 반시계 - 왼쪽
    for col in range(C - 1):
        A[R - 1][col] = A[R - 1][col + 1]
    ## 반시계 - 아래
    for row in range(R - 1, purifier + 1, -1):
        A[row][C - 1] = A[row - 1][C - 1]
    ## 반시계 - 오른쪽
    for col in range(C - 1, 1, -1):
        A[purifier + 1][col] = A[purifier + 1][col - 1]
    A[purifier + 1][1] = 0

print(sum([ sum(row) for row in A ]) + 2)