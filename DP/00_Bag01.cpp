#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
01����
*/
using namespace std;

//��ά����
int bag01(vector<int> weight, vector<int> value, int maxweight)
{
    int bagSize = weight.size();
    if (bagSize <= 0) return 0;

    vector<vector<int>> dp(bagSize, vector<int>(maxweight + 1, 0));
    //��ʼ��0����Ʒ��Ӧ��dp
    for (int idx = weight[0]; idx < maxweight; idx++) {
        dp[0][idx] = value[0];
    }
    //��ʼ���ƣ��ȱ�����Ʒ���ٱ�������
    for (int itemIdx = 1; itemIdx < bagSize; itemIdx++) {
        for (int weightIdx = 0; weightIdx <= maxweight; weightIdx++) {
            if (weight[itemIdx] > weightIdx) {
                dp[itemIdx][weightIdx] = dp[itemIdx - 1][weightIdx];
            } else {
                dp[itemIdx][weightIdx] = max(dp[itemIdx - 1][weightIdx], dp[itemIdx - 1][weightIdx - weight[itemIdx]] + value[itemIdx]);
            }
        }
    }
    return dp[bagSize - 1][maxweight];
}

//һά����
int bag01(vector<int> weight, vector<int> value, int maxweight)
{
    int bagSize = weight.size();
    if (bagSize <= 0) return 0;

    vector<vector<int>> dp(bagSize, vector<int>(maxweight + 1, 0));
    //��ʼ��0����Ʒ��Ӧ��dp
    for (int idx = weight[0]; idx < maxweight; idx++) {
        dp[0][idx] = value[0];
    }
    //��ʼ���ƣ��ȱ�����Ʒ���ٱ�������
    for (int itemIdx = 1; itemIdx < bagSize; itemIdx++) {
        for (int weightIdx = 0; weightIdx <= maxweight; weightIdx++) {
            if (weight[itemIdx] > weightIdx) {
                dp[itemIdx][weightIdx] = dp[itemIdx - 1][weightIdx];
            } else {
                dp[itemIdx][weightIdx] = max(dp[itemIdx - 1][weightIdx], dp[itemIdx - 1][weightIdx - weight[itemIdx]] + value[itemIdx]);
            }
        }
    }
    return dp[bagSize - 1][maxweight];
}

#define BAG_01
#ifdef BAG_01
int main(int argc, char** argv)
{
    vector<int> weight{ 1, 3, 4 };
    vector<int> value{ 15, 20, 30 };
    int maxWeight = 4;
    int maxbag01 = bag01(weight, value, maxWeight);
    printf("bag01:%d\n", maxbag01);

    getchar();
    return 0;
}
#endif // BAG_01
