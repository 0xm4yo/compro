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
    ll n,q;
    cin>>n>>q;
    vector<pair<ll,ll>> arr = {{0,0}};
    while(q--){
        ll a;
        cin>>a;
        if (a==1){
            char c;
            cin>>c;
            auto [dx,dy] = arr.back();
            if (c=='R'){
                dx++;
            }else if(c=='L'){
                dx--;
            }else if(c=='U'){
                dy++;
            }else{
                dy--;
            }
            arr.push_back({dx,dy});
        }else{
            ll cnt = arr.size();
            ll p;
            cin>>p;
            p--;
            ll pos = cnt-1;
            pos -= p;
            if (pos<0) cout << p+1-(cnt-1) << " " << 0 << endl;
            else cout << 1 + arr[pos].first << " " << arr[pos].second << endl;
        }
    }
    return 0;
}