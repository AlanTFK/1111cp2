#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int bagNum, target;
    cin >> bagNum >> target;
    
    int ans, curKg = 0;
    ans = bagNum;
    
    vector<int> bag;
    for(int i = 0; i < bagNum; ++i){
        int tmp;
        cin >> tmp;
        bag.push_back(tmp);
        curKg += tmp;
    }
    
    sort(bag.begin(), bag.end());
    
    if(curKg < target){
        cout << -1 << endl;
        return 0;
    }
    if(curKg == target){
        cout << ans;
        return 0;
    }
    
    
    for(int i = 0; i < bagNum; ++i)
        cout << bag[i] <<" ";
    cout << endl;
    
    
    return 0;
}

