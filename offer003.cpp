// 003:二维数组的查找

#include <iostream>
#include <vector>

using namespace std;

class Solution_1 {
public:
    bool Find(vector<vector<int> > array, int target ) {
        int row = 0, col = 0, t = 0;
        bool isFound = false;

        for(int i = 0; i < array.size(); i++) {
            for(int j = 0; j < array.size(); j++ ) {
                if(false == isFound && target == array[i][j]) {
                    isFound = true;
                }
            }
        }
        return isFound;
    }
};


#define __main main
#define __tmain

class Solution {
public:
    bool Find(vector<vector<int> > array, int target) {
        bool res = false;
        int row = array.size();
        int col = array[0].size();

        for(int i = 0, j = col -1; (i >= 0 && i < row) && (j >= 0 && j < col);) {
            if(target == array[i][j]) {
                res = true;
                break;
            }
            else if(target < array[i][j]) {
# ifdef __tmain
                cout << target <<" < " <<array[i][j] << "turn left" <<endl;
# endif // __tmain
                j--;
            }
            else {
# ifdef __tmain
                cout << target <<" < " <<array[i][j] << " turn down" <<endl;
# endif // __tmain
                i++;
            }
        }
        return res;
    }
};

int __main() {
    int a1[] = { 1, 2, 8, 13 };
    int a2[] = { 2, 3, 9, 29 };
    int a3[] = { 5, 8, 28, 48 };
    int a4[] = { 7, 15, 33, 52 };

    vector<vector<int> > array;
    array.push_back(vector<int>(a1, a1+4));
    array.push_back(vector<int>(a2, a2+4));
    array.push_back(vector<int>(a3, a3+4));
    array.push_back(vector<int>(a4, a4+4));

    Solution solu;
    cout << solu.Find(array, 99)<< endl;
    return 0;
}
