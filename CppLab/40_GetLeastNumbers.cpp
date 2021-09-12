#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>

/*
������������ arr ���ҳ�������С�� k ������
���磬����4��5��1��6��2��7��3��8��8�����֣�����С��4��������1��2��3��4��
*/

#define GETLEASTNUMBERS

#ifdef GETLEASTNUMBERS
using namespace std;

//��ͷ��
vector<int> getLeastNumbers(vector<int>& arr, int k)
{
    vector<int> ret;
    if (arr.size() == 0 || k <= 0) return ret;
    //�����ͷ����
    priority_queue<int> queue;
    for (size_t idx = 0; idx < arr.size(); idx++) {
        if (queue.size() < k) {
            queue.push(arr[idx]);
            continue;
        }
        int max = queue.top();
        if (arr[idx] < max) {
            queue.pop();
            queue.push(arr[idx]);
        }
    }
    //���뵽vector<int>
    while (!queue.empty()) {
        ret.push_back(queue.top());
        queue.pop();
    }
    return ret;
}

int main(int argc, char** argv)
{
    vector<int> vec{3, 2, 1};
    int k = 2;
    vector<int> ret = getLeastNumbers(vec, k);
    for_each(ret.begin(), ret.end(), [](int val) {printf("%d\t", val); });

    getchar();
    return 0;
}
#endif // GETLEASTNUMBERS

