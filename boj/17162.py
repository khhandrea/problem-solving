from queue import PriorityQueue
import sys

input = sys.stdin.readline
N, K = map(int, input().split())
customers = []
counts = []
for _ in range(N):
    customer, count = map(int, input().split())
    customers.append(customer)
    counts.append(count)

counters = PriorityQueue()
for i in range(K):
    counters.put((0, i)) # (카운터가 걸리는 시간, 카운터 번호)

finished = []
for i in range(N):
    time, counter = counters.get()
    counters.put((time + counts[i], counter))
    finished.append((time + counts[i], -counter, i)) # 시간순, 카운터순, 번호순으로 정렬할 거임

print(sum([ idx * customers[f[2]] for idx, f in enumerate(sorted(finished), 1) ]))