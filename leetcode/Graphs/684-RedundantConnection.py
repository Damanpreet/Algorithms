class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        cyclic_edges = []
        
        class Node:
            def __init__(self, parent, rank):
                self.parent = parent
                self.rank = rank
                
        class Tree:
            def __init__(self):
                self.parents = {}
            
            def findParent(self, i):
                if i!=self.parents[i].parent:
                    return self.findParent(self.parents[i].parent)
                return i
            
            def union(self, i, j):
                if self.parents[i].rank > self.parents[j].rank:
                    self.parents[j].parent = i
                elif self.parents[j].rank > self.parents[i].rank:
                    self.parents[i].parent = j
                else:
                    self.parents[i].parent = j
                    self.parents[j].rank += 1
                    
            def detectcycle(self, edges):
                for (i, j) in edges:
                    if i not in self.parents: self.parents[i] = Node(i, 0)
                    if j not in self.parents: self.parents[j] = Node(j, 0)
                    
                    parent_i=self.findParent(i)
                    self.parents[i].parent = parent_i
                    parent_j=self.findParent(j)
                    self.parents[j].parent = parent_j
                    
                    if parent_i == parent_j:
                        cyclic_edges.append((i, j))
                    
                    self.union(parent_i, parent_j)

                    
        t = Tree()
        t.detectcycle(edges)
        if len(cyclic_edges)>0:
            return cyclic_edges[-1]
        return []