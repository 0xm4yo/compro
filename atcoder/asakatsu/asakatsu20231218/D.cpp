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

vector<pair<char, long long>> runLengthEncoding(string s){
    long long n = s.length();
    vector<pair<char, long long>> res;
    long long l = 0;
    while (l < n){
        long long r = l + 1;
        while (r < n && s[l] == s[r]) r++;
        res.push_back(make_pair(s[l], r-l));
        l = r;
    }
    return res;
}

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    ll r0 = 0;
    ll r1 = 0;
    string s;
    rep(i,0,n) s += char('0' + a[i]);
    auto p = runLengthEncoding(s);
    for (auto [c,cnt]: p){
        if (c=='0'){
            chmax(r0,cnt);
        }else{
            chmax(r1,cnt);
        }
    }
    ll now = 0;
    rep(i,0,n)if(a[i]==1)now++;
    ll mx = now + r0;
    ll mi = now - r1;
    cout << mx - mi + 1 << endl;

    return 0;
}