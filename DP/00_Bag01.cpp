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

int bag01(vector<int> weight, vector<int> value, int maxweight)
{
    vector<vector<int>> dp(weight.size(), vector<int>(maxweight, 0));
    //��ʼ��0����Ʒ��Ӧ��dp
    for (int idx = weight[0]; idx < maxweight; idx++) {
        dp[0][idx] = value[0];
    }
    //��ʼ���ƣ��ȱ�����Ʒ���ٱ�������
    for (int itemIdx = 0; itemIdx < weight.size(); itemIdx++) {





    }
    return 0;
}

#define BAG_01
#ifdef BAG_01
int main(int argc, char** argv)
{
    
    getchar();
    return 0;
}
#endif // BAG_01
