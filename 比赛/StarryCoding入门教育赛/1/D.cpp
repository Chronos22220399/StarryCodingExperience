// MARK: - P161 环形密码
#include <iostream>
#include <string>
using namespace std;

int main(){
    int T, n; cin >> T;
    while(T--){
        cin >> n;
        string str1, str2;
        cin >> str1 >> str2;
        int flag = 0;
        for(int i = 0; i < n; ++i){
            string pre, end;
            pre = str2.substr(i, n-i);
            end = str2.substr(0, i);
            if(str1 == pre + end){
                flag = 1;
            }
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
