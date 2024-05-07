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

ll op(ll a, ll b){ return a+b; }
ll e(){ return 0; }

int main()
{
    ll n;
    cin>>n;
    vector<ll>p(n);
    rep(i,0,n)cin>>p[i];
    rep(i,0,n)p[i]--;

    vector<pair<char,ll>>ans;
    auto a = p;
    ll cnt0 = 0;
    rep(i,0,n){
        if (i%2)continue;
        if (i%2==a[i]%2)continue;
        cnt0++;
        ll tar = (cnt0-1)*2;
        ll now = i;
        while(now-2>=tar){
            swap(a[now-2],a[now]);
            ans.emplace_back('B', now-2+1);
            now -= 2;
        }
    }
    ll cnt1 = 0;
    rep(i,0,n){
        if (i%2==0)continue;
        if (i%2==a[i]%2)continue;
        cnt1++;
        ll tar = (cnt1-1)*2+1;
        ll now = i;
        while(now-2>=tar){
            swap(a[now-2],a[now]);
            ans.emplace_back('B', now-2+1);
            now -= 2;
        }
    }
    ll cnt = cnt0 + cnt1;
    rep(i,0,cnt){
        if (i%2)continue;
        swap(a[i],a[i+1]);
        ans.emplace_back('A', i+1);
    }

    while(1){
        bool flag = false;
        rep(i,0,n-2){
            if (a[i]>a[i+2]){
                flag = true;
                swap(a[i],a[i+2]);
                ans.emplace_back('B',i+1);
            }
        }
        if (!flag) break;
    }

    assert(ans.size()<=100000);
    cout << ans.size() << endl;
    for (auto [mode,pos]: ans){
        cout << mode << " " << pos << endl;
    }    

    return 0;
}