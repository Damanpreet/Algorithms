class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        N = len(graph)
        out = {}
        if N == 0: return []
        
        def dfs(node, visited):
            if node in out: return out[node]
            conns = graph[node]
            
            if len(conns)==0: 
                out[node] = True
                return out[node]
            
            for c in conns:
                if c in visited:    return False
                out[c] = dfs(c, visited+[c]) 
                if not out[c]: 
                    return False
            
            out[node] = True
            return out[node]
                 
        for i in range(N):
            if i not in out:
                out[i] = dfs(i, [i])
                
        
        return sorted([k for k in out if out[k]])