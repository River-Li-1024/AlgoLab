#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

/*
ð������
*/
using namespace std;

//������һ��iʹ��v[i]=v�������ڷ���-1
int BinarySearch_Any(vector<int>& arr, int val)
{
    if (arr.size() == 0) return -1;

    int len = arr.size();
    //����[left, right)
    int left = 0;
    int right = len;
    //����������left=right
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == val) return mid;
        else if (arr[mid] < val) left = mid + 1;
        else if (arr[mid] > val) right = mid;
    }
    return -1;
}

//����С��iʹ��v[i]=v�������ڷ���-1
int BinarySearch_Min(vector<int>& arr, int val)
{
    if (arr.size() == 0) return -1;

    int len = arr.size();
    //����[left, right)
    int left = 0;
    int right = len;
    //����������left=right
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == val) return right = mid;
        else if (arr[mid] < val) left = mid + 1;
        else if (arr[mid] > val) right = mid;
    }
    return -1;
}

//#define BINARY_SEARCH
#ifdef BINARY_SEARCH
int main(int argc, char** argv)
{
    vector<int> arr{ 1, 2, 2, 3, 3, 5, 5, 7, 7, 7, 7, 10 };
    printf("search:%d\n", BinarySearch_Any(arr, 11));

    getchar();
    return 0;
}
#endif // BINARY_SEARCH
