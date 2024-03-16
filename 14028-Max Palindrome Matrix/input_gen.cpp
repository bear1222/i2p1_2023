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

const ll mod = 1e9+7;
const ll inf = 1LL << 60;
const int NN = 2e5+5;

int n, m, k;
int a[105][105];

void solve(){
    int cnt = 2;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) a[i][j] = cnt++;
    
/*
    // 1D
    int s = rand() % m, e = rand() % m;
    if(e < s) swap(s, e);
    for(int i = s; i <= e; i++) a[0][i] = 1;
*/
    // square
    int len = rand() % (m - 1) + 1;
    int x1 = rand() % (m - len), y1 = rand() % (m - len);
    int x2 = x1 + len - 1, y2 = y1 + len - 1;
    cnt = 1;
    for(int i = x1; i <= (x1 + x2) / 2; i++){
        for(int j = y1; j <= y2; j++) a[i][j] = a[x1 + x2 - i][y1 + y2 - j] = cnt++;
    }
    // no
//    int x1 = rand() % n, x2 = rand() % n, y1 = rand() % m, y2 = rand() % m;
//    if(x2 < x1) swap(x1, x2); if(y2 < y1) swap(y1, y2);
//    cnt = 1;
////    cout << x1 << ',' << y1 << ' ' << x2 << ',' << y2 << endl;
//    for(int i = x1; i <= (x1 + x2) / 2; i++){
//        for(int j = y1; j <= y2; j++) a[i][j] = a[x1 + x2 - i][y1 + y2 - j] = cnt++;
//    }

    cout << n << ' ' << m << endl;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cout << a[i][j] << " \n"[j == m - 1];
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(0));
    cin >> n >> m;
    int t = 10;
    cout << t << endl;
    t--;
//    cin >> t;
    while(t--)
        solve();
    cout << n << ' ' << m << endl;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cout << 10 << " \n"[j == m - 1];
    return 0;
}

