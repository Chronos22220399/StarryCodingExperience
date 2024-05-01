// MARK: - P162 查名字
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1 = "eriktse";
    string s2;
    int T;  cin >> T;
    int n;
    while(T--){
        cin >> n;
        int flag = 0;
        while(n--){
            cin >> s2;
            for(auto &i : s2){
                if(i >= 65 && i <= 90)
                    i += 32;
            }
            if(s1 == s2)
                flag = 1;
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
