#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
*/
using namespace std;
int maxSubArray(vector<int>& nums)
{
    int max_sum = INT_MIN;
    int cur_sum = 0;
    for (int idx = 0; idx < nums.size(); idx++) {
        cur_sum += nums[idx];
        max_sum = max(max_sum, cur_sum);
        if (cur_sum <= 0) {
            cur_sum = 0;
        }
    }
    return max_sum;
}

//#define MAX_SUB_ARRAY
#ifdef MAX_SUB_ARRAY
int main(int argc, char** argv)
{
    vector<int> nums{ -2,-1,-3,4,-1,2,1,-5,4 };
    //vector<int> nums{ -1 };
    int sum = maxSubArray(nums);
    printf("maxSubArray:%d\n", sum);

    getchar();
    return 0;
}
#endif // MAX_SUB_ARRAY
