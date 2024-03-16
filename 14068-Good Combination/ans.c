#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;
int max(int a, int b){ return a > b ? a : b;}
int min(int a, int b){ return a < b ? a : b;}

int n, m, kk;
int a[25], tmp[10];
int ans[405][10], x;

void f(int k, int s){
    if(k == m){
        int same = 0;
        int sum = 0;
        for(int i = 0; i < m; i++) sum += tmp[i];
        if(sum != kk) return;
        for(int t = 0; t < x; t++){
            int che = 1;
            for(int i = 0; i < m; i++){
                if(tmp[i] != ans[t][i]) che = 0;
            } 
            if(che) same = 1;
        } 
        if(!same){
            for(int i = 0; i < m; i++) ans[x][i] = tmp[i];
            x++;
        }
        return;
    } 
    if(s == n) return;
    for(int i = s; i < n; i++){
        tmp[k] = a[i];
        f(k + 1, i + 1);
    } 
} 

signed main(){
    int t; scanf("%d", &t);
    while(t--){
        x = 0;
        scanf("%d%d%d", &n, &m, &kk);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        } 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[j - 1] > a[j]){
                    int tmp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = tmp;
                } 
            } 
        } 
//        for(int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
        f(0, 0);
        for(int i = 0; i < x; i++){
            for(int j = 0; j < m; j++){
                printf("%d ", ans[i][j]);
            } 
            printf("\n");
        } 
//        printf("\n");
    }
    return 0;
}

