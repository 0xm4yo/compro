#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int N;
using mint = modint1000000007;
int X[100010];
int Y[100010];
using Graph = vector<vector<int>>;
Graph G(100010);
bool flag[100010][2];
mint dp[100010][2];

mint f(int now, int mode, int pre){
    if (flag[now][mode]){
        return dp[now][mode];
    }
    flag[now][mode] = true;
    mint res = 1;
    for (auto nex : G[now]){
        if (nex == pre){
            continue;
        }
        if (mode){
            res *= f(nex, 0, now);
        }else{
            res *= f(nex, 0, now) + f(nex, 1, now);
        }
    }
    return dp[now][mode] = res;
}


int main()
{
    cin >> N;
    for (int i=0; i<N-1; i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    mint ans = f(1, 0, -1) + f(1, 1, -1);
    cout << ans.val() << endl; 
    return 0;
}