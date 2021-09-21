#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>
#include <unordered_map>

/*
���ַ��� s ���ҳ���һ��ֻ����һ�ε��ַ������û�У�����һ�����ո� s ֻ����Сд��ĸ��
*/

#define FIRSTUNIQUECHAR

#ifdef FIRSTUNIQUECHAR
using namespace std;

char firstUniqChar(string s)
{
    unordered_map<char, bool> dic;
    vector<char> vec;

    for (auto c : s) {
        bool bfirst = dic.find(c) == dic.end();
        if (bfirst) {
            vec.push_back(c);
        }
        dic[c] = bfirst;
    }
    for (auto c : vec) {
        if (dic[c]) return c;
    }
    return ' ';
}

int main(int argc, char** argv)
{
    char c = firstUniqChar("abaccdeff"); 
    printf("firstUniqChar:%c\n", c);

    getchar();
    return 0;
}
#endif // FIRSTUNIQUECHAR

