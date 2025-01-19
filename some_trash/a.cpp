#include <iostream>

using namespace std;


int func() {
    return 102;
}

int big_massive[10'000'000];

const int cont_x = 23;

int rew;

int main(int argc, const char** argv) {

    int x;
    


    int massive[1000];
    // int another_big_massive[10'000'000];

    cout << "func: " << (void *) &func << endl; 
    cout << "big mas global: " << (int *) big_massive << endl; 
    // cout << "big mas main: " << (int *) another_big_massive << endl; 
    cout << "x: " << (int *) &x << endl; 
    cout << "const : " << (int *) &cont_x << endl; 
    cout << "unitilized: " << (int *) &rew << endl; 

    getchar();

    return 0;
}