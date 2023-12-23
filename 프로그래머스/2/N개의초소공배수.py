def solution(arr):
    m=1
    
    for i in arr:
        m*=i
        
    for num in range(1,m):
        for i in arr:
            if num%i!=0:
                break
        else:
            return num
                