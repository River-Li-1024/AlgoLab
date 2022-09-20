#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

/*
206. ��ת����
���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
*/

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseList(ListNode* head)
{
    if (!head) return head;

    ListNode* plast = head;
    ListNode* pcur = plast->next;
    while (pcur) {
        ListNode* pnext = pcur->next;//�������½ڵ�
        pcur->next = plast;//����
        //���µ�����
        plast = pcur;
        pcur = pnext;
    }
    head->next = nullptr;

    return plast;
}

//#define REVERTLIST
#ifdef REVERTLIST
ListNode* CreateNode(ListNode* parent, int val)
{
    ListNode* pnode = new ListNode(val);
    if (parent) {
        parent->next = pnode;
    }
    return pnode;
}

void PrintNode(ListNode* head)
{
    ListNode* pnode = head;
    while (pnode) {
        printf("%d\t", pnode->val);
        pnode = pnode->next;
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    ListNode* p0 = CreateNode(nullptr, 0);
    ListNode* p1 = CreateNode(p0, 1);
    ListNode* p2 = CreateNode(p1, 2);
    ListNode* p3 = CreateNode(p2, 3);
    ListNode* p4 = CreateNode(p3, 4);
    ListNode* p5 = CreateNode(p4, 5);
    PrintNode(p0);

    {
        ListNode* node = reverseList(p0);
        PrintNode(node);
    }

    getchar();
    return 0;
}
#endif // REVERTLIST
