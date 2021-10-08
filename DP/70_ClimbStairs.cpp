#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
������
*/
using namespace std;

/*
������������¥�ݡ���Ҫ n ������ܵ���¥����
ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
*/
int climbStairs(int n)
{
    int dp[3] = {0, 1, 2};
    if (n <= 2) return dp[n];

    int sum = 0;
    for (int idx = 3; idx <= n; idx++) {
        sum = dp[2] + dp[1];
        dp[1] = dp[2];
        dp[2] = sum;
    }
    return dp[2];
}

/*
������������¥�ݡ���Ҫ n ������ܵ���¥����
ÿ��������� 1-m̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
*/
int climbStairs2(int n, int m)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i >= j) {
                dp[i] += dp[i - j];
            } else {
                break;
            }
        }
    }
    return dp[n];
}

//#define CLIMB_STAIRS
#ifdef CLIMB_STAIRS
int main(int argc, char** argv)
{
    {
        int stairs = climbStairs(5);
        printf("climbStairs %d:%d\n", 5, stairs);
    }

    {
        int stairs = climbStairs2(5, 2);
        printf("climbStairs2 %d/%d:%d\n", 5, 2, stairs);
    }
    getchar();
    return 0;
}
#endif // CLIMB_STAIRS
