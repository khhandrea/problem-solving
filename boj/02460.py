people_max = 0
present = 0

for i in range(10):
    train_out, train_in = map(int, input().split())
    present = present + train_in - train_out
    people_max = max(people_max, present)

print(people_max)