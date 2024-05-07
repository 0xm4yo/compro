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
const long long INF = 4004004003104004004LL; // (int)INFL = 1010931620;
ll coordinate(ll h, ll w, ll W){ return h*W + w; } // 二次元座標を一次元座標に変換

#define endl "\n" // インタラクティブの時はコメントアウトする


// これは窃盗したライブラリ
// 窃盗元: https://atcoder.jp/contests/abc328/submissions/47469055
//【ポテンシャル Union-Find】
/*
* Potential_union_find<T>(int n) : O(n)
*	非連結で大きさ n の重み付き Union-Find を構築する．
*
* bool set_diff(int a, int b, T d) : O(α(n))
*	v[b] - v[a] = d という関係を追加する．失敗は false を返す．
*
* bool same(int a, int b) : O(α(n))
*	頂点 a と頂点 b が同じ連結成分に属するかを返す．
*
* T get_diff(int a, int b) : O(α(n))
*	v[b] - v[a] を返す．（差が未確定なら -INFL）
*
* int leader(int a) : O(α(n))
*	頂点 a の属する連結成分の親を返す．
*
* int size(int a) : O(α(n))
*	頂点 a の属する連結成分の大きさを返す．
*
* int size() : O(1)
*	連結成分の個数を返す．
*
* vv<piT> groups() : O(n α(n))
*	連結成分の (頂点番号, ポテンシャル) の組のリストを返す．
*/
template <class T>
class Potential_union_find {
	int n; // 頂点の個数
	int m; // 連結成分の個数

	// parent_or_size[i] : 頂点 i の親または集合の大きさ
	// 頂点 i が根でない場合は親の番号（非負）を，
	// 根の場合は属する連結成分の大きさの -1 倍（負）を表す．
	vector<int> parent_or_size;

	// pot[i] : 親からみた頂点 i への差
	// 短絡後に参照すれば，根からみた頂点 i への差（ポテンシャル）になる．
	vector<T> pot;

public:
	// 非連結で大きさ n のポテンシャル Union-Find を構築する．
	Potential_union_find(int n_) : n(n_), m(n), parent_or_size(n, -1), pot(n) {}
	Potential_union_find() : n(0), m(0) {}

	// 頂点 a, b 間の差 v[b] - v[a] を設定する．
	bool set_diff(int a, int b, T d) {
		// verify : https://atcoder.jp/contests/abc320/tasks/abc320_d

		// 頂点 a, b の属する連結成分の根 ra, rb を得る．
		int ra = leader(a);
		int rb = leader(b);

		// 根が同じであれば既に連結であるから何もしない．
		// 既にある関係と整合しているかを返す．
		if (ra == rb) return pot[b] - pot[a] == d;

		// 根が異なる場合，大きい連結成分の根を改めて ra，小さい方を rb とする．
		if (-parent_or_size[ra] < -parent_or_size[rb]) {
			swap(a, b);
			swap(ra, rb);
			d *= -1;
		}

		// 小さい方の連結成分を ra を根とする連結成分に統合する．
		parent_or_size[ra] += parent_or_size[rb];
		parent_or_size[rb] = ra;
		pot[rb] = pot[a] - pot[b] + d;

		// 連結成分の数を 1 つ減らす．
		m--;

		return true;
	}

	// 頂点 a, b が同じ連結成分に属するかを返す．
	bool same(int a, int b) {
		// verify : https://atcoder.jp/contests/abc320/tasks/abc320_d

		// 根が同じなら連結である．
		return leader(a) == leader(b);
	}

	// v[b] - v[a] を返す．
	T get_diff(int a, int b) {
		// verify : https://atcoder.jp/contests/abc320/tasks/abc320_d

		if (!same(a, b)) return T(INF);

		// 根からの差の差として計算する．
		return pot[b] - pot[a];
	}

	// 頂点 a の属する連結成分の根を返す．
	int leader(int a) {
		// a が根であれば自分自身を返す．
		int pa = parent_or_size[a];
		if (pa < 0) return a;

		// a が根でなければ，a の親 pa の根 ra を求める．
		// 再帰的な処理が回り，pa の親は ra になっていることに注意．
		int ra = leader(pa);

		// a の親を ra に更新しつつ，a の根 ra を返す．
		parent_or_size[a] = ra;
		pot[a] += pot[pa];
		return ra;
	}

	// 頂点 a の属する連結成分の大きさを返す．
	int size(int a) {
		// a の根を調べ，そこに記録されている大きさの情報を返す．
		return -parent_or_size[leader(a)];
	}

	// 連結成分の個数を返す．
	int size() {
		// verify : https://yukicoder.me/problems/no/2251

		return m;
	}

	// 連結成分の (頂点番号, ポテンシャル) の組のリストを返す．
	vector<vector<pair<int, T>>> groups() {
		// verify : https://atcoder.jp/contests/code-festival-2016-quala/tasks/codefestival_2016_qualA_d

		vector<vector<pair<int, T>>> res(m);

		vector<int> r_to_i(n, -1); int i = 0;
		rep(a, 0, n) {
			int r = leader(a);
			if (r_to_i[r] == -1) r_to_i[r] = i++;
			res[r_to_i[r]].emplace_back(a, pot[a]);
		}

		return res;
	}
};


int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    ll n,m,q;
    cin>>n>>m>>q;

    Potential_union_find<ll> uf(n);
    map<pair<ll,ll>,ll> mp;
    vector<bool> ng(n);
    rep(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        if (!uf.set_diff(a,b,c)){
            ng[uf.leader(a)] = true;
        }
    }

    while(q--){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        if (!uf.same(x,y)){
            cout << "nan" << endl;
        }else if(ng[uf.leader(x)]){
            cout << "inf" << endl;
        }else{
            cout << uf.get_diff(x,y) << endl;
        }
    }

    return 0;
}