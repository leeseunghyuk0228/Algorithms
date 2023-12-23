def solution(new_id):
    import re
    print('입력 아이디: {id}\n'.format(id=new_id))
    
    #1단계(소문자 변환)
    new_id=new_id.lower()
    print('소문자로 변경: {id}\n'.format(id=new_id))
    
    #2단계(특수문자 제거)
    new_id=re.sub('[^ a-zA-Z0-9-_|.]','',new_id)
    print('특수문자 제거: {id}\n'.format(id=new_id))
    
    #3단계(온점 여러개시 중복 제거)
    new_id=re.sub('[.]{2,}','.',new_id)
    print('\'.\'개수 줄이기: {id}\n'.format(id=new_id))
    
    #4단계(맨앞,맨뒤 온점 제거)
    new_id=re.sub('^[.]|[.]$','',new_id)
    print('\'.\' 시작 끝 없애기: {id}\n'.format(id=new_id))
    
    #5단계(아이디 공백시 문자 'a' 대체)
    if new_id=='':
        new_id='a'
        print('아이디 공백일 때: ',new_id,'\n')
        
    #6단계(길이 15 초과 자르기)
    elif len(new_id)>15:
        new_id=new_id[:15]
        print('아이디 길이 15 축소 : ',new_id,'\n')
        
    #7단계(3글자 이하일 때, 반복)
    if len(new_id)<3:
        for i in range(0,3-len(new_id)):
            new_id+=new_id[-1]
        print('아이디 3글자 이하, 마지막 문자 반복: ',new_id,'\n')
            
    #4단계(마지막 맨앞, 맨뒤 온점 제거)
    answer = re.sub('^[.]|[.]$','',new_id)
    return answer