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
    string sr,sc;
    cin>>sr>>sc;
    vector<ll>a(n),b(n),c(n);
    rep(i,0,n){
        a[i]=i;
        b[i]=i;
        c[i]=i;
    }
    do{
        do{
            do{
                bool fail = false;
                rep(i,0,n){
                    if (a[i]==b[i] || b[i]==c[i] || c[i]==a[i]) fail = true;
                }
                if (fail)continue;
                vector<vector<char>> v(n, vector<char>(n, '.'));
                rep(i,0,n)v[i][a[i]] = 'A';
                rep(i,0,n)v[i][b[i]] = 'B';
                rep(i,0,n)v[i][c[i]] = 'C';
                string rr = "";
                rep(i,0,n)rep(j,0,n){
                    if (v[i][j]=='.')continue;
                    rr += v[i][j];
                    break;
                }
                if (rr!=sr)fail = true;
                if (fail)continue;
                string cc = "";
                rep(j,0,n)rep(i,0,n){
                    if (v[i][j]=='.')continue;
                    cc += v[i][j];
                    break;
                }
                if (cc!=sc)fail = true;
                if (fail)continue;
                cout << "Yes" << endl;
                rep(i,0,n){
                    rep(j,0,n){
                        cout << v[i][j];
                    }
                    cout << endl;
                }
                return 0;
            }while(next_permutation(all(c)));
        }while(next_permutation(all(b)));
    }while(next_permutation(all(a)));
    cout << "No" << endl;
    return 0;
}