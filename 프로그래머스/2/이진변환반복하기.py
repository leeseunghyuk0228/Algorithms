def solution(s):
    ans=[0,0]
    
    while s!='1':
        ans[1]+=s.count('0')
        ans[0]+=1
        s=str(bin(s.count('1')))[2:]
    return ans