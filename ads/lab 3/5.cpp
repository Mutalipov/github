#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector <int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i = 0; i<q;i++){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        long long c1=0,c2=0,c_int=0;
        if(l2<=r2){
            auto it1 = lower_bound(v.begin(),v.end(),l2);
            auto it2 = lower_bound(v.begin(),v.end(),r2);
            c1 = distance(it1,it2);
        }
        int l_int = max(l1,l2);
        int r_int = min(r1,r2);
        if (l_int <= r_int) {
            auto it1 = lower_bound(v.begin(), v.end(), l_int);
            auto it2 = upper_bound(v.begin(), v.end(), r_int);
            c_int = distance(it1, it2);
        }
        long long total_count = c1+c2-c_int;
        cout<<total_count<<"\n";
    }
}