def select(arr):
    for i in range(0, len(arr)):
        min_pos = i
        for j in range(i, len(arr)):
            if arr[min_pos] > arr[j]:
                min_pos = j
        tmp=arr[i]
        arr[i]=arr[min_pos]
        arr[min_pos]=tmp

if __name__ == "__main__":
    arr = [1, 10, 2, 7, 18, 19, 200, 12, 17, 18, 2]
    select(arr)

    # Print the array
    for i in range(len(arr)):
        print(arr[i])    