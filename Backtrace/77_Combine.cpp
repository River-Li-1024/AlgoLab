#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <stack>
#include <vector>

/*
������������ n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ�
*/
using namespace std;

vector<int> path;
vector<vector<int>> result;
void backtrace(int n, int k, int startIdx)
{
    //��ֹ����
    if (path.size() == k) {
        result.push_back(path);
        return;
    }
    //�ݹ�
    //��֦��ʣ��������

    for (int idx = startIdx; idx <= n - (k - path.size()) + 1; idx++) {
        path.push_back(idx);
        backtrace(n, k, idx + 1);
        path.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    path.clear();
    result.clear();
    backtrace(n, k, 1);
    return result;
}

//#define COMBINE
#ifdef COMBINE
int main(int argc, char** argv)
{
    int n = 4;
    int k = 2;
    vector<vector<int>> result = combine(n, k);
    for (auto vec : result) {
        for (auto num : vec) {
            printf("%d\t", num);
        }
        printf("\n");
    }

    getchar();
    return 0;
}
#endif // COMBINE
