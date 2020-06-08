package graph

import "fmt"

// Graph is
type Graph struct {
	nodesCount int
	graph map[int][]int
	visitedNodes map[int]bool
	curLabel int
	orderedVertices []int
}


func (this *Graph) New(graph map[int][]int)  {
	this.graph = graph
	this.nodesCount = len(this.graph)
	this.visitedNodes = make(map[int]bool, this.nodesCount)
	this.orderedVertices = make([]int, this.nodesCount)
}

func (this *Graph) markAllNodesNotVisted(){
	for key, _ := range this.visitedNodes {
		this.visitedNodes[key] = false
	}
}

func (this *Graph) TopoSort() {
	this.markAllNodesNotVisted()
	this.curLabel = len(this.graph)  // keeps track of ordering
	for v, _ := range this.graph {
		if this.visitedNodes[v] == false{
			this.dfsTopo(v)
		}
	}
}

func (this *Graph) dfsTopo(sourceNode int)  {
	// mark sourceNode as visited
	this.visitedNodes[sourceNode] = true 
	for _, vertex := range this.graph[sourceNode] {
		if !this.visitedNodes[vertex] {
			this.dfsTopo(vertex)
		}
	}
	this.orderedVertices[this.curLabel - 1] = sourceNode
	this.curLabel -- 
}

func (this *Graph) Print()  {
	for k := range this.graph {
		fmt.Printf("%d ->  %v\n", k, this.graph[k])
	}
}

func (this *Graph) PrintTopoSorted()  {
	i:=0
	for i=0; i < len(this.orderedVertices) - 1; i++{
		fmt.Printf("%d -> ", this.orderedVertices[i])
	}
	fmt.Printf("%d\n", this.orderedVertices[i])
}