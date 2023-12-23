def solution(s):
#     queue=[s[0]]

#     for i in s[1:]:   
#         if len(queue)!=0 and queue[-1]!=i and queue[-1]=='(':
#             queue.pop()
#         else:
#             queue.append(i)
        
#     if len(queue)==0: return True
#     else: return False
    if '()'*int(len(s)/2)==s:
        return True
    x = 0
    for w in s:
        if x < 0:
            break
        x = x+1 if w=="(" else x-1 if w==")" else x

    return x==0