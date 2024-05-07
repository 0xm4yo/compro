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

template<typename T>
struct Cum2D{
    vector<vector<T>> cum;
    int h,w;
    // コンストラクタ
    Cum2D(vector<vector<T>>& arr){
        h = arr.size();
        w = arr[0].size();
        cum.resize(h+1, vector<T>(w+1, 0));
        // 累積和を計算
        for (int i=1; i<h+1; i++){
            for (int j=1; j<w+1; j++){
                cum[i][j] = arr[i-1][j-1] + cum[i][j-1] + cum[i-1][j] - cum[i-1][j-1];
            }
        }
    }
    // 0-indexed, 長方形領域 [h1,w1] から [h2,w2] までの和を取得
    T get(int h1, int w1, int h2, int w2){
        assert(h1<=h2 && w1<=w2);
        return cum[h2+1][w2+1] - cum[h2+1][w1] - cum[h1][w2+1] + cum[h1][w1];
    }
    // 0-indexed, グリッド無限連結時の範囲外にも対応、長方形領域 [h1,w1] から [h2,w2] までの和を取得
    T get_overRange(long long h1, long long w1, long long h2, long long w2){
        // 完全に包含している領域の数
        T res = cum.get(0,0,h-1,w-1);
        return res;
    }
};

int main()
{
    ll h,w;
    cin>>h>>w;
    vector<vector<ll>> x(h,vector<ll>(w));
    rep(i,0,h)rep(j,0,w)cin>>x[i][j];

    Cum2D<ll> cum(x);

    ll q;
    cin>>q;
    while (q){
        q--;
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;b--;c--;d--;
        cout << cum.get(a,b,c,d) << endl;
    }
    return 0;
}