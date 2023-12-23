for s,c in zip(survey,choice):
    if c==4:
        pass
    elif c<4:
        MBTI[s[0]]+=point[c]
    else:
        MBTI[s[1]]+=point[c]
    print(MBTI)
print('\n누적 결과: ',MBTI)

for i,j in zip(list(MBTI.keys())[0::2],list(MBTI.keys())[1::2]):
    if MBTI[i]==MBTI[j]:
        answer+=min(i,j)
    elif MBTI[i]>MBTI[j]:
        answer+=i
    else:
        answer+=j
    print(answer)
print('\n성격 유형 검사 결과: ',answer)