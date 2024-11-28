#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long int n, ans, cards[100005];


void init()
{
    memset(cards, 0, sizeof(cards));
    ans = 0;
}

int main()
{
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &cards[i]);
    }
    ans = cards[0];
    for(int i = 0; i < n - 1; i++)
    {
        if(cards[i] < cards[i + 1])
        {
            ans += cards[i + 1] - cards[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}