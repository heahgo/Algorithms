def partition(arr : list, p : int, r : int):
    x = arr[p]
    i = p
    for j in range(p+1, r+1):
        if arr[j] <= x:
            arr[i+1], arr[j] = arr[j], arr[i+1]
            i += 1
    arr[i], arr[p] = arr[p], arr[i]
    return i

def quickSort(arr, p, r):
    if p > r:
        return
    q = partition(arr, p, r)
    quickSort(arr, p, q-1)
    quickSort(arr, q+1, r)

if __name__ == "__main__":
    arr = [31, 8, 48, 73, 11, 3, 20, 29, 65, 15]
    a = partition(arr, 0, len(arr)-1)
    print(a)
    quickSort(arr, 0, len(arr)-1)
    print(arr)
