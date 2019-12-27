#include "Statistic.h"

// -----------------------------------
//            MAIN CORE
// -----------------------------------

// -----------------------------------
// 菜单函数
// 负责人: 梁洪源 曾时铸
// -----------------------------------
void msg(void)
{
    cout
        << "----------------------------------------\n"
        << "1. Load the file of BidderList \n"
        << "2. Create a new BidderList\n"
        << "3. Output the file of BidderList\n"
        << "4. Sort the BidderList\n"// NOT FINISHED
        << "5. Print the BidderList\n"
        << "6. Insert/Delete bid\n"// NOT FINISHED
        << "7. Set the number of successful bidders\n"// NOT FINISHED
        << "8. Output the List of successful bidders\n"// NOT FINISHED
        << "9. Destroy the BidderList\n"// NOT FINISHED
        << "0. Exit\n"
        << "----------------------------------------\n"
        << "The highest bidder:\n" // << *最高出价的竞价序列号
        << "The highest price:\n"  // << *最高出价
        << "----------------------------------------\n"
        << "Enter the function you choose: ";
}

// -----------------------------------
// chooseFuction
// -----------------------------------
void chooseFuction(void)
{
    SqList L;
    InitList_Sq(L);
    int choose;
    int n;

    do
    {
        msg();
        cin >> choose;

        switch (choose)
        {
        case 1:
            loadTheAllbidderList(L);
            break;

        case 2:
            createTheBidderGroup(L);
            break;

        case 3:
            outputTheAllbidderList(L);
            break;

        case 5:
            printTheAllBidderGroup(L);
            break;

        case 9:
            destroyTheFile();
            destroyTheTemp(L);
            break;

        case 0:
            exit(1);
        }
    } while (choose != 0);
} // chooseFuction

// -----------------------------------
// THE START
// -----------------------------------
int main(int argc, char const *argv[])
{
    chooseFuction();
    return 0;
} // main
