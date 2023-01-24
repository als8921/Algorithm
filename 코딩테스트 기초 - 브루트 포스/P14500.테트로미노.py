
blocks = [
    [[1, 1, 1, 1]]
    ,
    [[1],
    [1],
    [1],
    [1]]
    ,   
    [[1, 1],
    [1, 1]]
    ,
    [[1, 1, 1],
    [1, 0, 0]]
    ,
    [[1, 1, 1],
    [0, 0, 1]]
    ,
    [[1, 0, 0],
    [1, 1, 1]]
    ,
    [[0, 0, 1],
    [1, 1, 1]]
    ,
    [[1, 1],
    [1, 0],
    [1, 0]]
    ,
    [[1, 0],
    [1, 0],
    [1, 1]]
    ,
    [[1, 1],
    [0, 1],
    [0, 1]]
    ,
    [[0, 1],
    [0, 1],
    [1, 1]]


    ,
    [[1, 1, 0],
    [0, 1, 1]]
    ,
    [[0, 1, 1],
    [1, 1, 0]]
    ,
    [[1, 0],
    [1, 1],
    [0, 1]]
    ,
    [[0, 1],
    [1, 1],
    [1, 0]]

    ,
    [[0, 1, 0],
    [1, 1, 1]]
    ,
    [[1, 1, 1],
    [0, 1, 0]]
    ,
    [[1, 0],
    [1, 1],
    [1, 0]]
    ,
    [[0, 1],
    [1, 1],
    [0, 1]]
]

for block in blocks:
    # print(len(block), len(block[0]))# y, x

    for i in range(len(block)):
        for j in range(len(block[0])):
            if(block[i][j] == 1):
                pass

n, m = map(int, input().split()) #세로, 가로
tetro = []
for _ in range(n):
    tetro.append(list(map(int, input().split())))

result = 0
for block in blocks:
    for x in range(m-len(block[0])+1):
        for y in range(n-len(block)+1):
            temp = 0
            for i in range(len(block)):
                for j in range(len(block[0])):
                    if(block[i][j] == 1):
                        temp += tetro[i+y][j+x]
            result = max(result, temp)

print(result)