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
const long long INF = (ll)1e18+10;
ll coordinate(ll h, ll w, ll W){ return h*W + w; } // 二次元座標を一次元座標に変換

using P = pair<ll,ll>;
P opmin(P a, P b){ return a.first < b.first ? a : b; }
ll opsum(ll a, ll b){ return a + b; }
P emin(){ return make_pair(INF, -1); }
ll esum(){ return 0LL; }
struct Euler_tour{
    // https://qiita.com/recuraki/items/72e37eb9be9f71bc623a
    vector<ll> vcost;
    vector<ll> visit, vcost1, vcost2, ecost1, ecost2, depth;
    ll step;
    vector<ll> vdepth, in, out;
    segtree<P,opmin,emin> RMQ;
    segtree<ll,opsum,esum> RSQv1, RSQv2, RSQe1, RSQe2;
    /*
    visit: STEPで訪れた頂点の番号
    vcost: 各頂点に与えられたコスト
    vcost1: 初めて訪れた際のその頂点のコスト(本例では頂点コストは頂点番号に等しくしている)
    vcost2: 初めて訪れた際のその頂点のコスト と 最後に訪れた際のコストをマイナスで記録したもの
    ecost1: 初めて通った辺のコスト
    ecost1: 初めて通った辺のコスト と 最後にその辺を訪れた時のコストをマイナスで記録したもの
    深さ: 根を 0 とした時の頂点の深さ
    dpeth: 各 STEP での深さ
    vdepth: 各頂点の深さ
    in: その頂点を最初に訪れた時間(STEP)
    out: その頂点を抜けた時間(STEP) つまり、その頂点を最後に訪れた時間+1
    RMQ: LCA(最小共通祖先) を管理
    RSQv1: ある頂点を根とした部分木の頂点コストの総和を管理
    RSQv2: ある頂点からある頂点へのパスの頂点コストの総和を管理
    RSQe1: ある頂点を根とした部分木の辺コストの総和を管理
    RSQe2: ある頂点からある頂点へのパスの辺コストの総和を管理
    */
    Euler_tour(ll n, ll st, vector<vector<ll>> g, vector<ll> cost){
        // コンストラクタ、頂点にコストあり
        // n: 頂点数、st: 根とする頂点、g: 連結リスト、cost: 各頂点のコスト
        visit.resize(2*n);
        vcost1.resize(2*n); vcost2.resize(2*n);
        ecost1.resize(2*n); ecost2.resize(2*n);
        depth.resize(2*n);
        step = 0;
        vdepth.resize(n, -1);
        in.resize(n); out.resize(n);
        vcost = cost;
        function<void(ll,ll)> dfs = [&](ll now, ll d){
            in[now] = step;
            vdepth[now] = d;
            visit[step] = now;
            vcost1[step] = vcost[now];
            vcost2[step] = vcost[now];
            depth[step] = d;
            step++;
            for (auto nex: g[now]){
                if (vdepth[nex] != -1) continue;
                dfs(nex, d + 1);
                visit[step-1] = now;
            }
            out[now] = step;
            vcost2[step] = -vcost[now];
            depth[step] = d - 1;
            step++;
        };
        dfs(st, 0);
        vector<P> v(2*n);
        for (ll i=0; i<2*n; i++) v[i] = make_pair(depth[i], visit[i]);
        RMQ = segtree<P,opmin,emin>(v);
        RSQv1 = segtree<ll,opsum,esum>(vcost1);
        RSQv2 = segtree<ll,opsum,esum>(vcost2);
        RSQe1 = segtree<ll,opsum,esum>(ecost1);
        RSQe2 = segtree<ll,opsum,esum>(ecost2);
    }

    Euler_tour(ll n, ll st, vector<vector<pair<ll,ll>>> g){
        // コンストラクタ、辺にコストあり
        // n: 頂点数、st: 根とする頂点、g: コスト付き連結リスト（pair型、first: 次の頂点、second: 辺のコスト)
        visit.resize(2*n);
        vcost1.resize(2*n); vcost2.resize(2*n);
        ecost1.resize(2*n); ecost2.resize(2*n);
        depth.resize(2*n);
        step = 0;
        vdepth.resize(n, -1);
        in.resize(n); out.resize(n);
        vcost.resize(n);
        function<void(ll,ll)> dfs = [&](ll now, ll d){
            in[now] = step;
            vdepth[now] = d;
            visit[step] = now;
            depth[step] = d;
            step++;
            for (auto [nex,cost]: g[now]){
                if (vdepth[nex] != -1) continue;
                ll u = now;
                ll v = nex;
                if (u>v) swap(u, v);
                ecost1[step] = cost;
                ecost2[step] = cost;
                dfs(nex, d + 1);
                visit[step-1] = now;
                ecost2[step-1] = -cost;
            }
            out[now] = step;
            depth[step] = d - 1;
            step++;
        };
        dfs(st, 0);
        vector<P> v(2*n);
        for (ll i=0; i<2*n; i++) v[i] = make_pair(depth[i], visit[i]);
        RMQ = segtree<P,opmin,emin>(v);
        RSQv1 = segtree<ll,opsum,esum>(vcost1);
        RSQv2 = segtree<ll,opsum,esum>(vcost2);
        RSQe1 = segtree<ll,opsum,esum>(ecost1);
        RSQe2 = segtree<ll,opsum,esum>(ecost2);
    }

    // a,b の LCA(最小共通祖先) を求める
    ll lca(ll a, ll b){
        ll l = min(in[a], in[b]);
        ll r = max(out[a], out[b]);
        auto res = RMQ.prod(l, r);
        return res.second;
    }
    ll get_subtree_vsum(ll a){
        return RSQv1.prod(in[a], out[a]);
    }
    ll get_subtree_esum(ll a){
        return RSQe1.prod(in[a]+1, out[a]);
    }
    ll rootpath_vsum(ll a){
        return RSQv2.prod(0, in[a]+1);
    }
    ll rootpath_esum(ll a){
        return RSQe2.prod(1, in[a]+1);
    }
    ll get_path_vsum(ll a, ll b){
        ll par = lca(a, b);
        return rootpath_vsum(a) + rootpath_vsum(b) - 2*rootpath_vsum(par) + vcost[par];
    }
    ll get_path_esum(ll a, ll b){
        ll par = lca(a, b);
        return rootpath_esum(a) + rootpath_esum(b) - 2*rootpath_esum(par);
    }
    void update_v(ll a, ll x){
        // 頂点 a のコストを x に置換
        vcost[a] = x;
        RSQv1.set(in[a], x);
        RSQv2.set(in[a], x);
        RSQv2.set(out[a], -x);
    }
    void update_e(ll a, ll b, ll x){
        // 辺 a-b のコストを x に置換
        if (in[a] > in[b]) swap(a, b);
        RSQe1.set(in[b], x);
        RSQe2.set(in[b], x);
        RSQe2.set(out[b], -x);
    }
};

int main()
{
    ll n;
    cin >> n;
    vector<vector<P>> g(n);
    vector<ll> u(n), v(n);
    rep(i, 0, n-1){
        ll w;
        cin >> u[i] >> v[i] >> w;
        u[i]--; v[i]--;
        g[u[i]].push_back({v[i], w});
        g[v[i]].push_back({u[i], w});
    }

    Euler_tour euler(n, 0, g);

    ll q;
    cin >> q;
    while(q--){
        ll c;
        cin >> c;
        if (c==1){
            ll i, w;
            cin >> i >> w;
            i--;
            euler.update_e(u[i], v[i], w);
        }else{
            ll a, b;
            cin >> a >> b;
            a--; b--;
            cout << euler.get_path_esum(a, b) << endl;
        }
    }

    // cout << fixed << setprecision(18);
    return 0;
}