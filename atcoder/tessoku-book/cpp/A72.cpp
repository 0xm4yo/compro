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

int main()
{
    ll h,w,k;
    cin>>h>>w>>k;
    vector<string>s(h);
    rep(i,0,h)cin>>s[i];
    ll ans = 0;
    rep(bit,0,1<<h){
        ll pc = __builtin_popcount(bit);
        if (pc > k) continue;
        ll dif = k - pc;
        ll res = w - dif;
        vector<ll>cnt(w);
        rep(j,0,w){
            ll temp = 0;
            rep(i,0,h){
                if (bit&(1<<i)) continue;
                if (s[i][j] == '.') temp++;
            }
            cnt[j] = temp;
        }
        sort(all(cnt));
        ll temp = 0;
        rep(j,0,res){
            temp += cnt[j];            
        }
        chmax(ans, h*w-temp);
    }
    cout << ans << endl;
    return 0;
}