a = []
b = []
c = []
cb = []
corb = []
cnb = []
cfnb = []
students = []
no = int(input("Enter the number of students: "))
for i in range(1, no + 1):
    n = input("Enter your name")
    students.append(n)
    no_of_s = int(input("Enter the number of sports you play: "))
    for j in range(no_of_s):
        s1 = input("Enter the sport you play: ")
        if (s1 == "cricket"):
            a.append(n)
        if (s1 == "badminton"):
            b.append(n)
        if (s1 == "football"):
            c.append(n)
class Sports:

    def __init__(self,name):
        self.name=name

    def cricket(self):
        flag=0
        for i in range(len(a)):
            if(a[i]==self.name):
                flag=1
                break
        if(flag==1):
            return(1)
    def badminton(self):
        flag = 0
        for i in range(len(b)):
            if (b[i] == self.name):
                flag = 1
                break
        if (flag == 1):
            return (1)
    def football(self):
        flag = 0
        for i in range(len(c)):
            if (c[i] == self.name):
                flag = 1
                break
        if (flag == 1):
            return (1)

def main():

    for i in range(len(students)):
        x=Sports(students[i])
        p=x.cricket()
        q=x.badminton()
        r=x.football()
        if(p==1 and q==1):
            cb.append(students[i])
        if(p==1 or q==1):
            corb.append(students[i])
        if(p!=1 and q!=1):
            cnb.append(students[i])
        if(p==1 and r==1 and q!=1):
            cfnb.append(students[i])


    print(cb)
    print(corb)
    print(len(cnb))
    print(len(cfnb))
if(__name__=="__main__"):
    main()