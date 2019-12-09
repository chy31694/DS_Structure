// 如果自己调用的函数需要相应的头文件支持则自行在这里添加
// 定义或者全局变量也是在这里添加

// ----------------------------
// 头文件
// ----------------------------
#include <iostream>

using namespace std;
// ----------------------------

// ----------------------------
// 定义
// ----------------------------
#define MAXSIZE 3000
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OVERFLOW -1
// ----------------------------

// ----------------------------
// 全局变量
// ----------------------------
typedef struct Bidder
{                    // 表示每一条竞价信息
    int phoneNumber; // 竞价信息的序列号(手机号)
    int price;       // 竞价信息的出价
} Bidder, *bidNode;

Bidder bidderGroup[MAXSIZE];    // 竞价信息组
int ifSorted = 0;               // 当前程序内的bidderGroup是否已排序,未排序为 0 ,已排序为 1 ;
// -----------------------------