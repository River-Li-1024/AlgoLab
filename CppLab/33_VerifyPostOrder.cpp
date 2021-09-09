#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

/*
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������
������򷵻� true�����򷵻� false���������������������������ֶ�������ͬ��
*/

//#define VERIFYPOSTORDER

#ifdef VERIFYPOSTORDER
using namespace std;

bool verifyPostorderPartial(vector<int>& postorder, int left, int right)
{
    if (left >= right) return true;
    if (left < 0 || right > postorder.size()) return false;

    int midVal = postorder[right];
    //�ҵ��м�ָ����
    size_t midIdx = left;
    for (; midIdx < right; midIdx++) {
        if (postorder[midIdx] > midVal) {
            break;
        }
    }
    //��֤�ұ߷�������
    for (size_t idx = midIdx; idx < right; idx++) {
        if (postorder[idx] < midVal) {
            return false;
        }
    }
    //�ݹ���֤����
    if (midIdx > left) {
        if (!verifyPostorderPartial(postorder, left, midIdx - 1)) {
            return false;
        }
    }
    //�ݹ���֤�Ұ��
    if (midIdx < right - 1) {
        if (!verifyPostorderPartial(postorder, midIdx, right - 1)) {
            return false;
        }
    }
    return true;
}

bool verifyPostorder(vector<int>& postorder)
{
    return verifyPostorderPartial(postorder, 0, postorder.size() - 1);
}

int main(int argc, char** argv)
{
    vector<int> vec{ 1,3,2,6,5 };
    vector<int> vec2{ 1,6,3,2,5 };
    bool bvalid = verifyPostorder(vec2);
    printf("verifyPostorder:%s\n", bvalid ? "true" : "false");

    getchar();

    return 0;
}
#endif // VERIFYPOSTORDER
