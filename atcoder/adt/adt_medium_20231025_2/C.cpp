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
    ll r,c;
    cin>>r>>c;
    vector<vector<ll>>s(15, vector<ll>(15));
    rep(i,0,15){
        s[i][0]=1;
        s[i][14]=1;
        s[0][i]=1;
        s[14][i]=1;
    }
    rep(i,2,13){
        s[i][2]=1;
        s[i][12]=1;
        s[2][i]=1;
        s[12][i]=1;       
    }
    rep(i,4,11){
        s[i][4]=1;
        s[i][10]=1;
        s[4][i]=1;
        s[10][i]=1;       
    }
    rep(i,6,9){
        s[i][6]=1;
        s[i][8]=1;
        s[6][i]=1;
        s[8][i]=1;       
    }
    r--;c--;
    if (s[r][c]==1) cout << "black" << endl;
    else cout << "white" << endl;


    return 0;
}