#include <iostream>
using namespace std;
#include <fstream>

int main(){
    ofstream input;
    input.open("input2.txt",ios::in);

    const int num = 10000;
    int m = rand()%1 + 1;
    int same = rand()%10 + 1;
    int q = rand()%10 + 1;
    input << m << " " << same << " " << same <<  " " << q << endl;
    for(int i=0;i<m;i++){
        for(int j =0 ;j<same; j++){
            input << rand()%50 << " ";
        }
        input << endl;
    }
    for(int i=0;i<same;i++){
        for(int j =0 ;j<q; j++){
            input << rand()%50 << " ";
        }
        input << endl;
    }
    input << endl;
    
}