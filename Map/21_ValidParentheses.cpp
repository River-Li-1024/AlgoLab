#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>
#include <ctime>
#include <unordered_map>

/*
��Ч������
*/

using namespace std;
bool isValid(string s)
{
    stack<char> stk;
    for (auto c : s) {
        if (c == '(') stk.push(')');
        else if (c == '{') stk.push('}');
        else if (c == '[') stk.push(']');
        else if (stk.empty() || stk.top() != c) return false;
        else stk.pop();
    }
    return stk.empty();
}

//#define VALID_PARENTHESES
#ifdef VALID_PARENTHESES
int main(int argc, char** argv)
{
    string str = "(([]{()}))";
    bool ret = isValid(str);
    printf("isValid��%s\n", ret?"true":"false");

    getchar();
    return 0;
}
#endif // VALID_PARENTHESES
