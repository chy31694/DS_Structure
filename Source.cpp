#include "Headerfile.h"
// -----------------------------------
//             MAINCORE
// -----------------------------------

// -----------------------------------
// 各项整理&步骤计数
// 负责人: 梁洪源 曾时铸
// -----------------------------------
void msg(SqList L)
{
    cout
        << "-----------------------------------------------\n"
        << "*   1. Load the file of BidderList            *\n"
        << "*   2. Create a new BidderList                *\n"
        << "*   3. Output the file of BidderList          *\n"
        << "*   4. Sort the BidderList                    *\n"
        << "*   5. Print the BidderList                   *\n"
        << "*   6. Insert/Delete bid                      *\n"
        << "*   7. Set the number of successful bidders   *\n"
        << "*   8. Output the List of successful bidders  *\n"
        << "*   9. Destroy the BidderList                 *\n"
        << "*   0. Exit                                   *\n"
        << "-----------------------------------------------\n"
        << "The highest price  :";
    (ifSorted == 1) ? (printf("%d\n", L.bidderGroup[L.length].price)) : (printf("Havn't Sorted\n"));
    cout
        << "The highest bidder :";
    (ifSorted == 1) ? (printf("%d\n", L.bidderGroup[L.length].phoneNumber)) : (printf("Havn't Sorted\n"));
    cout
        << "-----------------------------------------------\n"
        << "Enter The Function You Choose: ";
} // msg

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
            cout << "\nTotal swapped " << swapCount << "times." << endl;
            swapCount = 0;
            break;
        case 5:
            printTheAllBidderGroup(L);
            break;
        case 6:
            insertOrDelete(L);
            break;
        case 7:
            setTheNumberOfSuccessfulBidders(L);
            break;
        case 8:
            outputTheListOfSuccessfulBidders(L);
            break;
        case 9:
            destroyTheFile();
            destroyTheTemp(L);
            break;
        case 0:
            exit(1);
            // case -1:
            //     setTestMod();
            break;
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