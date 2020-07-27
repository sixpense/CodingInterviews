// 053-正则表达式匹配
// 请实现一个函数用来匹配包括'.'和"的正则表达式.
// 模式中'.'表示任意一个字符, "表示它前面的字符可以出现任意次.


// 解题思路:
// 1. 当两个字符串都为空时候, 返回true
// 2. 当第一个字符串不为空, 第二个字符串为空, 返回false.
//    如果第一个字符串为空, 第二个字符串不为空, 由于'*'之前可能出现的元素为0次, 所以有可能
//    匹配成功
// 开始匹配第一个字符:
// 3. pattern下一个字符不为'*':
//    如果匹配成功, 继续匹配下一个; 包含pattern当前字符为'.', 同时str的当前字符不为'\0'
//    如果匹配失败, 直接返回false;
// 4. pattern下一个字符为'*':
//    当'*'匹配0个字符时, str当前字符不变, pattern当前字符后移两位, 跳过'*'符号
//    当'*'匹配一个或者多个字符时, str当前字符移向下一个, pattern当前字符不变.
//


class Solution {
public:
    bool match(char* str, char* pattern) {
        if(*str == '\0' && *pattern == '\0') 
            return true;
        if(*str != '\0' && *pattern == '\0')
            return false;
        if(*(pattern+1) != '*') {
            if(*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str+1, pattern+1);
            else
                return false;
        }
        else {
            if(*str == *pattern || (*str != '\0' && *pattern == '.')) {
                return match(str, pattern+2) || match(str+1, pattern);          // 匹配0个, 或者按照正常匹配
            }
            else {
                return match(str, pattern+2);
            }
        }
    }
};

// 动态规划求解

class Solution_Dynamic_Programming {
public:
    bool match(string s, string p) {
        // f[i][j]: if s[0, ... , i-1] matches p[0, ... , j-1]
        // if p[j - 1] != '*'
        //              f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
        // if p[j - 1] == '*', denote p[j - 2] with x
        //              f[i][j] is true iff any of the following is true
        //              1) "x*" repeats 0 thime and matches empty: f[i][j - 2]
        //              2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i
        //              - 1][j]
        // '.' matches any single character
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m+1, vector<bool>(n+1, false));

        f[0][0] = true;
        for(int i = 1; i <= m; i++) {
            f[i][0] = false;
        }
        for(int j = 1; j <= n; j++) {
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j - 1] != '*') {
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                }
                else {
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
                }
            }
        }
        return f[m][n];
    }
};
