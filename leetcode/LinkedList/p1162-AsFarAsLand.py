from collections import deque
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        N = len(grid)
        if N==0: return 0
        
        visited = set()
        queue = deque()
        for r in range(N):
            for c in range(N):
                if grid[r][c]:
                    for ne in [(-1, 0), (0, -1), (1, 0), (0, 1)]:
                        if 0<=(r+ne[0])<N and 0<=(c+ne[1])<N:
                            if not grid[r+ne[0]][c+ne[1]] and (r+ne[0], c+ne[1]) not in visited: 
                                queue.append((r+ne[0], c+ne[1], 1))
                                visited.add((r+ne[0], c+ne[1]))
        if not queue: 
            return -1
        
        maxcost = 1          
        while queue:
            elem=queue.popleft()
            r, c, cost = elem[0], elem[1], elem[2]
            for ne in [(-1, 0), (0, -1), (1, 0), (0, 1)]:
                if 0<=(r+ne[0])<N and 0<=(c+ne[1])<N:
                    if not grid[r+ne[0]][c+ne[1]] and (r+ne[0], c+ne[1]) not in visited: 
                        queue.append((r+ne[0], c+ne[1], cost+1))
                        maxcost = max(maxcost, cost+1)
                        visited.add((r+ne[0], c+ne[1]))
        
        return maxcost
        