/*
 *
 */

#ifndef MCTS_MONTECARLOTREESEARCH_H
#define MCTS_MONTECARLOTREESEARCH_H

#include "chessBoard.h"
#define MAX_CHILD_NUM (16)

typedef struct _mctsNode {
    struct _mctsNode    *parent;
    struct _mctsNode    *child[MAX_CHILD_NUM];
    gameState           state;
    int                 winTime;
    int                 visitedTime;
    pieceType           whoseTurn;
    int                 board[3][3];
} mctsNode;
//typedef mctsNode_t *mctsNode;

mctsNode* monteCarloTreeSearch(mctsNode *root);
mctsNode* traverseTree(mctsNode *node);
int backPropagation(mctsNode *node, gameState result);
mctsNode* chooseTheBestChild(mctsNode *root);  // 返回value最大的子节点

#endif //MCTS_MONTECARLOTREESEARCH_H
