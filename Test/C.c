// Calculate a + b
// In this problem, a and b may be presented as Octal, Decimal or Hexadecimal.

#include <stdio.h>
#include <string.h>
#define MAX 1000000

int main() {
    char a[MAX], b[MAX];

    scanf("%s", a);
    scanf("%s", b);

    int a_int, b_int;
    
    if (a[0] == '0' && (a[1] == 'x' || a[1] == 'X')) 
    {
        sscanf(a, "%x", &a_int);
    } else if (a[0] == '0') 
    {
        sscanf(a, "%o", &a_int);
    } else 
    {
        sscanf(a, "%d", &a_int);
    }

    if (b[0] == '0' && (b[1] == 'x' || b[1] == 'X'))
    {
        sscanf(b, "%x", &b_int);
    } else if(b[0] == '0')
    {
        sscanf(b, "%xo", &b_int);
    } else
    {
        sscanf(b, "%xd", &b_int);
    }

    printf("%d\n", a_int + b_int);

    return 0;
}