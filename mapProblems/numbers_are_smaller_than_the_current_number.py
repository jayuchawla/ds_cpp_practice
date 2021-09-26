# Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

# Return the answer in an array.
# Input: nums = [8,1,2,2,3]
# Output: [4,0,1,1,3]
# Explanation: 
# For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
# For nums[1]=1 does not exist any smaller number than it.
# For nums[2]=2 there exist one smaller number than it (1). 
# For nums[3]=2 there exist one smaller number than it (1). 
# For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).

# Input: nums = [6,5,4,8]
# Output: [2,1,0,3]

def smallerNumbersThanCurrent(nums):
    """
    :type nums: List[int]
    :rtype: List[int]
    """
    d={}
    for i in nums:
        d[i]=d.get(i,0) + 1
    d=dict(sorted(d.items(), key=lambda x:x[0], reverse=True))
    m=0
    for i in d.items():
        m+=i[1]
    l=[]
    for k in d:
        m-=d[k]
        d[k]=m
    for i in nums:
        l.append(d[i])
    return l

print(smallerNumbersThanCurrent(nums = [6,5,4,8]))
print(smallerNumbersThanCurrent(nums = [7,7,7,7]))