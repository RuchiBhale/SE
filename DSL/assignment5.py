percent = []
n = int(input("Enter the number of students: "))
for i in range(n):
    marks = float(input("Enter the percentage: "))
    percent.append(marks)


class Sort:
    def __init__(self, per):
        self.per = per

    def insertion_sort(self):
        for j in range(1, len(self.per)):
            value = self.per[j]
            holepos = j
            while holepos > 0 and self.per[holepos - 1] > value:
                self.per[holepos] = self.per[holepos - 1]
                holepos = holepos - 1
            self.per[holepos] = value
        print(self.per)

    def shell_sort(self):

        gap = len(self.per)
        while gap > 0:
            gap = gap // 2
            for i in range(gap, n):
                temp = self.per[i]
                j = i
                while j >= gap and self.per[j - gap] > temp:
                    self.per[j] = self.per[j - gap]
                    j = j - gap
                self.per[j] = temp

        print(self.per)


def main():
    x = Sort(percent)
    print("1.Insertion sort\n2.Shell sort")
    ch = int(input("Enter your choice: "))
    if ch == 1:
        x.insertion_sort()
    elif ch == 2:
        x.shell_sort()
    else:
        print("Invalid choice")


if __name__ == "__main__":
    main()
