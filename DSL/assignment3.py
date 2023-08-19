r1 = int(input("Enter the number of rows of the first matrix: "))
c1 = int(input("Enter the number of columns of the first matrix: "))
matrix1 = []
for i in range(r1):
    x = []
    for j in range(c1):
        x.append(int(input()))
    matrix1.append(x)

for i in range(r1):
    for j in range(c1):
        print(matrix1[i][j], end=" ")
    print()

r2 = int(input("Enter the number of rows: "))
c2 = int(input("Enter the number of columns: "))
matrix2 = []
for i in range(r2):
    y = []
    for j in range(c2):
        y.append(int(input()))
    matrix2.append(y)

for i in range(r2):
    for j in range(c2):
        print(matrix2[i][j], end=" ")
    print()


class Matrix_operations:
    def __init__(self, row1, col1, row2, col2, m1, m2):
        self.row1 = row1
        self.row2 = row2
        self.col1 = col1
        self.col2 = col2
        self.m1 = m1
        self.m2 = m2

    def addition(self):
        sum = []
        for i in range(self.row1):
            z = []
            for j in range(self.col1):
                z.append(0)
            sum.append(z)
        if self.row1 == self.row2 and self.col1 == self.col2:

            for i in range(len(self.m1)):
                for j in range(len(self.m1[0])):
                    sum[i][j] = self.m1[i][j] + self.m2[i][j]
        else:
            print("Addition not possible ")

        print("The addition of the two matrices is: ")
        for i in range(self.row1):
            for j in range(self.col1):
                print(sum[i][j], end=" ")
            print()

    def subtraction(self):
        diff = []
        for i in range(self.row1):
            z = []
            for j in range(self.col1):
                z.append(0)
            diff.append(z)
        if self.row1 == self.row2 and self.col1 == self.col2:

            for i in range(len(self.m1)):
                for j in range(len(self.m1[0])):
                    diff[i][j] = self.m1[i][j] - self.m2[i][j]
        else:
            print("Subtraction  not possible ")
        print("The subtraction of the two matrices is: ")
        for i in range(self.row1):
            for j in range(self.col1):
                print(diff[i][j], end=" ")
            print()

    def multiplication(self):
        mul = []
        for i in range(self.row1):
            z = []
            for j in range(self.col1):
                z.append(0)
            mul.append(z)

        if self.row1 == self.row2 and self.col1 == self.col2:
            for i in range(len(self.m1)):
                for j in range(len(self.m2[0])):
                    for k in range(len(self.m2)):
                        mul[i][j] += (self.m1[i][k] * self.m2[k][j])





        else:
            print("multiplication is not possible ")
        print("The multiplication of the two matrices is: ")
        for i in range(self.row1):
            for j in range(self.col1):
                print(mul[i][j], end=" ")
            print()

    def transpose(self):
        trans1 = []
        trans2 = []
        for i in range(self.row1):
            z = []
            for j in range(self.col1):
                z.append(0)
            trans1.append(z)
            trans2.append(z)

        for i in range(len(self.m1)):
            for j in range(len(self.m1[0])):
                trans1[j][i] = self.m1[i][j]


        print("The transpose of matrix 1 is: ")
        for i in range(self.row1):
            for j in range(self.col1):
                print(trans1[i][j], end=" ")
            print()


def main():

    x = Matrix_operations(r1, c1, r2, c2, matrix1, matrix2)
    print("1.Addition\n2.Subtraction\n3.Multiplication\n4.Transpose")
    num=int(input("Enter you choice: "))
    if(num==1):
      x.addition()
    elif(num==2):
         x.subtraction()
    elif(num==3):
     x.multiplication()
    elif(num==4):
        x.transpose()
    else:
        print("Incorrect choice ")


if __name__ == "__main__":
    main()


