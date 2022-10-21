class User:
    name = ""
    age = 0

    def __init__(self, _name, _age):
        self.name = _name
        self.age = _age
	
    def updateName(self, newName):
        self.name = newName
	
    def updateAge(self, newAge):
        self.age = newAge

    def getInfo(self):
        print(f"{self.name} 님의 나이는 {self.age}살 입니다.")

