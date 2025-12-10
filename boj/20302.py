import sys
input = sys.stdin.readline

# make prime list
prime_list = [2]
next_num = 3
while next_num <= 100_000:
    for p in prime_list:
        if p > next_num / p:
            prime_list.append(next_num)
            break
        if next_num % p == 0:
            break
    next_num += 1

def factorization(num):
    def prime_generator():
        yield from prime_list

    prime = prime_generator()
    result = []
    p = next(prime)
    while True:
        if num % p == 0:
            result.append(p)
            num //= p
            if num == 1:
                break
        else:
            p = next(prime)
            if p > num / p:
                result.append(num)
                break
    return result

def solution(exp):
    numbers = list(map(abs, map(int, exp[::2])))
    operators = [''] + exp[1::2]

    table = {}

    for idx, num in enumerate(numbers): 
        if operators[idx] == '/': # pop division
            for factor in factorization(num):
                if factor in table:
                    table[factor] -= 1
                else:
                    table[factor] = -1
        else: # push multiply
            if num == 0:
                return 'mint chocolate'
            for factor in factorization(num):
                if factor in table:
                    table[factor] += 1
                else:
                    table[factor] = 1
    print(table)
    for v in table.values():
        if v < 0:
            return 'toothpaste'
    return 'mint chocolate'

N = int(input())
exp = input().split()
print(solution(exp))