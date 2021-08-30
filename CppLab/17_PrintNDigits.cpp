#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

/*
�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
*/

//#define PRINTNDIGITS

#ifdef PRINTNDIGITS
using namespace std;

vector<int> printNumbers(int n)
{
    if (n <= 0) {
        return vector<int>();
    }
    int maxNum = 0;
    if (n >= 8) {
        maxNum = INT32_MAX;
    } else {
        char *buffer = new char[n + 1];
        memset(buffer, '\0', n + 1);
        for (size_t idx = 0; idx < n; idx++) {
            buffer[idx] = '9';
        }
        maxNum = atoi(buffer);
    }

    vector<int> numbers;
    for (int idx = 1; idx <= maxNum; idx++) {
        numbers.push_back(idx);
    }
    return numbers;
}

int main(int argc, char** argv)
{
    {
        vector<int> numbers = printNumbers(2);
        for (int idx = 0; idx < numbers.size(); idx++) {
            printf("%d\t", numbers[idx]);
        }
        printf("\n");
    }

    /*{
        vector<int> numbers = printNumbers(33);
        for (int idx = 0; idx < numbers.size(); idx++) {
            printf("%d\t", numbers[idx]);
        }
        printf("\n");
    }*/

    getchar();
    return 0;
}
#endif // PRINTNDIGITS
