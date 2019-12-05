from collections import defaultdict

# using Tree data structure
class Tree:
    def __init__(self, vertices):
        self.graph = defaultdict(lambda: [])
        self.vertices = vertices

    # add edge to the graph
    def add(self, i, j):
        self.graph[i].append(j) 

    # find the parent of the node
    def findParent(self, i):
        if self.parent[i]==-1:
            return i
        return self.findParent(self.parent[i])

    def union(self, i, j):
        x = self.findParent(i)
        y = self.findParent(j)
        self.parent[x]=y    

    def isCyclic(self):
        self.parent = [-1] * self.vertices 

        for i in self.graph:
            parent_i = self.findParent(i)
            for j in self.graph[i]:
                parent_j = self.findParent(j)
                if parent_i == parent_j:
                    return 1
                self.union(i, j)
    
    def check(self):
        print(self.parent)

if __name__=='__main__':
    g = Tree(5)
    g.add(0, 1)
    g.add(1, 2)
    g.add(1, 3)
    g.add(1, 4)
    g.add(2, 4)

    if g.isCyclic():
        print("Graph contains cycle.")
    else:
        print("Graph does not contain a cycle.")

    g.check()