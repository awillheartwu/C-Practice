#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int binarysearch(int arr[],int len,int key);
int binarysearch2(int array[],int key,int low,int high);

    
int main(int argc, char * argv[])
{
    int array[] = {3,5,6,7,11,22,44,47 };
    int i;
    printf("请参照下列数组，输入你要查找的目标：\n {");
    int len = sizeof(array)/sizeof(int);
    
    for (i = 0; i < len; i++) {

        printf("%d,",array[i]);
        
    }
    printf("}:\n");
    int dest;
    scanf("%d",&dest);
    int res = binarysearch(array,len,dest);
    printf("1. res = %d\n",res);

    int res2 = binarysearch2(array,dest,0,len - 1);
    printf("2. res = %d\n",res2);

    
}
/**************************************************************************
函数名称：用循环实现二分法查找过程,
功能描述：
输入参数：
返   回：返回目标值在数组中的下标
**************************************************************************/


int binarysearch(int arr[],int len,int key)
{

    int high,low;
    high = len - 1;//假设数组是从小到大排列的
    low = 0;
    int midle = len/2;
    
    while(high >= low)
        {
            midle = (high + low)/2;
            
           if(arr[midle] == key)
               return midle;
           if(arr[midle] > key)
               high = midle - 1;         //前提是假设数组是从小到大排序，否则不确定是该加1还是减1
           else if(arr[midle] < key )
               low = midle + 1;
        }
    return (-1);
    
}
/**************************************************************************
函数名称：用递归实现二分法查找
功能描述：
输入参数：
返   回：
**************************************************************************/
int binarysearch2(int array[],int key,int low,int high)
{

    if (low >= high)
        return (-1);

    int midle = (low + high)/2;
    if(array[midle] == key)
        return midle;
    if(midle == high || midle == low) //此时，只剩下了下标为high和low的两个数，确定另一个数不是key后，就确定查找完毕，并且未找到目标值
        {
            if(array[high] == key)
                return high;
            else if(array[low] == key)
                return low;
            else
                return (-1);            
        }

    else if(array[midle] > key)
        return binarysearch2(array,key,low,midle);  //由于不确定排序方向，所以此处只能用midle值，而不能加1或减1
    else if(array[midle] < key)                    //当中间值小于目标值时，在high的一侧继续查找，low变到midle位置上
        return binarysearch2(array,key,midle,high);
}

