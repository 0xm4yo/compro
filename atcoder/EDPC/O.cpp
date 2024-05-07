#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int N, A[30][30];
using mint = modint1000000007;
mint dp[1<<21];
bool flag[1<<21];

int main()
{
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> A[i][j];
        }
    }

    
    queue<tuple<int, int>> q;
    q.push(make_tuple(0, 0));
    dp[0] = 1;
    flag[0] = true;

    while (!q.empty()){
        tuple<int, int> now = q.front();
        int i = get<0>(now);
        int j = get<1>(now);
        if (i >= N){
            break;
        }
        for (int k=0; k<N; k++){
            if ((1<<k) & j){
                continue;
            }
            if (A[i][k]){
                dp[j + (1<<k)] += dp[j];
            }

            if (flag[j + (1<<k)]){
                continue;
            }else{
                q.push(make_tuple(i + 1, j + (1<<k)));
                flag[j + (1<<k)] = true;
            }
        }
        q.pop();
    }

    cout << dp[(1<<N)-1 ].val() << endl;


    return 0;
}