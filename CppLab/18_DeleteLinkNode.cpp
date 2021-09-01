#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

/*
�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣
����ɾ����������ͷ�ڵ㡣
*/

//#define DELETELINKNODE

#ifdef DELETELINKNODE
using namespace std;

//Definition for singly - linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteNode(ListNode* head, int val)
{
    if (!head) return nullptr;

    if (head->val == val) {
        ListNode* ret = head->next;
        delete head;
        return ret;
    }

    ListNode* pre = head;
    ListNode* cur = head->next;
    while (cur && cur->val != val) {
        pre = cur;
        cur = cur->next;
    }
    if (cur) {
        pre->next = cur->next;
        delete cur;
    }
    return head;
}

ListNode* deleteNode2(ListNode* head, ListNode* pDelete)
{
    if (!pDelete) return head;

    //����β�ڵ�
    if (pDelete->next != nullptr) {
        ListNode* pNext = pDelete->next;
        *pDelete = *(pNext);
        delete pNext;
        pDelete = nullptr;
    } 
    //ɾ��ͷ�ڵ㣨ֻ��һ���ڵ㣩
    else if (head == pDelete) {
        delete pDelete;
        pDelete = nullptr;
        head = nullptr;
    }
    //β�ڵ�
    else {
        ListNode* pnode = head;
        while (pnode->next != pDelete) {
            pnode = pnode->next;
        }
        if (pnode) {
            pnode->next = nullptr;
            delete pDelete;
            pDelete = nullptr;
        }
    }
    return head;
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
    PrintNode(p0);

    {
        //ListNode* head = deleteNode2(p0, p0);
        //ListNode* head = deleteNode2(p0, p1);
        //ListNode* head = deleteNode2(p0, p5);
        //PrintNode(head);
    }

    {
        //ListNode* head = deleteNode(p0, 0);
        //ListNode* head = deleteNode(p0, 1);
        //ListNode* head = deleteNode(p0, 5);
        ListNode* head = deleteNode(p0, 6);
        PrintNode(head);
    }

    getchar();
    return 0;
}
#endif // DELETELINKNODE
