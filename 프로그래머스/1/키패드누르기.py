def solution(numbers, hand):
    answer=''
    L,R=10,12
    
    def LRcheck(answer,L,R,num):
        if num in [1,4,7]:
            answer+='L'
            L=num
            return answer,L,R
        if num in [3,6,9]:
            answer+='R'
            R=num
            return answer,L,R

    def get_coord(n):
        if n==0: return 3,1
        else: return (n-1)//3,(n-1)%3

    def get_dis(x1,y1,x2,y2):
        return abs(x2-x1)+abs(y2-y1)

    def check(dl,dr,answer,L,R,num):
        if dl>dr or ((dl==dr) and (hand[0]=='r')):
            answer+='R'
            R=num
        else :
            answer+='L'
            L=num
        return answer,L,R

    
    for num in numbers:
        if num not in [2,5,8,0]:
            answer,L,R=LRcheck(answer,L,R,num)
            
        else:
            tx,ty=get_coord(num)
            lx,ly=get_coord(L)
            rx,ry=get_coord(R)
            dl=get_dis(lx,ly,tx,ty)
            dr=get_dis(rx,ry,tx,ty)
            answer,L,R=check(dl,dr,answer,L,R,num)
            
    return answer