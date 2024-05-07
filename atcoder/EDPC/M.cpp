#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;

int N, K;
int A[100010];
mint dp[110][100010];
mint sm[110][100010];
long long smA[3010];

// sum[l, r]
long long s(int l, int r){
    return smA[r+1] - smA[l];
}

int main()
{
    cin >> N >> K;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }

    smA[0] = 0;
    for (int i=0; i<N; i++){
        smA[i+1] = smA[i] + A[i];
    }
    
    dp[0][0] = 1;
    for (int i=0; i<N+1; i++){
        if (i == 0){
            for (int j=1; j<K+1; j++){
                dp[i][j] = 0;
            }
            continue;
        }

        for (int j=0; j<K+1; j++){
            if (i == 0){
                sm[i-1][0] = 1;
            }
            sm[i-1][j] = sm[i-1][j-1] + dp[i-1][j];
        }

        int a = A[i-1];

        for (int j=0; j<K+1; j++){
            if (j == 0){
                dp[i][j] = 1;
            }
            if (j > smA[i]){
                dp[i][j] = 0;
            }
            if (j - a <= 0){
                dp[i][j] = sm[i-1][j];
            }else{
                dp[i][j] = sm[i-1][j] - sm[i-1][j-a-1];
            }
        }
    }

    mint ans = dp[N][K];
    
    cout << ans.val() << endl;

    return 0;
}