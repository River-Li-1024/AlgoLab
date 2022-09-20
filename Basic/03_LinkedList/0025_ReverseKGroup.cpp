#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <unordered_map>
using namespace std;

/*
25. K ��һ�鷭ת����
����һ������ÿ k ���ڵ�һ����з�ת�����㷵�ط�ת�������

k ��һ��������������ֵС�ڻ��������ĳ��ȡ�

����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��

���ף�

��������һ��ֻʹ�ó�������ռ���㷨�������������
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʽ��нڵ㽻����
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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode fhead;
        ListNode* cur = head;
        ListNode* front = head;
        ListNode* end = head;
        ListNode* prev = &fhead;
        ListNode* last = nullptr;
        int cnt = 0;
        while (cur != nullptr) {
            front = cur;
            //����K
            while (cnt < k && cur != nullptr) {
                last = cur;
                cur = cur->next;
                cnt++;
            }
            end = last;

            if (cnt == k) {
                //��ת����
                end->next = nullptr;
                reverse(front);
                //����״̬
                prev->next = end;
                front->next = cur;
                prev = front;
                front = end = cur;
            } else {
                //ֱ��������β��
                prev->next = front;
            }
            cnt = 0;
        }
        return fhead.next;
    }

    void reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    }
};
