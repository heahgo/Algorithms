# bubble_sort.py
# bubble sort  O(n**2)

def bubble_sort(arr, result):

    for i in range(len(arr)):
        for j in range(len(arr) - 1 - i):
            if result[j] > result[j+1]:
                tmp = result[j]
                result[j] = result[j + 1]
                result[j + 1] = tmp

if __name__=="__main__":
    number_list = list(map(int, input("Input Sequence : ").split()))
    sort = number_list[:]
    print("before :", number_list)
    bubble_sort(number_list, sort)
    print("after :", sort)

