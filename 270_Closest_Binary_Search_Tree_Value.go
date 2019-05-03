/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import (
    "math"
    "fmt"
)

func closestValue(root *TreeNode, target float64) int {
    ret := root.Val
    for root != nil {
        if math.Abs(target - float64(root.Val)) < math.Abs(float64(ret) - target) {
            ret = root.Val
        }
        if target < float64(root.Val) {
            root = root.Left
        } else {
            root = root.Right
        }
    }
    return ret
}