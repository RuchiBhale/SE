percent = []
n = int(input("Enter the number of students: "))
for j in range(n):
    marks = float(input("Enter the percentage: "))
    percent.append(marks)


def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for k in range(low, high):
        if arr[k] <= pivot:
            i = i + 1
            temp = arr[i]
            arr[i] = arr[k]
            arr[k] = temp

    temp1 = arr[i + 1]
    arr[i + 1] = arr[high]
    arr[high] = temp1
    return i + 1


class Sorting:

    def quick_sort(self, arr, low, high):
        if low < high:
            p = partition(arr, low, high)
            self.quick_sort(arr, low, p - 1)
            self.quick_sort(arr, p + 1, high)


def main():
    lower = 0
    length = len(percent) - 1
    x = Sorting()
    x.quick_sort(percent, lower, length)
    print("Sorted array is :")
    print(percent)


if __name__ == "__main__":
    main()
