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
    string x;
    cin>>x;
    ll n;
    cin>>n;
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    map<char,ll>mp;
    rep(i,0,26){
        mp[x[i]] = i;
    }

    auto cmp = [&](string a, string b){
        rep(i,0,min(a.size(), b.size())){
            ll ax = mp[a[i]];
            ll bx = mp[b[i]];
            if (ax==bx)continue;
            if (ax<bx) return true;
            else return false;
        }
        return a < b;
    };

    sort(all(s), cmp);
    for (auto ans: s){
        cout << ans << endl;
    }

    return 0;
}