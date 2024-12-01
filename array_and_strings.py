from typing import List

def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
    i, j = m - 1, n - 1
    k = m + n - 1

    while i >= 0 and j >= 0:
        if nums1[i] > nums2[j]:
            nums1[k] = nums1[i]
            i -= 1
        else:
            nums1[k] = nums2[j]
            j -= 1
        k -= 1

    while j >= 0:
        nums1[k] = nums2[j]
        j -= 1
        k -= 1

def removeElement(self, nums: List[int], val: int) -> int:
    k = 0
    for i in range(len(nums)):
        if nums[i] != val:
            nums[k] = nums[i]
            k += 1
    return k

def removeDuplicates(self, nums: List[int]) -> int:
    k = 1
    for i in range(1, len(nums)):
        if nums[i] != nums[i - 1]:
            nums[k] = nums[i]
            k += 1
    return k

def removeDuplicatesBis(self, nums: List[int]) -> int:
    n = len(nums)
    if n <= 2:
        return n

    write_index = 2

    for read_index in range(2, n):
        if nums[read_index] != nums[write_index - 2]:
            nums[write_index] = nums[read_index]
            write_index += 1

    return write_index
    
def majorityElement(self, nums: List[int]) -> int:
    # Boyer–Moore majority vote algorithm
    candidate = None
    count = 0
    for num in nums:
        if count == 0:
            candidate = num
        count += 1 if num == candidate else -1
    return candidate
    
def rotate(self, nums: List[int], k: int) -> None:
    n = len(nums)
    k %= n
    start = count = 0

    while count < n:
        current = start
        prev_value = nums[start]
        while True:
            next_idx = (current + k) % n
            nums[next_idx], prev_value = prev_value, nums[next_idx]
            current = next_idx
            count += 1

            if start == current:
                break
        start += 1

def maxProfit(self, prices: List[int]) -> int:
    min_price = float('inf')
    max_profit = 0
    
    for price in prices:
        min_price = min(min_price, price)
        profit = price - min_price
        max_profit = max(max_profit, profit)
    
    return max_profit