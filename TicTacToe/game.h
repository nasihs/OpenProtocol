//
// Created by nasihs on 2021/5/9.
//

#ifndef MCTS_CHESSBOARD_H
#define MCTS_CHESSBOARD_H

#define WIN_SCORE   (1)
#define LOSE_SCORE  (-1)
#define DRAW_SCORE  (0)

typedef enum _pieceType {
    BLANK = 0,
    CROSS = 1,
    NOUGHT = 2,
} pieceType;

typedef enum _gameState {
    NOT_END = 0,
    X_WIN = 1,
    O_WIN = 2,
    DRAW = 3,
} gameState;

typedef struct _move {
    int x;
    int y;
} move;

typedef struct _game {
    pieceType playersRole;
    pieceType robotsRole;
    gameState state;
    void*     root;
} game;

extern pieceType getPlayersRole(void);
extern pieceType getRobotsRole(void);

// extern int isGameFinished(int **board);
extern void showChessBoard(int **board);


#endif //MCTS_CHESSBOARD_H
