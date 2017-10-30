#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    char data;
    struct tree *lchild;
    struct tree *rchild;
}*Ptree;

Ptree createTree()//树的建立
{
    char ch;
    Ptree t;
    ch=getchar();//输入二叉树数据
    if(ch == NULL)//判断二叉树是否为空
        t=NULL;
    else
    {
        t=(Ptree)malloc(sizeof(Ptree));//二叉树的生成
        t->data=ch;
        t->lchild=createTree();
        t->rchild=createTree();
    }
    return t;
}

void preOrder(Ptree t)//先序遍历
{
    if(t)
    {
        printf("%c",t->data);
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}

void intOrder(Ptree t)//中序遍历
{
    if(t)
    {
        preOrder(t->lchild);
        printf("%c",t->data);
        preOrder(t->rchild);
    }
}

void postOrder(Ptree t)//后序遍历
{
    if(t)
    {
        preOrder(t->lchild);
        preOrder(t->rchild);
        printf("%c",t->data);
    }
}

void main()
{
    Ptree t;
    printf("先序建立二叉树，用空格表示虚节点:\n");
    t=createTree();
    printf("先序遍历");
    preOrder(t);
    printf("/n");
    printf("中序遍历");
    intOrder(t);
    printf("/n");
    printf("后序遍历");
    postOrder(t);
    printf("/n");
    system("pause");
}
