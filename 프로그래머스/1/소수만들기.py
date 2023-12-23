def solution(nums):
    ans=0
    for i in range(0,len(nums)-2):
        for j in range(i+1,len(nums)):
            for k in range(j+1,len(nums)):
                num=nums[i]+nums[j]+nums[k]
                cnt=0
                for n in range(2,int(num**(0.5))+1):
                    if num%n==0:
                        cnt+=1
                if cnt==0:
                    ans+=1
                    
    return ans