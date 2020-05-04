//
// Created by Chan Yeol on 2020/5/4.
//

#ifndef MCM_MCM_H
#define MCM_MCM_H
#include <stdio.h>

#define N 200
#define INT_MAX 2147483647

void matrix_chain_order(int *p, int length, int m[][N], int s[][N]);
void print_opt_parens(int s[][N], int i, int j);

#endif //MCM_MCM_H
