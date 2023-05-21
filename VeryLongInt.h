#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<windows.h>

#ifndef UNTITLED_VERYLONGINT_H
#define UNTITLED_VERYLONGINT_H
using namespace std;

//"    ---Copyright---(c++) 2023-2023 游竣超(222200231). All Rights Reserved.---    "

class VeryLongInt {
private:
    //用向量存放数据
    //动态数组容器
    vector<int> digits;
    //负数->true
    bool negative=false;

public:
    //字符串构造
    VeryLongInt(string str);

    //长整型构造
    VeryLongInt(long int other);

    //用一个向量和正负号来构造
    VeryLongInt(vector<int> v, bool negative);

    void print();

    // 取相反数
    VeryLongInt operator-() const;

    VeryLongInt Negative() const;

    VeryLongInt operator+(const VeryLongInt &other) const;

    VeryLongInt operator-(const VeryLongInt &other) const;

    VeryLongInt operator*(const VeryLongInt &other) const;

    VeryLongInt operator+=(const VeryLongInt &other);

    VeryLongInt operator-=(const VeryLongInt &other);

    VeryLongInt operator*=(const VeryLongInt &other);

    VeryLongInt operator+(const long int &other) const;

    VeryLongInt operator-(const long int &other) const;

    VeryLongInt operator*(const long int &other) const;

    VeryLongInt operator+=(const long int &other);

    VeryLongInt operator-=(const long int &other);

    VeryLongInt operator*=(const long int &other);

    VeryLongInt operator=(const VeryLongInt &other);

    VeryLongInt operator+(const string &other) const;

    VeryLongInt operator-(const string &other) const;

    VeryLongInt operator*(const string &other) const;

    VeryLongInt operator+=(const string &other);

    VeryLongInt operator-=(const string &other);

    VeryLongInt operator*=(const string &other);

    // 重载<
    bool operator<(const VeryLongInt &other) const;

    //重载>
    bool operator>(const VeryLongInt &other) const;

    //重载>=
    bool operator>=(const VeryLongInt &other) const;

    //重载<=
    bool operator<=(const VeryLongInt &other) const;

    // 判断相等
    bool operator==(const VeryLongInt &other) const;

    // 输出到流
    friend std::ostream &operator<<(std::ostream &os, const VeryLongInt &num);
};

void show_copyright();

void show_time();

#endif //UNTITLED_VERYLONGINT_H
