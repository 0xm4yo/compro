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
    vector<vector<ll>> a(9,vector<ll>(9));
    rep(i,0,9)rep(j,0,9)cin>>a[i][j];
    bool flag = true;
    rep(i,0,9){
        vector<bool>v(9);
        rep(j,0,9){
            if (v[a[i][j]])flag = false;
            v[a[i][j]]=true;
        }
    }
    rep(j,0,9){
        vector<bool>v(9);
        rep(i,0,9){
            if (v[a[i][j]])flag = false;
            v[a[i][j]]=true;
        }
    }
    rep(i,0,3){
        rep(j,0,3){
            ll st = i*3*9+j*3;
            vector<bool>v(9);
            rep(k,0,3){
                if(v[a[i*3][j*3+k]]) flag = false;
                v[a[i*3][j*3+k]] = true;
            }
            rep(k,0,3){
                if(v[a[i*3+1][j*3+k]]) flag = false;
                v[a[i*3+1][j*3+k]] = true;
            }
            rep(k,0,3){
                if(v[a[i*3+2][j*3+k]]) flag = false;
                v[a[i*3+2][j*3+k]] = true;
            }           
        }
    }
    YesNo(flag);
    return 0;
}
