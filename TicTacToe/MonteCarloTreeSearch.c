//
// Created by nasihs on 2021/5/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>
#include "MonteCarloTreeSearch.h"

static mctsNode* getBestUCTChild(mctsNode *node);
static mctsNode* expandNode(mctsNode *parent);
static gameState rollout(const mctsNode *node);
static gameState applyMove(mctsNode *node, const move *mov);
static int getChildNum(mctsNode *parent);
static mctsNode* createChildNode(mctsNode *parent, int x, int y);
static void appendChild(mctsNode *parent, mctsNode *child);


mctsNode* traverseTree(mctsNode *node) {
    if (!node)
        return NULL;
    mctsNode *ret = NULL;
    mctsNode *tmpNode = node;

    while (getChildNum(tmpNode) > 0) {
        tmpNode = getBestUCTChild(tmpNode);
    }
    if (tmpNode->visitedTime <= 0)
        tmpNode = expandNode(tmpNode);

    return tmpNode;
}

/* 采用随机走子模拟游戏结果 */
gameState rollout(const mctsNode *node) {
    gameState state = NOT_END;
    mctsNode tmpNode = *node;  /* 拷贝当前节点，禁止修改原节点 */
    pieceType nextPiece = (node->whoseTurn == NOUGHT)?NOUGHT:CROSS;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tmpNode.board[i][j] <= 0) {
                move nextMove = {i, j};
                state = applyMove(&tmpNode, &nextMove);
                nextPiece = (nextPiece == NOUGHT)?CROSS:NOUGHT;
                if (state >= X_WIN)
                    goto finally;
            }
        }
    }
finally:
    return state;
}



/* 添加当前节点所有可能的动作为子节点， 并返回第一个子节点*/
mctsNode* expandNode(mctsNode *parent) {
    if (!parent)
        return NULL;
    int possibleMoveNum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (parent->board[i][j] == 0) {
                mctsNode *child = createChildNode(parent, i, j);
                appendChild(parent, child);
            }
        }
    }
    // mctsNode *tmpNode = NULL;
    return parent->child[0];
}


int getChildNum(mctsNode *parent) {
    if (!parent)
        return 0;
    int count = 0;
    for (int i = 0; i < MAX_CHILD_NUM; i++) {
        if (parent->child[i])
            count++;
        else
            break;
    }
    return count;
}

mctsNode* createChildNode(mctsNode *parent, int x, int y) {
    mctsNode *tmpChild;
    tmpChild = (mctsNode*)malloc(sizeof(mctsNode));
    memcpy(tmpChild->board, parent->board, sizeof(parent->board));
    tmpChild->board[x][y] = parent->whoseTurn;
    return tmpChild;
}

void appendChild(mctsNode *parent, mctsNode *child) {
    mctsNode *tmp = parent->child[0];
    for (int i = 0; i < MAX_CHILD_NUM; i++) {
        if (parent->child[i]) {
            continue;
        } else {
            parent->child[i] = child;
            break;
        }
    }
}


