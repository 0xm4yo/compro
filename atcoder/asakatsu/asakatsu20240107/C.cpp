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
    ll n,p,q,r;
    cin>>n>>p>>q>>r;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    Cum<ll> cum(a);
    rep(x,0,n-2){
        ll ly = x;
        ll ry = n-2;
        while(ry-ly>1){
            ll mid = (ly+ry)/2;
            if (cum.get(x,mid)<p){
                ly = mid;
            }else{
                ry = mid;
            }
        }
        ll y = ry;
        if (cum.get(x,y)!=p) continue;
        ll lz = y;
        ll rz = n-1;
        while(rz-lz>1){
            ll mid = (lz+rz)/2;
            if (cum.get(y,mid)<q){
                lz = mid;
            }else{
                rz = mid;
            }
        }
        ll z = rz;
        if (cum.get(y,z)!=q) continue;
        ll lw = z;
        ll rw = n;
        while(rw-lw>1){
            ll mid = (lw+rw)/2;
            if (cum.get(z,mid)<r){
                lw = mid;
            }else{
                rw = mid;
            }
        }
        ll w = rw;
        if (cum.get(z,w)!=r) continue;
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;

    return 0;
}