#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <stack>
#include <vector>
#include <unordered_set>

/*
����һ���������� nums ���ҳ����������и������в�ͬ�ĵ��������У������������� ����������Ԫ�� ������԰� ����˳�� ���ش𰸡�
�����п��ܺ����ظ�Ԫ�أ����������������ȣ�Ҳ���������������е�һ�����������
*/
using namespace std;

vector<int> fspath;
vector<vector<int>> fsresult;
void findSubInternal(vector<int>& nums, int startIdx)
{
    //ͳ�ƽ��
    if (fspath.size() > 1) {
        fsresult.push_back(fspath);
    }
    //ȥ��
    unordered_set<int> used;
    //�ݹ�
    for (int idx = startIdx; idx < nums.size(); idx++) {
        //ͬһ���ڵ��µ�ͬ����ʹ�ù���Ԫ�ؾͲ�����ʹ����
        if (used.find(nums[idx]) != used.end()) {
            continue;
        }
        //��֦���ǵ������пɲ��ٿ���
        if (fspath.size() >= 1 && nums[idx] < fspath.back()) {
            continue;
        }
        used.insert(nums[idx]);
        fspath.push_back(nums[idx]);
        findSubInternal(nums, idx + 1);
        fspath.pop_back();
    }
}
vector<vector<int>> findSubsequences(vector<int>& nums)
{
    fspath.clear();
    fsresult.clear();
    findSubInternal(nums, 0);
    return fsresult;
}

#define FIND_SUB_SEQUENCE
#ifdef FIND_SUB_SEQUENCE
int main(int argc, char** argv)
{
    vector<int> nums{4, 6, 7, 7};
    vector<vector<int>> fsresult = findSubsequences(nums);
    for (auto vec : fsresult) {
        for (auto num : vec) {
            printf("%d\t", num);
        }
        printf("\n");
    }

    getchar();
    return 0;
}
#endif // FIND_SUB_SEQUENCE
