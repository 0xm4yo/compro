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
    ll h,w;
    cin>>h>>w;
    vector<string>g(h);
    rep(i,0,h)cin>>g[i];
    ll cnt = 0;
    ll nh = 0;
    ll nw = 0;
    while(cnt<10000000){
        cnt++;
        if (g[nh][nw]=='U'){
            if (nh==0){
                cout << nh+1 << " " << nw+1 << endl;
                return 0;
            }
            nh--;
        }else if(g[nh][nw]=='D'){
            if (nh==h-1){
                cout << nh+1 << " " << nw+1 << endl;
                return 0;
            }
            nh++;            
        }else if(g[nh][nw]=='L'){
            if (nw==0){
                cout << nh+1 << " " << nw+1 << endl;
                return 0;
            }
            nw--;
        }else{
            if (nw==w-1){
                cout << nh+1 << " " << nw+1 << endl;
                return 0;
            }
            nw++;   
        }
    }
    cout << -1 << endl;
    return 0;
}