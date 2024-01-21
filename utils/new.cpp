#include <iostream>
using namespace std;
#include <fstream>

int main(){
    ofstream input;
    input.open("input4.txt",ios::in);

    const int num = 10000;
    input << num << endl;
    for(int i=0;i<num;i++){
        input << rand()%991919 + 1 << " ";
    }
    input << endl;
    
}