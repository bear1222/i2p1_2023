#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back
#define All(a) a.begin(), a.end()
#define SZ(a) ((int)a.size())
#define endl '\n'
#define yn(ok) cout << (ok ? "Yes" : "No") << endl;
void db() {cout << '\n';}
template <typename T, typename ...U> void db(T a, U ...b) {
cout << a << ' ', db(b...);}

const ll mod = 1e9+7;
const ll inf = 1LL << 60;
const int NN = 2e5+5;

int n, m, k;

string pat, word[3], punc = ",.!?";

string createname(int len){
    string s = "";
    for(int i = 0; i < len; i++){
        int k = rand() % 53;
        char c = (k < 26 ? 'a' + k : k == 52 ? ' ' : 'A' + k - 26);
        s += c;
    } 
    return s;
} 
string createsentence(int len){
    string s = "";
    while(len){
        int k = rand() % 3, k2 = rand() % 4;
        int len2 = SZ(word[k]);
        if(len - len2 - 2 < 0) return s;
        for(int i = 0; i < len2; i++){
            s += (rand() & 1 ? toupper(word[k][i]) : word[k][i]);
        } 
        s += punc[k2];
        s += " ";
        len -= len2 + 2;
    } 
    return s;
} 

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int lenall;
    cin >> n >> pat;
    cin >> lenall;
    cout << n << ' ' << pat << endl;
    word[0] = pat;
    word[1] = "a" + pat;
    word[2] = pat + "a";
    for(int i = 0; i < n; i++){
        int k = rand() % min(lenall - 5, 100LL) + 1;
        string name = createname(k);
        string sentence = createsentence(lenall - k);
        cout << name << ":" << sentence << endl;
    } 
    return 0;
}

