#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <stack>
#include <vector>

/*
�ҳ��������֮��Ϊ n �� k ��������ϡ������ֻ������ 1 - 9 ��������������ÿ������в������ظ������֡�
*/
using namespace std;

int sum3;
vector<int> path3;
vector<vector<int>> result3;

void backtrace3(int n, int k, int startIdx)
{
    //��֦��ʣ��������
    if (sum3 > n) {
        return;
    }
    //��ֹ����
    if (path3.size() >= k) {
        if (sum3 == n) {
            result3.push_back(path3);
        }
        return;
    }
    //�ݹ�
    for (int idx = startIdx; idx <= 9; idx++) {
        sum3 += idx;
        path3.push_back(idx);
        backtrace3(n, k, idx + 1);
        path3.pop_back();
        sum3 -= idx;
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    sum3 = 0;
    path3.clear();
    result3.clear();
    backtrace3(n, k, 1);
    return result3;
}

//#define COMBINE_SUM
#ifdef COMBINE_SUM
int main(int argc, char** argv)
{
    int n = 7;
    int k = 3;
    vector<vector<int>> result = combinationSum3(n, k);
    for (auto vec : result) {
        for (auto num : vec) {
            printf("%d\t", num);
        }
        printf("\n");
    }

    getchar();
    return 0;
}
#endif // COMBINE_SUM
