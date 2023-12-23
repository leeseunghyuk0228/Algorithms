def solution(answers):
    import numpy as np
    
    data=[[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]] # 세 명의 찍는 패턴
    a=len(answers) # 최대 1만
    
    for idx,d in enumerate(data):
        if len(d)==a:
            pass
        else:
            data[idx]=np.tile(d,int(a/len(d))+1)[:a]
    
    data=np.array(data)-np.array(answers) # 답 개수만큼 변경된 패턴 - 답
    ans=[np.count_nonzero(d) for d in data] # 틀린 개수 리스트
    
    
    return [x+1 for x in range(0,3) if ans[x]==min(ans)]
    
    