func minSum(nums1 []int, nums2 []int) int64 {
    sum1 := int64(0)
    empty1 := int64(0) 
    for _, num := range nums1 {
        if num == 0 { empty1++ }
        sum1 += int64(num)
    }

    sum2 := int64(0)
    empty2 := int64(0)
    for _, num := range nums2 {
        if num == 0 { empty2++ }
        sum2 += int64(num)
    }

    if sum2 < sum1 + empty1 && empty2 == 0 { return -1 }
    if sum1 < sum2 + empty2 && empty1 == 0 { return -1 }
    return max(sum1 + empty1, sum2 + empty2)
}
