import re

def solution(input_string):
    
    res=[]
    for check in list(set(list(input_string))):
        data=list(filter(lambda x:x!='',re.findall(f'({check}*)',input_string)))
        if len(data)>=2:
            res.append(check)
    
    
    if res==[]: return 'N'
    else: return ''.join(sorted(res))

    
    
#     alpha=[0]
#     res=[]
#     for i in input_string:
#         if i in alpha:
#             if alpha[-1]==i:pass
#             else: res.append(i)
#         else:alpha.append(i)
#     print(alpha)
#     print(res)
    
    
#     if res==[]: return 'N'
#     else: return ''.join(sorted(list(set(res))))