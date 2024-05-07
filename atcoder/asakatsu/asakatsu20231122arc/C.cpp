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

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    deque<ll>q;
    rep(i,0,n)q.push_back(a[i]);
    ll cnt = 0;
    ll mode = 0;
    while(!q.empty()){
        if ((q.back()^mode)==0){
            q.pop_back();
        }else{
            if (q.front()^mode==0){
                q.pop_front();
                mode ^= 1;
            }else{
                break;
            }
        }
    }
    bool flag = false;
    if (q.empty()) flag = true;
    YesNo(flag);
    return 0;
}