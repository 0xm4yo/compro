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
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n,a,b;
    cin>>n>>a>>b;
    ll p,q,r,s;
    cin>>p>>q>>r>>s;
    
    ll mink1 = max(1-a,1-b);
    ll maxk1 = min(n-a,n-b);
    ll mink2 = max(1-a,b-n);
    ll maxk2 = min(n-a,b-1);

    vector<string> ans(q-p+1, "");
    rep(i,p,q+1)rep(j,r,s+1){
        if (b-a==j-i){
            if (a+mink1<=i && i<= a+maxk1 && b+mink1<=j && j<=b+maxk1){
                ans[i-p]+="#";
            }else{
                ans[i-p]+=".";
            }
            continue;
        }
        if (b+a==j+i){
            if (a+mink2<=i && i<=a+maxk2 && b-maxk2<=j && j<=b-mink2){
                ans[i-p]+="#";
            }else{
                ans[i-p]+=".";
            }
            continue;
        }
        ans[i-p] += ".";
    }
    rep(i,0,q-p+1){
        cout << ans[i] << endl;
    }
    
    return 0;
}