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
    string s;
    cin>>s;

    vector<ll>cnt(26);
    stack<ll> q;
    ll n = s.size();
    vector<ll> nex(n);
    rep(i,0,n){
        if (s[i]=='('){
            q.push(i);
        }else if (s[i]==')'){
            ll t = q.top(); q.pop();
            nex[t] = i;
            rep(j,t+1,i){
                if (s[j]==')')continue;
                if (s[j]=='('){
                    j = nex[j];
                }else{
                    cnt[s[j]-'a']--;
                }
            }
        }else{
            if (cnt[s[i]-'a']){
                cout << "No" << endl;
                return 0;
            }
            cnt[s[i]-'a']++;
        }
    }
    cout << "Yes" << endl;
    return 0;
}