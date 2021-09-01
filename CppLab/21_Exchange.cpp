#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

/*
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ����������λ�������ǰ�벿�֣�
����ż��λ������ĺ�벿�֡�
*/

//#define EXCHANGE

#ifdef EXCHANGE
using namespace std;

vector<int> exchange(vector<int>& nums)
{
    if (nums.size() <= 1) return nums;

    int left = 0, right = nums.size() - 1;
    while (left < right) {
        while (left < right && (nums[left] & 0x01) != 0) {
            left++;
        }
        while (left < right && (nums[right] & 0x01) == 0) {
            right--;
        }
        if (left < right) {
            swap(nums[left], nums[right]);
        }
    }
    return nums;
}

typedef bool (*ExchangeFun)(int val);
vector<int> exchange2(vector<int>& nums, ExchangeFun fun)
{
    if (nums.size() <= 1) return nums;

    int left = 0, right = nums.size() - 1;
    while (left < right) {
        while (left < right && fun(nums[left])) {
            left++;
        }
        while (left < right && !fun(nums[right])) {
            right--;
        }
        if (left < right) {
            swap(nums[left], nums[right]);
        }
    }
    return nums;
}

int main(int argc, char** argv)
{
    {
        vector<int> vec{ 1, 2, 3, 4, 5, 6, 7 };
        exchange(vec);
        for_each(vec.begin(), vec.end(), [](int val) {printf("%d\t", val); });
        printf("\n");
    }

    {
        vector<int> vec{ 1, 2, 3, 4, 5, 6, 7 };
        ExchangeFun fun = [](int val)->bool {
            return (val & 0x01) != 0;
        };
        exchange2(vec, fun);
        for_each(vec.begin(), vec.end(), [](int val) {printf("%d\t", val); });
        printf("\n");
    }


    getchar();
    return 0;
}
#endif // EXCHANGE
