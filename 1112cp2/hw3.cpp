#include<bits/stdc++.h>
using namespace std;

int main(){
    int buildingNum;
    cin >> buildingNum;
    vector<int> building;

    for(int i = 0; i < buildingNum; ++i){
        int tmpHigh = 0;
        cin >> tmpHigh;
        building.push_back(tmpHigh);
    }

    for(int i = 0; i < buildingNum - 1; ++i){
        int CBuilding = 0;
        int tmpBuilding = building[i+1];
        for(int j = i + 1; j < buildingNum; ++j){
            if(building[j] > building[i]){
                ++CBuilding;
                break;
            }      
            else if(i+1 == j)
                    ++CBuilding;
            else if(building[j] > tmpBuilding){
                    tmpBuilding = building[j];
                    ++CBuilding;
            }
        }
        cout << CBuilding << " ";
    }
    
    cout << "0 ";
    return 0;
}
