// Construct graph, return topological order

type Graph struct {
	nodes []byte
    edges map[byte][]byte
    topo_order []string
}

// Return the topo order of the graph as a string
func (g *Graph) topoSort() string {
	visited := make(map[byte]int)	// 0: white, 1: grey, 2: black
	// topo_order := make([]string, 0)
	for _, node := range g.nodes {
		if visited[node] == 0 {
			if g.dfs(visited, node) == false {
				return "CYCLE"
			}
		}
	}

	result := ""
	for i := len(g.topo_order) - 1; i >= 0; i-- {
        result += g.topo_order[i]
	}
	return result
}

// Start DFS from a specific node
func (g *Graph) dfs(visited map[byte]int, node byte) bool {
	visited[node] = 1

	for _, other := range g.edges[node] {
		if visited[other] == 1 {
            // fmt.Printf("Detected cycle!\n")
			return false
		} else if visited[other] == 2 {
			continue
		} else if g.dfs(visited, other) == false {
			return false
		}
	}

	visited[node] = 2
	g.topo_order = append(g.topo_order, string([]byte{node}))
	return true
}

func byteInSlice(a byte, list []byte) bool {
    for _, b := range list {
        if b == a {
            return true
        }
    }
    return false
}

func alienOrder(words []string) string {
	graph := Graph{}
	graph.nodes = make([]byte, 0)
	graph.edges = make(map[byte][]byte)
	// Pairwise comparison is sufficient to establish order
	for i := 0; i < len(words) - 1; i++ {
		s := words[i]
		t := words[i + 1]
		for j := 0; j < len(s) && j < len(t); j++ {
			if byteInSlice(s[j], graph.nodes) == false {
				graph.nodes = append(graph.nodes, s[j])
			}
			if byteInSlice(t[j], graph.nodes) == false {
				graph.nodes = append(graph.nodes, t[j])
			}
            if s[j] == t[j] {
				continue
			}
            if byteInSlice(t[j], graph.edges[s[j]]) == false {
			    graph.edges[s[j]] = append(graph.edges[s[j]], t[j])
            }
            break
		}
	}

	topo_order := graph.topoSort()

    // Append non-deterministic chars in the end
    if topo_order != "CYCLE" {
        for i := 0; i < len(words); i++ {
            for j := 0; j < len(words[i]); j++ {
                if byteInSlice(words[i][j], []byte(topo_order)) == false {
                    topo_order += string([]byte{words[i][j]})
                }
            }
        }
    } else {
        topo_order = ""
    }
	return topo_order
}