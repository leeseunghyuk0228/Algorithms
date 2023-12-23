def solution(n, words):
    data=[words[i::n] for i in range(0,n)]
    w=[]
    for i in range(len(data[0])):
        for j in range(len(data)):
            if w==[] or (w[-1][-1]==data[j][i][0] and data[j][i] not in w):
                w.append(data[j][i])
            else:
                return [j+1,i+1]
            
    return [0,0]