#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int N;
long long A[500];
bool flag[500][500];
long long dp[500][500];
long long sm[500];

// sum[l, r]
long long s(int l, int r){
    return sm[r+1] - sm[l];
}

// [l, r], 0-indexed
long long f(int l, int r){
    if (l == r){
        return 0;
    }

    if (flag[l][r]){
        return dp[l][r];
    }
    flag[l][r] = true;
    long long _min = std::pow(10, 15);

    for (int m=l; m<r; m++){
        _min = std::min(_min, f(l, m) + s(l, m) + f(m+1, r) + s(m+1, r));
    }

    return dp[l][r] = _min;

}

int main()
{
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }

    sm[0] = 0;
    for (int i=0; i<N; i++){
        sm[i+1] = sm[i] + A[i];
    }

    cout << f(0, N-1) << endl;

    return 0;
}