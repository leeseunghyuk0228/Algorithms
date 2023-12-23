def solution(n):
    if n==1: return 1
    cnt=0
    while 1:
        if n==1: return cnt+1
        elif n%2==0: n/=2
        else:
            n-=1
            n/=2
            cnt+=1