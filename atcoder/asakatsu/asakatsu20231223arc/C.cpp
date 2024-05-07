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
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll mi = n-1;
        ll mx = 0;
        rep(i,0,n){
            if (s[i]=='1'){
                chmin(mi,i);
                chmax(mx,i);
            }
        }

        vector<ll>arr(n);
        rep(i,0,n) if(s[i]=='0') arr[i]=1;
        Cum<ll> cum0(arr);
        ll cnt = 0;
        rep(i,0,n){
            if (i>mi) continue;
            if (i+k<=mx) continue;
            if (i+k>n) continue;
            if (cum0.get(i,i+k)) continue;
            cnt++;
        }
        YesNo(cnt==1);
    }
    return 0;
}