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
    ll n;
    cin>>n;
    vector<ll>t(n),x(n);
    rep(i,0,n)cin>>t[i]>>x[i];
    rep(i,0,n)x[i]--;
    
    vector<ll>p(n), bt(n);
    set<ll>arr;
    rrep(i,n-1,0){
        if (t[i]==1){
            if (p[x[i]]<0){
                bt[x[i]]--;
                p[x[i]]++;
                arr.insert(i);
            }
        }else{
            bt[x[i]]++;
            p[x[i]]--;
        }
    }
    rep(i,0,n){
        if (bt[x[i]] || p[x[i]]<0){
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 0;
    ll tot = 0;
    rep(i,0,n){
        if (t[i]==1){
            if (arr.find(i)==arr.end())continue;
            tot++;
            chmax(ans,tot);
        }else{
            tot--;
        }
    }
    cout << ans << endl;
    vector<ll>aa;
    rep(i,0,n){
        if (t[i]==2)continue;
        if (arr.find(i)==arr.end()) aa.push_back(0);
        else aa.push_back(1);
    }
    for (auto aaa: aa) cout << aaa << endl;
    return 0;
}