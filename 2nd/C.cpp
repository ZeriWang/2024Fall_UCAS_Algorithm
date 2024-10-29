#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    // freopen("test.txt","r",stdin); // 如果需要从文件读取输入，可以取消注释这行代码
    int m, n; // 定义变量 m 和 n，分别表示矩阵的行数和列数
    int food[51][51] = {0}; // 定义一个 51x51 的二维数组 food，并初始化为 0

    cin >> m >> n; // 读取矩阵的行数和列数
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> food[i][j]; // 读取每个位置的食物数量
        }
    }

    // 如果矩阵的行数和列数都大于等于 2
    if(m >= 2 && n >= 2){
        int dp[m + n - 1][n + 1][n + 1] = {0}; // 定义一个三维数组 dp，用于动态规划
        int rr = 0, rd = 0, dr = 0, dd = 0; // 定义四个变量，用于存储不同路径的食物数量

        // 遍历所有可能的路径
        for(int i = 1; i < m + n - 2; i++){
            for(int j = 1; j <= i && j < n; j++){
                for(int k = 0; k < j && k < n; k++){
                    rr = 0; rd = 0; dr = 0; dd = 0; // 重置路径变量
                    if(i - k >= m) continue; // 如果路径超出矩阵边界，跳过
                    if(i - j >= m - 1) continue; // 如果路径超出矩阵边界，跳过

                    // 计算 rr 路径的食物数量
                    if(k - 1 >= 0 && j - 1 >= 0){
                        rr = dp[i - 1][j - 1][k - 1] + food[i - j][j - 1] + food[i - k][k - 1];
                    }
                    // 计算 dr 路径的食物数量
                    if(j != i && k - 1 >= 0){
                        dr = dp[i - 1][j][k - 1] + food[i - k][k - 1] + food[i - j - 1][j];
                    }
                    // 计算 rd 路径的食物数量
                    if(j != k + 1){
                        rd = dp[i - 1][j - 1][k] + food[i - j][j - 1] + food[i - k - 1][k];
                    }
                    // 计算 dd 路径的食物数量
                    if(j != i){
                        dd = dp[i - 1][j][k] + food[i - j - 1][j] + food[i - k - 1][k];
                    }
                    // 选择最大路径的食物数量
                    dp[i][j][k] = max(max(rr, dr), max(rd, dd));
                }
            }
        }
        // 输出最终结果
        cout << dp[m + n - 3][n - 1][n - 2] + food[m - 2][n - 1] + food[m - 1][n - 2];
    }

    // 如果矩阵只有一行且列数大于 1
    if(m == 1 && n > 1){
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = ans + food[0][i]; // 累加每列的食物数量
        }
        cout << ans; // 输出结果
    }

    // 如果矩阵只有一列
    if(n == 1){
        int ans = 0;
        for(int j = 0; j < m; j++){
            ans = ans + food[j][0]; // 累加每行的食物数量
        }
        cout << ans; // 输出结果
    }

    return 0;
}