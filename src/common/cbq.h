//
// Created by caobaoqi on 2024/1/8.
//

#ifndef QKXG_C_2022_CBQ_H
#define QKXG_C_2022_CBQ_H

#endif //QKXG_C_2022_CBQ_H

#include "stdio.h"

/**
 * 输出 header
 * @param name 方法名
 */
void printHeader(char *name) {
    printf("\n|====== %s|Start =======|\n", name);
}

/**
 * 输出 footer
 * @param name 方法名
 */
void printFooter(char *name) {
    printf("\n|====== %s|End   =======|\n", name);
}

/**
 * 彩色输出 header
 * @param name 方法名
 */
void printHeaderColorful(char *name) {
    printf("\033[0;34m\n|====== %s | Start =======|\033[0m\n", name);
}

/**
 * 彩色输出 footer
 * @param name 方法名
 */
void printFooterColorful(char *name) {
    printf("\033[0;32m\n|====== %s | End   =======|\033[0m\n", name);
}