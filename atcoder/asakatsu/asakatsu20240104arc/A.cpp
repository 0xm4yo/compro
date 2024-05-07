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
    ll a,b;
    cin>>a>>b;
    vector<ll>ans;
    if (a>b){
        ll now = 0;
        rep(i,0,a){
            now++;
            ans.push_back(now);
        }
        ll rem = 0;
        rep(i,0,a) rem += ans[i];
        now = 0;
        rep(i,0,b-1){
            now--;
            ans.push_back(now);
            rem += now;
        }
        ans.push_back(-rem);
    }else{
        ll now = 0;
        rep(i,0,b){
            now--;
            ans.push_back(now);
        }
        ll rem = 0;
        rep(i,0,b) rem += ans[i];
        now = 0;
        rep(i,0,a-1){
            now++;
            ans.push_back(now);
            rem += now;
        }
        ans.push_back(-rem);
    }
    
    for (auto aa: ans) cout << aa << endl;
    return 0;
}