//
// Created by Chan Yeol on 2020/5/4.
//
#include "MCM.h"

void matrix_chain_order(int *p, int length, int m[][N], int s[][N])
{
    int i, l, j, k, q;
    int n = length;
    for(i=1; i<=n; i++)
    {
        m[i][i] = 0 ;
    }
    for(l=2; l<=n ; l++)
    {
        for(i=1; i<=(n-l+1); i++)
        {
         //   printf("i == %d\n",i);
            j = i+l-1 ;
         //   printf("j == %d\n",j);
            m[i][j] = INT_MAX;
            for(k=i; k<=j-1 ; k++)
            {
         //       printf("k == %d\n",k);
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j])
                {
                    m[i][j] = q;
         //            printf(" s[%d][%d] == %d\n",i,j,k);
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_opt_parens(int s[][N], int i, int j)
{
    if(i == j) printf("A%d ",i);
    else
    {
        printf("(");
        print_opt_parens(s, i, s[i][j]);
        print_opt_parens(s, s[i][j]+1, j);
        printf(")");
    }
}
