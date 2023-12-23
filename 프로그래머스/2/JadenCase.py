def solution(s):
    ans=''
    for i in s.split(' '):
        try:
            ans+=i[0].upper()
            ans+=i.lower()[1:]
            ans+=' '
        except:
            ans+=' '
    return ans[:-1]