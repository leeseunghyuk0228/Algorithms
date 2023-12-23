def solution(n, lost, reserve):
    #정렬
 
    reserve.sort()
    #중복 제거
    n_lost=[l for l in lost if l not in reserve]
    n_reserve=[r for r in reserve if r not in lost]
    #초기n -> 전체n - 도둑맞은 명수
    answer=n-len(n_lost)
    
    for r in n_reserve:
        if r-1 in n_lost:
            answer+=1
            n_lost.remove(r-1)
        elif r+1 in n_lost:
            answer+=1
            n_lost.remove(r+1)
            
    return answer