#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }
    int target;
    cin>>target;
    if(binary_search(v.begin(),v.end(),target)) cout<<"Yes";
    else cout<<"No";
}