// 046不使用判断条件求1 + 2 + 3 + 4 +...
// 短路运算 0 && cout, 使条件为假值, 从而不执行输出语句

class Solution {
public:
    int SumRecursion(int n) {
        int ans = n;
        n && (ans += SumRecursion(n - 1));
        return ans;
    }
}

// 使用位运算来计算n * (n + 1) / 2
int Multi(int a, int b) {
    int res = 0;
    while(a != 0) {
        if((a & 1) != 0) {
            res += b;
        }
        a >>= 1;
        b <<= 1;
    }
}
