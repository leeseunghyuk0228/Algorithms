def solution(board, moves):
    queue=[0]
    cnt=0
    for m in moves:
        for s in range(0,len(board[0])):
            if board[s][m-1]!=0:
                if board[s][m-1]==queue[-1]:
                    queue.pop()
                    cnt+=2
                else:
                    queue.append(board[s][m-1])
                board[s][m-1]=0
                break
    return cnt