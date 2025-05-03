func pushDominoes(dominoes string) string {
    s := "L" + dominoes + "R"
    var result strings.Builder
    prev := 0

    for curr := 1; curr < len(s); curr++ {
        if s[curr] == '.' {
            continue
        }

        span := curr - prev - 1

        // All of the original falling dominoes (L or R) will be in result
        if prev > 0 {
            result.WriteByte(s[prev])
        }

        // Process the span of .'s
        if s[prev] == s[curr] {
            // Both L's or Both R's
            for i := 0; i < span; i++ {
                result.WriteByte(s[prev])
            }
        } else if s[prev] == 'L' && s[curr] == 'R' {
            // Dominoes falling opposite directions, standing stay in place
            for i := 0; i < span; i++ {
                result.WriteByte('.')
            }
        } else {
            // R..L Dominoes falling inward simultaneously
            for i := 0; i < span/2; i++ {
                result.WriteByte('R')
            }
            if span % 2 == 1 {
                result.WriteByte('.')
            }
            for i := 0; i < span/2; i++ {
                result.WriteByte('L')
            }
        }

        prev = curr
    }

    return result.String()
}
