#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;
ll abss(ll a, ll b){ return a > b ? a - b : b - a;}
ll max(ll a, ll b){ return a > b ? a : b;}
ll min(ll a, ll b){ return a < b ? a : b;}

int n, m, k;
int a[25], gr[25];
long long ans;

void f(int k){
    if(k == n){
        long long sum1, sum2;
        sum1 = sum2 = 0;
        for(int i = 0; i < n; i++){
            if(gr[i]) sum1 += a[i];
            else sum2 += a[i];
        } 
        ans = min(ans, abss(sum1, sum2));
        return;
    } 
    gr[k] = 0;
    f(k + 1);
    gr[k] = 1;
    f(k + 1);
} 

signed main(){
    int t; scanf("%d", &t);
    while(t--){
        ans = 9999999999999;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        f(0);
        printf("%lld\n", ans);
    } 
    return 0;
}

