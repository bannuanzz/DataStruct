#include <iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int> &R, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (R[i] < R[i - 1])
        {
            int temp = R[i];
            int j = i - 1;
            do
            {
                R[j + 1] = R[j];
                j--;
            } while (j >= 0 && R[j] > temp);
            R[j + 1] = temp;
        }
    }
}

void BubbleSort(int arr[], int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void BinInsertSort(vector<int> &R, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (R[i] < R[i - 1])
        {
            int temp = R[i];
            int low = 0;
            int high = i - 1;
            while (low < high)
            {
                int mid = (low + high) / 2;
                if (temp < R[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
                for (int j = i - 1; j > high + 1; j--)
                    R[j + 1] = R[j];
                R[high + 1] = temp;
            }
        }
    }
}

void ShellSort(vector<int> &R, int n)
{
    int d = n / 2;
    while (d > 0)
    {
        for (int i = d; i < n; i++)
        {
            if (R[i] < R[i - d])
            {
                int temp = R[i];
                int j = i - d;
                do
                {
                    R[j + d] = R[j];
                    j = j - d;
                } while (j > 0 && R[j] > temp);
                R[j + d] = temp;
            }
        }
        d = d / 2;
    }
}
int Partition1(vector<int> &R, int s, int t)
{
    int base = R[s];
    int i = s;
    int j = t;
    while (i < j)
    {
        while (i < j && R[j] > base)
            j--;
        while (i < j && R[i] <= base)
            i++;
        if (i < j)
            swap(R[i], R[j]);
    }
    swap(R[s], R[j]);
    return i;
}
int Partition1_1(vector<int> &R, int s, int t)
{
    int base = R[s];
    int i = s, j = t + 1;
    while (i < j)
    {
        j--;
        while (R[j] > base && i < j)
            j--;
        i++;
        while (R[i] <= base && i < j)
            i++;
        if (i < j)
            swap(R[i], R[j]);
    }
    swap(R[s], R[i]);
    return j;
}
int Partition2(vector<int> &R, int s, int t)
{
    int i = s, j = t;
    int base = R[s];
    while (i < j)
    {
        while (j > i && R[j] > base)
            j--;
        if (j > i)
        {
            R[i] = R[j];
            i++;
        }
        while (i > j && R[i] <= base)
            i++;
        if (i < j)
        {
            R[j] = R[i];
            j--;
        }
    }
    R[i] = base;
    return i;
}
int Partition3(vector<int> &R, int s, int t)
{
    int i = s, j = s + 1;
    int base = R[s];
    while (j <= t)
    {
        if (R[j] <= base)
        {
            i++;
            if (i != j)
                swap(R[i], R[j]);
        }
    }
    j++;
    swap(R[s], R[i]);
    return i;
}
void _QuickSort(vector<int> &R, int s, int t)
{
    if (s < t)
    {
        int i = Partition3(R, s, t);
        _QuickSort(R, s, i - 1);
        _QuickSort(R, i + 1, t);
    }
}
void QuickSort(vector<int> &R, int n)
{
    _QuickSort(R, 0, n - 1);
}
void SelectSotr(vector<int> &R, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minj = i;
        for (int j = i + 1; j < n; j++)
            if (R[j] < R[minj])
                minj = j;
        if (minj != i)
            swap(R[i], R[minj]);
    }
}
class Heap
{
    int n;
    vector<int> R;

public:
    Heap() : n(0) {}
    void siftDown(int low, int high)
    {
        int i = low;
        int j = 2 * i + 1;
        int temp = R[i];
        while (j <= high)
        {
            if (j < high && R[j] < R[j + 1])
                j++;
            if (temp < R[j])
            {
                R[i] = R[j];
                i = j;
                j = 2 * i + 1;
            }
            else
                break;
        }
        R[i] = temp;
    }

    void siftUp(int j)
    {
        int i = (j - 1) / 2;
        while (1)
        {
            if (R[j] > R[i])
                swap(R[i], R[j]);
            if (i == 0)
                break;
            j = i;
            i = (j - 1) / 2;
        }
    }
    void push(int e)
    {
        n++;
        if (R.size() >= n)
            R[n - 1] = e;
        else
            R.push_back(e);
        if (n == 1)
            return;
        int j = n - 1;
        siftUp(j);
    }
    int pop()
    {
        if (n == 1)
        {
            n = 0;
            return R[0];
        }
        int e = R[0];
        R[0] = R[n - 1];
        n--;
        siftDown(0, n - 1);
        return e;
    }
};

void Merge(vector<int> &R, int low, int mid, int high)
// 将R[low..mid]和R[mid+1..high]两个有序段归并为一个有序段R[low..high]
{
    vector<int> R1;
    R1.resize(high - low + 1);       // 设置R1的长度为high-low+1
    int i = low, j = mid + 1, k = 0; // k是R1的下标,i、j分别为第1、2段的下标
    while (i <= mid && j <= high)    // 在第1段和第2段均未扫描完时循环
    {
        if (R[i] <= R[j]) // 将第1段中的元素放入R1中
        {
            R1[k] = R[i];
            i++;
            k++;
        }
        else // 将第2段中的元素放入R1中
        {
            R1[k] = R[j];
            j++;
            k++;
        }
    }
    while (i <= mid) // 将第1段余下部分复制到R1
    {
        R1[k] = R[i];
        i++;
        k++;
    }
    while (j <= high) // 将第2段余下部分复制到R1
    {
        R1[k] = R[j];
        j++;
        k++;
    }
    for (k = 0, i = low; i <= high; k++, i++) // 将R1复制回R中
        R[i] = R1[k];
}

void MergePass(vector<int> &R, int length)
// 对整个数序进行一趟归并
{
    int n = R.size(), i;
    for (i = 0; i + 2 * length - 1 < n; i += 2 * length) // 归并length长的两相邻子表
        Merge(R, i, i + length - 1, i + 2 * length - 1);
    if (i + length < n)                     // 余下两个子表,后者长度小于length
        Merge(R, i, i + length - 1, n - 1); // 归并这两个子表
}
void MergeSort1(vector<int> &R, int n) // 自底向上的二路归并排序
{
    for (int length = 1; length < n; length = 2 * length) // 进行log2n趟归并
        MergePass(R, length);
}

void _MergeSort2(vector<int> &R, int s, int t) // 被MergeSort2调用
{
    if (s >= t)
        return;               // R[s..t]的长度为0或者1时返回
    int m = (s + t) / 2;      // 取中间位置m
    _MergeSort2(R, s, m);     // 对前子表排序
    _MergeSort2(R, m + 1, t); // 对后子表排序
    Merge(R, s, m, t);        // 将两个有序子表合并成一个有序表
}
void MergeSort2(vector<int> &R, int n) // 自顶向下的二路归并排序
{
    _MergeSort2(R, 0, n - 1);
}
int geti(int key, int r, int i) // 求基数为r的正整数key的第i位
{
    int k = 0;
    for (int j = 0; j <= i; j++)
    {
        k = key % r;
        key = key / r;
    }
    return k;
}
void RadixSort1(LinkList<int> &L, int d, int r)
// 最低位优先基数排序算法
{
    LinkNode<int> *front[MAXR]; // 建立链队队头数组
    LinkNode<int> *rear[MAXR];  // 建立链队队尾数组
    LinkNode<int> *p, *t;
    for (int i = 0; i < d; i++) // 从低位到高位循环
    {
        for (int j = 0; j < r; j++) // 初始化各链队首、尾指针
            front[j] = rear[j] = NULL;
        p = L.head->next;
        while (p != NULL) // 分配：对于原链表中每个结点循环
        {
            int k = geti(p->data, r, i); // 提取关键字第k个位并放入第k个链队
            if (front[k] == NULL)        // 第k个链队空时，队头队尾均指向p结点
            {
                front[k] = p;
                rear[k] = p;
            }
            else // 第k个链队非空时，p结点进队
            {
                rear[k]->next = p;
                rear[k] = p;
            }
            p = p->next; // 取下一个待排序的结点
        }

        LinkNode<int> *h = NULL;    // 重新用h来收集所有结点
        for (int j = 0; j < r; j++) // 收集：对于每一个链队循环
            if (front[j] != NULL)   // 若第j个链队是第一个非空链队
            {
                if (h == NULL)
                {
                    h = front[j];
                    t = rear[j];
                }
                else // 若第j个链队是其他非空链队
                {
                    t->next = front[j];
                    t = rear[j];
                }
            }
        t->next = NULL; // 尾结点的next域置NULL
        L.head->next = h;
    }
}


void max_heapify(int arr[], int start, int end)
{
    // 建立父節點指標和子節點指標
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)
    {                                                  // 若子節點指標在範圍內才做比較
        if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比較兩個子節點大小，選擇最大的
            son++;
        if (arr[dad] > arr[son]) // 如果父節點大於子節點代表調整完畢，直接跳出函數
            return;
        else
        { // 否則交換父子內容再繼續子節點和孫節點比較
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len)
{
    // 初始化，i從最後一個父節點開始調整
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    // 先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}
