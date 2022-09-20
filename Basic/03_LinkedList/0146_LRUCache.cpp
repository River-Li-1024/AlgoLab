#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <unordered_map>

/*
146. LRU ����
������Ʋ�ʵ��һ������  LRU (�������ʹ��) ���� Լ�������ݽṹ��
ʵ�� LRUCache �ࣺ
LRUCache(int capacity) �� ������ ��Ϊ���� capacity ��ʼ�� LRU ����
int get(int key) ����ؼ��� key �����ڻ����У��򷵻عؼ��ֵ�ֵ�����򷵻� -1 ��
void put(int key, int value) ����ؼ��� key �Ѿ����ڣ�����������ֵ value ����������ڣ����򻺴��в������ key-value ���������������¹ؼ����������� capacity ����Ӧ�� ��� ���δʹ�õĹؼ��֡�
���� get �� put ������ O(1) ��ƽ��ʱ�临�Ӷ����С�
*/
using namespace std;
class CacheNode
{
public:
    CacheNode() : val(-1), next(nullptr), prev(nullptr) {}
    CacheNode(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
public:
    int key;
    int val;
    CacheNode* next;
    CacheNode* prev;
};

//˫������
class Deque
{
public:
    Deque() : _size(0)
    {
        //��ͷβ�ڵ�
        head = new CacheNode();
        tail = new CacheNode();
        head->next = tail;
        tail->prev = head;
    }

    ~Deque()
    {
        delete head;
        delete tail;
        _size = 0;
    }
    //��ӵ�ͷ
    void addToHead(CacheNode* node)
    {
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
        _size++;
    }
    //��ӵ�β
    void addToTail(CacheNode* node)
    {
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
        node->next = tail;
        _size++;
    }
    //��ȡβ�ڵ�
    CacheNode* getTail()
    {
        if (_size == 0) return nullptr;
        return tail->prev;
    }
    //ɾ���ڵ㣨��ɾ����
    void remove(CacheNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
        _size--;
    }

    int size()
    {
        return _size;
    }

private:
    CacheNode* head;
    CacheNode* tail;
    int _size;
};

class LRUCache
{
public:
    LRUCache(int capacity) : cap(capacity)
    {
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        //�ƶ���ͷ��
        CacheNode* node = mp[key];
        dq.remove(node);
        dq.addToHead(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end()) {
            CacheNode* node = new CacheNode(key, value);
            //������ɾ��β��
            if (dq.size() >= cap) {
                CacheNode* tail = dq.getTail();
                mp.erase(tail->key);
                dq.remove(tail);
                delete tail;
                tail = nullptr;
            }
            //��ӵ�ͷ���������ݷ���ͷ����
            mp.insert({ key, node });
            dq.addToHead(node);
        } else {
            //������ֵ��ͬʱ����ͷ��
            CacheNode* node = mp[key];
            node->val = value;
            dq.remove(node);
            dq.addToHead(node);
        }
    }

private:
    unordered_map<int, CacheNode*> mp;  //��������
    Deque dq;                           //ά��˳�򣬴洢
    int cap;                            //����
};

//#define LRU_CACHE
#ifdef LRU_CACHE
int main(int argc, char* argv)
{
    int capacity = 10;
    LRUCache* obj = new LRUCache(capacity);
    //int param_1 = obj->get(1);
    //obj->put(key, value);

    getchar();
    return 0;
}
#endif // LRU_CACHE
