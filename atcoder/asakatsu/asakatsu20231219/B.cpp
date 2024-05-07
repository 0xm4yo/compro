#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e18+10;

int main()
{
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<ll>c(n);
    rep(i,0,n)cin>>c[i];
    vector<deque<char>> arr(m);
    rep(i,0,n){
        ll cl = c[i]-1;
        arr[cl].push_back(s[i]);
    }
    rep(i,0,m){
        char lt = arr[i].back();
        arr[i].pop_back();
        arr[i].push_front(lt);
    }
    string ans = "";
    rep(i,0,n){
        char ss = arr[c[i]-1].front();
        arr[c[i]-1].pop_front();
        ans += ss;
    }
    cout << ans << endl;
    return 0;
}