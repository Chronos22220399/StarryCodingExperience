// MARK: - P164 字符串检验
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1 = "starrystarry";
    string s2;
    int T;  cin >> T;
    while(T--){
        cin >> s2;
        if(s2.find(s1) == string::npos)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
