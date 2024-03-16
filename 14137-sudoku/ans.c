#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;
int max(int a, int b){ return a > b ? a : b;}
int min(int a, int b){ return a < b ? a : b;}

int n, m, k;

char sudoku[10][10]; // start from (0, 0)

int in(int r, int c){
    return r >= 0 && r < 9 && c >= 0 && c < 9;
} 
int can_put(int r, int c, int k){
    k += '0';
    if(!in(r, c)) return 0;
    int x = r / 3, y = c / 3;
//    printf("%d, %d %d, %d\n", r, c, x, y);
    for(int i = 0; i < 9; i++){
        if(sudoku[r][i] == k) return 0;
        if(sudoku[i][c] == k) return 0;
        if(sudoku[x * 3 + i / 3][y * 3 + i % 3] == k){
//            printf("wrong:%d, %d\n", x + i / 3, y + i % 3);
            return 0;
        }
    } 
    return 1;
} 

void print(){
    for(int i = 0; i < 9; i++){
        printf("%s\n", sudoku[i]);
    } 
    printf("\n");
} 

void f(int r, int c){
    if(r == 9){
        print();
        return;
    } 
    if(c == 9){
        f(r + 1, 0);
        return;
    } 
    if(sudoku[r][c] != '0'){
        f(r, c + 1);
        return;
    } 
//    print();
//    printf("%d, %d\n", r, c);
    for(int i = 1; i <= 9; i++){
        if(can_put(r, c, i)){
            sudoku[r][c] = '0' + i;
            f(r, c + 1);
            sudoku[r][c] = '0';
        } 
    } 
} 

void solve(){
    for(int i = 0; i < 9; i++){
        scanf(" %s", sudoku[i]);
    } 
    f(0, 0);
} 

signed main(){
    int t; scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}

