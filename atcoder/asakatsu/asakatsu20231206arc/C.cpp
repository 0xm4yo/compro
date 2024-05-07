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

template<typename T>
struct Cum{
    vector<T> cum;
    // コンストラクタ
    Cum() {}
    Cum(vector<T>& arr){
        int n = arr.size();
        cum.resize(n+1,0);
        // 累積和を計算
        for (int i=0; i<n; i++){
            cum[i+1] = cum[i] + arr[i];
        }
    }
    // 0-indexed, 区間 [l,r) の和を取得
    T get(int l, int r){
        assert(l<=r);
        return cum[r] - cum[l];
    }
};

int main()
{
    string s;
    cin>>s;
    vector<Cum<ll>> arr(26);
    ll n = s.size();
    rep(i,0,26){
        vector<ll> bit(n);
        ll ss = 'a' + i;
        rep(j,0,n) if (s[j]==ss) bit[j]=1;
        Cum<ll> sm(bit);
        arr[i] = sm;
    }

    char pre = 'A';
    ll pidx = n;
    ll ans = 0;
    rrep(i,n-2,1){
        if (s[i]==s[i+1]){
            pidx = i;
            pre = s[i];
            continue;
        }
        if (s[i]==s[i-1]){
            if (s[i]==pre){
                ans += pidx - (i+1);
                ans -= arr[s[i]-'a'].get(i+1, pidx);
            }else{
                ans += n-(i+1);
                ans -= arr[s[i]-'a'].get(i+1, pidx);
                pre = s[i];
            }
        }
    }
    cout << ans << endl;

    return 0;
}