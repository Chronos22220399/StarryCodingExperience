// MARK: - P159 ASCII码
#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    for(auto &i : str){
        cout << int(i) << " ";
    }
    return 0;
}
