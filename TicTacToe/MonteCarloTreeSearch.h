//
// Created by nasihs on 2021/5/6.
//

#ifndef MCTS_MONTECARLOTREESEARCH_H
#define MCTS_MONTECARLOTREESEARCH_H

typedef struct _mctsNode {
    struct _mctsNode *parent;
    struct _mctsNode *child;
    int state;
    int winTime;
    int visitedTime;
} mctsNode;
//typedef mctsNode_t *mctsNode;

int isLeafNode(mctsNode* node);
int expandNode(mctsNode *node);
int simulateANode(mctsNode *node);  /* 0->fail, 1->success */
int backPropagation(mctsNode *node, int result);
mctsNode* chooseTheBestChild(mctsNode *root);  // 返回value最大的子节点

#endif //MCTS_MONTECARLOTREESEARCH_H
