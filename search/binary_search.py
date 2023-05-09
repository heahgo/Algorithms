# binary_search.py
# Binary Search Algorithm
# Time Complexity : O(logn)

def binary_search_algorithm(arr, num, left, right): 
        
    length = right - left + 1
    mid = length // 2 + left
    if arr == []:
        print("error : arr is Empty")
        return None
    if num == arr[mid]:
        return mid
    elif num < arr[mid]:
        return binary_search_algorithm(arr, num, left, mid - 1) 
    else:
        return binary_search_algorithm(arr, num, mid + 1, right)

def binary_search(arr, num):
    return binary_search_algorithm(arr, num, 0, len(arr) - 1)
    
if __name__ == "__main__":

    exam_arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30]
    seq = int(input('Input find number : '))
    print(f'{seq} index is {binary_search(exam_arr, seq)}')