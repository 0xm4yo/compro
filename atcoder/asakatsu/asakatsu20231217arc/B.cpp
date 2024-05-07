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

using mint = modint998244353;

int main()
{
    ll x;
    cin>>x;
    queue<ll>q;
    mint ans = 1;
    map<ll,ll> mp;
    mp[x]++;
    auto now = mp.end();
    while(now!=mp.begin()){
        now--;
        auto [nx, cnt] = *now;
        if (nx<=4){
            ans *= pow_mod(nx,cnt,998244353);
            continue;
        }
        mp[nx/2] += cnt;
        mp[(nx+2-1)/2] += cnt;
    }
    cout << ans.val() << endl;
    return 0;
}