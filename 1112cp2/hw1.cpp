#include <bits/stdc++.h>

using namespace std;

class classTime{
    int day;
    int start;
    int end;
public:
    classTime();
    classTime(int a, int b,int c){
        day = a;
        start = b;
        end = c;
    }
    ~classTime();
    void print(){cout << day << ", " << start << ", " << end << endl;};
    int getD(){ return day; };
    int getS(){ return start; };
    int getE(){ return end; };
};

class Class{
    string countID;
    int sessionCount = 1;
    classTime* T[10];
public:
    Class();
    Class(int _sessionC, string _countID)
    :sessionCount(_sessionC)
    {
        countID = _countID;
        int wd, start ,end;
        for(int i = 0; i < sessionCount; ++i){
            scanf("%d, %d, %d", &wd, &start, &end);
            classTime *b = new classTime(wd,start,end);
            T[i] = b;
            //printf("%d, %d, %d\n", wd, start,end);
        }    
    };
    void print(){
        cout << sessionCount << " " << countID << endl;
        for(int i = 0; i < sessionCount; ++i){
            T[i]->print();
        }
    };
    ~Class();
    
    int getS(int j){ return T[j]->getS(); };
    int getE(int j){ return T[j]->getE(); };
    int getD(int j){ return T[j]->getD(); };
    int getSC(){ return sessionCount; };
};

struct classPoint{
    bool conflict = false;
    int ID = 0;
};

int main()
{
    
    int N = 0;
    cin >> N;
    Class *myClass[N];
    int SC;
    string CI;
    for(int i = 0; i < N; ++i){
        cin >> SC >> CI;
        Class *a = new Class(SC,CI);
        myClass[i] = a;
    }
    
    classPoint timeTable[17][7];

    int countID = 1;
    int tmpID = 0;
    
    for(int i = 0; i < N; ++i){
        
        int classSessionCount = myClass[i]->getSC();
        for(int j = 0; j < classSessionCount; ++j){
            
            int classStart = myClass[i]->getS(j) - 6;
            int classEnd = myClass[i]->getE(j) - 6;
            int classDay = myClass[i]->getD(j) - 1;

            for(int k = classStart; k < classEnd; ++k)
                if(timeTable[k][classDay].ID != 0)
                    tmpID = timeTable[k][classDay].ID;
            
            for(int k = classStart; k < classEnd; ++k){
                if(tmpID != 0){
                    timeTable[k][classDay].ID = countID;
                    timeTable[k][classDay].conflict = true;
                }
                else timeTable[k][classDay].ID = countID;
            }
          

            if(tmpID != 0){
                for(int l = 0; l < 7; ++l){
                    for(int k = 0; k < 17; ++k){
                        if(timeTable[k][l].ID == tmpID){
                            timeTable[k][l].ID = countID;
                            timeTable[k][l].conflict = true;
                        }
                    }
                }
            }
        
        }
        tmpID = 0;
        countID++;
        /*for(int i = 0; i < 17; ++i){
            for(int j = 0; j < 7; ++j)
                cout << timeTable[i][j].ID << " ";
            cout << endl;
        }
        cout << "--------" << endl;*/
        
    }
    
    /*for(int i = 0; i < 17; ++i){
            for(int j = 0; j < 7; ++j)
                cout << timeTable[i][j].ID << " ";
            cout << endl;
        }*/

   vector<int> Num;

    for(int j = 0; j < 17; ++j){
        for(int i = 0; i < 7; ++i){
            if(timeTable[j][i].conflict == true)
                Num.push_back(timeTable[j][i].ID);
        }
    }

    sort(Num.begin(), Num.end());
    
    if(Num.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    
    int count = 1;
    
    for(int i = 0; i < Num.size()-1; ++i)
        if(Num[i] != Num[i+1])
            count++;
 
    cout << count << endl;
    return 0;
}


