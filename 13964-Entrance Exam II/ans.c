#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;
int max(int a, int b){ return a > b ? a : b;}
int min(int a, int b){ return a < b ? a : b;}

int n, m, k;

signed main(){
    int a, b, c, d;
    scanf("%d", &a);
    int aa = a;
    int z = a % 10;
    a /= 10;
    int y = a % 10;
    a /= 10;
    int x = a % 10;
    a /= 10;
    int w = a;
//    printf("%d, %d, %d, %d\n", w, x, y, z);
    b = x * 1000 + w * 100 + z * 10 + y;
    c = z * 1000 + w * 100 + x * 10 + y;
    d = z * 1000 + y * 100 + x * 10 + w;
//    printf("%d\n%d\n%d\n", b, c, d);
    printf("%.3f\n", (1.0 * aa + b) / (c + d));
    return 0;
}

