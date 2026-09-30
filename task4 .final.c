#include <stdio.h>

int N;

int solve(int col,int left,int right);

int main(){
    printf("请给定N的值：");
    scanf("%d",&N);

    if (N < 1 || N > 15){
        printf("错误！");
        return 0;
    }
    int col = 0;
    int left = 0;
    int right = 0;
    printf("共有%d种方案",solve(col,left,right));

    return 0;
}

int solve(int col,int left,int right){
    if(N < 1){
        return 0;
    }
    int limit = (1 << N) - 1;
    if(col == limit){
        return 1;
    }

    int chance = limit & (~(col | left | right));
    int place = 0;
    int count = 0;

    while(chance != 0){
        place = (chance & (-chance));
        chance ^= place;
        count += solve((col | place),(left | place) >> 1,(right | place) << 1);
    }

    return count;
}