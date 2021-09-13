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

//#define MEDIANFINDER

#ifdef MEDIANFINDER
using namespace std;
class MedianFinder {
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        //����ż����
        if (_largeQueue.size() == _smallQueue.size()) {
            _smallQueue.push(num);
            int top = _smallQueue.top();
            _smallQueue.pop();
            _largeQueue.push(-top);
        } else {
            _largeQueue.push(-num);
            int top = _largeQueue.top();
            _largeQueue.pop();
            _smallQueue.push(-top);
        }
    }

    double findMedian()
    {
        if (_largeQueue.size() == _smallQueue.size()) {
            return ((double)(-_largeQueue.top()) + _smallQueue.top()) / 2.0;
        } else {
            return -_largeQueue.top();
        }
    }
private:
    priority_queue<int> _largeQueue;//�ϴ������Сͷ��(����)
    priority_queue<int> _smallQueue;//��С��������ͷ��
};

int main(int argc, char** argv)
{
    MedianFinder finder;
    //finder.addNum(1);
    finder.addNum(2);
    finder.addNum(3);
    double median = finder.findMedian();
    printf("MedianFinder:%f\n", median);

    getchar();
    return 0;
}
#endif // MEDIANFINDER

