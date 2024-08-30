// Find the number of lattice points strictly above the straight line & strictly inside circle. r & l are real numbers.

#include <bits/stdc++.h>
using namespace std;

int main() {
    double r, k;
    cin >> r >> k;
    
    long long count = 0;
    
    double top = floor(r);
    if(top == r) top--;
    
    double line = ceil(k);
    if(line == k) line++;
    
    double y = top;
    double x = 0;
    for(; y >= 0 && y >= line; y--) {
        while(y * y + x * x < r * r) x++;
        count += 2 * x - 1;
    }
    for(; y >= line && y >= -top; y--) {
        while(y * y + x * x >= r * r) x--;
        count += 2 * x + 1;
    }
    
    cout << count << endl;
    
    return 0;
}
