n = int(input())
for _ in range(n):
    sentence = input().split()
    for word in sentence:
        for i in range(len(word) - 1, -1, -1):
            print(word[i], end="")
        print(" ", end="")
    print()