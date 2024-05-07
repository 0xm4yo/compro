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

int main()
{
    ll n;
    char c;
    cin>>n>>c;
    string s;
    cin>>s;
    ll r = count(all(s), 'R');
    ll b = count(all(s), 'B');
    ll flag = 0;
    flag += r*1;
    flag += b*2;
    if (flag%3==1 && c=='R'){
        cout << "Yes" << endl;
    }else if(flag%3==2 && c=='B'){
        cout << "Yes" << endl;
    }else if(flag%3==0 && c=='W'){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}