type Coord struct {
	x, y int
}

func wallsAndGates(rooms [][]int)  {
	// Sanity check
	if len(rooms) == 0 || len(rooms[0]) == 0 {
		return
	}

	// BFS
	queue := make([]Coord, 0)
	for i := 0; i < len(rooms); i++ {
		for j := 0; j < len(rooms[0]); j++ {
			if rooms[i][j] == 0 {
				queue = append(queue, Coord{ x: i, y: j })
			}
		}
	}

	for len(queue) > 0 {
		coord := queue[0]
		queue = queue[1 : len(queue)]

		x := coord.x
		y := coord.y
		if x > 0 && rooms[x - 1][y] == math.MaxInt32 {
			rooms[x - 1][y] = rooms[x][y] + 1
			queue = append(queue, Coord{ x: x-1, y: y })
		}
		if x < len(rooms) - 1 && rooms[x + 1][y] == math.MaxInt32 {
			rooms[x + 1][y] = rooms[x][y] + 1
			queue = append(queue, Coord{ x: x+1, y: y })
		}
		if y > 0 && rooms[x][y - 1] == math.MaxInt32 {
			rooms[x][y - 1] = rooms[x][y] + 1
			queue = append(queue, Coord{ x: x, y: y-1 })
		}
		if y < len(rooms[0]) - 1 && rooms[x][y + 1] == math.MaxInt32 {
			rooms[x][y + 1] = rooms[x][y] + 1
			queue = append(queue, Coord{ x: x, y: y+1 })
		}
	}
}