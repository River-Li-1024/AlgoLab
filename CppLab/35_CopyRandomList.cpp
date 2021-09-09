#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>

/*
��ʵ�� copyRandomList ����������һ����������
�ڸ��������У�ÿ���ڵ������һ�� next ָ��ָ����һ���ڵ㣬
����һ�� random ָ��ָ�������е�����ڵ���� null��
*/

#define COPYRANDOMLIST

#ifdef COPYRANDOMLIST
using namespace std;
class Node
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head)
{
    if (head == nullptr) return nullptr;
    //����NodeNew��ӵ�ԭ�ڵ�ĺ��
    for (Node* pnode = head; pnode != nullptr; pnode = pnode->next->next) {
        Node* pnodenew = new Node(pnode->val);
        pnodenew->next = pnode->next;
        pnode->next = pnodenew;
    }
    //�����½ڵ��randomָ��
    for (Node* pnode = head; pnode != nullptr; pnode = pnode->next->next) {
        Node* pnodenew = pnode->next;
        pnodenew->random = (pnode->random != nullptr)? pnode->random->next:nullptr;
    }
    //�����������
    Node* headnew = head->next;
    for (Node* pnode = head; pnode != nullptr; pnode = pnode->next) {
        Node* pnodenew = pnode->next;
        pnode->next = pnode->next->next;
        pnodenew->next = (pnodenew->next != nullptr) ? pnode->next->next : nullptr;
    }
    return headnew;
}

Node* CreateNode(Node* parent, int val)
{
    Node* pnode = new Node(val);
    if (parent) {
        parent->next = pnode;
    }
    return pnode;
}

void PrintNode(Node* head)
{
    Node* pnode = head;
    while (pnode) {
        printf("%d(%d)\t", pnode->val, (pnode->random)?pnode->random->val:-1);
        pnode = pnode->next;
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    Node* p0 = CreateNode(nullptr, 0);
    Node* p1 = CreateNode(p0, 1);
    Node* p2 = CreateNode(p1, 2);
    Node* p3 = CreateNode(p2, 3);
    Node* p4 = CreateNode(p3, 4);
    p2->random = p4;
    p3->random = p0;
    PrintNode(p0);

    Node* clone = copyRandomList(p0);
    PrintNode(clone);

    getchar();
    return 0;
}
#endif // COPYRANDOMLIST
