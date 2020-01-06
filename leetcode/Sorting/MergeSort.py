arr = [38, 27, 43, 3, 9, 82, 10]
# arr = [4, 3, 2, 10, 12, 1, 5, 6]

def merge(l, m, r):
    n1 = m - l + 1
    n2 = r - m
    left = arr[l:m+1]
    right = arr[m+1:r+1]
    
    i, j = 0, 0
    k = l
    while i<n1 and j<n2:
        if  left[i] > right[j]:
            arr[k] = right[j]
            j+=1
        else:
            arr[k] = left[i]
            i+=1
        k+=1
    
    while i<n1:
        arr[k] = left[i]
        k+=1
        i+=1
    
    while j<n2:
        arr[k] = right[j]
        k+=1
        j+=1


def mergeSort(l, r):
    if l<r:
        m = (l+r)//2
        mergeSort(l, m)
        mergeSort(m+1, r)
        merge(l, m, r)

if __name__ == "__main__":
    mergeSort(0, len(arr)-1)
    print("Sorted Array: ")
    for elem in arr:
        print(elem, end="\t")
    print()