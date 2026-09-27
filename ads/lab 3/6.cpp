#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long h;
    if (!(cin >> n >> h)) return 0;
    
    vector<long long> bags(n);
    long long max_bag = 0;
    for(int i = 0; i < n; i++){
        cin >> bags[i];
        max_bag = max(max_bag, bags[i]);
    }
    
    long long low = 1, high = max_bag;
    long long ans = high;
    
    while(low <= high){
        long long mid = low + (high - low) / 2;
        long long hours_needed = 0;
        bool p = true;
        for(int i = 0; i < n; i++){
            hours_needed += (bags[i] + mid - 1) / mid;
            if(hours_needed > h){
                p = false;
                break;
            }
        }
        
        if(p){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << ans << "\n";
    return 0;
}