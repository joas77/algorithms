import random
import copy
import math
from collections import deque



class Graph:
    def __init__(self, adjlist):
        #self.graph =  copy.deepcopy(dict_repr)
        raw = copy.deepcopy(adjlist)
        self.graph = {}
        self.visited = {}
        for nodes in raw:
            val = nodes.pop(0)
            self.graph[val] = nodes
            self.visited[val] = False


    @property
    def num_vertices(self):
        return len(self.graph)

    def get_vertices(self):
        return list(self.graph.keys())

    def edges_at_vertice(self, vertice):
        if vertice not in self.graph:
            raise Exception(f"Vertice {vertice} does not exist")
        return self.graph[vertice]

    def __str__(self):
        return str(self.graph)

    def dfs_topo(self, vertex):
        # mark all vertices as unexplored
        for node in self.graph:
            self.visited[node] = False

        stack = deque([vertex])
        while len(stack) > 0:
            v = stack.pop()
            if not self.visited[v]:
                self.visited[v] = True
                for w in self.graph[v]:
                    stack.append(w)

    def dfs_top(self, vertex):
        
        stack = deque([vertex])
        while len(stack) > 0:
            v = stack.pop()
            if not self.visited[v]:
                self.visited[v] = True
                for w in self.graph[v]:
                    stack.append(w)

    def topo_sort(self):
        pass


# TODO: use graph.edges_at_vertice(v) instead of graph.graph(v)


def merge(graph, vertice1, vertice2):
    if not (vertice1 in graph.graph and vertice2 in graph.graph):
        raise Exception("Vertice doesn't exist!")
    merged_edges = graph.graph[vertice1] + graph.graph[vertice2]
    new_vertice = min(vertice1, vertice2)
    old_vertice = max(vertice1, vertice2)

    del graph.graph[old_vertice]
    graph.graph[new_vertice] = merged_edges

    for vertice, edges in graph.graph.items():
        # replacing old by new in all vertex
        while old_vertice in edges:
            edges.remove(old_vertice)
            edges.append(new_vertice)

        # removing self-loops
        while vertice in edges:
            edges.remove(vertice)


def minimum_cut(graph_dict):
    min_cut = math.inf
    # n = graph_dict.num_vertices
    n = len(graph_dict)
    print(f"calculating the minumum cut of a graph of {n} vertices")

    for i in range(int(n*n * math.log2(n))):
        graph = Graph(graph_dict) # copy.deepcopy(graph_dict)
        #print(graph)
        while graph.num_vertices > 2:
            u = random.choice(list(graph.graph))
            v = random.choice(graph.graph[u])
            merge(graph, u, v)

        # print(new_graph)
        vertice = graph.get_vertices()[0]
        min_cut_iter = len(graph.edges_at_vertice(vertice))
        min_cut = min( min_cut, min_cut_iter )
        print(f"minimum cut number found at iteration {i}: {min_cut_iter}, minimun cut number until now: {min_cut}")

    return min_cut

def alg(test_file):
    test = open(test_file)
    data =[ list(map(int, line.strip().split() )) for line in test.readlines()]
    test.close()
    # print(data)
    graph_dict = {}
    # for nodes in data:
    #     graph_dict[nodes.pop(0)] = nodes
    
    # graph = Graph(graph_dict)
    min_cut = minimum_cut(data) # (graph_dict)
    print(f"Minumum cut of graph{graph_dict}: {min_cut}")
    return min_cut


if __name__ == "__main__":
    g = [[1, 2, 3],
         [2, 1, 3, 4],
         [3, 1, 2, 4],
         [4, 3, 2]
    ]

    graph = Graph(g)
    print(graph)
    print("Testing DFS method...")
    graph.dfs(1)
    print("visited vertices:")
    print(graph.visited)
    

    #alg("KargerMinCut.txt")
