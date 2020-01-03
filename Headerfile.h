// 如果自己调用的函数需要相应的头文件支持则自行在这里添加
// 定义或者全局变量也是在这里添加

// ----------------------------
// EXTERNAL INCLUDE
// ----------------------------
#include <iostream>
#include <iomanip>
#include <time.h>
#include <string.h>

using namespace std;

// ----------------------------
// DEFINE
// ----------------------------
#define MAXSIZE 3000
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OVERFLOW -1
#define OK 1

// ----------------------------
// STRUCT
// ----------------------------
typedef struct Bidder
{                    // 表示每一条竞价信息
    int phoneNumber; // 竞价信息的序列号(手机号)
    int price;       // 竞价信息的出价
} Bidder, *bidNode;

typedef struct
{
    Bidder *bidderGroup;
    int length; //当前长度
} SqList;

int ifSorted = 0; // 当前程序内的bidderGroup是否已排序,未排序为 0 ,已排序为 1 ;
int successfulBidders = 0; // 中标者设定数量
// int TestMod = 0;    // 开发者模式

int swapCount = 0;  // 交换次数 ;
int evalCount = 0;  // 移动与赋值次数 ;
int compCount = 0;  // 比较次数 ;

// ----------------------------
// FILE INCLUDE
// ----------------------------
#include "CreateAndSort.h"
#include "InsertAndDelete.h"
#include "LoadFileAndOutput.h"