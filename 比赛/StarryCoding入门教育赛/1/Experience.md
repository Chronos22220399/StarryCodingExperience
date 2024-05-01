# StarryCoding 入门教育赛 1

## A: ASCII 码

### 题解

```cpp
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
```

### 解析

如果使用的字符数组的话要注意数组的长度大约要在 1150 之上（可能可以低一点），虽然说是 `一行输入一个字符串𝑆(1≤∣𝑆∣≤1000)*S*(1≤∣*S*∣≤1000)。`，但实际长度比 1000 要大一些，所以会卡住一个结果

> 这里最好的做法是使用 string，因为不用管字符串的长度



## B: 字符串检验

### 题解

```cpp
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
```

### 解析

使用字符串查找函数对子穿进行查找即可

### 知识点

#### 字符串查找函数：

1. `size_t find(const string& str, size_t pos = 0) const;`
2. `size_t find(const char *s, size_t pos = 0) const;`

> 查找成功会返回子串在母串里的第一个字符的下标，未找到则返回 string::npos

其中：pos 表示起始查找位置的下表



## C: 查名字

### 题解

```cpp
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
```

### 解析

匹配的串为小写，则将被匹配的串的大写字符都小写后在匹配即可

### 知识点

字符 a - z 对应范围 [97 - 122]

字符 A - Z 对应范围为 [65 - 90]

#### 字符串 cmp

`string`可以用 `==`运算符直接比较

也可以使用对应的比较函数进行比较



## D: 环型密码

### 题解

```cpp
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
```

### 解析

本题的环形就是约瑟夫环

可以采取两种解法：

#### 1. 暴力枚举

外层将环形串匹配的初始下标进行枚举，内层则按照环形队列的方式直接与匹配串匹配即可

##### 时间复杂度为 O(n^2)

##### 代码：

```cpp
string s1, s2;
int flag;
for(int i = 0; i < len; ++i){
  flag = 1;
  for(int j = 0; j < len; ++j){
    if(s1[(i+j)%len] != s2[j])
      flag = 0;
  }
  if(flag = 1){
    cout << "YES" << endl;
    break;
  }
}
if(!flag)
  cout << "NO" << endl;

```

#### 2. 使用通过枚举被匹配串，然后将被匹配串按序拼接后与子串相比较即可

可以将环形串这样看，对于一个环形串，可以将其分为前后两部分，前面一部分由子串的靠后的串越界后取模得到，后面一部分的串由子串靠前的串偏移后得到，因此我们只需要枚举这个分割前后两部分的分割点即可

##### 例如：

子串：`StarryCoding`

被匹配串：`dingStarryCo`

被匹配串由子串的首字母向左偏移 4 个字符后得到，因此分割点为 4

将 0 - 3 的子串和 4 - len-1 的子串拼接即可（前者在后，后者在前）

##### 时间复杂度：O(n^2)

题解采用的此方法



## E: 最长公共前缀

### 题解

```cpp
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
```

### 解析

本题匹配的是公共前缀，从上到下依次匹配公共前缀即可，每一次匹配到的公共前缀必然不长于前一次匹配到的公共前缀的长度，因此以 maxCL 作为最长公共前缀的长度，将前一个字符串 s1 和当前字符串 s2 的前 maxCL 个字符进行比较（直接枚举）即可，得到的新的长度用来更新 maxCL（取更小的那个值）

> 注意在 `s1[index] != s2[index++]` 这一段的执行顺序是从左到右，因此 `index++` 要放在最右边

### 本次踩坑

将 `s1[index] != s2[index++]` 写成 `s1[index++] != s2[index++]`，从而导致字符串匹配出错。下次需注意