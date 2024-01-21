#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int Max = 100;
vector<int> mem;
typedef struct BTree
{
    int data;
    BTree *left;
    BTree *right;
} *Tree;
void insert(Tree &root, int data)
{
    if (root == NULL)
    {
        root = new BTree;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data > root->data)
    {
        insert(root->right, data);
    }
    else
    {
        insert(root->left, data);
    }
}
void BuildTree(Tree &root, int data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        insert(root, data[i]);
    }
}
int cnt = 0;
int Search(Tree &root, int n, int cnt)
{
    if (root == NULL)
        return 0;
    if (root->data == n)
        return cnt;
    if (n < root->data)
        return Search(root->left, n, ++cnt);
    if (n > root->data)
        return Search(root->right, n, ++cnt);
}
void inOrderTraver(Tree &root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraver(root->left);
    cout << root->data << " ";
    mem.push_back(root->data);
    inOrderTraver(root->right);
}
int cnt2 = 0;
int BinSearch1(vector<int> &mem, int low, int high, int k, int cnt2)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (k == mem[mid])
            return cnt2;
        if (k < mem[mid])
            return BinSearch1(mem, low, mid - 1, k, ++cnt2);
        else
            return BinSearch1(mem, mid + 1, high, k, ++cnt2);
    }
}
int BinSearch2(vector<int> &mem, int k)
{
    return BinSearch1(mem, 0, mem.size()-1, k, 1);
}
int main()
{
    int n;
    cin >> n;
    Tree root = NULL;
    int num;
    int data[Max];
    memset(data, 0, sizeof(data));
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    cin >> num;
    BuildTree(root, data, n);
    cout << Search(root, num, 1) << endl;
    inOrderTraver(root);
    cout << endl;
    cout << BinSearch2(mem, num);
}