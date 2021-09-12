#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>

/*
����һ���ַ�������ӡ�����ַ������ַ����������С�
*/

//#define PERMUTATION

#ifdef PERMUTATION
using namespace std;

//��һ�����㷨
bool permutationNext(string& s)
{
    int minIdx = s.size() - 2;
    //�Ӻ���ǰ�ҵ���Сֵ
    while (minIdx >= 0 && s[minIdx] >= s[minIdx + 1]) {
        minIdx--;
    }
    if (minIdx < 0) return false;
    //�Ӻ���ǰ�ҵ���Դ�ֵ(���������Сֵ��
    int maxIdx = s.size() - 1;
    while (maxIdx >= 0 && s[minIdx] >= s[maxIdx]) {
        maxIdx--;
    }
    //����
    swap(s[minIdx], s[maxIdx]);
    //β����С��������
    sort(s.begin() + minIdx + 1, s.end());
    return true;
}
vector<string> permutation(string s)
{
    vector<string> vec;
    if (s.empty()) return vec;
    if (s.size() == 1) {
        vec.push_back(s);
        return vec;
    }

    sort(s.begin(), s.end());
    do {
        vec.push_back(s);
    } while (permutationNext(s));
    return vec;
}

//���ݷ�
vector<bool> _vis;
vector<string> _ret;
void backtrace(const string& str, int bidx, string& perm)
{
    if (bidx == str.size()) {
        _ret.push_back(perm);
    }

    for (size_t idx = 0; idx < str.size(); idx++) {
        if (_vis[idx] || (idx > 0 && !_vis[idx - 1] && str[idx] == str[idx - 1])) {
            continue;
        }
        _vis[idx] = true;
        perm.push_back(str[idx]);
        backtrace(str, bidx + 1, perm);
        perm.pop_back();
        _vis[idx] = false;
    }
}
vector<string> permutation2(string s)
{
    if (s.empty()) return _ret;
    if (s.size() == 1) {
        _ret.push_back(s);
        return _ret;
    }

    int size = s.size();
    _vis.resize(size);
    sort(s.begin(), s.end());

    string perm;
    backtrace(s, 0, perm);
    return _ret;
}

int main(int argc, char** argv)
{
    string str = "445";
    {
        printf("permutation1:\n");
        vector<string> vec = permutation(str);
        for (size_t idx = 0; idx < vec.size(); idx++) {
            printf("%s\n", vec[idx].c_str());
        }
    }
    {
        printf("permutation2:\n");
        vector<string> vec = permutation2(str);
        for (size_t idx = 0; idx < vec.size(); idx++) {
            printf("%s\n", vec[idx].c_str());
        }
    }

    getchar();
    return 0;
}
#endif // PERMUTATION
