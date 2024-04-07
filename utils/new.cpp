#include <iostream>
using namespace std;
#include <fstream>

int main(){
    ofstream input;
    input.open("input3.txt",ios::in);

    const int num = 20;
    input << num << endl;
    // input << rand() % 9999 + 1 << endl;
    // int m = rand() % 50 + 1;
    // int same = rand() % 10 + 1;
    // int q = rand() % 50 + 1;
    // input << m << " " << same << " " << same <<  " " << q << endl;
    // int snakes[50];
    // int ladders[50];
    // for(int i = 0; i < 100; i++){
    //     if(i%2 == 0){
    //         snakes[i/2] = 10000 - 49*i;
    //     }else{
    //         ladders[(i-1)/2] = 49*i;
    //     }
    // }

    for(int i = 0; i < num; i++){
    
        input << rand()%10 << endl;
        for(int j = 0 ;j < num; j++){
            input << rand()%2 << " ";
        }
        input << endl;
    }
    // for(int i = 0; i < same; i++){
    //     for(int j = 0 ; j < q; j++){
    //         input << rand()%50 << " ";
    //     }
    //     input << endl;
    // }
    // for(int i = 0; i < 50; i++){
    //     input << ladders[i] << " " << 10000 - ladders[i]<< endl;
    // }
    // for(int i = 0; i < 50; i++){
    //     input << snakes[i] << " " << 10000 - snakes[i]<< endl;
    // }
    input << endl;
    
}