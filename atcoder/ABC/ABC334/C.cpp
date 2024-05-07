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
    Cum(vector<ll>& arr){
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
    ll n,k;
    cin>>n>>k;
    vector<ll>a(k);
    rep(i,0,k)cin>>a[i];

    if (k%2){
        ll ans = INF;
        vector<ll> ev, od;
        if (k==1){
            cout << 0 << endl;
            return 0;
        }
        rep(i,0,k-1){
            if (i%2) continue;
            ev.push_back(a[i+1]-a[i]);
        }
        rep(i,1,k){
            if (i%2==0) continue;
            od.push_back(a[i+1]-a[i]);
        }        
        Cum<ll>cum_ev(ev), cum_od(od);
        rep(i,1,k+1){
            ll temp = 0;
            if (i%2){
                temp += cum_ev.get(0,i/2);
                temp += cum_od.get(i/2,k/2);
                chmin(ans,temp);
            }else{
                temp += cum_ev.get(0,(i-1)/2);
                temp += cum_od.get(i/2,k/2);
                temp += a[i] - a[i-2];
                chmin(ans,temp);
            }
        }
        cout << ans << endl;
    }else{
        ll ans = 0;
        rep(i,0,k){
            if (i%2)continue;
            ans += a[i+1] - a[i];
        }
        cout << ans << endl;
    }

    return 0;
}