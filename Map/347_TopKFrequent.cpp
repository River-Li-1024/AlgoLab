#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <deque>
#include <vector>
#include <queue>
#include <unordered_map>

/*
ǰ K ����ƵԪ��
*/

using namespace std;
//�Զ���Сͷ�ѣ�priority_queueĬ��Ϊ��ͷ��
static bool cmp(pair<int, int>& left, pair<int, int>& right)
{
    return left.second > right.second;
}

vector<int> topKFrequent(vector<int>& nums, int k)
{
    vector<int> ret;
    //���浽�ֵ�map��ͳ�Ƴ��ִ���
    unordered_map<int, int> map;
    for (auto num : nums) {
        map[num]++;
    }
    //��Сͷ�Ѳ���ǰk��
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> queue(cmp);
    for (auto pair : map) {
        if (queue.size() >= k) {
            if (queue.top().second < pair.second) {
                queue.pop();
                queue.push({ pair.first, pair.second });
            }
        } else {
            queue.push({pair.first, pair.second});
        }
    }
    //ת��λvector���
    while (!queue.empty()) {
        ret.push_back(queue.top().first);
        queue.pop();
    }
    return ret;
}

//#define TOPK_FREQUENT
#ifdef TOPK_FREQUENT
int main(int argc, char** argv)
{
    vector<int> nums{ 1,1,1,2,2,3 };
    int k = 2;
    vector<int> ret = topKFrequent(nums, k);
    for (auto num : ret) {
        printf("%d\t", num);
    }

    getchar();
    return 0;
}
#endif // TOPK_FREQUENT
