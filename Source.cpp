#include "Statistic.h"

// -----------------------------------
//             MAINCORE
// -----------------------------------

// -----------------------------------
// 菜单函数
// 负责人: 梁洪源 曾时铸
// -----------------------------------
void msg(SqList L)
{
    cout
        << "----------------------------------------\n"
        << "1. Load the file of BidderList \n"
        << "2. Create a new BidderList\n"
        << "3. Output the file of BidderList\n"
        << "4. Sort the BidderList\n"
        << "5. Print the BidderList\n"
        << "6. Insert/Delete bid\n"                     // NOT FINISHED
        << "7. Set the number of successful bidders\n"  // NOT FINISHED
        << "8. Output the List of successful bidders\n" // NOT FINISHED
        << "9. Destroy the BidderList\n"
        << "0. Exit\n"
        << "----------------------------------------\n"
        << "The highest price  :";
    (ifSorted == 1) ? (printf("%d\n", L.bidderGroup[L.length].price)) : (printf("Havn't Sorted\n"));
    cout
        << "The highest bidder :";
    (ifSorted == 1) ? (printf("%d\n", L.bidderGroup[L.length].phoneNumber)) : (printf("Havn't Sorted\n"));
    cout
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
        msg(L);
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
        case 4:
            sortTheAllBidderList(L);
            break;
        case 5:
            printTheAllBidderGroup(L);
            break;
        case 7:
            if (L.length == 0)
            {
                cout << "\nThere is no bid\n" << endl;
                break;
            }
            while (successfulBidders < 0 || successfulBidders > L.length){
            cout << "Enter the numbers of successful bidders(Now: " << L.length << " bidders):";
            cin >> successfulBidders;
            }
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
