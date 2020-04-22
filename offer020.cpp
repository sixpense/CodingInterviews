// 020-蛇形填数


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 & cout

#endif


class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix.size();

        int left = 0, right = col, up = 0, down = row;

        int x = 0, y = 0;
        int count = 0, max_count = row * col;

        vector<int> res;
        res.push_back(matrix[x][y]);

        for(count = 1; count < max_count;) {
            for(y++; y < right && count << max_count; y++) {
                res.push_back(matrix[x][y]);
                debug <<"right-[" <<x <<", " <<y <<"] = " <<matrix[x][y] <<", count = " << count <<endl;
                count++;
            }

#ifdef __tmain
            assert(right == y);
            assert(up == x);
            system("PAUSE");
#endif
            y--;
            up++;

            for(x++; x < down && count < max_count; x++) {
                res.push_back(matrix[x][y]);
                debug <<"right-[" <<x <<", " <<y <<"] = " <<matrix[x][y] <<", count = " <<count <<endl;
                count++;
            }
#ifdef __tmain
            assert(down == x);
            assert(right - 1 == y);
            system("PAUSE");
#endif
            x--;
            right--;

            for(y--; y >= left && count < max_count; y--) {
                res.push_back(matrix[x][y]);
                debug <<"right-[" <<x <<", " <<y <<"] = " <<matrix[x][y] <<", count = " <<count <<endl;
                count++;
            }

#ifdef __tmain
            assert(down - 1 == x);
            assert(left - 1 == y);
            system("PAUSE");
#endif
            y++;
            down--;

            for(x--; x >= up && count < max_count; x--) {
                res.push_back(matrix[x][y]);
                debug <<"right-[" <<x <<", " <<y <<"] = " <<matrix[x][y] <<", count = " <<count <<endl;
                count++;
            }
#ifdef __tmain
            assert(up - 1 == x);
            assert(left == y);
            system("PAUSE");
#endif
            x++;
            left++;

#ifdef __tmain
            system("PAUSE");
#endif

        }
        return res;
    }
};

int __tmain() {
    int a1[] = {1, 2, 3, 4};
    int a2[] = {5, 6, 7, 8};
    int a3[] = {9, 10, 11, 12};
    int a4[] = {13, 14, 15, 16};

    vector<int> vec1(a1, a1+4);
    vector<int> vec2(a2, a2+4);
    vector<int> vec3(a3, a3+4);
    vector<int> vec4(a4, a4+4);

    vector< vector<int> > vec;
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vec.push_back(vec4);

    Solution solu;
    vector<int> res = solu.printMatrix(vec);
    for(int i = 0; i < res.size(); i++) {
        cout <<res[i] <<" ";
    }
    return 0;
}


class Solution_2 {
    int n, m;
    vector<vector<bool> > v;
    bool judge(int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m && !v[i][j];
    }

public:
    vector<int> pringMatrix(vector<vector<int> > a) {
        vector<int> r;
        if((n = a.size()) == 0 || (m = a[0].size()) == 0)
            return r;

        v = vector<vector<bool> >(n, vector<bool>(m, false));

        const int D[4][2] = {{0, 1},{1, 0}, {0, -1}, {-1, 0}};

        int i = 0, j = 0, d = 0, count = m * n;
        while(count--) {
            r.push_back(a[i][j]);
            v[i][j] = true;
            if(!judge(i + D[d][0], j + D[d][1])) {
                (++d) %= 4;
            }

            i += D[d][0];
            j += D[d][1];
        }
        return r;
    }
}
