#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
template <class T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define smod(n, m) ((((n) % (m)) + (m)) % (m)) // 非負mod
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

inline int popcount(int n) { return __builtin_popcount(n); } // 2進数で表した場合に立ってるビット数がいくつか
inline int popcount(ll n) { return __builtin_popcountll(n); }
inline int ctz(int n) { return n != 0 ? __builtin_ctz(n) : -1; } // 2進数で表した場合に 1 の位からいくつ 0 が連なっているか
inline int ctz(ll n) { return n != 0 ? __builtin_ctzll(n) : -1; }
inline int clz(int n) { return n != 0 ? (31 - __builtin_clz(n)) : -1; } // 2進数で表した場合に左側にいくつ 0 を埋める必要があるか
inline int clz(ll n) { return n != 0 ? (63 - __builtin_clzll(n)) : -1; }

const double PI = 3.141592653589793;
const vector<int> DX = { 1, 0, -1, 0 };
const vector<int> DY = { 0, 1, 0, -1 };
const long long INF = 4004004003104004004LL; // (int)INF = 1010931620;
ll coordinate(ll h, ll w, ll W){ return h*W + w; } // 二次元座標を一次元座標に変換

// #define endl "\n" // インタラクティブの時はコメントアウトする

using mint = modint998244353;

// 2次元行列ライブラリ
template<typename T>
struct mat {
    vector<vector<T>> m;
    // コンストラクタ h: 行数、w: 列数、init: 初期値
    mat() : m(vector<vector<T>>()){}
    mat(int h, int w) : m(vector<vector<T>>(h, vector<T>(w))){}
    mat(int h, int w, T init) : m(vector<vector<T>>(h, vector<T>(w, init))){}
    
    // 添字演算子
    vector<T> operator[](const int i) const { return m[i]; }
    vector<T>& operator[](const int i) { return m[i]; }
    
    // 行数と列数
    int nrow = m.size();
    int ncol = m[0].size();

    // 行列・行列の演算
    mat& operator=(const mat& a){
        if (this != &a){ m = a.m; nrow = a.nrow; ncol = a.ncol; }
        return *this;
    }
    mat& operator+=(const mat& a){
        assert(ncol == a.ncol && nrow == a.nrow);
        rep(i, 0, nrow) rep(j, 0, ncol) m[i][j] += a.m[i][j];
        return *this;
    }
    mat& operator-=(const mat& a){
        assert(ncol == a.ncol && nrow == a.nrow);
        rep(i, 0, nrow) rep(j,0, ncol) m[i][j] -= a.m[i][j]; 
        return *this;
    } 
    mat& operator*=(const mat& a){
        assert(ncol == a.nrow);
        mat<T> m2(nrow, a.ncol, 0);
        rep(i, 0, nrow) rep(j, 0, a.ncol) rep(k, 0, ncol){
            m2.m[i][j] += m[i][k] * a.m[k][j];
        }
        ncol = a.ncol;
        rep(i, 0, nrow) m[i].resize(ncol);
        rep(i, 0, nrow) rep(j, 0, ncol) m[i][j] = m2.m[i][j]; 
        return *this;
    }
    mat operator+(const mat& a) const { return mat(*this) += a; }
    mat operator-(const mat& a) const { return mat(*this) -= a; }
    mat operator*(const mat& a) const { return mat(*this) *= a; }
    bool operator==(const mat& a) const {
        if (!(ncol == a.ncol && nrow == a.nrow)) return false;
        bool flag = true;
        rep(i, 0, nrow) rep(j, 0, ncol) if(m[i][j] != a.m[i][j]) flag = false;
        return flag;
    }

    // 行列・スカラの演算
    mat& operator+=(const T& a){ rep(i, 0, nrow)rep(j, 0, ncol) m[i][j] += a; return *this; }
    mat& operator-=(const T& a){ rep(i, 0, nrow)rep(j, 0, ncol) m[i][j] -= a; return *this; }
    mat& operator*=(const T& a){ rep(i, 0, nrow)rep(j, 0, ncol) m[i][j] *= a; return *this; }
    mat& operator/=(const T& a){ rep(i, 0, nrow)rep(j, 0, ncol) m[i][j] /= a; return *this; }
    mat operator+(const T& a) const { return mat(*this) += a; }
    mat operator-(const T& a) const { return mat(*this) -= a; }
    mat operator*(const T& a) const { return mat(*this) *= a; }
    mat operator/(const T& a) const { return mat(*this) /= a; }

    // 転置行列
    mat<T> transpose() const {
        mat<T> transposed(ncol, nrow, 0);
        rep(i, 0, nrow) rep(j, 0, ncol) transposed.m[j][i] = m[i][j];
        return transposed;
    }

    // 行列累乗 正方行列を初期化
    vector<mat<T>> v;
    int MAX_SIZE = 63;
    bool INITIALIZE_POW = false;
    void pow_init(){
        assert(nrow == ncol);
        INITIALIZE_POW = true;
        v.resize(MAX_SIZE, *this);
        rep(i, 1, MAX_SIZE) v[i] = v[i-1]*v[i-1];
    }

    // 行列累乗 正方行列のk乗を出力
    mat pow(long long k){
        assert(nrow == ncol);
        if (!INITIALIZE_POW) pow_init();
        mat<T> e(nrow, nrow, 0);
        rep(i, 0, nrow) e[i][i] = (T)1;
        mat<T> mk = e;
        rep(i, 0, MAX_SIZE) if (k & (1LL<<i)) mk *= v[i];
        return mk;
    }

    // 回転 degの数だけ時計回りに90度回転して値を更新
    // https://qiita.com/gnbrganchan/items/47118d45b3af9d5ae9a4
    mat& rot(int deg){
        deg = (deg%4 + 4) % 4;
        mat<T> m2(ncol, nrow);
        if(deg == 1 || deg == 3){
            if (deg == 1) rep(i, 0, nrow)rep(j, 0, ncol) m2.m[j][nrow-i-1] = m[i][j];
            if (deg == 3) rep(i, 0, nrow)rep(j, 0, ncol) m2.m[ncol-j-1][i] = m[i][j];
            swap(ncol, nrow); 
            m.resize(nrow);
            rep(i, 0, nrow) m[i].resize(ncol);
        }else if (deg == 2){
            rep(i, 0, nrow) rep(j, 0, ncol) m2.m[nrow-i-1][ncol-j-1] = m[i][j];
        }else{
            return *this;
        }
        rep(i, 0, nrow) rep(j, 0, ncol) m[i][j] = m2.m[i][j];
        return *this;
    }

    // 標準出力
    void show(){
        rep(i, 0, nrow) rep(j, 0, ncol){
            if (j != 0) cout << " ";
            cout << m[i][j];
            if (j == ncol-1) cout << endl;
        }
        return ;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    ll n,m;
    cin>>n>>m;
    vector<string> s(m);
    rep(i,0,m)cin>>s[i];
    
    auto f = [](string &a, string &b){
        // b が a に含まれるか
        if (b.size() > a.size()) return false;
        bool yes = false;
        rep(i,0,a.size()){
            if (i+b.size()>a.size()) break;
            if (a.substr(i,b.size())==b) yes = true;
        }
        if (yes) return true;
        else return false;
    };

    if (n<=12){
        mint ans = 0;
        rep(i,0,1LL<<n){
            string t = "";
            rep(j,0,n){
                if (i&(1LL<<j)) t += 'b';
                else t += 'a';
            }
            bool ng = false;
            rep(j,0,m){
                if (f(t,s[j])) ng = true;
            }
            if (!ng) ans += 1;
        }
        cout << ans.val() << endl;
       
        return 0;
    }

    vector<bool> ok(1LL<<6);
    vector<string> t(1LL<<6);
    rep(i,0,1LL<<6){
        rep(j,0,6){
            if (i&(1LL<<j)) t[i] += 'b';
            else t[i] += 'a';
        }
        bool ng = false;
        rep(j,0,m){
            if (f(t[i], s[j])) ng = true;
        }
        if (!ng) ok[i] = true;
    }

    mat<mint> mat(1LL<<6, 1LL<<6);
    rep(i,0,1LL<<6){
        if (!ok[i]) continue;
        rep(j,0,1LL<<6){
            if (!ok[j]) continue;
            string t2 = t[i]+t[j];
            bool ng = false;
            rep(k,0,m){
                if (f(t2, s[k])) ng = true;
            }
            if (!ng){
                mat.m[i][j] = 1;
            }
        }
    }

    mat.pow_init();
    ll x = n/6;
    auto arr = mat.pow(x-1);
    ll rem = n%6;
    vector<string> srem(1LL<<rem);
    rep(i,0,1LL<<rem){
        rep(j,0,rem){
            if (i&(1LL<<j)) srem[i] += 'b';
            else srem[i] += 'a';
        }
    }

    vector<mint> add(1LL<<6);
    rep(i,0,1LL<<6){
        if (!ok[i]) continue;
        rep(j,0,1LL<<rem){
            string t2 = t[i]+srem[j];
            bool ng = false;
            rep(k,0,m){
                if (f(t2, s[k])) ng = true;
            }
            if (!ng) add[i] += 1;
        }
    }


    mint ans = 0;
    rep(i,0,1LL<<6){
        if (!ok[i]) continue;
        rep(j,0,1LL<<6){
            if (!ok[j]) continue;
            ans += arr[i][j]*add[j];
        }
    }
    cout << ans.val() << endl;

    return 0;
}