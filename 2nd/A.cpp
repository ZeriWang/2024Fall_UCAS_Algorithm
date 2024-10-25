#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
int a[N] , c[N];
int f[N][4];

int main()
{
    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i ++ ) cin >> a[i];
    for(int i = 1 ; i <= n ; i ++ ) cin >> c[i];

    memset(f , 0x3f , sizeof f);
    for(int i = 1 ; i <= n ; i ++ )
    {

        for(int k = 2 ; k <= 3 ; k ++ )
        {
            f[i][1] = c[i];
            for(int j = 1 ; j < i ; j ++ )
                if(a[i] > a[j]) f[i][k] = min(f[i][k] , f[j][k - 1] + c[i]);
        }
    }

    int res = 0x3f3f3f3f;
    for(int i = 1 ; i <= n ; i ++ ) res = min(res , f[i][3]);
    if(res != 0x3f3f3f3f) cout << res << endl;
    else cout << "-1" << endl;

    return 0;

}