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

const ll mod = 1e6 + 1;
const ll inf = 1LL << 60;
const int NN = 2e5+5;

int n, m, k;

void solve(){
    db(n);
    vector<int> a(n);
    for(int &i : a) i = rand() % mod;
    for(int &i : a) cout << i << ' '; cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(0));
    cin >> n;
    int t = 10;
    db(t);
//    cin >> t;
    while(t--)
        solve();
    return 0;
}

