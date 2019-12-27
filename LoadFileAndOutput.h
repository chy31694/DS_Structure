#include "InsertAndDelete.h"
// -----------------------------------
// 模块:文件的载入和导出
// 负责人:杭子奇
// 暂定目标: 编写函数, 实现:
// 1.将已有的外部数据文件载入全局变量数组 bidderGroup
// 2.将程序内的 bidderGroup数据导出至外部文件
// -----------------------------------

// -----------------------------------
// Output File
// -----------------------------------
void outputTheAllbidderList(SqList L)
{
    int i;

    if (L.length == 0)
    {
        cout << "\nThere is no bid." << endl;
        return;
    }

    FILE *fp;
    fp = fopen("BidderList", "w");
    fprintf(fp, "This is the List of bidder\nWARNING: DO NOT MODIFY THE FORMAT!\n\n");
    fprintf(fp, "Length: %d\n\n", L.length);
    for (i = 1; i <= L.length; ++i)
    {
        fprintf(fp, "Num %04d. Phone: %d  Price: %d\n", i, L.bidderGroup[i].phoneNumber, L.bidderGroup[i].price);
    }

    fclose(fp);
} // outputTheAllbidderList

// -----------------------------------
// Load File
// -----------------------------------
void loadTheAllbidderList(SqList &L)
{
    InitList_Sq(L);

    int i, t;
    FILE *fp;

    fp = fopen("BidderList", "r");
    if ((fp = fopen("BidderList", "r")) == NULL)
    {
        cout << "\nFile not found!\n"
             << endl;
        return;
    }

    fscanf(fp, "This is the List of bidder\nWARNING: DO NOT MODIFY THE FORMAT!\n\n");
    fscanf(fp, "Length: %d\n\n", &L.length);

    for (i = 1; i <= L.length; ++i)
    {
        fscanf(fp, "Num %04d. Phone: %d  Price: %d\n", &t, &L.bidderGroup[i].phoneNumber, &L.bidderGroup[i].price);
    }

    fclose(fp);
} // loadTheAllbidderList
