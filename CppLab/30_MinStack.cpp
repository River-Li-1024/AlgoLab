#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

/*
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص� min �����ڸ�ջ�У����� min��push �� pop ��ʱ�临�Ӷȶ��� O(1)��
*/

//#define MINSTACK

#ifdef MINSTACK
using namespace std;

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int x)
    {
        m_data.push(x);
        int tmin = x;
        if (m_mins.size() > 0) {
            int cmin = m_mins.top();
            tmin = (int)std::min(x, cmin);
        }
        m_mins.push(tmin);
    }

    void pop()
    {
        m_data.pop();
        m_mins.pop();
    }

    int top()
    {
        if (m_data.size() > 0) {
            return m_data.top();
        } else {
            return INT_MAX;
        }
    }

    int min()
    {
        if (m_mins.size() > 0) {
            return m_mins.top();
        } else {
            return INT_MAX;
        }
    }
private:
    stack<int> m_data;
    stack<int> m_mins;
};

int main(int argc, char** argv)
{
    MinStack* obj = new MinStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(0);
    obj->push(5);
    obj->push(6);
    obj->pop();
    int top = obj->top();
    int min = obj->min();
    printf("top:%d\n", top);
    printf("min:%d\n", min);

    getchar();
    return 0;
}
#endif // MINSTACK
