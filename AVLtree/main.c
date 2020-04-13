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
        printf("请输入选择：\n");
        printf("1.插入节点数据        2.查看AVL树\n");
        printf("3.删除节点数据        4.退出\n");
        printf("================================\n");

        scanf("%c", &choose);
        switch(choose){
            case '1':
                printf("** 依次添加: ");
                ilen = (sizeof(arr)) / (sizeof(arr[0]));
                for(i=0; i<ilen; i++)
                {
                    printf("%d ", arr[i]);
                    root = avltree_insert(root, arr[i]);
                }
                break;
            case '2':
                printf("** 高度: %d\n", avltree_height(root));
                printf("** 前序遍历: \n");
                avltree_preorder(root);
                printf("\n** 中序遍历: \n");
                avltree_inorder(root);
                printf("\n** 树的详细信息为: \n");
                avltree_print(root, root->key, 0);
                break;
            case '3':
                i = 6;
                printf("\n** 删除根节点数值: %d\n", i);
                if((root = avltree_delete(root, i)) != NULL)
                    printf("删除成功！\n");
                break;
            case '4':
                avltree_destroy(root);
                exit(0);
            default:
                printf("请输入正确选择！\n");
        }
        getchar();
        printf("\n");
    }
    return 0;
}
