#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
����һ�������� n��������Ϊ���������������ĺͣ���ʹ��Щ�����ĳ˻���󻯡� ��������Ի�õ����˻���
*/
using namespace std;

int integerBreak(int n)
{
    vector<int> dp(n + 1, 0);
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        }
    }
    return dp[n];
}

//#define INTEGER_BREAK
#ifdef INTEGER_BREAK
int main(int argc, char** argv)
{
    int brk = 10;
    printf("integerBreak:%d=>%d\n", 10, integerBreak(10));
    
    getchar();
    return 0;
}
#endif // INTEGER_BREAK
