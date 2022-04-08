#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
�����������֮��Ĳ��ϸ���������͸���֮�佻�棬���������г�Ϊ �ڶ����� ����һ���������ڵĻ�����������������������һ��Ԫ�ػ��ߺ���������Ԫ�ص�����Ҳ�����ڶ����С�
������ ����ͨ����ԭʼ������ɾ��һЩ��Ҳ���Բ�ɾ����Ԫ������ã�ʣ�µ�Ԫ�ر�����ԭʼ˳��

����һ���������� nums ������ nums ����Ϊ �ڶ����� �� ������еĳ���
*/
using namespace std;
int wiggleMaxLength(vector<int>& nums)
{
    if (nums.size() <= 1) return nums.size();
    int length = 1;
    int diff = 0, lastdiff = 0;
    for (int idx = 1; idx < nums.size(); idx++) {
        diff = nums[idx] - nums[idx - 1];
        if ((diff > 0 && lastdiff <= 0) || (diff < 0 && lastdiff >= 0)) {
            length++;
            lastdiff = diff;
        }
    }
    return length;
}

//#define WIGGLE_MAX_LENGTH
#ifdef WIGGLE_MAX_LENGTH
int main(int argc, char** argv)
{
    vector<int> nums{ 1,17,5,10,13,15,10,5,16,8 };
    int length = wiggleMaxLength(nums);
    printf("wiggleMaxLength:%d\n", length);

    getchar();
    return 0;
}
#endif // WIGGLE_MAX_LENGTH
