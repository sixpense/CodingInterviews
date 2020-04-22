// 028 字符串的排列
// 输入一个字符串,按字典序打印出该字符串中字符的所以排列
// INPUT: abc
// OUTPUT: abc, acb, bac, bca, cab, cba

class Solution {
protected:
    vector<string> m_res;

public:
    void Permutation(string prefix, string str) {
        if(str.length() == 0) {
            m_res.clear();
        }
        else {
            for(int i = 0; i < str.length(); i++) {
                Permutation(prefix+str[i], str.substr(0, i) + str.substr(i+1, str.length()));
            }
        }
    }

    vector<string> Permutation(string s) {
        m_res.clear();
        if(s.empty() == true) {
            return m_res;
        }
        Permutation("", s);

        return m_res;
    }
}


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define dubug 0 && cout

#endif

class Solution_1 {
protected:
    vector<string> m_res;

public:
    vector<string> Permutation(string str) {
        m_res.clear();

        if(str.empty() == true) {
            return m_res;
        }
        PermutationRecursion(str, 0);
        
        sort(m_res.begin(), m_res.end());
        return m_res;
    }

    void PermutationRecursion(string str, int begin) {
        if(str[begin] == '\0') {
            debug << str <<endl;
            m_res.push_back(str);
        }
        else {
            for(int i = begin; str[i] != '\0'; i++) {
                if(!HasDuplicate(str, begin, i)) {
                    swap(str[i], str[begin]);
                    debug <<"swap " <<str[i] <<"(" <<i <<")" <<" and " <<str[begin] <<"(" <<begin <<")" <<endl;
                    PermutationRecursion(str, begin+1);
                    swap(str[i], str[begin]);
                }
            }
        }
    }
private:
    bool HasDuplicate(string& str, int k, int i) const {
        for(int p = k; p < i; p++) {
            if(str[p] == str[i])
                return true;
            return false;
        }
    }
};

int __tmain() {
    Solution_1 solu;
    solu.Permutation("abc");

    return 0;
}

// 使用STL
class Solution_2 {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.empty() == true) {
            return res;
        }
        sort(str.begin(), str.end());

        do {
            res.push_back(str);
            debug <<str <<endl;
        }while(next_permutation(str.begin(), str.end()));

        return res;
    }
}
