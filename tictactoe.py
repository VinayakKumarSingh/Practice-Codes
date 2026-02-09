import time

# 1. FIX: Keep spaces for formatting consistency
board = [' '] * 9

def show():
    print()
    print(board[0],'|',board[1],'|',board[2])
    print('--+---+--')
    print(board[3],'|',board[4],'|',board[5])
    print('--+---+--')
    print(board[6],'|',board[7],'|',board[8])
    print()

def win(p):
    return((board[0]==board[1]==board[2]==p)or
    (board[3]==board[4]==board[5]==p)or
    (board[6]==board[7]==board[8]==p)or
    (board[0]==board[3]==board[6]==p)or
    (board[1]==board[4]==board[7]==p)or
    (board[2]==board[5]==board[8]==p)or
    (board[0]==board[4]==board[8]==p)or
    (board[2]==board[4]==board[6]==p))

def isFull():
    # 2. FIX: Check for ' ' (space), not ''
    return ' ' not in board

def dfs(is_ai):
    if(win('X')):  return 1
    elif(win('O')):  return -1
    elif(isFull()):  return 0

    if is_ai:
        best_score = -100
        for i in range(9):
            # 3. FIX: Check for space
            if(board[i] == ' '):
                board[i] = 'X'
                score = dfs(False)
                board[i] = ' ' # Backtrack with space
                best_score = max(best_score, score)
        return best_score
    else:
        best_score = 100
        for i in range(9):
            # 3. FIX: Check for space
            if(board[i] == ' '):
                board[i] = 'O'
                score = dfs(True)
                board[i] = ' ' # Backtrack with space
                best_score = min(best_score, score)
        return best_score

def ai_move():
    best_score = -100
    move = -1
    for i in range(9):
        # 3. FIX: Check for space
        if(board[i] == ' '):
            board[i] = 'X'
            score = dfs(False)
            board[i] = ' '

            if score > best_score:
                move = i
                best_score = score
    
    # 4. FIX: Use 'move', not 'i'
    if move != -1:
        board[move] = 'X'

#main program execution
print('Tic-Tac-Toe You-O ,Ai-X \n let\'s play \n you start \n')
show()

while(1):
    #human move
    try:
        user_input = input("Your move (1-9): ")
        if not user_input.isdigit(): continue
        pos = int(user_input) - 1
        
        # 5. FIX: Check if spot is NOT a space
        if pos < 0 or pos > 8 or board[pos] != ' ':
            print('INVALID INPUT !!')
            continue
            
        board[pos] = 'O'
        show()
    except Exception as e:
        print(e)
        continue

    # 6. FIX: Use print, not println
    if(win('O')):
        print('You Win')
        break
    if(isFull()):
        print('Draw')
        break
    
    #ai move
    print('Ai is thinking...')
    for i in range(5):
        print('.', end='', flush=True)
        time.sleep(0.1) # Added small delay
    print()

    ai_move()
    show()
    
    if win('X'):
        print('AI wins')
        break
    elif isFull():
        print('Draw')
        break