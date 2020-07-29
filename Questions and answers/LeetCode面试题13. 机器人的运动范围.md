# LeetCode面试题13. 机器人的运动范围

每日一题 2020.04.08 难度 中等

## 题目

地上有一个m行n列的方格，从坐标 `[0,0]` 到坐标 `[m-1,n-1]` 。一个机器人从坐标 `[0, 0] `的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

 

**示例 1：**

```
输入：m = 2, n = 3, k = 1
输出：3
```

**示例 1：**

```
输入：m = 3, n = 1, k = 0
输出：1
```

**提示：**

- `1 <= n,m <= 100`
- `0 <= k <= 20`



## 题解

&emsp;&emsp;这里可以使用广度优先搜索（bfs）来搜索我们可以走到的所有的地方，对每一个可以走到的地方，并且符合当前位置的行、列的各位的和小于等于K的，加入到队列中，并且ans++。这里我们的ans初始值需要设置为1，因为我们一开始就在[0,0],是必定能够访问到的。然后我们就是创建一个结构体来记录row,col，创建队列`queue<ds>`来存储我们可以剩余可访问的结点，然后依次访问各个结点，并且查看上下左右四个方向能否访问，如果能访问，则加入队列，并且ans++。全部访问完之后，ans便是我们的答案。

```cpp
class Solution {
    typedef struct{
        int row;
        int col;
    }ds;
public:
    int movingCount(int m, int n, int k) {
        //默认为1，即(0,0)
        int ans = 1;
        //方向数组
        int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        bool visit[m][n];
        memset(visit,false,sizeof(visit));
        visit[0][0] = true;
        queue<ds> store;
        ds temp = {0,0};
        store.push(temp);
        while(store.size()){
            ds now = store.front();
            store.pop();
            for(int i = 0; i < 4; i++){
                    if((now.row + dir[i][0] >= 0) && (now.row + dir[i][0] < m) && (now.col + dir[i][1] >= 0) && (now.col + dir[i][1] < n) && (visit[now.row + dir[i][0]][now.col + dir[i][1]] == false)){
                    int sum_number,temp_x;
                    sum_number = 0;
                    // 计算行的位数和
                    temp_x = now.row + dir[i][0];
                    while(temp_x){
                        sum_number += temp_x % 10;
                        temp_x /= 10;
                    }
                    // 计算列的位数和
                    temp_x = now.col + dir[i][1];
                    while(temp_x){
                        sum_number += temp_x % 10;
                        temp_x /= 10;
                    }
                    if(sum_number <= k){
                        // 满足条件，小于等于k时，加入队列，ans++
                        ds temp = {now.row + dir[i][0],now.col + dir[i][1]};
                        store.push(temp);
                        visit[now.row + dir[i][0]][now.col + dir[i][1]] = true;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
```

执行效率为：


![截屏2020-04-08 下午7.38.56](/Users/qiguan/Desktop/截屏2020-04-08 下午7.38.56.png)

