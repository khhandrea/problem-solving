from itertools import permutations

N = int(input())
A = list(map(int, input().split()))
ad, ab, mu, di = map(int, input().split())
ops = []

ops.extend(["+" for _ in range(ad)])
ops.extend(["-" for _ in range(ab)])
ops.extend(["*" for _ in range(mu)])
ops.extend(["/" for _ in range(di)])

ops_list = list(permutations(ops, len(ops)))
print(len(ops_list))