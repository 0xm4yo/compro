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
const ll INF = (ll)1e15;

using mint = modint1000000007;

int main()
{
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<mint> cum(n+1,0);
    ll x = 97;
    vector<mint>mpow(n+1,1);
    rep(i,1,n+1){
        mpow[i] = mpow[i-1]*x;
    }
    rep(i,0,n){
        cum[i+1] = cum[i] + (s[i]-'a'+1)*mpow[i];
    }
    while(q){
        q--;
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;b--;c--;d--;
        ll dif = c-a;
        mint ab = cum[b+1]-cum[a];
        mint cd = cum[d+1]-cum[c];
        if(dif<0){
            cd *= mpow[-dif];
        }else{
            ab *= mpow[dif];
        }
        YesNo(ab==cd);
    }

    return 0;
}