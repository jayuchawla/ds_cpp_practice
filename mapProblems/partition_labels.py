# You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

# Return a list of integers representing the size of these parts.

# Input: s = "ababcbacadefegdehijhklij"
# Output: [9,7,8]
# Explanation:
# The partition is "ababcbaca", "defegde", "hijhklij".
# This is a partition so that each letter appears in at most one part.
# A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

# Input: s = "eccbbbbdec"
# Output: [10]

def partitionLabels(s):
    d={};l=[]
    for i in range(len(s)):
        d[s[i]] = d.get(s[i], [])
        d[s[i]].append(i)
    prev_min_index=d[s[0]][0]
    prev_max_index=d[s[0]][0]
    for i in d:
        current_min_index=min(d[i]);current_max_index=max(d[i])
        if(current_min_index > prev_max_index):
            # l.append(s[prev_min_index:prev_max_index+1])
            l.append(prev_max_index-prev_min_index+1)
            prev_max_index=-1;prev_min_index=-1 
        if(prev_max_index < current_max_index):
            prev_max_index=current_max_index
        if(prev_min_index == -1 or current_min_index < prev_min_index):
            prev_min_index=current_min_index
    l.append(prev_max_index-prev_min_index+1)
    # l.append(s[prev_min_index:prev_max_index+1])
    return l

print(partitionLabels('ababcbacadefegdehijhklij'))
print(partitionLabels('eccbbbbdec'))