// 029-数组中出现次数超过一半的数字
// 基于Partition函数的$O(n)$的查找第K大的数
// 数组中有一个数字出现的次数超过了数组长度的一半, 那么我们把这个数组排序, 那么排序之后位于
// 数组中间的那个数字就是出现次数超过数组长度一半的数字.
//

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0) {
            return 0;
        }
        else if(numbers.size() == 1) {
            return numbers[0];
        }

        int num = FindKth(numbers, 0, numbers.size() - 1, numbers.size()/2);

        if(CheckMoerThanHalf(numbers, num) == true) {
            return num;
        }
        else {
            return 0;
        }
    }
    /**
     * [Partition 快速排序的划分函数, 返回枢轴在排序的数组中应该所处的位置]
     * @Author sixpence
     * @DateTime 2020-04-22T00:08:34+0800
     * @param numbers                           [待划分数组]
     * @param left                              [待划分数据的起始位置]
     * @param right                             [带划分数据的结束位置]
     * @return                                  [返回枢轴在排序后数组中应该在的位置]
     */
    int Partition(vector<int> &numbers, int left, int right) {
        int i = left, j= right;

        int pivotIndex = left;
        int pivotNum = numbers[pivotIndex];

        debug <<"pivotNum = " <<pivotNum <<endl;
        while(i < j) {
            while(i < j && numbers[j] >= pivotNum) {
                debug <<"[" <<i <<"," <<j <<"]" <<numbers[j] <<" >= pivotNum" <<endl;
                j--;
            }
            debug <<"now we find i = " <<i <<", pos" <<j <<", num = " <<numbers[j] <<" < " <<pivotNum <<endl;
            // swap(numbers[i], numbers[j]);
            numbers[i] = numbers[j];

            while(i < j && numbers[i] <= pivotNum) {
                debug <<"[" <<i <<", " <<j <<"] " <<numbers[i] <<" <= " <<pivotNum <<endl;
                i++;
            }

            debug <<"now we find j = " <<i <<", pos" <<j <<", num = " <<numbers[i] <<" > " <<pivotNum <<endl;
            // swap(numbers[i], numbers[j]);
            numbers[j] = numbers[i];
        }
        numbers[i] = pivotNum;
#ifdef __tmian
        debug <<pivotNum <<" 's post is" <<i <<endl;
        for(int pos = left; pos <= right, pos++) {
            debug <<numbers[pos] <<" ";
        }
        debug <<endl;
#endif
        return i;

    }

    /**
     * [FindKth 查找数组中第K大的元素}
     * @Author
     * @DateTime
     * @param       numbers                 [待查找元素所在的数组]
     * @param       left                    [数据起始查找位置]
     * @param       right                   [数据终止位置]
     * @param       k                       [数组中第K大的元素]
     * @return                              [数组中第K大的元素值]
     */ 

    int FindKth(vector<int> &numbers, int left, int right, int k) {
        int res;
        int pivotIndex = left + 1;

        if(left == right) {
            debug <<"left == right " <<numbers[left] <<endl;
            return numbers[left];
        }
        pivotIndex = Partition(numbers, left, right);

        if(pivotIndex < k) {
            //第K大的在pivot之后,在[pivotIndex +1, right]之间查找
            debug <<"K is in [" <<pivotIndex + 1 <<", " <<right <<"]" <<endl;
            return FindKth(numbers, pivotIndex + 1, right, k);
        }
        else if(pivotIndex > k) {
            debug <<"K is in [" <<left <<", " <<pivotIndex - 1 <<"]" <<endl;
            return FindKth(numbers, left, pivotIndex - 1, k);
        }
        else {
            debug << "pivotIndex == k, " numbers[pivotIndex] <<endl;
            return numbers[pivotIndex];
        }

    }
    bool CheckMoerThanHalf(vector<int> numbers, int num) {
        int count = 0;
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers[i] == num) {
                count++;
            }
        }
        debug <<"num = " <<num <<", count = " <<count <<endl;

        if(count > numbers.size() / 2) {
            return true;
        }
        else {
            return false;
        }
    }
};



// 阵地攻守, 充分利用出现次数超过一半的条件

class Solution_3 {
public:
    int MortThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0) {
            return 0;
        }
        else if(numbers.size() == 1) {
            return numbers[0];
        }

        int num = numbers[0], count = 1;

        for(int i = 1; i < numbers.size(); i++) {
            if(numbers[i] == num) {
                count++;
            }
            else {
                count--;
            }

            dubug <<"numbers[i] = " <<numbers[i] <<", count = " <<count <<endl;
            if(count == 0) {
                num = numbers[i];
                count = 1;
            }
        }
        debug << "find num = " <<num <<endl;
        count = 0;
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers[i] == num) {
                count++;
            }
        }

        if(count > numbers.size() / 2) {
            debug <<"num = " <<num <<", count = " <<count <<endl;
            return num;
        }
        else {
            return 0;
        }
    }
};


// 使用STL的count函数统计某个值出现的次数

// template<class InputIterator, class T> inline siez_t count(InputIterator First, InputIterator Last, const T& Value)

// template<class _InIt, class _Pr> inline typename iterator_traits<_InIt>::difference_type count_if(_InIt _First, _InIt _Last, _Pr _Pred);

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0) {
            return 0;
        }
        for(int i = 0; i < numbers.size(); i++) {
            if(count(numbers.begin(), numbers.end(), numbers[i]) * 2 > numbers.size()) {
                return numbers[i];
            }
        }
        return 0;
    }
};


// 使用map来建立数字到出现次数的映射

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> hmap;     //建立数字到出现次数的映射

        int nsize = numbers.size();

        for(int i = 0; i < nsize; i++) {
            if(hmap.find(numbers[i]) != hmap.end()) {           // 用find函数来定位数据出现位置，它返回的一个迭代器，当数据出现时，它返回数据所在位置的迭代器，如果map中没有要查找的数据，它返回的迭代器等于end函数返回的迭代器
                hmap[numbers[i]] += 1;
            }
            else {
                hmap[numbers[i]] = 1;
            }
        }

        for(map<int, int>::iterator it = hmap.begin(); it != hmap.end(); ++it) {
            if(it->second * 2 > nsize) {                // it->first:   key
                return it->first;                       // it->second:  value
            }
        }
        return 0;
    }
}
