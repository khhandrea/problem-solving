def isPrime(n):
    i = 2

    if n == 1:
        return False
    
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

M = int(input())
N = int(input())
result = 0
least = 0

for i in range(M, N + 1):
    if isPrime(i):
        result += i
        least = i if least == 0 else least

if result > 0:
    print(result)
    print(least)
else:
    print(-1)