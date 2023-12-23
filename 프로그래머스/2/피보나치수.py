def solution(n):
    pibo=[0,1,1,2]
    
    if n>3:
        for i in range(1,n-2):
            pibo.append(pibo[-1]+pibo[-2])
            
    return pibo[n]%1234567
