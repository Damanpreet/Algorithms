import sys

class Graph:
    def __init__(self, VERTICES):
        self.graph = [[0]*VERTICES]*VERTICES
        self.parent = [None]*VERTICES        
        self.distance = [sys.maxint]*VERTICES
        self.vertices = [False]*VERTICES

    def dijkstra(self, start_vertex):
        print('Begin finding path')
        self.distance[start_vertex] = 0 
        for v in range(len(self.vertices)):
            u = self.min_distance()
            self.vertices[u] = True
            for v in range(len(self.vertices)):
                if self.graph[u][v] > 0 and self.vertices[v] == False and self.distance[v] > (self.distance[u] + self.graph[u][v]):
                    self.distance[v] = self.distance[u] + self.graph[u][v]
                    # print(self.distance)
                    self.parent[v] = u 

    def min_distance(self):
        min_dist = sys.maxint
        for v in range(len(self.vertices)):
            if self.vertices[v] == False and min_dist > self.distance[v]:
                return v
    
    def print_path(self):
        print('Printing path')
        for v in range(len(self.vertices)):
            if self.vertices[v] != True:
                print('All paths not explored.')
                return 
        
        if None in self.parent:
            u = self.parent.index(None)
            print('Start from vertex: ', u)
            
        
        for v in range(len(self.vertices)):
            for vert in range(len(self.vertices)):
                if self.parent[vert] == v:
                    print('vertex '+str(v)+' ---> '+str(vert))

        print('Distances: ')
        for v in range(len(self.vertices)):
            print(self.distance[v])

            
    
# Testing
g = Graph(9)
# g.graph = [[0, 2, 4, 10, 12], [0, 0, 1, 3, 11], [0, 1, 0, 12, 8], [1, 1, 0, 0, 13], [0, 1, 2, 0, 0]]
g.graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0], 
                      [4, 0, 8, 0, 0, 0, 0, 11, 0], 
                      [0, 8, 0, 7, 0, 4, 0, 0, 2], 
                      [0, 0, 7, 0, 9, 14, 0, 0, 0], 
                      [0, 0, 0, 9, 0, 10, 0, 0, 0], 
                      [0, 0, 4, 14, 10, 0, 2, 0, 0], 
                      [0, 0, 0, 0, 0, 2, 0, 1, 6], 
                      [8, 11, 0, 0, 0, 0, 1, 0, 7], 
                      [0, 0, 2, 0, 0, 0, 6, 7, 0] 
            ]
g.dijkstra(0)
g.print_path()