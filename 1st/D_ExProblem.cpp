#include <bits/stdc++.h> // 包含所有标准库头文件
using namespace std;

int n, k, a, b, l, st[100001], top, fa[100001], dep[100001], ans;
bool leaf[100001], flag[100001];
vector<int> tree[100001]; // 定义树的邻接表

// 初始化函数
void init()
{
    ans = 0; // 重置答案
    top = 0; // 重置栈顶指针
    fill(st, st + n + 1, 0); // 重置栈
    fill(leaf, leaf + n + 1, 0); // 重置叶子节点标志
    fill(flag, flag + n + 1, 0); // 重置标志
}

// 深度优先搜索1
void dfs1 (int i, int fr)
{
    st[++top] = i; // 将当前节点压入栈中
    if (tree[i].size() == 1 && i != 1) // 如果当前节点是叶子节点且不是根节点
    {
        flag[st[top / 2 + 1]] = 1; // 标记栈中间的节点
        top--; // 弹出当前节点
        return;
    }
    for (int k = 0; k < tree[i].size(); k++) // 遍历当前节点的所有子节点
    {
        int now = tree[i][k];
        if (now != fr) // 如果子节点不是父节点
            dfs1 (now, i); // 递归调用dfs1
    }
    top--; // 弹出当前节点
}

// 深度优先搜索2
void dfs2 (int i, int fr)
{
    if (flag[i]) // 如果当前节点被标记
    {
        ans++; // 增加答案计数
        return;
    }
    for (int k = 0; k < tree[i].size(); k++) // 遍历当前节点的所有子节点
    {
        int now = tree[i][k];
        if (now != fr) // 如果子节点不是父节点
            dfs2 (now, i); // 递归调用dfs2
    }
}

int main()
{
    cin >> n; // 输入节点数

    for (int i = 1; i < n; i++) // 输入树的边
    {
        cin >> a >> b;
        tree[a].push_back (b); // 添加边 a-b
        tree[b].push_back (a); // 添加边 b-a
    }

    for(int k = 1; k <= n; k++) // 遍历每个节点
    {
        fa[k] = 0; // 重置父节点数组
        
        dfs1 (k, 0); // 从节点 k 开始进行第一次深度优先搜索
        dfs2 (k, 0); // 从节点 k 开始进行第二次深度优先搜索
        cout << ans << "\n"; // 输出答案

        init(); // 初始化
    }
    
    return 0;
}