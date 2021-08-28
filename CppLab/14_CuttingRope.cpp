#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

/*
����һ������Ϊ n �����ӣ�������Ӽ����������ȵ� m �Σ�m��n����������n>1����m>1����ÿ�����ӵĳ��ȼ�Ϊ k[0],k[1]...k[m-1] ������ k[0]*k[1]*...*k[m-1] ���ܵ����˻��Ƕ��٣����磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��
*/

//#define CUTTINGROPE

#ifdef CUTTINGROPE
using namespace std;

int cuttingRope(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n == 3) return 2;

    int* products = new int[n + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;
    for (int len = 4; len <= n; len++) {
        max = 0;
        for (int hlen = 1; hlen <= len / 2; hlen++) {
            int product = products[hlen] * products[len - hlen];
            if (max < product) {
                max = product;
            }
        }
        products[len] = max;
    }

    max = products[n];
    delete[] products;
    return max;
}

int main(int argc, char** argv)
{
    printf("len:%d max:%d\n", 5, cuttingRope(5));
    printf("len:%d max:%d\n", 10, cuttingRope(10));
    printf("len:%d max:%d\n", 15, cuttingRope(15));
    printf("len:%d max:%d\n", 100, cuttingRope(100));

    getchar();
    return 0;
}
#endif // CUTTINGROPE
