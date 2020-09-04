import math

class Node:
    def __init__(self, value):
        self.value = value
        self.edges = []
        self.is_visited = False
        self.length = math.inf
        

class Edge:
    def __init__(self, value, node_from, node_to):
        self.value = value
        self.node_from = node_from
        self.node_to = node_to

class Graph:
    def __init__(self, nodes=[], edges=[]):
        self.nodes = nodes
        self.edges = edges
        self._order = len(nodes)

    def insert_node(self, new_node_val):
        new_node = Node(new_node_val)
        self.nodes.append(new_node)
        self._order+=1
        return new_node

    def insert_edge(self, new_edge_val, node_from_val, node_to_val):
        from_found = None
        to_found = None

        for node in self.nodes:
            if node_from_val == node.value:
                from_found = node
            if node_to_val == node.value:
                to_found = node

        if from_found == None:
            from_found = self.insert_node(node_from_val)
        
        if to_found == None:
            to_found = self.insert_node(node_to_val)

        new_edge = Edge(new_edge_val, from_found, to_found)
        from_found.edges.append(new_edge)
        to_found.edges.append(new_edge)
        self.edges.append(new_edge)

    def topo_sort(self):
        for node in self.nodes:
            node.is_visited = False

        self._order = len(self.nodes) # keeps track of ordering

        for vertex in self.nodes:
            if not vertex.is_visited:
                self.dfs(vertex)

        

    def dfs(self, source:Node):
        for node in self.nodes:
            node.is_visited = True

        for edge in source.edges:
            vertex = edge.node_to
            if not vertex.is_visited:
                self.dfs(vertex)

    def dijkstra(self, source):
        processed_nodes = {source}
        source.length = 0
        while True:
            pass




        

def graph_from_file(file_path):
    pass

if __name__ == "__main__":
    graph = Graph()

    # generating sample graph
    for i in range(1, 4):
        graph.insert_node(i+1)

    graph.insert_edge(1, 1, 2)
    graph.insert_edge(1, 1, 3)
    graph.insert_edge(1, 1, 4)
    graph.insert_edge(1, 4, 3)
    graph.insert_edge(1, 2, 3)

    s = graph.nodes[0]
    graph.dfs(s)

    for node in graph.nodes:
        print(node.is_visited)