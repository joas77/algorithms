package graph

import (
	"fmt"
)

// vertex is
type vertex struct {
	Value     int
	IsVisited bool
	OutEdges  []*edge
	IntEdges  []*edge
}

func (v *vertex) New(value int) {
	v.Value = value
	v.IsVisited = false
}

// edge is
type edge struct {
	Source *vertex
	Dest   *vertex
}

// Graph is
type Graph struct {
	nodesCount      int
	vertices        []vertex
	curLabel        int
	orderedVertices []int
}

// New graph generator from map adjacent list
func (g *Graph) New(graph map[int][]int) {
	// g.graph = graph
	// g.nodesCount = len(g.graph)
	// g.visitedNodes = make(map[int]bool, g.nodesCount)
	// g.orderedVertices = make([]int, g.nodesCount)
	// g.vertices = append(g.vertices, )

	for k, values := range graph {
		var v vertex
		v.New(k)
		for vertexVal, _ := range values {
			var node vertex
			node.New(vertexVal)
		}
	}
}

func (g *Graph) markAllNodesNotVisted() {
	for _, vertex := range g.vertices {
		vertex.IsVisited = false
	}
}

// TopoSort ...
func (g *Graph) TopoSort() {
	g.markAllNodesNotVisted()
	g.curLabel = len(g.graph) // keeps track of ordering
	for v := range g.graph {
		if g.visitedNodes[v] == false {
			g.dfsTopo(v)
		}
	}
}

// TopoSortReversed implements toposort algorithm in the reversed graph
func (g *Graph) TopoSortReversed() {
	g.markAllNodesNotVisted()
	g.curLabel = len(g.graph)

}

func (g *Graph) dfsTopo(sourceNode int) {
	// mark sourceNode as visited
	g.visitedNodes[sourceNode] = true
	for _, vertex := range g.graph[sourceNode] {
		if !g.visitedNodes[vertex] {
			g.dfsTopo(vertex)
		}
	}
	g.orderedVertices[g.curLabel-1] = sourceNode
	g.curLabel--
}

// Print method
func (g *Graph) Print() {
	for k := range g.graph {
		fmt.Printf("%d ->  %v\n", k, g.graph[k])
	}
}

// PrintTopoSorted prints sorted vertices
func (g *Graph) PrintTopoSorted() {
	i := 0
	for i = 0; i < len(g.orderedVertices)-1; i++ {
		fmt.Printf("%d -> ", g.orderedVertices[i])
	}
	fmt.Printf("%d\n", g.orderedVertices[i])
}
