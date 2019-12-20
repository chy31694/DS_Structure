#include "Headerfile.h"
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
