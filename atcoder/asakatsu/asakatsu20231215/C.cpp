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
    ll t;
    cin>>t;
    vector<ll>pow3 = {1};
    rep(i,0,38) pow3.push_back(pow3.back()*3);

    while(t){
        t--;
        ll n,k;
        cin>>n>>k;
        ll cnt = 0;
        while(n){
            ll l = 0;
            ll r = 38;
            while(r-l>1){
                ll mid = (l+r)/2;
                if (n<pow3[mid]){
                    r = mid;
                }else{
                    l = mid;
                }
            }
            cnt++;
            n -= pow3[l];
        }
        ll rem = k - cnt;
        if (rem<0){
            cout << "No" << endl;
            continue;
        }
        if (rem%2) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}