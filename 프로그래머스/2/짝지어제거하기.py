def solution(s):
    a=[i for i in s]
    b=[]
    
    for j in a:
        if b!=[] and b[-1]==j:
            b.pop(-1)
        else:
            b.append(j)
            
    return int(b==[])
