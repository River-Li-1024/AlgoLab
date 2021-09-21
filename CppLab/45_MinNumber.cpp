#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>

/*
����һ���Ǹ��������飬����������������ƴ�������ų�һ������
��ӡ��ƴ�ӳ���������������С��һ����
*/

//#define MINNUMBER

#ifdef MINNUMBER
using namespace std;

static bool Compare(string& left, string& right)
{
    return (left + right) < (right + left);
}

string minNumber(vector<int>& nums)
{
    vector<string> strs;
    for (auto num : nums) {
        strs.push_back(to_string(num));
    }
    sort(strs.begin(), strs.end(), Compare);
    string ret;
    for (auto str : strs) {
        ret.append(str);
    }
    return ret;
}

int main(int argc, char** argv)
{
    vector<int> nums{ 3,30,34,5,9, 35, 0 };
    string ret = minNumber(nums);
    printf("minNumber:%s", ret.c_str());

    getchar();
    return 0;
}
#endif // MINNUMBER

