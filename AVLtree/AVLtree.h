#ifndef _AVL_TREE_H
#define _AVL_TREE_H

typedef int Type;

//节点定义
typedef struct AVLTreeNode{
    Type   key;    //节点排序
    int    height;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
}Node, *AVLTree;

void avltree_preorder(AVLTree tree); //前序遍历
void avltree_inorder(AVLTree tree); //中序遍历
void avltree_postorder(AVLTree tree); //后序遍历

Node* left_left_rotation(AVLTree tree);
Node* right_right_rotation(AVLTree tree);
Node* left_right_rotation(AVLTree tree);
Node* right_left_rotation(AVLTree tree);

int   avltree_height(AVLTree tree); // 获取AVL树的高度
Node* avltree_maximum(AVLTree tree); // 查找最大结点：返回tree为根结点的AVL树的最大结点。
Node* avltree_minimum(AVLTree tree); // 查找最小结点：返回tree为根结点的AVL树的最小结点。

Node* avltree_create(Type key, Node *left, Node* right);
Node* avltree_insert(AVLTree tree, Type key); // 将结点插入到AVL树中，返回根节点
Node* avltree_delete(AVLTree tree, Type key);
Node* avltree_search(AVLTree tree, Type key); // (递归实现)查找"AVL树tree"中键值为key的节点
void  avltree_destroy(AVLTree tree); // 销毁AVL树

void avltree_print(AVLTree tree, Type key, int direction);

#endif