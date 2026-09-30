#include <stdio.h>

void print(int x);

int main(){
    int x;
    int n;
    int t;
    printf("请输入一个十进制数");
    scanf("%d",&x);
    printf("你要更改该数字的第几位：");
    scanf("%d",&n);
    printf("你要更改的数字为（0或1）：");
    scanf("%d",&t);

    printf("该数字原本的二进制为：");
    if(x == 0){
        printf("0");
    }else {
        print(x);
    }
    
    //防止出现超位
    if (n < 1 || n > 31) {
        printf("\n你输入的位数超出范围");
        return 1;
    }
    //对x进行更改
    if(t == 1){
        x |= (1 << (n-1));
    }else {
        x &= ~(1 << (n-1));
    }

    printf("\n更改后，该数字的二进制为：");
    print(x);
    
    return 0;
}

void print(int x){
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
    return;
}