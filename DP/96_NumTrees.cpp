#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
����һ������ n ����ǡ�� n ���ڵ�����ҽڵ�ֵ�� 1 �� n ������ͬ�� ���������� �ж����֣�������������Ķ�����������������
*/
using namespace std;
int numTrees(int n)
{
    if (n <= 0) return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;//dp[0]Ҳ��������
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

//#define INTEGER_BREAK
#ifdef INTEGER_BREAK
int main(int argc, char** argv)
{
    printf("numTrees:%d=>%d\n", 3, numTrees(3));
    
    getchar();
    return 0;
}
#endif // INTEGER_BREAK
