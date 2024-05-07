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
    string s;
    cin>>s;
    ll n = s.size();
    vector<vector<ll>>arr(10, vector<ll>(n));
    rep(i,0,n){
        arr[s[i]-'0'][i] = 1;
    }
    rep(i,0,10)rep(j,1,n){
        arr[i][j] ^= arr[i][j-1];
    }

    vector<ll> cnt(1LL<<10, 0);
    cnt[0] += 1;
    rep(j,0,n){
        int k = 0;
        rep(i,0,10){
            if (arr[i][j]){
                k += (1LL << i);
            }
        }
        cnt[k] += 1;
    }

    ll ans = 0;
    rep(k, 0, 1LL<<10){
        ans += cnt[k]*(cnt[k]-1)/2;
    }

    cout << ans << endl;

    return 0;
}