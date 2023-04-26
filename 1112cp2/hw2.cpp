#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> p, int lowDay, int highDay, int target, int ans){
    if(lowDay == highDay) return ans;
    int midDay = (highDay+lowDay)/2, sum = 0;
    for(int i = 0, j = 0; i < p.size(); ++i){
        if(p[i] - j > 0)
            sum += (p[i] - j);
        if((i+1)%midDay == 0) j++;
    }
    if(sum > target){
        if(midDay < ans) ans = midDay;
        return binary_search(p, lowDay, midDay, target, ans);
    }
    else if(sum < target)
        return binary_search(p, midDay+1, highDay, target, ans);
    else return midDay;
}

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
    if(curKg < target){
        cout << -1 << endl;
        return 0;
    }
    sort(bag.rbegin(), bag.rend());
    
    int lowDay = 0, highDay = ans;
    
    ans = binary_search(bag, lowDay, highDay, target, ans);
    
    /*for(int i = 0; i < bagNum; ++i)
        cout << bag[i] <<" ";
    cout << endl;*/
    cout << ans << endl;
    
    return 0;
}
