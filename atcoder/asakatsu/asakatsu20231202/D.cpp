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
    ll H,W,n,h,w;
    cin>>H>>W>>n>>h>>w;
    vector<vector<ll>>a(H,vector<ll>(W));
    rep(i,0,H)rep(j,0,W)cin>>a[i][j];
    vector<ll>cnt(n+1);
    rep(i,0,H)rep(j,0,W)cnt[a[i][j]]++;
    ll st = 0;
    rep(i,1,n+1)if(cnt[i])st++;
    
    
    rep(i,0,H){
        if (i+h>H) break;
        ll tot = st;
        auto cnt2 = cnt;
        rep(j,0,W){    
            if (j+w>W) break;
            if (j==0){
                rep(k,0,h)rep(l,0,w){
                    cnt2[a[i+k][l]]--;
                    if (cnt2[a[i+k][l]]==0) tot--;
                }
                cout << tot << " ";
                continue;
            }
            rep(k,0,h){
                if (cnt2[a[i+k][j-1]]==0) tot++;
                cnt2[a[i+k][j-1]]++;
            }
            rep(k,0,h){
                cnt2[a[i+k][j+w-1]]--;  
                if (cnt2[a[i+k][j+w-1]]==0) tot--;    
            }
            cout << tot << " ";
        }
        cout << endl;
    }
    return 0;
}