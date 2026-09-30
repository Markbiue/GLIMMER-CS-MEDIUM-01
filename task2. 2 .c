#include <stdio.h>

int main(){
    int x;
    int n;
    printf("请输入一个十进制数");
    scanf("%d",&x);
    printf("你要查询该数字的第几位：");
    scanf("%d",&n);

    

    if (x == 0) {
        printf("该数字的二进制为：0\n");
        return 0;
    }
    printf("该数字的二进制为：");

    int started = 0;

    for (int i = 31; i >= 0; i--) {
        //从第一个1开始输出
        if (x & (1 << i)) {
            started = 1; 
        }
        if (started) {
            printf("%d", (x & (1 << i)) ? 1 : 0);
        }
    }
    //防止出现超位
    if (n < 1 || n > 31) {
        printf("\n你输入的位数超出范围");
        return 1;
    }

    if(x & (1 << (n-1))){
        printf("\n该数字的第%d位为：1",n);
    }else {
        printf("\n该数字的第%d位为：0",n);
    }
    return 0;
}