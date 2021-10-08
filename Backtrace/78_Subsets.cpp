#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <stack>
#include <vector>

/*
����һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����
�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��
*/
using namespace std;

vector<int> subsetPath;
vector<vector<int>> subsetResult;
void subsetsBackbtrace(vector<int>& nums, int startIdx)
{
    //������нڵ�
    subsetResult.push_back(subsetPath);
    //��ֹ�������Բ���
    if (nums.size() <= startIdx) {
        return;
    }
    //�ݹ�
    for (int idx = startIdx; idx < nums.size(); idx++) {
        subsetPath.push_back(nums[idx]);
        subsetsBackbtrace(nums, idx + 1);
        subsetPath.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums)
{
    subsetResult.clear();
    subsetPath.clear();
    subsetsBackbtrace(nums, 0);
    return subsetResult;
}

//#define SUBSETS
#ifdef SUBSETS
int main(int argc, char** argv)
{
    vector<int> nums{ 1, 2, 3 };
    vector<vector<int>> subsetResult = subsets(nums);
    for (auto vec : subsetResult) {
        for (auto num : vec) {
            printf("%d\t", num);
        }
        printf("\n");
    }

    getchar();
    return 0;
}
#endif // SUBSETS
