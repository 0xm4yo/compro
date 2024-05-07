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
    string s;
    cin>>s;
    vector<char> ans;
    rep(i,0,n){
        if (ans.size()>=1){
            char lt = ans.back();
            if (lt=='B' && s[i]=='A'){
                ans.pop_back();
                ans.push_back('A');
                ans.push_back('B');
            }else if(lt=='B' && s[i]=='B'){
                ans.pop_back();
                ans.push_back('A');        
            }else{
                ans.push_back(s[i]);
            }
        }else{
            ans.push_back(s[i]);
        }
    }
    for (auto a: ans){
        cout << a;
    }
    cout << endl;
    return 0;
}