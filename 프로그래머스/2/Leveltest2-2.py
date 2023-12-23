def solution(s, K):
    ns=sorted(list(filter(lambda x:x<K,s)))
    cnt=0
    
    if len(ns)==0:
        return 0
    if len(s)==1:
        ns.append(sorted(s)[0])

    while min(ns) <= K:
        ns[0]+=ns[1]*2
        ns.pop(1)
        ns.sort()
        cnt+=1
        if len(ns)==1 and ns[0]<K:
            return -1
        
    return cnt