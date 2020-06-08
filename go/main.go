package main

import (
	"fmt"
	"strconv"
	"graph"
	"io/ioutil"
	"log"
	"strings"
)

func readGraph(file string) map[int][]int {
	content, err := ioutil.ReadFile(file)
	if err != nil {
		log.Fatal(err)
	}

	data := string(content)
	//fmt.Printf("original file data \n %s", data)
	//fmt.Println()
	graphAdjList := strings.Split(data, "\n")

	var graphInt [][]int
	for i, line := range graphAdjList {
		nodes := strings.Split(line, " ")
		graphInt = append(graphInt, make([]int, len(nodes)))
		for j, elem := range nodes {
			graphInt[i][j], _ = strconv.Atoi(elem)	
		}
	}

	fmt.Println(graphInt)

	graph := make(map[int][]int)

	for _, arr := range graphInt {
		key:= arr[0]
		graph[key] = make([]int, len(arr)-1)
		for i := 1; i <= len(arr) - 1; i++ {
			graph[key][i-1] = arr[i]
		}
	}

	return graph
}

func main() {
	fileName := "./test/simple_graph.txt"

	graphMap := readGraph(fileName)
	fmt.Println(graphMap)

	var graph graph.Graph
	graph.New(graphMap)
	graph.Print()
	graph.TopoSort()
	graph.PrintTopoSorted()

}
