#include<cstdio>
#include<cstring>
#include<algorithm>
   using namespace std;
   
   struct arr{
       int num;
       long long sum;
   } a[100000], b[100000];
  int T, n, sizea, sizeb;
  long long D, w[40];
  bool legal[40];
  bool cmp(arr a, arr b)
  {
      return a.sum < b.sum;
  }
  int main()
  {
      scanf("%d", &T);
      int cas = 0;
      while(T--)
      {
          scanf("%d %lld", &n, &D);
          for (int i = 0; i < n; i++) scanf("%lld", w+i);
          sizea = sizeb = 1;
          a[0].num = b[0].num = a[0].sum = b[0].sum = 0;
          for (int i = 0; i <= n/2; i++){
              int tmp = sizea;
              for (int j = 0; j < tmp; j++){
                  a[sizea].num = a[j].num + 1;
                  a[sizea++].sum = a[j].sum + w[i];
              }
          } 
         for (int i = n/2+1; i < n; i++){
              int tmp = sizeb;
              for (int j = 0; j < tmp; j++){
                  b[sizeb].num = b[j].num + 1;
                  b[sizeb++].sum = b[j].sum + w[i];
              }
          }
          sort(a, a+sizea, cmp);
          sort(b, b+sizeb, cmp);
          int count = 0, ans;
          memset(legal, 0, sizeof(legal));
         for (int i = 0; i < sizea; i++){
              if (a[i].sum > D || count > 1) break;
              if (a[i].sum == D){
                 int number = a[i].num;
                  if (!legal[number]){
                      legal[number] = true;
                      count ++;
                      ans = number;
                  }
              }
              if (a[i].sum <= D){
                  long long need = D - a[i].sum;
                  int l = 0, r = sizeb-1, pos = -1;
                  while (l <= r)
                  {
                      int mid = (l + r) >> 1;
                      if (b[mid].sum == need){
                          pos = mid;
                          break;
                      }
                      else if (b[mid].sum < need) l = mid + 1;
                      else r = mid - 1;
                  }
                  if (pos != -1){
                      int tmp = pos;
                      while(pos < sizeb && b[pos].sum == b[tmp].sum){
                          int number = a[i].num + b[pos].num;
                          if (!legal[number]){
                              legal[number] = true;
                             count ++;
                              ans = number;
                          }
                          pos ++;
                      }
                      pos = tmp-1;
                      while(pos >= 0 && b[pos].sum == b[tmp].sum){
                          int number = a[i].num + b[pos].num;
                          if (!legal[number]){
                              legal[number] = true;
                              count ++;
                              ans = number;
                          }
                          pos --;
                      }
  
                  }
              }
          }
          cas ++;
          printf("Case #%d: ", cas);
          if (count == 0) printf("IMPOSSIBLE\n");
          else if (count > 1) printf("AMBIGIOUS\n");
          else printf("%d\n", ans);
      }
      return 0;
 }