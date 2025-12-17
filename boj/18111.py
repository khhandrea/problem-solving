from collections import Counter
import sys
input = sys.stdin.readline


def main():
    # Input
    N, M, B = map(int, input().split())
    heights = []
    for _ in range(N):
        heights.extend(map(int, input().split()))

    # Initialize
    min_time = float("inf")
    ans_height = 0
    height_counts = Counter(heights)

    # Search
    min_height = min(heights)
    max_height = max(heights)
    for target_height in range(min_height, max_height + 1):
        num_to_remove = sum(height_counts[h] * (h - target_height) for h in height_counts.keys() if h > target_height)
        num_to_put = sum(height_counts[h] * (target_height - h) for h in height_counts.keys() if h < target_height)

        if num_to_put > B + num_to_remove:
            break

        target_time = 2 * num_to_remove + num_to_put
        if target_time <= min_time:
            min_time = target_time
            ans_height = target_height

    print(min_time, ans_height)

        
if __name__ == "__main__":
    main()