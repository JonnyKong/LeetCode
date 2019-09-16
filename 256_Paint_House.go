package main

import (
    "fmt"
    "math"
)

func minCost(costs [][]int) int {
    if len(costs) == 0 {
        return 0
    }

    // Init DP array, set first row of DP
    dp := make([][]int, len(costs))
    for i := 0; i < len(dp); i += 1 {
        dp[i] = make([]int, len(costs[0]))
    }
    for i := 0; i < len(dp[0]); i += 1 {
        dp[0][i] = costs[0][i]
    }

    for i := 1; i < len(dp); i += 1 {
        for j := 0; j < len(dp[0]); j += 1 {
            dp[i][j] = math.MaxInt32
            for k := 0; k < len(dp[0]); k += 1 {
                if k == j {
                    continue
                }
                if dp[i - 1][k] + costs[i][j] < dp[i][j] {
                    dp[i][j] = dp[i - 1][k] + costs[i][j]
                }
            }
        }
    }

    // Extract min value from DP
    global_min := math.MaxInt32
    for i := 0; i < len(dp[0]); i += 1 {
        if dp[len(dp) - 1][i] < global_min {
            global_min = dp[len(dp) - 1][i]
        }
    }
    return global_min
}

func main() {
    a := [][]int{
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3},
    }
    fmt.Printf("%d\n", minCost(a))
}