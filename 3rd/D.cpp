#include<bits/stdc++.h> 
using namespace std;
int const MAX = 1e4 + 5;
struct Stop
{
    int dis,fuel;
}s[MAX];
bool cmp(Stop a, Stop b)
{
    return a.dis<b.dis;
}
int m;
int main()
{
    cin>>m;
    for(int k=1;k<=m;k++)
    {
    memset(s,0,sizeof(s));
    bool f=true;
    int n, l, p;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&s[i].dis,&s[i].fuel);
    scanf("%d%d",&l,&p);
    for(int i=0;i<n;i++)
        s[i].dis=l-s[i].dis; 
    s[n].fuel=0;//将城镇当做一个加油站
    s[n].dis=l;
    n++; 
    sort(s,s+n,cmp);
    priority_queue <int> q;
    int ans = 0, pos = 0, num = p;//num车剩下的汽油，pos上一个加油站距起点的距离 
    for(int i = 0; i < n; i++)
    {
        int d=s[i].dis-pos;//从上一个加油站到这个加油站的距离 
        while(num < d)
        {
            if(q.empty())
            {
                printf("-1\n");
                f=false;
                break;
            }
            ans++;     //加油
            num+=q.top();
            q.pop();
        }
        if(f==false) break;
        num-=d;   
        q.push(s[i].fuel);
        pos=s[i].dis;
    }
     if(f==true)  printf("%d\n",ans);
   }
}