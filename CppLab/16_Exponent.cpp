#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

/*
ʵ�� pow(x, n) �������� x �� n ���ݺ���������xn��������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣
*/

//#define EXPONENT

#ifdef EXPONENT
using namespace std;

double myPow(double x, int n)
{
    if (abs(x - 0.0) < DBL_EPSILON) return 1;

    if (n == 0) return 1;
    if (n == 1) return x;
    if (n == -1) return 1 / x;

    //����Դ�nΪ������ż��
    if (n & 0x01) {
        return myPow(x * x, n >> 1) * x;
    } else {
        return myPow(x * x, n >> 1);
    }
}

int main(int argc, char** argv)
{
    //printf("x:%.2f e:%d weiht:%.2f\n", 12.0, 2, myPow(12.0, 2));
    //printf("x:%.2f e:%d weiht:%.2f\n", 2.0, 5, myPow(2.0, 5));
    printf("x:%.2f e:%d weiht:%.2f\n", 1.0, -2147483648, myPow(1.0, -2147483648));

    getchar();
    return 0;
}
#endif // EXPONENT
