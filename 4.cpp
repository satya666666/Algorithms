// Fibonacci F(i)=i, for less than 100, F(i)=(F(i-100)+F(i-99)) % (10^9+7)

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1'000'000'007;
vector<vector<long long>> multiply(
    const vector<vector<long long>>& a,
    const vector<vector<long long>>& b
) {
    int ra = a.size();
    int ca = a[0].size();
    int rb = b.size();
    int cb = b[0].size();
    vector<vector<long long>> result(ra, vector<long long>(cb, 0));
    
    for (int i = 0; i < ra; ++i) {
        for (int j = 0; j < cb; ++j) {
            long long sum = 0;
            for (int k = 0; k < ca; ++k) {
                sum = (sum + a[i][k] * b[k][j]) % MOD;
            }
            result[i][j] = sum;
        }
    }
    return result;
}
 vector<vector<long long>> calculatePower(const string& n) {
    vector<vector<long long>> base(100, vector<long long>(100, 0));
    base[0][98] = 1;
    base[0][99] = 1;
    for (int i = 1; i < 100; ++i) {
        base[i][i-1] = 1;
    }
    
    vector<vector<long long>> result(100, vector<long long>(100, 0));
    for (int i = 0; i < 100; ++i) {
        result[i][i] = 1;
    }
    
    for (int i = n.size() - 1; i >= 0; --i) {
        vector<vector<long long>> z(100, vector<long long>(100, 0));
        for (int j = 0; j < 100; ++j) {
            z[j][j] = 1;
        }
        long long value = n[i] - '0';
        while (value > 0) {
            z = multiply(z, base);
            --value;
        }
        result = multiply(result, z);
        vector<vector<long long>> replace(100, vector<long long>(100, 0));
        for (int j = 0; j < 100; ++j) {
            replace[j][j] = 1;
        }
        
        for (long long j = 0; j < 10; ++j) {
            replace = multiply(replace, base);
        }
        base = replace;
    }
    return result;
}

int main() {
    string n;
    cin >> n;
    
    auto result = calculatePower(n);
    
    vector<vector<long long>> multiplyFactor(100,vector<long long>(1, 0));
    for (int j = 0; j <= 99; ++j) {
        multiplyFactor[j][0] = 99 - j;
    }
    
    result = multiply(result, multiplyFactor);
    
    cout << result[99][0] << endl;
    
    return 0;
}