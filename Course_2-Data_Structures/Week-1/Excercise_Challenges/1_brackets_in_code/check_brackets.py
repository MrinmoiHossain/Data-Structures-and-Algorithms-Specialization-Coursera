def matching(left, right):
    return (left + right) in ["()", "[]", "{}"]

def is_balanced(text):
    stack = []
    for i, c in enumerate(text):
        if c in ['(', '{', '[']:
            stack.append([c, i])
        else:
            if c in [')', '}', ']']:
                if len(stack) == 0:
                    return i + 1
                top = stack.pop()[0]
                if matching(top, c) == False:
                    return i + 1
                
    if len(stack):
        return stack.pop()[1] + 1
    else:
        return 0


if __name__ == "__main__":
    text = input()
    result = is_balanced(text)

    if result:
        print(result)
    else:
        print("Success")
