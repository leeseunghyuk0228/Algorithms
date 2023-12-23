def solution(t,a,b):
    if t==2: return 1
    
    a,b,cnt=a-1,b-1,0
    
    while 1:
        if a//2==b//2: return cnt+1
        else:
            a,b,cnt=a//2,b//2,cnt+1