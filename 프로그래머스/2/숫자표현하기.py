def solution(n):
    s=1
    tmp,ans=0,0
    
    while s<=n:
        
        mcnt=(n//s)+1
        plus=1
        
        for i in range(s,n+1):
            tmp+=i
            plus+=1
            
            if tmp==n:
                ans+=1
                break    
                
            if plus>=mcnt or tmp>n:
                break
        s+=1
        tmp=0
        
    return ans