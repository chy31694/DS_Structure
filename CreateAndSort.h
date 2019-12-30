// -----------------------------------
// 模块: 创建和排序数据组
// 负责人: 陈宇航 赵子航 田祺
// 暂定目标: 此模块将数据处理完毕后,导入至全局变量数组 bidderGroup 中
// -----------------------------------

bool InitList_Sq(SqList &L)
{
    // 构造一个空的线性表L
    L.bidderGroup = new Bidder[MAXSIZE];
    if (!L.bidderGroup)
        exit(OVERFLOW); // 分配空间失败

    L.length = 0; //表示长度为 0
    return OK;
    // 由于函数运行至return就已经截止, 以下部分并不会执行, 仅作为后续函数编写时的参考, 便于诸位理解

    L.bidderGroup[1].phoneNumber = 0000; // 表示当前读取的竞价表中第 1 条竞价信息的手机序列号赋值为 0000
    L.bidderGroup[1].price = 1000;       // 表示当前读取的竞价表中第 1 条竞价信息的出价为 1000
    L.length = 100;                      // 表示当前竞价表中有 100 条竞价信息

    // 示例:如何交换 1 号竞价者和 2 号竞价者在竞价表"bidderGroup"中的位置
    Bidder T; // 新建一个临时竞价信息(临时变量)
    T = L.bidderGroup[1];
    L.bidderGroup[1] = L.bidderGroup[2];
    L.bidderGroup[2] = T;

    // 对比常见的交换变量 a 和 b 的值
    int t, a = 1, b = 2;
    t = a;
    a = b;
    b = t;

} // InitList_Sq

// -----------------------------------
// Create/Initialize the BidderGroup
// -----------------------------------
bool createTheBidderGroup(SqList &L)
{
    InitList_Sq(L);
    int i, n;
    cout << "\nEnter the number of bidders: ";
    cin >> n;
    L.length = n;
    srand((unsigned int)time(0)); // Initialize the 'randseed'
    for (i = 1; i <= n; ++i)
    {
        L.bidderGroup[i].phoneNumber = i + 1000;
        L.bidderGroup[i].price = rand() % 9001 + 1000;
        evalCount += 2;
    }
    ifSorted = 0;
    return OK;
} // createTheBidderGroup

// -----------------------------------
// Print the BidderGroup
// -----------------------------------
void printTheAllBidderGroup(SqList L)
{
    int i;
    if (L.length == 0)
    {
        cout << "\nThere is no bid." << endl;
        return;
    }

    cout << "\nThe BidderList:" << endl;

    for (i = 1; i <= L.length; ++i)
    {
        printf("Num %04d. ", i);
        cout << "Phone:" << L.bidderGroup[i].phoneNumber << setw(10) << "Price:" << L.bidderGroup[i].price << endl;
    }
    cout << "\nFinished.\n"
         << endl;
} // printTheAllBidderGroup

// -----------------------------------
// SORTTING
// -----------------------------------
void ECore_Swap(Bidder &A, Bidder &B)
{
    Bidder T;
    T = A;
    A = B;
    B = T;
    ++swapCount;
} // ECore_Swap

void ECore_Qsort(Bidder arr[], int low, int high){
    if (high <= low) return;
    int i = low;
    int j = high + 1;
    int key = arr[low].price;
    while (true)
    {
        /*从左向右找比key大的值*/
        while (arr[++i].price < key)
        {
            if (i == high){
                break;
            }
            ++compCount;
        }
        /*从右向左找比key小的值*/
        while (arr[--j].price > key)
        {
            if (j == low){
                break;
            }
            ++compCount;
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
        ECore_Swap(arr[i], arr[j]);
    }
    /*中枢值与j对应值交换*/
    ECore_Swap(arr[low], arr[j]);
    ECore_Qsort(arr, low, j - 1);
    ECore_Qsort(arr, j + 1, high);
} // ECore_Qsort

void sortTheAllBidderList(SqList &L)
{
    if (L.length == 0)
    {
        cout << "\nThere is no bid.\n" << endl;
        return;
    }
    ECore_Qsort(L.bidderGroup, 0, L.length);
    ifSorted = 1;
    cout << "\nSort Finished.\n" << endl;
} // sortTheAllBidderList