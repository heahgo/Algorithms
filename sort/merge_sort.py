# merge_sort.py
# merge Sort Algorithm
# Time Complexity : O(nlogn)

def merge(arr, tmp, left, right):
    mid = (left + right) // 2
    L = left
    R = mid + 1
    k = left
    while L <= mid and R <= right:
        if arr[L] <= arr[R]:
            tmp[k] = arr[L]
            L = L + 1
            k = k + 1
        else:
            tmp[k] = arr[R]
            R = R + 1
            k = k + 1
    if L > mid:
        for i in range(R, right + 1):
            tmp[k] = arr[i]
            k = k + 1
    else:
        for i in range(L, mid + 1):
            tmp[k] = arr[i]
            k = k + 1

    for i in range(left, right + 1):
        arr[i] = tmp[i]

def merge_sort(arr, tmp, left, right):
    if left == right:
        return
    mid = (left + right) // 2
    merge_sort(arr, tmp, left, mid)
    merge_sort(arr, tmp, mid + 1, right)
    merge(arr, tmp, left, right)

if __name__ == "__main__":
    number_list = list(map(int, input("Input Sequence : ").split()))
    tmp = []
    for i in range(len(number_list)):
        tmp.append(0)

    print("before :", number_list)
    merge_sort(number_list, tmp, 0, len(number_list) - 1)
    print("after :", number_list)



