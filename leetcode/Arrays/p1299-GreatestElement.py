class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        MAX_VAL = -1
        for i in range(len(arr)-1, -1, -1):
            temp = max(MAX_VAL, arr[i])
            arr[i] = MAX_VAL
            MAX_VAL = temp
        return arr