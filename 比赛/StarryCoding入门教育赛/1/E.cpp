// MARK: - P163 最长公共子前缀
#include <iostream>
#include <string>
using namespace std;

int main(){
    int T, n, _n; cin >> T;
    while(T--){
        cin >> n; _n = n;
        string s1, s2;
        int maxCL;
        while(n--){
            cin >> s2;
            if(n == _n-1){
                maxCL = s2.length();
            } else {
                int index = 0;
                int length = 0;
                while(index < maxCL){
                    if(s1[index] != s2[index++]) {
                        break;
                    }
                    else
                        length ++;
                }
                maxCL = min(length, maxCL);
            }
            s1 = s2;
        }
        cout << maxCL << endl;
    }
    return 0;
}
