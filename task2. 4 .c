#include <stdio.h>

int main (){
    int x;
    printf("请输入一个有符号的十进制整数：");
    scanf("%d",&x);
    int y = x;//引入y来存储x的初始值
    int z = 0;//存储第一个1的位置
    x &= -x;
    
    for(int i = 0;i < 31;i++){
        if(x & (1 << i)){
            z = i+1;

        }
    }
    
    if(z){
            printf("该数字的第一个1在第%d位",z);
        }else {
            printf("二进制表示中没有1！");
        }
    
    printf("\n该十进制数的二进制表示为：");
    if(y == 0){
        printf("0");
    }else {
        int started = 0;

        for (int i = 31; i >= 0; i--) {
            if (y & (1 << i)) {
                started = 1; 
            }
            if (started) {
                printf("%d", (y & (1 << i)) ? 1 : 0);
            }
        }
    }
    return 0;
}