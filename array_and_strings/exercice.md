## Merge sorted array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

```
def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p1 = m - 1
        p2 = n - 1
        insert = m + n - 1

        while p1 >=0 and p2 >= 0:
            if nums1[p1] >= nums2[p2]:
                nums1[insert] = nums1[p1]
                p1 -= 1
            else:
                nums1[insert] = nums2[p2]
                p2 -= 1
            insert -= 1

        while p2 >= 0:
            nums1[insert] = nums2[p2]
            insert -= 1
            p2 -= 1
```