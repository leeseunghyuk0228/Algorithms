# 로또 순위를 리스트로
def solution(lottos,win):
    score=[6,6,5,4,3,2,1]
    ### score 인덱스 = 맞춘 개수
    cnt_0=lottos.count(0)
    cnt_w=sum([1 for l in lottos if l in win])

    return score[cnt_0+cnt_w],score[cnt_w]