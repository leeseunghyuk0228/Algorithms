def solution(참가자, 완주자):
    참가자.sort()
    완주자.sort()
    
    for 참가,완주 in zip(참가자,완주자):
        if 참가!=완주:
            return 참가
        
    return 참가자[-1]