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
    bool flag = false;
    ll x = -1;
    if (n==1){
        cout << "Yes" << endl;
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    rep(i,3,n+10){
        if (i*(i-1)/2LL==n){
            flag = true;
            x = i;
        }
    }
    YesNo(flag);
    if (!flag) return 0;

    vector<vector<ll>> ans(x);
    ans[0].push_back(1);
    ans[1].push_back(2);
    ans[2].push_back(3);
    ans[0].push_back(2);
    ans[1].push_back(3);
    ans[2].push_back(1);
    ll now = 3;
    rep(i,now,x){
        ll st = i*(i-1)/2LL+1LL;
        rep(j,0,i){
            ans[j].push_back(st+j);
        }
        ll temp = st;
        while(ans[i].size()<i){
            ans[i].push_back(temp);
            temp++;
        }
    }
    cout << ans.size() << endl;
    for (auto a: ans){
        cout << a.size() << " ";
        for (auto b: a){
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}