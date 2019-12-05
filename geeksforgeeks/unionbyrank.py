from collections import defaultdict

class Node:
    def __init__(self, parent, rank):
        self.parent = parent
        self.rank = rank

class Tree:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = defaultdict(lambda: [])

    def add_edge(self, i, j):
        self.graph[i].append(j)
    
    def find_parent(self, i):
        if i!=self.parents[i].parent:
            return self.find_parent(self.parents[i].parent) 
        return i
    
    def union(self, i, j):
        # attach smaller rank tree to the root of the larger rank tree
        if self.parents[i].rank > self.parents[j].rank:
            self.parents[j].parent = i 
        elif self.parents[i].rank < self.parents[j].rank:
            self.parents[i].parent = j
        else:
            self.parents[i].parent = j
            self.parents[j].rank += 1

    def iscycle(self):
        # start with the node itself instead of -1
        # this is because even if they belong to different groups they can have -1 as the parent.
        # so, the answer will be incorrect in this scenario.
        self.parents = [Node(i, 0) for i in range(self.vertices)]  
        for i in self.graph:
            parent_i = self.find_parent(i)
            self.parents[i].parent = parent_i
            if i!=parent_i: 
                self.parents[i].rank = 1
            else: 
                self.parents[i].rank -= 1

            for j in self.graph[i]:
                parent_j = self.find_parent(j)
                self.parents[j].parent = parent_j
                if j!=parent_j: 
                    self.parents[j].rank = 1
                else: 
                    self.parents[j].rank -= 1

                if parent_i==parent_j:
                    # print([self.parents[i].parent for i in range(len(self.parents))])
                    return 1
                self.union(parent_i, parent_j) 

        # print([self.parents[i].parent for i in range(len(self.parents))])

if __name__ == "__main__":
    g = Tree(4)
    g.add_edge(0, 1)
    g.add_edge(1, 2)
    g.add_edge(2, 3)
    g.add_edge(3, 1)

    if g.iscycle(): print("Cycle found!")
    else: print("Cycle not found!")
