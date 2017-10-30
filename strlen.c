#include<stdio.h>

void main()
{
    int i,sum;
    char ch[100];
    printf("请输入一个字符串：\n");
    gets(ch);
    for(i=0;i<100;i++)  
    {
        if(ch[i]=='\0')
        break;
    }
    sum=i+1;
    printf("该字符串的长度为：%d\n",sum);
}
