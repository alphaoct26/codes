#include <stdio.h>
int main(void)
{
    int a, b, n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &a, &b);
        printf("%s\n", (a % 2 != 0 && a == b - 1 || a == b - 2 || a == b + 2 || a % 2 == 0 && a == b + 1) ? "YES" : "NO");
    }
    return 0;
}