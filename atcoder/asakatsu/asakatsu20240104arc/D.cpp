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
const double INF = 1e18+10;

int main()
{
    ll n;
    cin>>n;
    vector<ll>x(n);
    rep(i,0,n)cin>>x[i];
    vector<ll>mi,pl;
    rep(i,0,n){
        if(x[i]<0) mi.push_back(x[i]);
        else pl.push_back(x[i]);
    }
    sort(all(mi));
    sort(all(pl));
    double _min = INF;
    double _max = -INF;

    vector<ll> y;
    if (mi.size()<10){
        for (auto a: mi) y.push_back(a);
    }else{
        rep(i,0,4) y.push_back(mi[i]);
        rrep(i,mi.size()-1,mi.size()-4) y.push_back(mi[i]);
    }

    if (pl.size()<10){
        for (auto a: pl) y.push_back(a);
    }else{
        rep(i,0,4) y.push_back(pl[i]);
        rrep(i,pl.size()-1,pl.size()-4) y.push_back(pl[i]);
    }
    rep(i,0,y.size()){
        rep(j,i+1,y.size()){
            rep(k,j+1,y.size()){
                double temp = (double)(y[i]+y[j]+y[k])/(double)(y[i]*y[j]*y[k]);
                chmin(_min, temp);
                chmax(_max, temp);
            }
        }
    }

    cout << fixed << setprecision(15) << _min << endl;
    cout << fixed << setprecision(15) << _max << endl;
    return 0;
}