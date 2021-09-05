#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

/*
��ȡ���е���ڽڵ�
*/

//#define CIRCLEENTRY

#ifdef CIRCLEENTRY
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//��ȡ���еĽڵ�(Ҳ�������ж��Ƿ��л�)
ListNode* GetLoopNode(ListNode* head)
{
    if (!head) return nullptr;
    ListNode *p1, *p2;
    p1 = head->next;
    if (!p1) {
        return nullptr;
    }
    p2 = p1->next;
    while (p1 && p2) {
        if (p1 == p2) {
            return p1;
        }
        p1 = p1->next;//p1ÿ�β���1
        p2 = p2->next;//p2ÿ�β���2
        if (p2) {
            p2 = p2->next;
        }
    }
    return nullptr;
}

//���нڵ��ٴλص�ԭλ�ã���ʾ�ƻ�һȦ
int GetLoopLength(ListNode *node)
{
    if (!node) return 0;

    int cnt = 1;
    ListNode* pcur = node->next;
    while (pcur) {
        if (pcur == node) break;//�ص�ԭλ��
        pcur = pcur->next;
        cnt++;
    }
    return cnt;
}

//��ȡ����ڣ�p1����n��
ListNode* GetEntryNode(ListNode* head)
{
    if (!head) return nullptr;
    //��û��нڵ�
    ListNode* pnode = GetLoopNode(head);
    if (!pnode) {
        return nullptr;
    }
    //��û�����
    int loopCnt = GetLoopLength(pnode);
    if (loopCnt <= 0) {
        return nullptr;
    }
    //p1���߻�����
    ListNode* p1, * p2;
    p1 = p2 = head;
    while (loopCnt > 0) {
        p1 = p1->next;
        loopCnt--;
    }
    //ͬʱ�������غϵ㼴Ϊ��ڽڵ�
    while (p1 && p2) {
        if (p1 == p2) {
            return p1;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return nullptr;
}

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
    ListNode* p6 = CreateNode(p5, 6);
    p6->next = p3;
    //PrintNode(p0);

    ListNode* node = GetLoopNode(p0);
    if (node) {
        printf("GetLoopNode:%d\n", node->val);
        printf("GetLoopLength:%d\n", GetLoopLength(node));
    }
    ListNode* entryNode = GetEntryNode(p0);
    if (entryNode) {
        printf("GetEntryNode:%d\n", entryNode->val);
    }

    getchar();
    return 0;
}
#endif // CIRCLEENTRY
