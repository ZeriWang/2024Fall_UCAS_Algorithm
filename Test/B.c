// Tower of Hanoi
#include <stdio.h>

// 运算汉诺塔移动次数
int hanoi_count(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return 2 * hanoi_count(n - 1) + 1;
}

// 运算汉诺塔移动步骤
void hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if(n == 1)
    {
        printf("%c %c\n", from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("%c %c\n", from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    scanf("%d", &n);
    int move_count = 0;
    move_count = hanoi_count(n);
    printf("%d\n", move_count);
    hanoi(n, '1', '3', '2');
    return 0;
}