#include<bits/stdc++.h> // 包含所有标准库头文件

using namespace std;

const int N = 2e5 + 5; // 定义常量 N，表示字符数组的大小
int t, n; // 定义整型变量 t 和 n，分别表示测试用例数量和字符串长度
char s[2][N]; // 定义二维字符数组 s，用于存储两个字符串

int main() // 主函数
{
    scanf("%d", &t); // 读取测试用例数量 t
    while (t--) // 循环处理每个测试用例
    {
        scanf("%d%s%s", &n, s[0] + 1, s[1] + 1); // 读取字符串长度 n 和两个字符串 s[0] 和 s[1]
        bool flag = 0; // 定义布尔变量 flag，初始值为 0（即 false）
        
        // 循环遍历字符串，步长为 2，从索引 2 开始
        for (int i = 2; i <= n; i += 2)
        {
            // 检查 s[0][i] 是否为 '<'，并且 s[1][i-1] 或 s[1][i+1] 是否为 '<'
            if (s[0][i] == '<' && (s[1][i - 1] == '<' || (i + 1 < n && s[1][i + 1] == '<')))
            {
                flag = 1; // 如果条件满足，将 flag 置为 1（即 true）
                break; // 跳出循环
            }
        }
        
        // 根据 flag 的值输出结果
        flag ? puts("No") : puts("Yes"); // 如果 flag 为 1，输出 "No"；否则输出 "Yes"
    }
}