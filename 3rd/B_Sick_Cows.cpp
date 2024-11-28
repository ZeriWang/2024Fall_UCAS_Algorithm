#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long int ll;
using pll = pair<int, ll>;
const int maxn = 4e5 + 10;
const ll mod = 998244353LL;
const ll inf = 1145141919810LL;
int n, a[maxn], p = 0; char s[maxn];
int main() {
	scanf("%d%s", &n, s + 1); s[++n] = '0'; int num = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') ++num;
		else if (num) {
			a[++p] = num; num = 0;
		}
	}
	int day = maxn; day = min(day, a[1] - 1);
	if (s[1] == '0') day = min(day, (a[1] - 1) / 2);
	for (int i = 2; i < p; i++) {
		day = min(day, (a[i] - 1) / 2);
	}
	day = min(day, a[p] - 1);
	if (s[n - 1] == '0') day = min(day, (a[p] - 1) / 2); int sum = 0;
	for (int i = 1; i <= p; i++) sum += ceil((double)a[i] / (day * 2 + 1));
	printf("%d\n", sum);
	return 0;
}