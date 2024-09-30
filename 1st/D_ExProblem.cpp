#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define MAXN 70005 
#define int long long
using namespace std;

vector<int>G[MAXN]; // 邻接表表示的图
int n, sum, root, tree_size[MAXN], son[MAXN]; // 全局变量
bool used[MAXN]; // 标记节点是否已被访问

// 获取树的重心节点
void getroot(int u, int fa) {
    tree_size[u] = 1; son[u] = 0;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == fa || used[v]) continue;
        getroot(v, u);
        tree_size[u] += tree_size[v];
        son[u] = max(son[u], tree_size[v]);
    }
    son[u] = max(son[u], sum - tree_size[u]);
    if (son[u] < son[root]) root = u;
}

int g[MAXN], dep[MAXN], du[MAXN]; // 全局变量

// 第一次深度优先搜索，计算每个节点到最近叶子节点的距离
void dfs1(int u, int father, int depth) {
    dep[u] = depth;
    g[u] = 2147483647;
    if (du[u] == 1) g[u] = 0;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == father) continue;
        dfs1(v, u, depth + 1);
        g[u] = min(g[u], g[v] + 1);
    }
}

// 第二次深度优先搜索，更新每个节点到最近叶子节点的距离
void dfs2(int u, int father) {
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == father) continue;
        g[v] = min(g[v], g[u] + 1);
        dfs2(v, u);
    }
}

int d[MAXN]; // 全局变量

// 计算每个节点到根节点的距离
void getdistance(int u, int father, int cur) {
    d[u] = cur;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == father || used[v]) continue;
        getdistance(v, u, cur + 1);
    }
}

struct node {
    int dg, deg;
    bool operator<(const node a) const {
        return dg < a.dg;
    }
} q[MAXN]; // 节点结构体

struct bond {
    int id, dis;
    bool operator<(const bond a) const {
        return dis < a.dis;
    }
} p[MAXN]; // 边结构体

int ans[MAXN]; // 结果数组

int tot = 0; // 全局变量

// 将节点信息添加到数组中
void addin(int u, int father) {
    p[++tot] = (bond){u, d[u]};
    q[tot] = (node){g[u] - d[u], 2 - du[u]};
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == father || used[v]) continue;
        addin(v, u);
    }
}

// 计算每个节点的答案
void calc(int u, int father, int type) {
    tot = 0;
    addin(u, father);
    sort(p + 1, p + tot + 1);
    sort(q + 1, q + tot + 1);
    int Sum = 0, cursor = 0;
    for (int i = 1; i <= tot; i++) {
        while (cursor < tot && p[i].dis >= q[cursor + 1].dg) {
            cursor++;
            Sum += q[cursor].deg;
        }
        ans[p[i].id] += type * Sum;
    }
}

// 递归解决问题
void solve(int u) {
    used[u] = 1;
    getdistance(u, 0, 0);
    calc(u, 0, 1);
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (used[v]) continue;
        calc(v, u, -1);
        sum = tree_size[v];
        root = 0;
        getroot(v, u);
        solve(root);
    }
}

signed main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        du[x]++; du[y]++;
    }
    dfs1(1, 0, 1); dfs2(1, 0);
    root = 0; sum = son[0] = n; getroot(1, 0);
    solve(root);
    for (int i = 1; i <= n; i++)
        if (du[i] == 1) ans[i] = 1;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}