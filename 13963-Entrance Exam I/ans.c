#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;
int max(int a, int b){ return a > b ? a : b;}
int min(int a, int b){ return a < b ? a : b;}

int n, m, k;

signed main(){
    scanf("%d", &k);
    n += k % 10;
    k /= 10;
    m += k % 10;
    k /= 10;
    n += k % 10;
    k /= 10;
    m += k % 10;
    printf("%.2f\n", 1.0 * m / n);
    return 0;
}

