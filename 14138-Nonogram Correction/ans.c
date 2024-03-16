#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;
int max(int a, int b){ return a > b ? a : b;}
int min(int a, int b){ return a < b ? a : b;}

int n, m, k;

int a[50][50], b[50][50], an[50], bn[50];
int aa[50][50], bb[50][50], aan[50], bbn[50];
char g[50][50];

int check(){
    int ok = 1;
    for(int i = 0; i < n; i++){
        int now = 0, x = 0;
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'x'){
                if(now == 0) continue;
                if(now != a[i][x]) ok = 0;
//                printf("%d ", now);
                now = 0, x++;
            }else
                now++;
        }
        if(now){
            if(now != a[i][x]) ok = 0;
//            printf("%d ", now);
            now = 0, x++;
        }
//        printf("\n");
        if(x != an[i]) ok = 0;
    }
    for(int i = 0; i < m; i++){
        int now = 0, x = 0;
        for(int j = 0; j < n; j++){
            if(g[j][i] == 'x'){
                if(now == 0) continue;
                if(now != b[i][x]) ok = 0;
//                printf("%d ", now);
                now = 0, x++;
            }else
                now++;
        }
        if(now){
            if(now != b[i][x]) ok = 0;
//            printf("%d ", now);
            now = 0, x++;
        }
//        printf("\n");
        if(x != bn[i]) ok = 0;
    }
    return ok;
} 

void print(){
    for(int i = 0; i < n; i++){
        printf("%s\n", g[i]);
    } 
} 

void cha(int r, int c){
    g[r][c] = (g[r][c] == 'x' ? 'o' : 'x');
} 

void solve(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &an[i]);
        for(int j = 0; j < an[i]; j++){
            scanf("%d", &a[i][j]);
        } 
    } 
    for(int i = 0; i < m; i++){
        scanf("%d", &bn[i]);
        for(int j = 0; j < bn[i]; j++){
            scanf("%d", &b[i][j]);
        } 
    } 
    for(int i = 0; i < n; i++){
        scanf(" %s", g[i]);
    } 
    int ok = check();
    if(ok){
        print();
        return;
    } 
    for(int i = 0; i < m * n; i++){
        int ri = i / m, ci = i % m;
        cha(ri, ci);
        if(check()){
            print();
            return;
        } 
        for(int j = i + 1; j < m * n; j++){
            int rj = j / m, cj = j % m;
            cha(rj, cj);
            if(check()){
                print();
                return;
            } 
            cha(rj, cj);
        } 
        cha(ri, ci);
    } 
    print("gg\n");
} 

signed main(){
    int t;
    scanf("%d", &t);   
    while(t--){
        solve();
    } 
    return 0;
}

