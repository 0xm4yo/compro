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
const ll INF = numeric_limits<ll>::max();

// https://tjkendev.github.io/procon-library/cpp/convex_hull_trick/deque.html
class ConvexHullTrick {
    struct F {
        ll a, b;
        F(ll a, ll b) : a(a), b(b) {}
    };

    deque<F> deq;

    bool check(F &f1, F &f2, F &f3) {
        return (f2.a - f1.a) * (f3.b - f2.b) >= (f2.b - f1.b) * (f3.a - f2.a);
    }

    ll f(F &f1, ll x) {
        return f1.a * x + f1.b;
    }

    public:
    // a_{prev} >= a
    void add_line(ll a, ll b) {
        F f1 = F(a, b);
        while(deq.size() >= 2 && check(deq[deq.size()-2], deq[deq.size()-1], f1)) {
        deq.pop_back();
        }
        deq.push_back(f1);
    }

    // x_{prev} <= x
    ll query(ll x) {
        while(deq.size() >= 2 && f(deq[0], x) >= f(deq[1], x)) {
        deq.pop_front();
        }
        return f(deq[0], x);
    }
};

int main()
{
    ll n,c;
    cin>>n>>c;

    vector<ll>h(n);
    rep(i,0,n)cin>>h[i];
    
    vector<ll>dp(n);
    ConvexHullTrick cht;
    cht.add_line(-2*h[0],h[0]*h[0]);
    rep(i,1,n){
        dp[i] = h[i]*h[i]+c+cht.query(h[i]);
        cht.add_line(-2*h[i], dp[i]+h[i]*h[i]);
    }
    cout << dp[n-1] << endl;
    
    return 0;
}