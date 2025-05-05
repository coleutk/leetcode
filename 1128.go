func numEquivDominoPairs(dominoes [][]int) int {
    // Instead of storing the domino pair, we can encode it as an integer
    freq := make(map[int]int)

    for _, domino := range dominoes {
        // Sort the pair if not already
        a, b := domino[0], domino[1]
        if a > b {
            a, b = b, a
        }

        // Encode pair as integer (works b/c dominoes digits are from 1-9)
        key := a*10 + b
        freq[key]++
    }

    res := 0
    for _, count := range freq {
        res += (count * (count - 1)) / 2
    }

    return res
}
