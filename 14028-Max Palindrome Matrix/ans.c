#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;
int max(int a, int b){ return a > b ? a : b;}
int min(int a, int b){ return a < b ? a : b;}

int n, m, k;
int a[505][505];

int check(int x1, int y1, int x2, int y2){
    int sum1 = x1 + x2, sum2 = y1 + y2;
    for(int i = x1; i <= x2; i++){
        for(int j = y1; j <= y2; j++){
            if(a[i][j] != a[sum1 - i][sum2 - j]) return 0;
        } 
    } 
    return 1;
} 

signed main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) scanf("%d", &a[i][j]);
        } 
        int ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k1 = i; k1 < n; k1++){
                    for(int k2 = j; k2 < m; k2++){
                        if(check(i, j, k1, k2)){
                            ans = max(ans, (k1 - i + 1) * (k2 - j + 1));
//                            printf("%d, %d  %d, %d\n", i, j, k1, k2);
                        }
                    } 
                } 
            } 
        } 
        printf("%d\n", ans);
    }   
    return 0;
}

