def solution(id_list, report, k):
    # answer 리스트 인덱스=유저 ID, 리스트 값=정지된 ID 값
    answer=[0]*len(id_list)
    # {ID:신고 당한 횟수} 딕셔너리 생성
    reports = {x : 0 for x in id_list} 
    print('answer 생성: ',answer) 
    print('reports(신고당한 횟수) 생성: ',reports,'\n')
    
    #신고한 사람(split[0])
    #신고당한 사람(split[1])
    #중복 신고 비허용을 위한 set함수 사용
    for r in set(report):
        print('[유저ID, 신고 당한 ID] --> ',r.split())
        reports[r.split()[1]] += 1 # 신고 누적 횟수 증가
    print('\nreports(신고당한 횟수):',reports)
    
    # 신고한 사람 ID 해당 index 증가
    for r in set(report):
        if reports[r.split()[1]]>=k:
            answer[id_list.index(r.split()[0])]+=1
    
            
    return answer