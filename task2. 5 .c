#include <stdio.h>

int main() {
    char a[101], b[101];
    printf("请输入二进制编码a:");
    scanf("%s",a);
    printf("请输入二进制编码b:");
    scanf("%s",b);
    //计算a,b的位数
    int len_a = 0, len_b = 0;
    while (a[len_a]) len_a++;
    while (b[len_b]) len_b++;
    //如果a，b的位数不相同，那么 & 的运算结果肯定位0
    if(len_b != len_a){
        for(int i = 0;i < len_b;i++){
            printf("0");
        }
    }else {
        int count;
        for(count = 0;b[count] && a[count] == b[count];count++);

        for (int k = 0; k < len_b; k++){
        printf("%c", k < count ? b[k] : '0');
        }
    }

    return 0;
}
