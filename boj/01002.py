T = int(input())

for _ in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())

    if (x1 == x2) and (y1 == y2) and (r1 == r2):
        print(-1)
        continue

    d = ((x1 - x2)**2 + (y1 - y2)**2)**0.5
    r = r1 + r2
    if (r == d) or (r == d + 2 * min(r1, r2)):
        print(1)
    elif r < d or (r > d + 2 * min(r1, r2)):
        print(0)
    else:
        print(2)