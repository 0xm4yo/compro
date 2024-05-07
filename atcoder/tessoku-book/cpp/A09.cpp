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
const ll INF = (ll)1e15;

ll cum[1510][1510] = {0};

int main()
{
    ll h,w,n;
    cin>>h>>w>>n;
    rep(i,0,n){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        cum[a][b]++;
        cum[c+1][d+1]++;
        cum[c+1][b]--;
        cum[a][d+1]--;
    }
    rep(i,1,h+1)rep(j,1,w+1){
        cum[i][j] += cum[i][j-1] + cum[i-1][j] - cum[i-1][j-1];
    }
    
    rep(i,1,h+1)rep(j,1,w+1){
        cout << cum[i][j] << endl;
    }

    return 0;
}