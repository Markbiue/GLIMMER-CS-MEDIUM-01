#include <stdio.h>

int hasCommonChar(const char *s1, const char *s2) {
    int mask1 = 0;
    int mask2 = 0;

    for(int i = 0;s1[i];i++){
        mask1 |= (1 << (s1[i] - 'a'));
        
    }
    for(int i = 0;s2[i];i++){
        mask2 |= (1 << (s2[i] - 'a'));
    }

    //当两个字符串没有公共字符时，返回0，否则返回1
    return (mask1 & mask2) != 0;
}

int main() {
    printf("%d\n", hasCommonChar("hello", "world"));
    printf("%d\n", hasCommonChar("abc", "xyz"));
    return 0;
}