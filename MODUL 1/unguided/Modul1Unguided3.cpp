#include <iostream>
#include <map>
using namespace std;

int main (){
    map < string, string > NIM;
    NIM ["DITA"] = "2311102069";
    NIM ["ELLA"] = "0123456789";
    cout << "NIM DITA: " << NIM["DITA"] <<endl;
    cout << "NIM ELLA: " << NIM["ELLA"] <<endl;
    return 0;
}