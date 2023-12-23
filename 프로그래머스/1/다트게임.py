def solution(s):
    import re

    
    ex={'S':'**1','D':'**2','T':'**3','#':'*(-1)'}

    point=re.findall('(\d{1,2}[a-zA-Z]{1,2}\*?\#?)',s)

    for i in [1,2]:
        if '*' in point[i]:
            point[i-1]=point[i-1]+'*'
    answer='+'.join(point)
    answer=answer.replace('*','*2')

    for e in ex.keys():
        answer=answer.replace(e,ex[e])
    return eval(answer)