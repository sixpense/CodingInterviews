// 051-数组中重复的数字
// 题目描述: 在一个长度为n的数组里的所有数字都在0 ~ n-1的范围内
// 数组中的某些数字是重复的, 但不知道有几个数字是重复的, 也不知道每个数字重复几次
// 请找出数组中任意一个重复的数字.
// 样例输入: 2, 3, 1, 0, 2, 5, 3
// 样例输出: 2





// 检查数据合法性

bool CheckValidity(int *numbers, int length) {
    if(numbers == NULL || length <= 0) {
        return false;
    }
    // 元素必须在[0, n - 1]的范围内
    for(int i = 0; i < length; i++) {
        if(numbers[i] < 0 || numbers[i] > length - 1) {
            return false;
        }
    }

    return true;
}


// 排序后判断重复
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        *duplication = -1;

        if(CheckValidity(numbers, length) == false) {
            return false;
        }

        sort(numbers, numbers + length);

        int i = 0;
        bool isDup = false;
        *duplication = -1;

        for(i = 0; i < length - 1; i++) {
            if(numbers[i] == numbers[i + 1]) {
                isDup = true;
                *duplication = numbers[i];
                break;
            }
        }
        return isDup;
    }
};

// 使用hashtable哈希法优化查找效率
class Solution_Hashtable {
public:
    // Parameters:
    //      numbers:    an array of integers
    //      length:     the length of array numbers
    //      duplication:(Output) the duplicated number in the array number
    //      Return value: true if the input is valid, and there are some duplications in 
    //                      the array number otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        *duplication = -1;
        if(CheckValidity(numbers, length) == false) {
            return false;
        }

        set<int> s;
        bool isDup = false;
        *duplication = -1;
        for(int i = 0; i < length; i++) {
            if(s.count(numbers[i]) == 1) {
                isDup = true;
                *duplication = numbers[i];
                break;
            }
            s.insert(numbers[i]);
        }
        return isDup;
    }
};

// 标识数组法

class Solution_Array {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        *duplication = -1;

        if(CheckValidity(numbers, length) == false) {
            return false;
        }

        int flags[length];
        menset(flags, 0, sizeof(flags));
        for(int i = 0; i < length; i++) {
            if(flags[numbers[i] != 0]) {
                *duplication = numbers[i];
                return true;
            }
            else {
                flags[numbers[i]] = 1;
            }
        }
        return false;
    }
};

// 符号位标识法
// 数组中元素大小都在[0, n) 区间中,那么符号位是无关紧要的, 可以拿符号位当成标识位

#define SET_SYMBOL_BIT(num) ((num) |= (1 << 31))                     // 设置符号位为1
#define GET_ORIGIN_NUM(num) ((num) & (~(1 << 31)))                  // 获取到源数据
#define GET_SYMBOL_BIT(num) (((num) >> 31) & 1)                     // 获取符号位(标识)

class Solution_Symbol {
public:
    // 对于每一个数据numbers[i], 其源数据origin = GET_ORIGIN_NUM(numbers[i])的标识存储在
    // numbers[origin]的符号位, 判断其标识是否为1即可
    bool duplicate(int numbers[], int length, int* duplication) {
        *duplication = -1;

        if(CheckValidity(numbers, length) == false) {
            return false;
        }
        for(int i = 0; i < length; i++) {
            // 当前数字numbers[i]的标识即是numbers[numbers[i]]的符号位
            if(GET_SYMBOL_BIT(numbers[GET_ORIGIN_NUM(numbers[i])]) == 1) {
                *duplication = GET_ORIGIN_NUM(numbers[i]);
                return true;
            }
            else {
                SET_SYMBOL_BIT(numbers[GET_ORIGIN_NUM(numbers[i])]);
            }
        }
        return false;
    }
};

// 固定偏移法
// 采用类似移码的方法, 让书记加上一个固定的偏移量, 即可以标识数据又不损坏数据

class Solution_Offset {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        *duplication = -1;
        if(CheckValidity(numbers, length) == false) {
            return false;
        }

        for(int i = 0; i < length; i++) {
            if(numbers[numbers[i] % length] >= length) {
                *duplication = numbers[i] % length;
                return true;
            }
            else {
                numbers[numbers[i] % length] += length;
            }
        }
        return false;
    }
};

// 将元素放在自己该在的位置

class Solution_Location {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        *duplication = -1;
        if(CheckValidity(numbers, length) == false) {
            return false;
        }

        for(int i = 0; i < length; i++) {
            while(numbers[i] != i) {
                if(numbers[i] == numbers[numbers[i]]) {
                    *duplication = numbers[i];
                    return true;
                }
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return false;
    }
};
