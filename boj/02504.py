buf = input()
stack = []
result = 0
temp = 1

for idx, char in enumerate(buf):
    if char == '(':
        stack.append(char)
        temp *= 2

    elif char == '[':
        stack.append(char)
        temp *= 3

    elif char == ')':
        if not stack or stack.pop() == '[':
            result = 0
            break
        if buf[idx - 1] == '(':
            result += temp
        temp //= 2

    elif char == ']':
        if not stack or stack.pop() == '(':
            result = 0
            break
        if buf[idx - 1] == '[':
            result += temp
        temp //= 3
if stack:
    result = 0

print(result)