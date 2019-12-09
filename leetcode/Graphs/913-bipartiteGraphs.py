from collections import deque

class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        setA = set()
        setB = set()
        
        n = len(graph)
        if n==0: return True
        
        nodes = list(range(n))
        bipar = deque()
        visited = list()
        
        for n in nodes:
            if n not in visited:
                bipar.append((n, 'A'))
                setA.add(n)

                while bipar:
                    (node, s) = bipar.popleft()
                    visited.append(node)
                    children = graph[node]
                    if s == 'A':
                        for child in children:
                            if child in setA:                    
                                return False
                            elif child not in setB:
                                setB.add(child)
                                bipar.append((child, 'B'))
                    else:
                        for child in children:
                            if child in setB:                            
                                return False
                            elif child not in setA:
                                setA.add(child)
                                bipar.append((child, 'A'))

        return True
