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
    string s,t;
    cin>>s>>t;
    vector<ll> scnt(26), tcnt(26);
    ll sc = 0, tc = 0;
    ll n = s.size();
    rep(i,0,n){
        if (s[i]=='@'){
            sc++;
        }else{
            scnt[s[i]-'a']++;
        }
    }
    rep(i,0,n){
        if (t[i]=='@'){
            tc++;
        }else{
            tcnt[t[i]-'a']++;
        }        
    }
    bool flag = true;
    vector<char> arr = { 'a', 't', 'c', 'o', 'd', 'e', 'r'};
    rep(i,0,26){
        if (find(all(arr),'a'+i)==arr.end()){
            if (scnt[i]!=tcnt[i]) flag = false;
        }else{
            if (scnt[i]<tcnt[i]){
                ll dif = tcnt[i]-scnt[i];
                if (sc<dif) flag = false;
                else sc -= dif;
            }else{
                ll dif = scnt[i]-tcnt[i];
                if (tc<dif) flag = false;
                else tc -= dif;                
            }
        }
    }
    YesNo(flag);

    return 0;
}