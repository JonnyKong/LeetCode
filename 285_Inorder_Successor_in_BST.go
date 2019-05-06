package main

import (
	"fmt"
)
type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

// Idea: Remember the lowest ancestor, that branched left.
// 3 cases
func inorderSuccessor(root *TreeNode, p *TreeNode) *TreeNode {
	var anc *TreeNode
	cur := root
	for cur.Val != p.Val {
		if cur.Val < p.Val {
			cur = cur.Right
		} else {
			anc = cur
			cur = cur.Left
		}
	}

	if cur.Right != nil {
		// Case 1: Search for leftmost child in right subtree
		return getLeftmostChild(cur.Right)
	} else if anc != nil {
		// Case 2: Search for last ancestor where search took the left path
		return anc
	} else {
		// Case 3: p is the rightmost element in the tree
		return nil
	}
}

// Get the left most child, assuming the root is not nil
func getLeftmostChild(root *TreeNode) *TreeNode {
	if root.Left == nil {
		return root
	} else {
		return getLeftmostChild(root.Left)
	}
}

func main() {
	root := TreeNode {
		Val: 	2,
		Left:	&TreeNode { Val: 1, },
		Right: 	&TreeNode { Val: 3, },
	}
	p := TreeNode { Val: 2, }
	fmt.Printf("%d\n", inorderSuccessor(&root, &p).Val)
}