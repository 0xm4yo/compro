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

#define endl "\n" // インタラクティブの時はコメントアウトする

// 任意の半環に対応した行列累乗ライブラリ
// 1. (R, +) は単位元 0 を持つ可換モノイドを成す:
//      1. (a + b) + c = a + (b + c),
//      2. 0 + a = a + 0 = a,
//      3. a + b = b + a.
// 2. (R, ·) は単位元 1 を持つモノイドを成す:
//      1. (a · b)· c = a ·(b · c),
//      2. 1 · a = a · 1 = a.
// 3. 乗法は加法の上に分配的である:
//      1. a ·(b + c) = (a · b) + (a · c),
//      2. (a + b)· c = (a · c) + (b · c).
// 4. 0-倍は R を零化する:
//      1. 0 · a = a · 0 = 0.
template<typename T, T (*add)(T, T), T (*zero)(), T (*mul)(T, T), T (*one)()>
class Matrix {
private:
    vector<vector<T>> data; // 行列データ
    int rows, cols; // 行数と列数

public:
    // コンストラクタ
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, vector<T>(cols, zero()));
    }

    // 添字演算子
    vector<T>& operator[](int index) { return data[index]; }

    // 加法（行列＋行列）
    Matrix& operator+=(const Matrix& other) {
        assert(rows == other.rows && cols == other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = add(data[i][j], other.data[i][j]);
            }
        }
        return *this;
    }
    Matrix operator+(const Matrix& other) const {
        Matrix result(*this);
        result += other;
        return result;
    }

    // 乗法（行列・行列）
    Matrix& operator*=(const Matrix& other) {
        assert(cols == other.rows);
        vector<vector<T>> newData(rows, vector<T>(other.cols, zero()));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    newData[i][j] = add(newData[i][j], mul(data[i][k], other.data[k][j]));
                }
            }
        }
        data = newData;
        cols = other.cols;
        return *this;
    }
    Matrix operator*(const Matrix& other) const {
        Matrix result(*this);
        result *= other;
        return result;
    }
    
    // 行列の冪乗
    Matrix pow(long long exponent) const {
        assert(rows == cols); // 正方行列であることを確認
        // 単位行列で初期化
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            result.data[i][i] = one();
        }
        if (exponent == 0) return result;

        Matrix base = *this;
        while (exponent > 0) {
            if (exponent & 1) {
                result = result * base;
            }
            base = base * base;
            exponent >>= 1;
        }
        return result;
    }

    // 行列の表示
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// ADD_MUL_semi-ring
// long long add000(long long x, long long y) { return x + y; }
// long long zero000() { return 0LL; }
// long long mul000(long long x, long long y) { return x * y; }
// long long one000() { return 1LL; }
// #define ADD_MUL_semiring_000 long long, add000, zero000, mul000, one000

// ADD_MUL_semi-ring mint
// verify: https://atcoder.jp/contests/abc009/tasks/abc009_4
using mint = modint;
mint add001(mint x, mint y) { return x + y; }
mint zero001() { return 0; }
mint mul001(mint x, mint y) { return x * y; }
mint one001() { return 1; }
#define ADD_MUL_semiring mint, add001, zero001, mul001, one001


// XOR_AND_semi-ring
// verify: https://atcoder.jp/contests/abc009/tasks/abc009_4
long long add002(long long x, long long y) { return x ^ y; }
long long zero002() { return 0LL; }
long long mul002(long long x, long long y) { return x & y; }
long long one002() { return ~0LL; }
#define XOR_AND_semiring long long, add002, zero002, mul002, one002


int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    ll a,x,m;
    cin>>a>>x>>m;
    mint::set_mod(m);

    Matrix<ADD_MUL_semiring> mat(2,2);
    mat[0][0] = a;
    mat[0][1] = 1;
    mat[1][1] = 1;
    
    auto arr = mat.pow(x-1);
    mint ans = arr[0][0] + arr[0][1];
    cout << ans.val() << endl;
    
    return 0;
}