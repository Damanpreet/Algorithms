class Solution:
    def orderOfLargestPlusSign(self, N: int, mines: List[List[int]]) -> int:
        if N==0: return 0
        order=0        
        A = [[1 for i in range(N)] for j in range(N)]
        left = [[0 for i in range(N)] for j in range(N)]
        right = [[0 for i in range(N)] for j in range(N)]
        up = [[0 for i in range(N)] for j in range(N)]
        down = [[0 for i in range(N)] for j in range(N)]
        
        for mine in mines:
            A[mine[0]][mine[1]] = 0
        
        for i in range(N):
            for j in range(N):
                if j==0: left[i][j]=A[i][j]
                else:
                    if A[i][j]:
                        left[i][j]=left[i][j-1]+1
        
        for i in range(N):
            for j in range(N):
                if i==0: up[i][j]=A[i][j]
                else:
                    if A[i][j]:
                        up[i][j]=up[i-1][j]+1  
        
        for i in range(N-1, -1, -1):
            for j in range(N):
                if i==N-1: down[i][j]=A[i][j]
                else:
                    if A[i][j]:
                        down[i][j]=down[i+1][j]+1   
        
        for i in range(N):
            for j in range(N-1, -1, -1):
                if j==N-1: right[i][j]=A[i][j]
                else:
                    if A[i][j]:
                        right[i][j]=right[i][j+1]+1   
                        
        for i in range(N):
            for j in range(N):
                c = min(up[i][j], down[i][j], left[i][j], right[i][j]) 
                if c==0: c = A[i][j]
                order = max(order, c)
                    
        return order                            