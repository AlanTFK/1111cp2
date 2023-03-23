#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> buildingNum;
    vector<int> building;

    for(int i = 0; i < buildingNum; ++i){
        int tmpHigh = 0;
        cin >> tmpHigh;
        building.push_back(tmpHigh);
    }

    for(int i = 0; i < buildingNum - 1; ++i){
        int CBuilding = 1;
        int tmpBuilding = building[i+1];
        for(int j = i + 1; j < buildingNum && building[i] > building[j]; ++j){
            if(building[j] > tmpBuilding){
                tmpBuilding = building[j];
                ++CBuilding;
            }
        }
        cout << CBuilding << " ";
    }
        
    return 0;
}
