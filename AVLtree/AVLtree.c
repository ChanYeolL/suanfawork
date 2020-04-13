#include<stdio.h>
#include <stdlib.h>
#include "AVLtree.h"

#define MAX(a, b)    ( (a) > (b) ? (a) : (b) )
#define HEIGHT(treeNode)    ( (treeNode==NULL) ? 0 : (((Node *)(treeNode))->height) )

//前序遍历
void avltree_preorder(AVLTree tree)
{
    if(tree != NULL)
    {
        printf("%2d ", tree->key);
        avltree_preorder(tree->left);
        avltree_preorder(tree->right);
    }
}

//中序遍历
void avltree_inorder(AVLTree tree)
{
    if(tree != NULL)
    {
        avltree_inorder(tree->left);
        printf("%2d ", tree->key);
        avltree_inorder(tree->right);
    }
}

//后序遍历
void avltree_postorder(AVLTree tree)
{
    if(tree != NULL)
    {
        avltree_postorder(tree->left);
        avltree_postorder(tree->right);
        printf("%2d ", tree->key);
    }
}

Node* left_left_rotation(AVLTree tree)
{
    AVLTree p;

    p          = tree->left;
    tree->left = p->right;
    p->right   = tree;

    tree->height = MAX( HEIGHT(tree->left), HEIGHT(tree->right)) + 1;
    p->height    = MAX( HEIGHT(p->left),    tree->height) +1;

    return p;
}

Node* right_right_rotation(AVLTree tree)
{
    AVLTree p;

    p          = tree->right;
    tree->right = p->left;
    p->left    = tree;

    tree->height = MAX( HEIGHT(tree->left), HEIGHT(tree->right)) + 1;
    p->height    = MAX( tree->height,       HEIGHT(p->right)) +1;

    return p;
}

Node* left_right_rotation(AVLTree tree)
{
    tree->left = right_right_rotation(tree->left);

    return left_left_rotation(tree);
}

Node* right_left_rotation(AVLTree tree)
{
    tree->right = left_left_rotation(tree->right);

    return right_right_rotation(tree);
}

int avltree_height(AVLTree tree)
{
    return HEIGHT(tree);
}

Node* avltree_create(Type key, Node *left, Node* right)
{
    Node* treeNode;

    if((treeNode = (Node *)malloc(sizeof(Node))) == NULL )
        return NULL;

    treeNode->key    = key;
    treeNode->height = 0;
    treeNode->left   = left;
    treeNode->right  = right;

    return treeNode;
}

Node* avltree_insert(AVLTree tree, Type key)
{
    if(tree == NULL)
    {
        tree = avltree_create(key, NULL, NULL);
        if(tree == NULL)
        {
            printf("error：创建树节点失败！\n");
            return NULL;
        }
    }else if(key < tree->key)
    {
        tree->left = avltree_insert(tree->left, key);

        if(HEIGHT(tree->left) - HEIGHT(tree->right) ==2)
        {
            if(key < tree->left->key)
                tree = left_left_rotation(tree);
            else
                tree = left_right_rotation(tree);
        }
    }else if(key > tree->key)
    {
        tree->right = avltree_insert(tree->right, key);

        if(HEIGHT(tree->right) - HEIGHT(tree->left) ==2)
        {
            if(key > tree->right->key)
                tree = right_right_rotation(tree);
            else
                tree = right_left_rotation(tree);
        }
    }else
    {
        printf("error:添加失败，不能添加相同的节点!\n");
    }

    tree->height = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;

    return tree;
}

Node* avltree_maximum(AVLTree tree)
{
    if(tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->right;

    return tree;
}

Node* avltree_minimum(AVLTree tree)
{
    if(tree == NULL)
        return NULL;

    while(tree->left != NULL)
        tree = tree->left;

    return tree;
}

Node* avltree_delete(AVLTree tree, Type key)
{

    if(tree == NULL)
    {
        printf("error:删除节点失败！\n");
        return NULL;
    }

    if(key < tree->key)  //要删除的节点在左边
    {
        tree->left = avltree_delete(tree->left, key);
        if(HEIGHT(tree->right) - HEIGHT(tree->left) == 2)
        {
            Node *p = tree->right;
            if(HEIGHT(p->left) > HEIGHT(p->right))
                tree = right_left_rotation(tree);
            else
                tree = right_right_rotation(tree);
        }

    }else if(key > tree->key)//要删除的节点在右边
    {
        tree->right = avltree_delete(tree->right, key);
        if(HEIGHT(tree->left) - HEIGHT(tree->right) == 2)
        {
            Node *p = tree->left;
            if(HEIGHT(p->right) > HEIGHT(p->left))
                tree = left_right_rotation(tree);
            else
                tree = left_left_rotation(tree);
        }
    }else if(key == tree->key)//tree就是要删除的节点
    {
        if((tree->left) && (tree->right))
        {
            if(HEIGHT(tree->left) > HEIGHT(tree->right)) //用"tree的左子树中最大节点"做"tree"的替身
            {
                Node *max = avltree_maximum(tree);
                tree->key = max->key;
                tree->left = avltree_delete(tree->left, key);

            }else //用"tree的右子树中最小节点"做"tree"的替身；
            {
                Node *min = avltree_minimum(tree);
                tree->key = min->key;
                tree->right = avltree_delete(tree->right, key);
            }
        }else
        {
            Node *p = tree;
            tree = tree->left ? tree->left : tree->right;
            free(p);
        }
    }else
    {
        printf("error:未找到删除节点！\n");
        return NULL;
    }
    if (tree != NULL)
    {
        tree->height = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;
    }
    return tree;
}

Node* avltree_search(AVLTree tree, Type key)
{
    if(tree == NULL || tree->key == key)
        return tree;

    if(key < tree->key)
        return avltree_search(tree->left, key);
    else
        return avltree_search(tree->right, key);

}

void avltree_destroy(AVLTree tree)
{
    if(tree == NULL)
        return ;

    if(tree->left != NULL)
        avltree_destroy(tree->left);

    if(tree->right !=NULL)
        avltree_destroy(tree->right);

    free(tree);
}

//direction  --  0，表示该节点是根节点; -1，表示该节点是它的父结点的左孩子; 1，表示该节点是它的父结点的右孩子。
void avltree_print(AVLTree tree, Type key, int direction)
{
    if(tree != NULL)
    {
        if(direction == 0)
            printf("%2d 是根节点\n",tree->key, key);
        else
            printf("%2d 是 %2d 的 %2s 节点\n", tree->key, key, direction == -1 ? "左" : "右");

        avltree_print(tree->left, tree->key, -1);
        avltree_print(tree->right, tree->key, 1);
    }
}