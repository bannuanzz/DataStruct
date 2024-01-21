#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct BTNode
{
    char data;
    BTNode *lchild;
    BTNode *rchild;
    BTNode() : lchild(NULL), rchild(NULL) {}
    BTNode(char d)
    {
        data = d;
        lchild = rchild = NULL;
    }
};
int Sum(BTNode *r)
{
    if (r == NULL)
        return 0;
    else
        return r->data + Sum(r->lchild) + Sum(r->rchild);
}
class BTree
{
    BTNode *r;

public:
    BTree()
    {
        r = NULL;
    }
    // void CreateBTree(string str)
    // {

    // }
    BTNode *FindNode(char x)
    {
        return FindNode1(r, x);
    }
    BTNode *FindNode1(BTNode *b, char x)
    {
        BTNode *p;
        if (b == NULL)
            return NULL;
        else if (b->data == x)
            return b;
        else
        {
            p = FindNode1(b->lchild, x);
            if (p != NULL)
                return p;
            else
                return FindNode1(b->rchild, x);
        }
    }
    int Height()
    {
        return Height1(r);
    }
    int Height1(BTNode *b)
    {
        if (b == NULL)
            return 0;
        else
            return max(Height1(b->lchild), Height1(b->rchild)) + 1;
    }
    void DestroyBTree(BTNode *b)
    {
        if (b != NULL)
        {
            DestroyBTree(b->lchild);
            DestroyBTree(b->rchild);
            delete b;
        }
    }
    ~BTree()
    {
        DestroyBTree(r);
        r = NULL;
    }
    void LevelOrder(BTree &bt)
    {
        BTNode *p;
        queue<BTNode *> qu;
        qu.push(bt.r);
        while (!qu.empty())
        {
            p = qu.front();
            qu.pop();
            cout << p->data;
            if (p->lchild != NULL)
                qu.push(p->lchild);
            if (p->rchild != NULL)
                qu.push(12p- > rchild);
        }
    }
    int KCount1(BTree &bt, int k) // 解法1：求二叉树第k层结点个数
    {
        int cnt = 0;             // 累计第k层结点个数
        queue<QNode> qu;         // 定义一个队列qu
        qu.push(QNode(1, bt.r)); // 根结点(层次为1)进队
        while (!qu.empty())      // 队不空循环
        {
            QNode p = qu.front();
            qu.pop();      // 出队一个结点
            if (p.lev > k) // 当前结点的层次大于k，返回cnt
                return cnt;
            if (p.lev == k)
                cnt++; // 当前结点是第k层的结点,cnt增1
            else       // 当前结点的层次小于k
            {
                if (p.node->lchild != NULL) // 有左孩子时将其进队
                    qu.push(QNode(p.lev + 1, p.node->lchild));
                if (p.node->rchild != NULL) // 有右孩子时将其进队
                    qu.push(QNode(p.lev + 1, p.node->rchild));
            }
        }
        return cnt;
    }

    void CreateBTree1(BTree &bt, vector<char> pres, vector<char> ins)
    {
        int n = pres.size();
        bt.r = CreateBTree11(pres, 0, ins, 0, n);
    }

    BTNode *CreateBTree11(vector<char> pres, int i,
                          vector<char> ins, int j, int n) // 被CreateBTree1调用
    {
        if (n <= 0)
            return NULL;
        char d = pres[i];          // 取根结点值d
        BTNode *b = new BTNode(d); // 创建根结点(值为d)
        int p = j;
        while (ins[p] != d)
            p++;                                                           // ins中找根索引p
        int k = p - j;                                                     // 左子树中结点个数k
        b->lchild = CreateBTree11(pres, i + 1, ins, j, k);                 // 递归构造左子树
        b->rchild = CreateBTree11(pres, i + k + 1, ins, p + 1, n - k - 1); // 递归构造右子树
        return b;
    }
    void CreateBTree2(BTree &bt, vector<char> posts, vector<char> ins)
    // 由后序序列posts和中序序列ins构造二叉链
    {
        int n = posts.size();
        bt.r = CreateBTree21(posts, 0, ins, 0, n);
    }
    BTNode *CreateBTree21(vector<char> posts, int i,
                          vector<char> ins, int j, int n)
    // 被CreateBTree2调用
    {
        if (n <= 0)
            return NULL;
        char d = posts[i + n - 1]; // 取后序序列尾元素即根值d
        BTNode *b = new BTNode(d); // 创建根结点(结点值为d)
        int p = j;
        while (ins[p] != d)
            p++;                                                        // 在ins中找到根结点的索引p
        int k = p - j;                                                  // 确定左子树中结点个数k
        b->lchild = CreateBTree21(posts, i, ins, j, k);                 // 递归构造左子树
        b->rchild = CreateBTree21(posts, i + k, ins, p + 1, n - k - 1); // 递归构造右子树
        return b;
    }
};

// {
// }

void PreOrder11(BTNode *b)
{
    if (b != NULL)
    {
        cout << b->data;
        PreOrder11(b->lchild);
        PreOrder11(b->rchild);
    }
}
void InOrder11(BTNode *b)
{
    if (b != NULL)
    {
        PreOrder11(b->lchild);
        cout << b->data;
        PreOrder11(b->rchild);
    }
}
void PostOrder11(BTNode *b)
{
    if (b != NULL)
    {
        PreOrder11(b->lchild);
        PreOrder11(b->rchild);
        cout << b->data;
    }
}

void DispLeaf11(BTNode *b)
{
    if (b != NULL)
    {
        if (b->lchild == NULL && b->rchild == NULL)
            cout << b->data << " "; // 根结点为叶子结点时输出
        DispLeaf11(b->lchild);      // 输出左子树的叶子结点
        DispLeaf11(b->rchild);      // 输出右子树的叶子结点
    }
}

int Level1(BTNode *b, char x, int h) // 被Level()算法调用
{
    if (b == NULL)
        return 0; // 空树不能找到该结点
    else if (b->data == x)
        return h; // 根结点即为所找,返回其层次
    else
    {
        int l = Level1(b->lchild, x, h + 1);    // 在左子树中查找
        if (l != 0)                             // 左子树中找到了
            return l;                           // 返回其层次l
        else                                    // 左子树中未找到
            return Level1(b->rchild, x, h + 1); // 再在右子树中查找
    }
}
void KCount1(BTNode *b, int h, int k, int &cnt)
{
    if (b == NULL)
        return; // 空树返回
    if (h == k)
        cnt++; // 当前层的结点在第k层，cnt增1
    if (h < k) // 当前层次小于k，递归处理求子树
    {
        KCount1(b->lchild, h + 1, k, cnt);
        KCount1(b->rchild, h + 1, k, cnt);
    }
}
struct QNode // 队列元素类
{
    int lev;                // 结点的层次
    BTNode *node;           // 结点指针
    QNode(int l, BTNode *p) // 构造函数
    {
        lev = l;
        node = p;
    }
};

bool Ancestor11(BTNode *b, char x, vector<char> &res)
{
    if (b == NULL) // 空树返回false
        return false;
    if (b->lchild != NULL && b->lchild->data == x)
    {
        res.push_back(b->data); // 结点b是x结点的祖先
        return true;
    }
    if (b->rchild != NULL && b->rchild->data == x)
    {
        res.push_back(b->data); // 结点b是x结点的祖先
        return true;
    }
    if (Ancestor11(b->lchild, x, res) || Ancestor11(b->rchild, x, res))
    {
        res.push_back(b->data); // 结点b的孩子是x的祖先，则它是x的祖先
        return true;
    }
    return false; // 其他情况返回false
}

void Ancestor1(BTree &bt, char x, vector<char> &res)
// 算法1：返回x结点的祖先
{
    Ancestor11(bt.r, x, res);
    reverse(res.begin(), res.end()); // 逆置res→按根结点到结点x双亲的顺序
}
void Ancestor21(BTNode *b, char x, vector<char> path, vector<char> &res)
{
    if (b == NULL)
        return; // 空树返回
    path.push_back(b->data);
    if (b->data == x)
    {
        path.pop_back(); // 删除x结点
        res = path;      // 复制path到res
        return;          // 找到路径后返回
    }
    Ancestor21(b->lchild, x, path, res); // 在左子树中查找
    Ancestor21(b->rchild, x, path, res); // 在右子树中查找
}
void Ancestor2(BTree &bt, char x, vector<char> &res)
// 算法2：返回x结点的祖先
{
    vector<char> path;
    Ancestor21(bt.r, x, path, res);
}

template <typename T1, typename T2>
struct BSTNode // 二叉排序树结点类
{
    T1 key;             // 存放关键字,假设关键字为T1类型
    T2 data;            // 存放数据项,假设数据项为T2类型
    BSTNode *lchild;    // 存放左孩子指针
    BSTNode *rchild;    // 存放右孩子指针
    BSTNode(T1 k, T2 d) // 构造函数
    {
        key = k;
        data = d;
        lchild = rchild = NULL; // 新建结点默认为叶子结点
    }
};
template <typename T1, typename T2>
class BSTClass // 二叉排序树类模板
{
public:
    BSTNode<T1, T2> *r; // 二叉排序树根结点
    BSTNode<T1, T2> *f; // 用于临时存放待删除结点的双亲
    BSTClass()          // 构造函数
    {
        r = NULL;
        f = NULL;
    }
    ~BSTClass() // 析构函数
    {
        DestroyBTree(r); // 调用DestroyBTree()函数
        r = NULL;
    }
    void DestroyBTree(BSTNode<T1, T2> *b) // 释放所有的结点空间
    {
        // …
    }
    // 二叉排序树的基本运算算法
    void InsertBST(T1 k, T2 d) // 插入一个(k,d)结点
    {
        r = _InsertBST(r, k, d);
    }

    BSTNode<T1, T2> *_InsertBST(BSTNode<T1, T2> *p, T1 k, T2 d)
    // 在以p为根的BST中插入关键字为k的结点
    {
        if (p == NULL) // 原树为空,为根结点
            p = new BSTNode<T1, T2>(k, d);
        else if (k < p->key)
            p->lchild = _InsertBST(p->lchild, k, d); // 插入到p的左子树中
        else if (k > p->key)
            p->rchild = _InsertBST(p->rchild, k, d); // 插入到p的右子树中
        else                                         // 相同关键字,修改data域
            p->data = d;
        return p;
    }
    void CreateBST(vector<T1> &a, vector<T2> &b)
    // 由a和b向量创建一棵二叉排序树
    {
        r = new BSTNode<T1, T2>(a[0], b[0]); // 创建根结点
        for (int i = 1; i < a.size(); i++)   // 创建其他结点
            InsertBST(a[i], b[i]);           // 插入(a[i],b[i])
    }
};
