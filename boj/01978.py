def isPrime(n):
    i = 2

    if n == 1 :
        return False
    while(i * i <= n):
        if n % i == 0:
            return False
        i += 1
    return True

N = int(input())

print(sum(map(isPrime, list(map(int, input().split())))))