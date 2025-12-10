n, k = map(int, input().split())
count = 0

for divisor in range(1, n + 1):
    if n % divisor == 0:
        count += 1
        if count == k:
            print(divisor)
            break
if count < k:
    print(0)