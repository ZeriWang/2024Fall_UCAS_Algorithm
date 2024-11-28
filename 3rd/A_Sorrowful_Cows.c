# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAXS 205

int occpuied_stall[MAXS];
int empty_stall[MAXS];

void quicksort1(int *a, int l, int r) {
    if (l >= r) return;
    int i = l, j = r, x = a[l + r >> 1];
    while (i <= j) {
        while (a[i] > x) i++;
        while (a[j] < x) j--;
        if (i <= j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    quicksort1(a, l, j);
    quicksort1(a, i, r);
}

void quicksort2(int *a, int l, int r) {
    if (l >= r) return;
    int i = l, j = r, x = a[l + r >> 1];
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    quicksort2(a, l, j);
    quicksort2(a, i, r);
}

int main()
{
    // 初始化全局数组
    for(int i = 0; i < MAXS; i++)
    {
        occpuied_stall[i] = 0;
        empty_stall[i] = 0;
    }

    int m, s, c;
    scanf("%d %d %d", &m, &s, &c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &occpuied_stall[i]);
    }

    // 特判：当木板数大于等于牛数时，所需木板总长度即为牛数
    if(m >= c)
    {
        printf("%d\n", c);
        return 0;
    }

    // 对牛所占木板位置排序
    quicksort2(occpuied_stall, 0, c - 1);

    // 所需木板最小总长度，初始条件假设只有一个木板 
    int ans = occpuied_stall[c - 1] - occpuied_stall[0] + 1;

    // 计算相邻牛之间的间隔
    for (int i = 1; i < c; i++) {
        empty_stall[i - 1] = occpuied_stall[i] - occpuied_stall[i - 1] - 1;
    }

    // 对间隔排序
    quicksort1(empty_stall, 0, c - 2);

    // 分割m-1次，每次从最大间隙中分割
    for (int i = 0; i < m - 1; i++) {
        ans = ans - empty_stall[i];
    }

    printf("%d\n", ans);
    return 0;
}