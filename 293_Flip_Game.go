// Idea: Brute force string manipulation

func generatePossibleNextMoves(s string) []string {
    var results []string
    for i := 0; i < len(s) - 1; i++ {
        if s[i] == s[i + 1] && s[i] == '+' {
            result := []byte(s)
            result[i] = '-'
            result[i + 1] = '-'
            results = append(results, string(result))
        }
    }
    return results
}