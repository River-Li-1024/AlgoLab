#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

/*
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ����磬���� {1,2,3,4,5} ��ĳջ��ѹջ���У�
���� {4,5,3,2,1} �Ǹ�ѹջ���ж�Ӧ��һ���������У��� {4,3,5,1,2} �Ͳ������Ǹ�ѹջ���еĵ������С�
*/

#define VALIDATESTACKSEQ

#ifdef VALIDATESTACKSEQ
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
    if (pushed.size() == 0 && popped.size() == 0) return true;
    if (pushed.size() == 0 || popped.size() == 0) return false;

    stack<int> tstack;
    int pidx = 0;
    for (size_t idx = 0; idx < pushed.size(); idx++) {
        tstack.push(pushed[idx]);
        while (pidx < popped.size() && tstack.size() > 0 && popped[pidx] == tstack.top()) {
            tstack.pop();
            pidx++;
        }
    }
    return tstack.empty();
}

int main(int argc, char** argv)
{
    vector<int> pushd{ 1, 2, 3, 4, 5, 6 };
    //vector<int> popped{ 4, 6, 5, 3, 2, 1 };
    vector<int> popped{ 4, 6, 2, 3, 5, 3, 1 };
    bool bvalid = validateStackSequences(pushd, popped);
    printf("ValidateStackSeq:%s\n", bvalid ? "true" : "false");
   
    getchar();
    return 0;
}
#endif // VALIDATESTACKSEQ
