#include <stdio.h>
#include "MonteCarloTreeSearch.h"
#include "game.h"

static mctsNode *initGame(void);

int main() {
    printf("Hello, World!\n");
//    printf("errorCode: a: 0x%04x, b: 0x%04x", moduleARun(), moduleBRun());
    initGame();
    return 0;
}

mctsNode *initGame(void) {
    extern game myGame;
    int role = -1;
    mctsNode *root = NULL;
    while (role != 0 && role != 1) {
        printf("Please select the role: (1) X, (2) O. (1 or 2):");
        scanf("%d", &role);
        if (role == 1 || role == 2) {
            myGame.playersRole = role;
            printf("%s is selected.", (role == 1)?"X":"O");
        } else {
            printf("%d is not legal, please input again\n");
        }
    }

    return root;
}
