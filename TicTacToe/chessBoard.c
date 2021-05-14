//
// Created by nasihs on 2021/5/9.
//
#include <stdio.h>
#include "chessBoard.h"

enum PieceType {
    NOUGHT = 0,
    CROSS,
};

int chessBoard[3][3] = {
        -1, -1, -1,
        -1, -1, -1,
        -1, -1, -1,
};

/* 0:blank, 0->X, 1->O */
static void showLine(int *line) {
    for (int i = 0; i < 3; i++) {
        if (line[i] == -1)
            printf("| ");
        else if (line[i] == 0)
            printf("|X");
        else if (line[i] == 1)
            printf("|O");
    }
    printf("|\n");
}

int placeAPiece(int x, int y, int type) {
    if (chessBoard[x][y] != -1)
        return -1;
    else
        chessBoard[x][y] = type;

    return 0;
}


void showChessBoard(void) {
    printf("-------\n");
    showLine(chessBoard[0]);
    showLine(chessBoard[1]);
    showLine(chessBoard[2]);
    printf("-------\n");
}