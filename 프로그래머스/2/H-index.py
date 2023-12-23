# enumerate & index 활용한 방법

def solution(nums):
    nums=sorted(nums,reverse=True)
    return max(map(min,enumerate(nums,start=1)))