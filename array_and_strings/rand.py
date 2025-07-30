def rotate(nums, k):
    k=k%len(nums)
    print(k)
    print(nums[-k:])
    print(nums[:-k])
    nums[:]=nums[-k:]+nums[:-k]

rotate([1, 2, 3, 4, 5, 6, 7, 8, 9], 3)