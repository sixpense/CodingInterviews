// 021-包含min函数的栈
//

class Solution {
public:
    void push(int value) {
        this->m_data.push(value);

        if(this->m_min.size() == 0 || value < this->m_min.top()) {
            this->m_min.push(value);
        }
        else {
            this->m_min.push(this->m_min.top());
        }
    }

    void pop() {
        assert(this->m_data.size() > 0 && this->m_min.size() > 0);

        this->m_data.pop();
        this->m_min.pop();
    }

    int top() {
        if(this->m_data.empty() == true) {
            return 0;
        }
        return this->m_min.top();
    }
protected:
    stack<int> m_data;
    stack<int> m_min;
}
