#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;
int max(int a, int b){ return a > b ? a : b;}
int min(int a, int b){ return a < b ? a : b;}

int n, m, k;
int a[520][520], aa[520][520], b[10][10], c[520][520], d[520][520];

signed main(){
    int t; scanf("%d", &t);
    while(t--){
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        int r, p, s;
        scanf("%d%d%d%d%d%d", &n, &m, &k, &r, &p, &s);
        r %= 4;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) scanf("%d", &aa[i][j]);
        } 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++) scanf("%d", &b[i][j]);
        } 
    
        while(r--){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    a[i][j] = aa[n - j - 1][i];
                } 
            } 
            memcpy(aa, a, sizeof(a));
        } 
//        printf("rotate:\n");
//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < n; j++) printf("%2d ", a[i][j]);
//            printf("\n");
//        } 
        memset(a, 0, sizeof(a));
    
        for(int i = p; i < p + n; i++){
            for(int j = p; j < p + n; j++)
                a[i][j] = aa[i - p][j - p];
        } 
        n += p * 2;
//        printf("padding:\n");
//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < n; j++) printf("%2d ", a[i][j]);
//            printf("\n");
//        } 
    
        int x = 0, y;
        for(int i = 0; i + m <= n; i += s, x++){
            for(int j = 0, y = 0; j + m <= n; j += s, y++){
                for(int k1 = 0; k1 < m; k1++){
                    for(int k2 = 0; k2 < m; k2++){
                        c[x][y] += a[i + k1][j + k2] * b[k1][k2];
                    } 
                } 
            } 
        } 
//        printf("convolution:\n");
//        for(int i = 0; i < x; i++){
//            for(int j = 0; j < x; j++) printf("%2d ", c[i][j]);
//            printf("\n");
//        }printf("\n"); 
    
        int x1 = 0, y1;
        for(int i = 0; i < x; i += k, x1++){
            for(int j = 0, y1 = 0; j < x; j += k, y1++){
                d[x1][y1] = c[i][j];
                for(int k1 = 0; k1 < k && i + k1 < x; k1++){
                    for(int k2 = 0; k2 < k && j + k2 < x; k2++){
                        d[x1][y1] = max(d[x1][y1], c[i + k1][j + k2]);
                    } 
                } 
            } 
        } 
        for(int i = 0; i < x1; i++){
            for(int j = 0; j < x1; j++){
                printf("%d ", d[i][j]);
            } 
            printf("\n");
        } 
    }
    return 0;
}

