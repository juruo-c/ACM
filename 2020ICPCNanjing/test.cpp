#include <iostream>

using namespace std;

const int N = 100005;

struct Node
{
    char ch;
    Node* next;
}node[N];
int cnt;

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    string s;
    while (getline(cin, s))
    {
        // 初始化当前节点数量和头尾节点(head, tail)当前节点(cur)
        cnt = 0;
        node[++ cnt].next = NULL;
        Node* head = &node[1];
        Node* tail = &node[1];
        Node* cur = head;

        // 开始解析输入的字符串
        int n = s.size();
        for (int i = 0; i < n; i ++ )
        {
            if (s[i] == '[')
                cur = head;
            else if(s[i] == ']')
                cur = tail;
            else 
            {
                // 创建新节点
                node[++ cnt] = {s[i], NULL};
                // 连接
                node[cnt].next = cur->next;
                cur->next = &node[cnt];
                // 如果新节点是最后一个节点，更新tail
                if (node[cnt].next == NULL)
                    tail = &node[cnt];
                // 移动cur到新插入的节点上
                cur = &node[cnt];
            }
        }
        
        Node* q = head->next;
        while (q)
        {   
            printf("%c", q->ch);
            q = q->next;
        }
        puts("");
    }
    return 0;
}