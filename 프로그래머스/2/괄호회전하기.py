def solution(s):
    ans,tmp=0,['a']
    
    for n in range(len(s)):
        
        for i in s:
            if ord(tmp[-1])-ord(i)==-1 or ord(tmp[-1])-ord(i)==-2 :tmp.pop()
            else: tmp.append(i)

        if len(tmp)==1: ans+=1
        
        tmp=['a']
        s+=s[0]
        s=s[1:]
        
    return ans
