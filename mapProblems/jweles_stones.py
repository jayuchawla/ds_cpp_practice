# You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

# Letters are case sensitive, so "a" is considered a different type of stone from "A".

# Input: jewels = "aA", stones = "aAAbbbb"
# Output: 3

# Input: jewels = "z", stones = "ZZ"
# Output: 0

def numJewelsInStones(jewels, stones):
    """
    :type jewels: str
    :type stones: str
    :rtype: int
    """
    d={};t=0
    for i in stones:
        d[i]=d.get(i,0)+1
    for i in jewels:
        t+=d.get(i,0)
    return t

print(numJewelsInStones(jewels = "aA", stones = "aAAbbbb"))
print(numJewelsInStones(jewels = "z", stones = "ZZ"))