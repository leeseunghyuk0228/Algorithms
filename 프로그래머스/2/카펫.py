def solution(b, y):   
    ylist=[i for i in range(y,0,-1) if y%i==0]
    for idx,yl in enumerate(ylist):
        w=yl*2+4
        h=ylist[-idx-1]*2
        if w+h==b:
            return [yl+2,ylist[-idx-1]+2]