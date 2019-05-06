// Idea: Sort, and swap pairs

import (
  "sort"
)

func wiggleSort(nums []int)  {
  sort.Sort(sort.IntSlice(nums))
  for i := 1; i + 1 < len(nums); i += 2 {
    nums[i] ^= nums[i + 1]
    nums[i + 1] ^= nums[i]
    nums[i] ^= nums[i + 1]
    }
}