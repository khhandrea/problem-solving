a, b = map(int, input().split())

a_start = 1
b_start = 1
step = 1
result = 0
sigma = lambda x: int(x * (x + 1) / 2)

# a_start
while sigma(step) < a:
    step += 1
a_start = step

# b_start
step = 1
while sigma(step) < b:
    step += 1
b_start = step

if a_start == b_start:
    result = a_start * (b - a + 1)
else:
    result += a_start * (sigma(a_start) - a + 1)
    result += b_start * (b - sigma(b_start - 1))
    
    step = a_start + 1
    while step < b_start:
        result += step * step
        step += 1

print(result)