//
// Created by nasihs on 2021/5/9.
//
#include <stdio.h>
#include "chessBoard.h"
#include "MonteCarloTreeSearch.h"

static game myGame;
pieceType getPlayersRole(void) {
    return myGame.playersRole;
}

pieceType getRobotsRole(void) {
    return myGame.robotsRole;
}

static gameState checkWhetherAnyoneWin(const mctsNode *node, const move *mov);
static int isBoardFull(int board[3][3]);
gameState applyMove(mctsNode *node, const move *mov) {
    node->board[mov->x][mov->y] = node->whoseTurn;
    gameState state = checkWhetherAnyoneWin(node, mov);
    if (state == NOT_END) {
        if (isBoardFull(node->board))
            state = DRAW;
    }
    return state;
}

gameState checkWhetherAnyoneWin(const mctsNode *node, const move *mov) {
    gameState state = NOT_END;

    /* check row and column */
    if ((node->board[0][mov->y] == node->whoseTurn
         && node->board[1][mov->y] == node->whoseTurn
         && node->board[2][mov->y] == node->whoseTurn)
        || (node->board[mov->x][0] == node->whoseTurn
            && node->board[mov->x][1] == node->whoseTurn
            && node->board[mov->x][2] == node->whoseTurn)) {
        state = (node->whoseTurn == NOUGHT)?X_WIN:O_WIN;
    } else if (mov->x == mov->y) {
        /* check diagonal */
        if ((node->board[0][0] == node->whoseTurn
             && node->board[1][1] == node->whoseTurn
             && node->board[2][2] == node->whoseTurn)
            || (node->board[0][2] == node->whoseTurn
                && node->board[1][1] == node->whoseTurn
                && node->board[2][0] == node->whoseTurn)) {
            state = (node->whoseTurn == NOUGHT)?X_WIN:O_WIN;
        }
    }
    return state;
}

int isBoardFull(int board[3][3]) {
    int ret = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] <= BLANK) {
                ret = 0;
                goto finally;
            }
        }
    }
    finally:
    return ret;
}

static void showLine(int *line) {
    for (int i = 0; i < 3; i++) {
        if (line[i] == BLANK)
            printf("| ");
        else if (line[i] == CROSS)
            printf("|X");
        else if (line[i] == NOUGHT)
            printf("|O");
    }
    printf("|\n");
}

void showChessBoard(int **board) {
    printf("-------\n");
    showLine(board[0]);
    showLine(board[1]);
    showLine(board[2]);
    printf("-------\n");
}