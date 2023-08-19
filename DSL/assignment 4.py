roll_no = []
num = int(input("Enter the number of students who attended the camp: "))
for i in range(num):
    roll_num = int(input("Enter the roll no: "))
    roll_no.append(roll_num)
print(roll_no)

ch = int(input("Enter the roll number which is to be searched: "))


class Search:
    def __init__(self, list, n, element):
        self.list = list
        self.n = n
        self.element = element

    def linear(self):
        found = False
        position = -1
        index = 0
        while index < self.n and not found:
            if self.element == self.list[index]:
                found = True
                position = index
                break
            else:
                index = index + 1
        print("The index of the element is: ")
        return position

    def sentinel(self):
        last = self.list[self.n - 1]
        self.list[self.n - 1] = self.element
        i = 0
        while self.list[i] != self.element:
            i = i + 1
        self.list[self.n - 1] = last
        if i < self.n - 1 or self.element == self.list[self.n - 1]:
            print("Element is Present")
        else:
            print("Not found ")

    def binary(self):
        temp = 0
        for i in range(0, len(self.list)):
            for j in range(i + 1, len(self.list)):

                if self.list[i] > self.list[j]:
                    temp = self.list[i]
                    self.list[i] = self.list[j]
                    self.list[j] = temp
        low = 0
        high = len(self.list) - 1
        mid = 0

        while low <= high:

            mid = (high + low) // 2
            if self.list[mid] < self.element:
                low = mid + 1
            elif self.list[mid] > self.element:
                high = mid - 1
            else:
                return mid

    def fibonacci(self):
        temp = 0
        for i in range(0, len(self.list)):
            for j in range(i + 1, len(self.list)):

                if self.list[i] > self.list[j]:
                    temp = self.list[i]
                    self.list[i] = self.list[j]
                    self.list[j] = temp
        fibo = []
        a = 1
        b = 1
        c = 0
        fibo.append(a)
        fibo.append(b)
        for i in range(1, self.n):
            c = a + b
            fibo.append(c)
            a = b
            b = c
        m = 0
        offset = 0
        while fibo[m] < self.n:
            m = m + 1
            offset = -1
        while fibo[m] > 1:
            mid = min(offset + fibo[m - 2], self.n - 1)
            if self.element > self.list[mid]:
                m = m - 1
                offset = mid
            elif self.element < self.list[mid]:
                m = m - 2
            else:
                return mid
        if fibo[m - 1] and self.list[offset + 1] == self.element:
            return offset + 1
        return -1


def main():
    print("1. Linear search\n2.Sentinel Search\n3.Binary Search\n4.Fibonacci Search\n")
    choice = int(input("Enter your choice: "))
    z = Search(roll_no, num, ch)
    if choice == 1:
        x = z.linear()
        print(x)
    elif choice == 2:
        z.sentinel()
    elif choice == 3:
        y = z.binary()
        if y == -1:
            print("Element not found")
        else:
            print("After sorting the array element found at index", y)
    elif choice == 4:
        w = z.fibonacci()
        if w == -1:
            print("element not found")
        else:
            print("After sorting the array element found at index: ", w)
    else:
        print("Invalid choice")


if __name__ == "__main__":
    main()
