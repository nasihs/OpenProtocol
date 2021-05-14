#include <stdio.h>
#include "MonteCarloTreeSearch.h"
#include "chessBoard.h"
#include "moduleB.h"
#include "moduleA.h"

extern int chessBoard[3][3];

int a = 1;
int main() {
    printf("%d\n", chessBoard[0][1]);
    printf("Hello, World!\n");
    showChessBoard();
    printf("errorCode: a: 0x%04x, b: 0x%04x", moduleARun(), moduleBRun());

    return 0;
}
