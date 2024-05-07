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

template <class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V, int), V (*put_vertex)(E, int)>
struct RerootingDP {
    struct edge {
        int to, idx, xdi;
    };
    RerootingDP(int n_ = 0) : n(n_), inner_edge_id(0) {
        es.resize(2*n-2);
        start.resize(2*n-2);
        if (n == 1) es_build();
    }
    void add_edge(int u, int v, int idx, int xdi){
        start[inner_edge_id] = u;
        es[inner_edge_id] = {v,idx,xdi};
        inner_edge_id++;
        start[inner_edge_id] = v;
        es[inner_edge_id] = {u,xdi,idx};
        inner_edge_id++;
        if (inner_edge_id == 2*n-2){
            es_build();
        }
    }
    vector<V> build(int root_ = 0){
        root = root_;
        vector<V> subdp(n); subdp[0] = put_vertex(e(),0);
        outs.resize(n);
        vector<int> geta(n+1,0);
        for (int i = 0; i < n; i++) geta[i+1] = start[i+1] - start[i] - 1;
        geta[root+1]++;
        for (int i = 0; i < n; i++) geta[i+1] += geta[i];
        auto dfs = [&](auto sfs, int v, int f) -> void {
            E val = e();
            for (int i = start[v]; i < start[v+1]; i++){
                if (es[i].to == f){
                    swap(es[start[v+1]-1],es[i]);
                }
                if (es[i].to == f) continue;
                sfs(sfs,es[i].to,v);
                E nval = put_edge(subdp[es[i].to],es[i].idx);
                outs[geta[v]++] = nval;
                val = merge(val,nval);
            }
            subdp[v] = put_vertex(val, v);
        };
        dfs(dfs,root,-1);
        return subdp;
    }
    vector<V> reroot(){
        vector<E> reverse_edge(n);
        reverse_edge[root] = e();
        vector<V> answers(n);
        auto dfs = [&](auto sfs, int v) -> void {
            int le = outs_start(v);
            int ri = outs_start(v+1);
            int siz = ri - le;
            vector<E> rui(siz+1);
            rui[siz] = e();
            for (int i = siz-1; i >= 0; i--){
                rui[i] = merge(outs[le+i],rui[i+1]);
            }
            answers[v] = put_vertex(merge(rui[0],reverse_edge[v]),v);
            E lui = e();
            for (int i = 0; i < siz; i++){
                V rdp = put_vertex(merge(merge(lui,rui[i+1]),reverse_edge[v]),v);
                reverse_edge[es[start[v]+i].to] = put_edge(rdp,es[start[v]+i].xdi);
                lui = merge(lui,outs[le+i]);
                sfs(sfs,es[start[v]+i].to);
            }
        };
        dfs(dfs,root);
        return answers;
    }
    private:
    int n, root, inner_edge_id;
    vector<E> outs;
    vector<edge> es;
    vector<int> start;
    int outs_start(int v){
        int res = start[v] - v;
        if (root < v) res++;
        return res;
    }
    void es_build(){
        vector<edge> nes(2*n-2);
        vector<int> nstart(n+2,0);
        for (int i = 0; i < 2*n-2; i++) nstart[start[i]+2]++;
        for (int i = 0; i < n; i++) nstart[i+1] += nstart[i];
        for (int i = 0; i < 2*n-2; i++) nes[nstart[start[i]+1]++] = es[i];
        swap(es,nes);
        swap(start,nstart);
    }
};

// https://atcoder.jp/contests/abc348/tasks/abc348_e
using P = pair<ll,ll>;
P merge(P a, P b){
    return {max(a.first, b.first), a.second+b.second};
}
P e(){
    return {0LL, 0LL};
}
vector<ll> cost;
ll n;
P put_edge(P v, int i){
    if (i>=n) return {v.first+cost[i], v.second};
    else return {v.first+cost[i], v.second+1};
}
P put_vertex(P e, int v){
    return {e.first, e.second};
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll d;
    cin>>n>>d;
    cost.resize(n*2);
    RerootingDP<P,P,merge,e,put_edge,put_vertex> g(n);
    rep(i,0,n-1){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        g.add_edge(a,b,i,i+n);
        cost[i] = c;
        cost[i+n] = c;
    }
    g.build();
    vector<P> arr = g.reroot();
    ll ans = INF;
    for (auto a: arr){
        if (a.first <= d){
            chmin(ans, a.second);
        }
    }
    if (ans==INF) ans = -1;
    cout << ans << endl;
    
    return 0;
}