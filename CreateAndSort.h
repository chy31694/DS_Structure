#include "Headerfile.h"
// -----------------------------------
// 模块: 创建和排序数据组
// 负责人: 陈宇航 赵子航 田祺
// 暂定目标: 此模块将数据处理完毕后,导入至全局变量数组 bidderGroup中
// -----------------------------------

bool InitList_Sq(SqList &L)
{
    // 构造一个空的线性表L
    L.bidderGroup = new Bidder[MAXSIZE];
    if (!L.bidderGroup)
        exit(OVERFLOW); // 分配空间失败

    L.length = 0;
    return OK;
} // InitList_Sq