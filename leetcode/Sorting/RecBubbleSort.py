arr = [5, 1, 4, 2, 8]

def bubbleSort(j, n):
    if n==1:
        return
    
    for i in range(n-1):
        if arr[i] > arr[i+1]:
            # swap
            tmp = arr[i]
            arr[i] = arr[i+1]
            arr[i+1] = tmp
    
    print("Pass ", j)
    for elem in arr:
        print(elem, end="\t")
    print()
    bubbleSort(j+1, n-1)
        
if __name__ == "__main__":
    bubbleSort(1, len(arr)) 
    
    # Print array
    print("Final Array: ")
    for elem in arr:
        print(elem, end="\t")
