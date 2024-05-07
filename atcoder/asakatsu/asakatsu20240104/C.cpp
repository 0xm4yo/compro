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
    vector<ll>p(n);
    rep(i,0,n)cin>>p[i];
    ll mx = -1;
    ll idx = -1;
    Cum<ll>cum(p);
    rep(i,0,n){
        if (i+k>n)break;
        if (mx<cum.get(i,i+k)){
            mx = cum.get(i, i+k);
            idx = i;
        }
    }
    double ans = 0.0;
    rep(i,idx,idx+k){
        ans += ((double)p[i]*(double)(1+p[i])/2.0) * (1.0/(double)p[i]);
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}