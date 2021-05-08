//
// Created by nasihs on 2021/5/7.
//

#include "moduleA.h"
#define MODULE_ID 0x02

int moduleARun(void) {
    return getErrorCode(0x0F);
}