N=5
stages=[2, 1, 2, 6, 2, 4, 3, 3]

def solution(N, stages):
    from collections import Counter
    
    stage_cnt=Counter(stages)
    data={}
    stage_len=len(stages)
    
    for i in range(1,N+1):
        try:
            data[i]=stage_cnt[i]/stage_len
        except:
            data[i]=0
            
        stage_len-=stage_cnt[i]
    
    return sorted(data,key=lambda x: data[x],reverse=True)