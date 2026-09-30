#include <stdio.h>
#include <stdbool.h>

// 定义简单队列结构用于 BFS
typedef struct {
    int pos;   // 当前节点编号 (0~15)
    int dist;  // 到达当前节点的最短步数
} Node;

int minStepsToCheese(int walls) {
    int start = 0;
    int target = 15;

    // 如果起点或终点本身是墙，直接不可达
    if ((walls & (1 << start)) || (walls & (1 << target))) {
        return -1;
    }

    // BFS 队列与访问位图
    Node queue[16];
    int front = 0, rear = 0;
    int visited = 0;

    // 起点入队并标记已访问 (请使用位运算)
    queue[rear++] = (Node){start, 0};
    visited |= (1 << start);

    // 上、下、左、右四个方向的节点偏移量
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    //请在TO DO 和END OF TO DO 行之间补全代码：
    //TO DO
    while(front < rear){
        Node p = queue[front++];

        if(p.pos == 15){
            return p.dist;
        }

        for(int i = 0;i < 4;i++){
        Node next_p;

        next_p.pos = p.pos + 4*dr[i] + dc[i];
        next_p.dist = p.dist + 1;

        if (next_p.pos < 0 || next_p.pos > 15) continue;
        
        if ((i == 0 && p.pos < 4) ||
            (i == 1 && p.pos > 11) ||
            (i == 2 && p.pos % 4 == 0) ||
            (i == 3 && p.pos % 4 == 3) || 
            (walls & (1 << next_p.pos)) ||
            (visited & (1 << next_p.pos)))
        {
            continue;
        }
        
        visited |= (1 << next_p.pos);
        queue[rear++] = (Node){next_p.pos,next_p.dist};
        }
    }

/*确定方向：
 上 left = 4*dr[0] + dc[0]; 
 下 right =  4*dr[1] + dc[1]; 
 左 down = 4*dr[2] + dc[2];
 右 up = 4*dr[3] + dc[3];
*/

//循环结束条件： 有最优解：pos == 15;无解：front >= rear
//走一步：

/*确定方向（pos += 方向）

判断格子编号是否在 0~15
判断能不能走（边界/墙/已经过）
pos < 4 :no up
pos > 11 : no down
pos % 4 == 0 : no left
pos % 4 == 3 :no right
（visited & (1 << pos)输出0就说明可以走）
*/

//更新状态：visited |= (1 << pos),dist++;

//传入新的数据结构

    //END OF TO DO

    return -1; // 无法到达
}

int main() {
    int walls = (1 << 5) | (1 << 10); // 5号和10号格子是墙
    int steps = minStepsToCheese(walls);
    printf("Minimum steps: %d\n", steps); // 应输出 6
    return 0;
}