// -----------------------------------
// 模块: 竞价信息组的数据动态管理
// 负责人:尹逸凡
// 暂定目标: 编写函数,实现全局变量数组 bidderGroup 的插入/删除操作
// -----------------------------------

// -----------------------------------
// InsertBidder
// -----------------------------------
void insertBidder_1(SqList &L, Bidder newBidder)
{
    L.bidderGroup[L.length + 1] = newBidder;
    ++evalCount;
    ++L.length;
} // insertBidder_1

void insertBidder_2(SqList &L, Bidder newBidder)
{
    int low = 1, high = L.length, m, j;
    while (low <= high)
    {
        m = (low + high) / 2;
        if (L.bidderGroup[m].price > newBidder.price)
            high = m - 1;
        else
            low = m + 1;
        ++compCount;
    } // while
    for (j = L.length; j >= high; --j)
    {
        L.bidderGroup[j + 1] = L.bidderGroup[j];
        ++evalCount;
    }
    L.bidderGroup[low] = newBidder;
    ++evalCount;
    ++L.length;

} // insertBidder_2

void insertBidder(SqList &L)
{
    Bidder newBidder;
    do
    {
        cout << "\nEnter the biider's price(1000~9999):";
        cin >> newBidder.price;
        cout << "\nEnter the bidder's phone(1000~9999):";
        cin >> newBidder.phoneNumber;
    } while (!(newBidder.phoneNumber >= 1000 && newBidder.phoneNumber <= 9999 && newBidder.price >= 1000 && newBidder.price <= 9999));

    if (ifSorted == 0)
        insertBidder_1(L, newBidder);
    if (ifSorted == 1)
        insertBidder_2(L, newBidder);
} // insertBidder

// -----------------------------------
// DeleteBidder
// -----------------------------------
void deleteBidder(SqList &L)
{
    int t, i = 1, j;
    if (L.length == 0)
    {
        cout << "\nThere is no bid." << endl;
        return;
    }
    cout << "Enter the bidder's phone:";
    cin >> t;

    while (TRUE)
    {
        if (L.bidderGroup[i].phoneNumber != t)
            i++;
        else
        {
            for (; i < L.length; ++i)
            {
                L.bidderGroup[i] = L.bidderGroup[i + 1];
                ++evalCount;
            }
            --L.length;
            cout << "\nDelete Finished.\n"
                 << endl;
            return;
        }
        if (i > L.length)
            break;
    }
    cout << "\nBidder not found.\n"
         << endl;

} // deleteBidder

// -----------------------------------
// Choose insert or delete
// -----------------------------------
void insertOrDelete(SqList &L)
{
    int choose = 0;
    while (!(choose == 1 || choose == 2))
    {
        cout << "\n1. Insert a bid\n"
             << "2. Delete a bid\n\n"
             << "Choose:";
        cin >> choose;
    }
    if (choose == 1)
        insertBidder(L);
    if (choose == 2)
        deleteBidder(L);
} // insertOrDelete