cmd = input()
answer = ""
stack = []
for i in cmd:
    # 문자인지 기호인지 구분하기
    if i.isalpha():
        answer += i
    
    # 여는 괄호를 스택에 추가하여 시작 점을 알림
    elif i == "(":
        stack.append(i)

    # +, - 가 나올 경우 이전 스택을 비우며 answer에 추가
    elif i == "+" or i == "-":
        while(stack and stack[-1] != "("):
            answer += stack.pop()
        stack.append(i)

    # *, / 가 연속적으로 나오는 경우 answer에 추가
    elif i == "*" or i == "/":
        while(stack and (stack[-1] == "*" or stack[-1] == "/")):
            answer += stack.pop()
        stack.append(i)

    # 닫는 괄호가 나올 경우 여는 괄호가 나올 때 까지 stack에서 pop하며 answer에 추가
    elif i == ")":
        while(stack and stack[-1] != "("):
            answer += stack.pop()
        stack.pop()

# 스택에 남은 연산자를 모두 answer에 추가     
while(stack):
    answer += stack.pop()

print(answer)