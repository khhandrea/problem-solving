cand = input()
target = reversed(input())
count = 0

digit = 1
for t in target:
    count = (count + digit * (cand.index(t) + 1)) % 900528
    digit = digit * len(cand) % 900528

print(count)