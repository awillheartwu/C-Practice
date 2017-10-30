#include<stdio.h>

// Ptree creatTree()//树的建立
// {
//     char ch;
//     Ptree t;
//     ch=getchar();//输入二叉树数据
//     ifch==(' ')//判断二叉树是否为空
//         t=NULL;
//     else
//     {
//         t=(Ptree)malloc(sizeof(Ptree));//二叉树的生成
//         t->data=ch;
//         t->lchild=creatTree();
//         t->rchlid=creatTree();
//     }
//     return t;
// }

void createBiTree(BiTree &T) {
    char c;
    scanf("%c",&c);
    if(‘#’ == c)
        T = NULL;
    else
    {
        T = new BiTreeNode;
        T->data = c;
        createBiTree(T->leftChild);
        createBiTree(T->rightChild);
    }   
}
