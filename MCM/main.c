#include "MCM.h"

int main() {
    int p[] = {11,22,33,44,3,20,18};
    int i =1, j;

    j = sizeof(p) / sizeof(p[0]) - 1;
    int m[N][N], s[N][N];
    matrix_chain_order(p, j, m, s);
    printf("���Ž�Ϊ\n%d\n", m[1][6]);
    printf("�������Ż�����Ϊ\n");
    print_opt_parens(s, i, j);

    return 0;
}
