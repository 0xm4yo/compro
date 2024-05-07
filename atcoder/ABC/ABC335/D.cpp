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
    vector<vector<ll>> arr(n+2,vector<ll>(n+2,-1));
    rep(i,1,n+1)rep(j,1,n+1) arr[i][j] = 0;
    ll posh = 1;
    ll posw = 1;
    ll now = 0;
    ll mode = 0;
    while(1){
        now++;
        arr[posh][posw] = now;
        if (mode==0 && arr[posh][posw+1]==0){
            posw++;
            continue;
        }else{
            mode = 1;
        }
        if (mode==1 && arr[posh+1][posw]==0){
            posh++;
            continue;
        }else{
            mode = 2;
        }
        if (mode==2 && arr[posh][posw-1]==0){
            posw--;
            continue;
        }else{
            mode = 3;
        }
        if (mode==3 && arr[posh-1][posw]==0){
            posh--;
            continue;
        }else{
            mode = 0;
        }
        if (mode==0 && arr[posh][posw+1]==0){
            posw++;
            continue;
        }else{
            mode = 1;
        }
        if (mode==1 && arr[posh+1][posw]==0){
            posh++;
            continue;
        }else{
            mode = 2;
        }
        if (mode==2 && arr[posh][posw-1]==0){
            posw--;
            continue;
        }else{
            mode = 3;
        }
        if (mode==3 && arr[posh-1][posw]==0){
            posh--;
            continue;
        }else{
            mode = 0;
        }
        arr[posh][posw] = INF;
        break;
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            if (arr[i][j]==INF) cout << 'T' << " ";
            else cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}