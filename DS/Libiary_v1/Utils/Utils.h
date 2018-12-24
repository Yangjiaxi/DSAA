/*
    Some useful functions
*/

#ifndef USEFUL_FUNC_H
#define USEFUL_FUNC_H

// 布尔类型
#define False 0
#define True 1
typedef char Bool;

// 报告错误信息并退出
void Fatal(const char* info);
// 连接字符串，使用后需要free
char* StrConcat(const char* s1, char* s2);
// 输出"[ $text ]"，并用pad在两侧填充至宽度为width
void AlignPrint(int width, char pad, const char* text);
// 换行
void endl();
// 在str中寻找字母ch首次出现的下标，没找到则返回-1
int FindChar(const char* str, char ch);
// 从str开始拷贝size个元素，返回指针，需要使用后free
char* StrCopy(const char* str, int size);
// 获取控制台宽度
int GetConsoleWidth();
// 比大小
int Max(int a, int b);
// 获取[L, R)区间内的随机数
int GetRandomNumber(int L, int R);
// 判断num是否为素数
Bool IsPrime(int num);
// 产生num后的第一个素数(如果num不是素数)
int NextPrime(int num);
// 计算数组的平均值
double ArrayMean(int a[], int size);
// 计算数组的标准差
double ArrayStd(int a[], int size);
// 产生未初始化的malloc数组， bytes * size的空间
void* AllocArray(unsigned bytes, unsigned size);
// 产生0初始化的malloc数组，见上
void* AllocZeroArray(unsigned bytes, unsigned size);
// 产生特定初始化的数组
void* AllocSpecArray(unsigned bytes, unsigned size, char spec);
// 随机生成字符串
char* RandomString(unsigned size);
// 整数次方a^b
int IntPow(int a, int b);
// 字符串比较
int CmpString(const char* LHS, const char* RHS);
// 整数比较
int CmpInteger(int LHS, int RHS);
#endif  // USEFUL_FUNC_H