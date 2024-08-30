// Find Kth largest number.

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,k;
    cin>>n>>k;
    vector<int > arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<arr[n-k]<<endl;
    
    return 0;
}