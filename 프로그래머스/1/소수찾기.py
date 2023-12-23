def solution(n):
    cnt=0
    for i in range(2,n+1):
        for nn in range(2,int(i**0.5)+1):
            if i%nn==0:
                break
        else:
            cnt+=1
                
    return cnt