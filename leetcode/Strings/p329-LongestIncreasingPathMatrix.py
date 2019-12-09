from collections import defaultdict

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        visited = set()
        n=len(matrix)
        if n==0: return 0
        m=len(matrix[0])
        dp = defaultdict(lambda: defaultdict(lambda: -1))
        
        def search_neigh(pos):
            maxlen = 1
            (r, c) = pos
            
            if (r+1)<n and matrix[r+1][c]>matrix[r][c]: 
                if dp[r+1][c]==-1: dp[r+1][c] = search_neigh((r+1, c))   
                maxlen = max(maxlen, dp[r+1][c]+1)
                
            if (r-1)>=0 and matrix[r-1][c]>matrix[r][c]:
                if dp[r-1][c]==-1: dp[r-1][c] = search_neigh((r-1, c))   
                maxlen = max(maxlen, dp[r-1][c]+1)
            
            if (c+1)<m and matrix[r][c+1]>matrix[r][c]:
                if dp[r][c+1]==-1: dp[r][c+1] = search_neigh((r, c+1))   
                maxlen = max(maxlen, dp[r][c+1]+1)
            
            if (c-1)>=0 and matrix[r][c-1]>matrix[r][c]:
                if dp[r][c-1]==-1: dp[r][c-1] = search_neigh((r, c-1))   
                maxlen = max(maxlen, dp[r][c-1]+1)
            
            return maxlen
                
                
        for r in range(n):
            for c in range(m):
                if (r, c) not in visited:
                    visited.add((r, c))
                    if dp[r][c]==-1:    dp[r][c]=search_neigh((r, c))
        
        # print(dp)
        return max(dp[x][y] for x in range(n) for y in range(m))