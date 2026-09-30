#include <stdio.h>
#include <stdlib.h>

int is_safe(int row[],int r);//r表示当前行数
void solve(int row[],int N,int r,int *count);
void print(int row[],int N);

int main(){
    int N;
    printf("请给定N的值：");
    scanf("%d",&N);
    if(N > 0 && N <=15){
        int row[N];
        int x = 0;
        int count = 0;

        printf("可能的方案有：\n");
        solve(row,N,x,&count);

       printf("总共有%d种方案",count);
    }else {
        printf("错误！");
    }
return 0;
}

//检测插入的控制棒是否安全
int is_safe(int row[],int r){

    if (r == 0) return 1;

    //检查正上方的列
    for(int i = 0;i < r;i++){
       if ((row[r] & row[i]) != 0) {
            return 0;
        }
    
    //行距是r-i，只需要将row[i]左移或右移(r-i)位后做&就可以了
    //检查右上方斜线
    if(((row[i] << (r - i)) & row[r]) != 0){
        return 0;
        }

    //检查左上方斜线
    if(((row[i] >> (r - i)) & row[r]) != 0){
        return 0;
        }
    } 

    return 1;
}

//打印所有可行的方案
void print(int row[], int N){
    for(int i = 0; i < N; i++){
        for(int j = N - 1; j >= 0; j--){
            // 有控制棒的位置打印 1，没有的位置打印 0
            printf("%d ", (row[i] & (1 << j)) ? 1 : 0);
        }
        printf("\n");
    }
    printf("---------------\n");
}

//生成所有可行的方案
void solve(int row[],int N,int r,int *count){
    //递归出口
    if(r == N){
        (*count)++;
        print(row,N);
        return;
    }

    for (int index = 0;index < N;index++){
        row[r] = (1 << index);

        if(is_safe(row,r)){
            solve(row,N,r+1,count);
        }
    }
    return;
}