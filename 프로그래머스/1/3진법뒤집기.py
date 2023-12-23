def solution(n):
    nn=1
    while 3**nn<=n:
        nn+=1
    
    data=[]
    for i in range(nn-1,-1,-1):
        data.append(n//(3**i))
        n=n%(3**i)
    
    return sum([d*(3**(idx)) for idx,d in enumerate(data)])

### int(sting,n) -> 문자열 n진법으로 변환
def solution(n):
    ans=''
    while n:
        ans+=str(n%3)
        n=n//3
    return int(ans,3)
    