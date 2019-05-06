// package main

import (
    "fmt"
)

func canWin(s string) bool {
    if len(s) < 2 {
        return false
    } else {
        b := []byte(s)
        cache := make(map[string]bool)
        return canWinHelper(&b, cache)
    }
}

func canWinHelper(b *[]byte, cache map[string]bool) bool {
    if ret, ok := cache[string(*b)]; ok {
        return ret
    }
    for i := 0; i < len(*b) - 1; i++ {
        if (*b)[i] == '+' && (*b)[i + 1] == '+' {
            (*b)[i] = '-'
            (*b)[i + 1] = '-'
            ret := canWinHelper(b, cache)
            (*b)[i] = '+'
            (*b)[i + 1] = '+'
            if !ret {
                cache[string(*b)] = true
                return true
            }
        }
    }
    cache[string(*b)] = false
    return false
}

// func main() {
// 	s := "++++"
// 	if canWin(s) {
// 		fmt.Printf("Success\n")
// 	}
// }