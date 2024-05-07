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
    ll n,q;
    cin>>n>>q;
    vector<multiset<ll>> arr(200010);
    vector<ll> pos(n),score(n);

    rep(i,0,n){
        ll a,b;
        cin>>a>>b;
        pos[i] = b;
        arr[b].insert(a);
        score[i] = a;
    }

    multiset<ll> st;
    rep(i,0,200010){
        if (arr[i].size()){
            auto itr = arr[i].end();
            itr--;
            st.insert(*itr);
        }
    }

    while(q--){
        ll c,d;
        cin>>c>>d;
        c--;
        ll now = pos[c];
        ll nex = d;
        
        auto itr = arr[now].end();
        itr--;
        if (*itr == score[c]){
            arr[now].erase(itr);
            itr = st.lower_bound(score[c]);
            st.erase(itr);
            if (arr[now].size()!=0){
                itr = arr[now].end();
                itr--;
                st.insert(*itr);
            }
        }else{
            itr = arr[now].lower_bound(score[c]);
            arr[now].erase(itr);
        }

        pos[c] = nex;
        itr = arr[nex].end();
        if (arr[nex].size()!=0){
            itr--;
            if (*itr < score[c]){
                itr = st.lower_bound(*itr);
                st.erase(itr);
                st.insert(score[c]);
                arr[nex].insert(score[c]);
            }else{
                arr[nex].insert(score[c]);
            }
        }else{
            arr[nex].insert(score[c]);
            st.insert(score[c]);
        }
        cout << *st.begin() << endl;
    }

    return 0;
}