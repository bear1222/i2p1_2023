#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NN 100005

typedef long long ll;
int max(int a, int b){ return a > b ? a : b;}
int min(int a, int b){ return a < b ? a : b;}

int n, m, k;
char pat[1005];
int patlen;
char name[NN], sen[NN];
char tmp;
char s[NN];
char s2[NN];
int mx = 0;

int f(char *s){
    int len = strlen(s), cnt = 0;
    for(int i = 0; i < len; i++){
        s2[i] = tolower(s[i]);
        if(s2[i] > 'z' || s2[i] < 'a') s2[i] = ' ';
    }s2[len] = '\0';
//    printf("%s\n", s2);
    char *tok = strtok(s2, " ");
    while(tok != NULL){
        if(strcmp(tok, pat) == 0) cnt++;
//        printf("tok: %s\n", tok);
        tok = strtok(NULL, " ");
    } 
//    printf("cnt: %d, len: %d\n", cnt, len);
    return cnt;
} 

signed main(){
    scanf("%d %s", &n, pat);   
    patlen = strlen(pat);
    for(int i = 0; i < patlen; i++) pat[i] = tolower(pat[i]);
    scanf("%c", &tmp);
//    printf("pat: %s\n", pat);
    for(int i = 0; i < n; i++){
        fgets(s, sizeof(s), stdin);
//        printf("str: %s\n", s);
        int len = strlen(s);
        char *se;
        for(int j = 0; j < len; j++){
            if(s[j] == ':'){
                s[j] = '\0';
                se = s + j + 1;
                break;
            } 
        } 
        int cnt = f(se);
        if(cnt > mx){
            mx = cnt;
            strcpy(name, s);
            strcpy(sen, se);
        } 
    } 
    printf("%s: %s", name, sen);
    return 0;
}

