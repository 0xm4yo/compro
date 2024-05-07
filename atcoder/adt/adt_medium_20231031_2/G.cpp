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

int main()
{
    string s;
    cin>>s;
    ll q;
    cin>>q;
    
    string ss = "ABC";
    auto g = [&](ll a){
        ll now = s[0] - 'A';
        now += a;
        now %= 3;
        return ss[now];
    };

    function<char(ll,ll)> f = [&](ll a, ll b){
        if (a==0) return s[b];
        if (b==0) return g(a);
        if (b%2) return ss[(f(a-1,b/2)-'A'+2)%3];
        else return ss[(f(a-1,b/2)-'A'+1)%3];
    };
    while(q){
        q--;
        ll t,k;
        cin>>t>>k;
        k--;
        cout << f(t,k) << endl; 
    }

    return 0;
}