def solution(s):
    m=list(map(int,(s.split(' '))))

    return str(min(m))+' '+str(max(m))