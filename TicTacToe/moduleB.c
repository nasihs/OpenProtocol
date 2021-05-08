//
// Created by nasihs on 2021/5/7.
//

#include "moduleB.h"
#include "moduleA.h"

#define MODULE_ID 0x01

int moduleBRun(void) {
    return getErrorCode(0x0F);
}