// Digit frequency in O(logn) time.

#include<bits/stdc++.h>
using namespace std;
 
  int main(){
    int t;
    cin>>t;
    while(t--){
    long long n;
    int k;
    cin>>n>>k;
  int freq=0;
    while(n!=0){
        if(n%10==k){freq++;}
        n=n/10;
    }
    cout<<freq<<endl;
  }
  return 0;
  }