#include <stdio.h>
#include <stdlib.h>
#include "AVLtree.h"

static int arr[]  = {2,1,3,15,14,13,12,11,4,5,6,7,16,10,8,9};
static int arrs[] = {7,16,15,3,2,1,5,6,18,17};

int main()
{
    int i, choose = 0, ilen;
    AVLTree root = NULL;

    while(1)
    {
        printf("================================\n");
        printf("������ѡ��\n");
        printf("1.����ڵ�����        2.�鿴AVL��\n");
        printf("3.ɾ���ڵ�����        4.�˳�\n");
        printf("================================\n");

        scanf("%c", &choose);
        switch(choose){
            case '1':
                printf("** �������: ");
                ilen = (sizeof(arr)) / (sizeof(arr[0]));
                for(i=0; i<ilen; i++)
                {
                    printf("%d ", arr[i]);
                    root = avltree_insert(root, arr[i]);
                }
                break;
            case '2':
                printf("** �߶�: %d\n", avltree_height(root));
                printf("** ǰ�����: \n");
                avltree_preorder(root);
                printf("\n** �������: \n");
                avltree_inorder(root);
                printf("\n** ������ϸ��ϢΪ: \n");
                avltree_print(root, root->key, 0);
                break;
            case '3':
                i = 6;
                printf("\n** ɾ�����ڵ���ֵ: %d\n", i);
                if((root = avltree_delete(root, i)) != NULL)
                    printf("ɾ���ɹ���\n");
                break;
            case '4':
                avltree_destroy(root);
                exit(0);
            default:
                printf("��������ȷѡ��\n");
        }
        getchar();
        printf("\n");
    }
    return 0;
}
