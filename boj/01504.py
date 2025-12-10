from queue import Queue
import sys

input = sys.stdin.readline

N, E = map(int, input().split())
adj_list = {}
for _ in range(E):
    a, b, c = map(int, input().split())
    if a in adj_list:
        adj_list[a].append((b, c)) # target, distance
    else:
        adj_list[a] = [(b, c)]
    if b in adj_list:
        adj_list[b].append((a, c))
    else:
        adj_list[b] = [(a, c)]
v1, v2 = map(int, input().split())

def dijkstra(start):
    distances = [float('inf') for _ in range(N + 1)]
    distances[start] = 0
    queue = Queue()
    queue.put((start, distances[start]))

    while not queue.empty():
        cur_target, cur_distance = queue.get()

        if cur_distance > distances[cur_target]:
            continue

        for target, distance in adj_list[cur_target]:
            temp = cur_distance + distance
            if temp < distances[target]:
                distances[target] = temp
                queue.put((target, temp))
    
    return distances

dist_start = dijkstra(1)
dist_v1 = dijkstra(v1)
dist_v2 = dijkstra(v2)

result = min(dist_start[v1] + dist_v1[v2] + dist_v2[N],\
        dist_start[v2] + dist_v2[v1] + dist_v1[N])
if result == float('inf'):
    print(-1)
else:
    print(result)