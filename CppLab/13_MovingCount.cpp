#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

/*
������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18���������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�
=> ���ݷ������ƹ�����ȱ���
*/

//#define MOVINGCOUNT

#ifdef MOVINGCOUNT
using namespace std;

int CalcDigitSum(int num)
{
    if (num <= 0) return 0;
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

int CalcMovingCount(int rows, int cols, int row, int col, int k, bool* visited)
{
    if (row < 0 || col < 0 || row >= rows || col >= cols) {
        return 0;
    }
    //���㵱ǰλ����λ��
    int dsum = CalcDigitSum(row) + CalcDigitSum(col);

    //���λ������
    if (!visited[row * cols + col] && dsum <= k) {
        visited[row * cols + col] = true;
        return 1
            + CalcMovingCount(rows, cols, row + 1, col, k, visited)
            + CalcMovingCount(rows, cols, row - 1, col, k, visited)
            + CalcMovingCount(rows, cols, row, col + 1, k, visited)
            + CalcMovingCount(rows, cols, row, col - 1, k, visited);
    }
    return 0;
}

int movingCount(int m, int n, int k)
{
    if (m <= 0 || n <= 0 || k < 0) {
        return 0;
    }

    bool* visited = new bool[m * n];
    memset(visited, false, m * n);

    int count = CalcMovingCount(m, n, 0, 0, k, visited);
    delete [] visited;
    return count;
}

void testMovingCount(int rows, int cols, int k)
{
    int count = movingCount(rows, cols, k);
    printf("Moving rows(%d),cols(%d),k(%d)=> count(%d)\n", rows, cols, k, count);
}

int main(int argc, char** argv)
{
    testMovingCount(2, 2, 1);
    testMovingCount(2, 3, 1);
    testMovingCount(3, 1, 0);

    getchar();
    return 0;
}
#endif // MOVINGCOUNT
