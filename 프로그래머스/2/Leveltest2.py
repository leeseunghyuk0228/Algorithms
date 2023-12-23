def solution(p, l):
    if len(p)==1:
        return 1
    cnt=0
    n_p=[str(idx)+' '+str(i) for idx,i in enumerate(p)]
    
    while 1:
        n=n_p.pop(0)
        tmp_idx,tmp_num=int(n.split(' ')[0]),int(n.split(' ')[1])
        
        if max(list(map(lambda x:int(x.split(' ')[1]),n_p)))>tmp_num:
            n_p.append(n)
            
        elif max(list(map(lambda x:int(x.split(' ')[1]),n_p)))<=tmp_num and tmp_idx==l:
            cnt+=1
            return cnt
        
        else:
            cnt+=1
        
        if len(n_p)==1:
            return cnt+1