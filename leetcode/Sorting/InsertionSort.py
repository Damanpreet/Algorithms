arr = [4, 3, 2, 10, 12, 1, 5, 6]
# arr = [1, 4, 2, 8, 5]

def insertionSort():
    # sort from the beginning of array
    for i in range(1, len(arr)):
        tmp = arr[i]
        j= i-1

        while j>=0 and arr[j] > tmp:
            arr[j+1] = arr[j]
            j -= 1

        arr[j+1] = tmp

def insertionSortLast():
    # begin from the end of the array
    n = len(arr)
    for i in range(n-2, -1, -1):
        tmp = arr[i]
        j = i+1

        while j<n and arr[j] < tmp:
            arr[j-1] = arr[j]
            j += 1
        arr[j-1] = tmp

def recInsertion(n):
    if n==1: return

    recInsertion(n-1)
    
    tmp = arr[n-1]
    j = n-2

    while j>=0 and arr[j] > tmp:
        arr[j+1] = arr[j]
        j-=1
    
    arr[j+1] = tmp


if __name__ == "__main__":
    recInsertion(len(arr))

    # Print array
    print("Final Array: ")
    for elem in arr:
        print(elem, end="\t")
    print()