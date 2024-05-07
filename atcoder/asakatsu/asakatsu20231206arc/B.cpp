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
    ll a,b,c;
    cin>>a>>b>>c;
    ll ma = 0;
    vector<ll>arr;
    ll now = a%10;
    arr.push_back(now);
    while(1){
        now *= a;
        now %= 10;
        ma++;
        if (find(all(arr), now)==arr.end()){
            arr.push_back(now);
        }else{
            break;
        }
    }
    ll pos = pow_mod(b,c,ma);
    if (pos==0) cout << arr.back() << endl;
    else cout << arr[(pos-1)%ma] << endl;
    return 0;
}