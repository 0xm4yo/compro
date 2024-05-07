#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int N;
long long A[20][20];
long long dp[1<<20];
long long cost[1<<20];

int main()
{
    cin >> N;
    for (int i=0; i<N; i++) for (int j=0; j<N; j++){
        cin >> A[i][j];
    }

    for (int s=0; s<(1<<N); s++) dp[s] = - (1<<30);

    for (int s=1; s<(1<<N); s++){
        for(int i=0; i<N; i++){
            if (!((s>>i) & 1)) continue;
            for (int j=i+1; j<N; j++){
                if (!((s>>j) & 1)) continue;
                cost[s] += A[i][j];
            }
        }
    }

    dp[0] = 0;
    for (int s=1; s<(1<<N); s++){
        for (int t=s; t>0; t = (t-1)&s){
            dp[s] = max(dp[s], dp[s-t] + cost[t]);
        }
    }

    cout << dp[(1<<N)-1] << endl;
    return 0;
}