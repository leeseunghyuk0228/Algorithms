nums=[3,3,3,2,2,4]

def solution(nums):
    cnt=len(nums)/2/2
    if cnt>=len(set(nums)): return(len(set(nums)))
    else: return (cnt)
    return answer