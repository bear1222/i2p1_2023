#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;
int max(int a, int b){ return a > b ? a : b;}
int min(int a, int b){ return a < b ? a : b;}

int n, m, k, t;
int a[505][505], b[505][505], aa[505][505];

signed main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &aa[i][j]);
            } 
        } 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &b[i][j]);
            } 
        } 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = aa[i][n - j - 1];
            } 
        } 
        int ans = 0;
        for(int i = 0; i < n - m + 1; i++){
            for(int j = 0; j < n - m + 1; j++){
                int sum = 0;
                for(int x = 0; x < m; x++){
                    for(int y = 0; y < m; y++){
                        sum += a[i + x][j + y] * b[x][y];
                    } 
                } 
                if(sum > k) ans++;
            } 
        } 
        printf("%d\n", ans);
    }
    return 0;
}

