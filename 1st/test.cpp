#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int MAXN = 100000 + 5;

int n ,  rt , f[MAXN] , nd[MAXN] , dep[MAXN];

vector <int> G[MAXN];

void add(int u , int v) {G[u].push_back(v);}

void init() {
    memset(f, 0, sizeof(f)); // 将 f 数组初始化为 0
    memset(dep, 0, sizeof(dep)); // 将 dep 数组初始化为 0
    memset(nd, 0x3f, sizeof(nd)); // 将 nd 数组初始化为一个大值
}

int dfs(int u , int fa) {
	f[u] = fa;
	dep[u] = dep[fa] + 1;
	bool leafy = true;
	for(int i = 0 , v ; i < (int)G[u].size() ; ++i) {
		if((v = G[u][i]) == fa) continue;
		nd[u] = min(dfs(v , u) , nd[u]);
		leafy = false;
	}
	if(leafy) return nd[u] = dep[u];
	return nd[u];
}

int dfs2(int u) {
	if(2 * dep[u] > nd[u]) return 1;
	int res = 0;
	for(int i = 0 , v ; i < (int)G[u].size() ; ++i) {
		if((v = G[u][i]) == f[u]) continue;
		res += dfs2(v); 
	}
	return res;
}

int main() {
	memset(nd , 0x3f , sizeof nd);
	scanf("%d" , &n);
	for(int i = 1 , u , v ; i < n ; ++i) {
		scanf("%d %d" , &u , &v);
		add(u , v) , add(v , u);
	}
	for(rt = 1 ; rt <= n ; rt++)
    {
        dfs(rt , 0); 
	    printf("%d\n" , dfs2(rt));
        init();
    }
	return 0;
}