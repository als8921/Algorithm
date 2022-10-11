n = int(input())
m = []
for i in range(n):
    m.append(list(input()))

def find_maxlen(_list):
    cnt_list = []
    cnt = 1
    for idx in range(len(_list)-1):
        if(_list[idx]==_list[idx+1]):
            cnt+=1
        else:
            cnt_list.append(cnt)
            cnt = 1
        if(idx==len(_list)-2):
            cnt_list.append(cnt)
    return (max(cnt_list))

result = 0
def process():
    global result, m
    for row in range(n):
        for i in range(n-1):
            m[row][i], m[row][i+1] = m[row][i+1], m[row][i]
            result = max(result, find_maxlen(m[row]))
            result = max(result, find_maxlen([col[i] for col in m]))
            result = max(result, find_maxlen([col[i+1] for col in m]))
            m[row][i], m[row][i+1] = m[row][i+1], m[row][i]

process()
m = list(map(list, zip(*m)))
process()
print(result)