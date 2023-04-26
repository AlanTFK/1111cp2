#include <iostream>
using namespace std;

int main(){
    int min = 999999999, num = 0, tmpAns = 0,  ans = 0;
    cin >> min;
    while (cin >> num){
        if (num < min) min = num;
        tmpAns = num - min;
        if (tmpAns > ans) ans = tmpAns;
    }

    cout << ans << endl;
    return 0;
}
