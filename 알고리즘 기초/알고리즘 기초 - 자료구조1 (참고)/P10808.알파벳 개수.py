cnt = [0] * 26
word = input()
for i in word:
    cnt[ord(i)-97] += 1
    
for i in cnt:
    print(i, end = " ")