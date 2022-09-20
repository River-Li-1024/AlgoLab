#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <queue>

using namespace std;

/*
143. ��������
����һ�������� L ��ͷ�ڵ� head �������� L ��ʾΪ��

L0 �� L1 �� �� �� Ln - 1 �� Ln
�뽫���������к��Ϊ��

L0 �� Ln �� L1 �� Ln - 1 �� L2 �� Ln - 2 �� ��
����ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode* head)
    {
        //��ȡ�м�λ�ã��ǵð�ǰ��ε�ĩβ��Ϊnullptr
        ListNode* pmid = getMiddle(head);
        ListNode* pend = pmid->next;
        pmid->next = nullptr;

        //��ת����
        pend = reverse(pend);

        //�ϲ�����
        merge(head, pend);
    }

    //��ȡ�����������ͷ��λ��, pslow
    ListNode* getMiddle(ListNode* head)
    {
        ListNode* pfast = head;
        ListNode* pslow = head;

        while (pfast->next != nullptr && pfast->next->next != nullptr) {
            pfast = pfast->next->next;
            pslow = pslow->next;
        }
        return pslow;
    }

    //��ת����
    ListNode* reverse(ListNode* head)
    {
        ListNode* ppre = nullptr;
        ListNode* pcur = head;
        ListNode* pnext = nullptr;
        while (pcur != nullptr) {
            pnext = pcur->next;
            pcur->next = ppre;
            ppre = pcur;
            pcur = pnext;
        }
        return ppre;
    }

    //�ϲ�����
    void merge(ListNode* pfront, ListNode* pend)
    {
        ListNode* tpfront = nullptr;
        ListNode* tpend = nullptr;
        while (pfront != nullptr && pend != nullptr) {
            tpfront = pfront->next;
            tpend = pend->next;

            pfront->next = pend;
            pfront = tpfront;

            pend->next = pfront;
            pend = tpend;
        }
    }
};
