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
    ll n,q;
    cin>>n>>q;
    vector<ll> to(n,-1), ba(n,-1);

    while (q){
        q--;
        ll a;
        cin>>a;
        if(a==1){
            ll x,y;
            cin>>x>>y;
            x--;y--;
            to[x] = y;
            ba[y] = x;
        }else if(a==2){
            ll x,y;
            cin>>x>>y;
            x--;y--;
            to[x] = -1;
            ba[y] = -1;
        }else{
            ll x;
            cin>>x;
            x--;
            queue<ll> qu;
            
            vector<ll>ans;
            qu.push(x);
            ans.push_back(x);
            while (!qu.empty()){
                ll now = qu.front(); qu.pop();
                if (ba[now]==-1){
                    continue;
                }else{
                    ans.push_back(ba[now]);
                    qu.push(ba[now]);
                }
            }
            reverse(all(ans));
            qu.push(x);
            while (!qu.empty()){
                ll now = qu.front(); qu.pop();
                if (to[now]==-1){
                    continue;
                }else{
                    ans.push_back(to[now]);
                    qu.push(to[now]);
                }
            }
            cout << ans.size() << " ";
            for (auto aa: ans){
                cout << aa+1 << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}