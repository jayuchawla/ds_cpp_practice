# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# You can return the answer in any order.

# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Output: Because nums[0] + nums[1] == 9, we return [0, 1].

# Input: nums = [3,3], target = 6
# Output: [0,1]

def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    d={}
    for i in range(len(nums)):
        d[nums[i]] = i
    for i in range(len(nums)):
        if target-nums[i] in d and i!=d[target-nums[i]]:
            return [i,d[target-nums[i]]]

print(twoSum(nums = [2,7,11,15], target = 9))
print(twoSum(nums = [3,3], target = 6))