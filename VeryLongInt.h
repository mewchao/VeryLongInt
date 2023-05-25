/*************************************************
 *  class:02
 *  id:   222200231
 *  name: 游竣超
 *  phone number:15059635473
 *  email :2835190741@qq.com
 *  开发环境：clion 2022版本和 github远程仓库连接
 *  运行环境：CMake，一个跨平台的安装（编译）工具
Copyright (C), 2023-2023, 游竣超.
FileName: VeryLongInt.h
Author: 游竣超
Version : 最新
Date: 2023.5.25
Description: Contains declarations of large integer c
             lasses and member functions, declarations of ordinary functions
Function List: class VeryLongInt ;                                                             //大整数类
               class invalic_number_exception ;                                                //存放异常十六进制八进制
               std::string convert_base(const std::string &number, int oldBase, int newBase);
                std::string as_base(int number, int base);
                std::string convert_to_decimal(const std::vector<int> &digits);
                bool is_hexadecimal(long int number);
                bool is_octal(long int number);
                long int hexadecimal_to_decimal(long int hexadecimal_number);
                long int octal_to_decimal(long int octalNumber);
                void show_copyright();
                void show_time();
Modification Log :first commit               2023.5.17
                 完善加减法重载                 2023.5.18
                 完善乘法除法重载和其他类型的op    2023.5.19
                  修改了几个bug                2023.5.20
                  增加了十六进制八进制的构造       2023.5.20
                  增加了十六进制八进制的输出       2023.5.21
                  修改了字符串构造的bug          2023.5.22
                  fix                        2023.5.22
                  程序功能完成                  2023.5.23
                  重新格式化输出，格式化代码       2023.5.23
                  完善注解                     2023.5.24
                  完善main函数                 2023.5.24
<游竣超> <2023.5.25> <latest > <VeryLongInt.h>题
***********************************************************/
#ifndef UNTITLED_VERYLONGINT_H
#define UNTITLED_VERYLONGINT_H

#ifndef IOSTREAM
#define IOSTREAM

#include <iostream>

#endif // IOSTREAM_H


#ifndef SSTREAM
#define SSTREAM

#include <sstream>

#endif // SSTREAM


#ifndef IOMANIP
#define IOMANIP

#include <iomanip>

#endif // IOMANIP

#ifndef VECTOR
#define VECTOR

#include <vector>

#endif // VECTOR

#ifndef ITERATOR
#define ITERATOR

#include <iterator>


#endif // ITERATOR_H


#ifndef STDLIB_H
#define STDLIB_H

#include<stdlib.h>

#endif//STDLIB_H

#ifndef STRING
#define STRING

#include <string>

#endif // STRING_H

#ifndef ALGORITHM
#define ALGORITHM

#include <algorithm>

#endif // ALGORITHM_H

#ifndef WINDOWS_H
#define WINDOWS_H

#include <windows.h>

#endif // WINDOWS_H

#ifndef MATH_H
#define MATH_H

#include <math.h>

#endif // MATH_H

#ifndef CLIMITS
#define CLIMITS

#include <climits>

#endif // CLIMITS

#ifndef STDIOSTREAM
#define STDIOSTREAM

#include <stdexcept>

#endif // STDIOSTREAM_H

#ifndef STRING_H
#define STRING_H

#include <string.h>

#endif // STRING_H

//捕获非法十六进制，八进制异常
#ifndef CATCH_INVALID_NUMBER_EXCEPTION
#define CATCH_INVALID_NUMBER_EXCEPTION \
catch (invalic_number_exception & ex) {\
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);\
SetConsoleTextAttribute(hConsole, 4);  \
std::cout<<ex.get()<<ex.what()<<std::endl;     }
#endif //CATCH_INVALID_NUMBER_EXCEPTION

//捕获除以0错
#ifndef CATCH_INVALID_DIVISION
#define CATCH_INVALID_DIVISION \
catch (std::invalid_argument & ex) {\
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);\
SetConsoleTextAttribute(hConsole, 4);             \
std::cout<<ex.what()<<std::endl;     }
#endif //CATCH_INVALID_DIVISION

//捕获模以0错
#ifndef CATCH_INVALID_MOD
#define CATCH_INVALID_MOD \
catch (std::invalid_argument & ex) {\
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);\
SetConsoleTextAttribute(hConsole, 4);             \
std::cout<<ex.get()<<std::endl;     }
#endif //CATCH_INVALID_MOD


const int BASE=10;

class VeryLongInt {
private:
    //用向量存放数据
    //动态数组容器
    std::vector<int> digits;
    //负数->true
    bool negative=false;

public:
    const std::vector<int> &getDigits() const { return digits; };

    //字符串构造
    VeryLongInt(std::string str="");

    //长整型构造
    VeryLongInt(long long other);

    //用一个向量和正负号来构造
    VeryLongInt(std::vector<int> v, bool negative);

    //输出到10进制
    void print_decimal();

    //输出到16进制
    void print_hex();

    //输出到8进制
    void print_oct();

    //输出到10进制
    void print_decimal(std::ostream &os) const;

    //输出到16进制
    void print_hex(std::ostream &os) const;

    //输出到8进制
    void print_oct(std::ostream &os) const;

    // 取相反数
    VeryLongInt operator-() const;

    VeryLongInt Negative() const;

//============================================任意长整数类op任意长整数类==============================
    VeryLongInt operator+(const VeryLongInt &other) const;

    VeryLongInt operator-(const VeryLongInt &other) const;

    VeryLongInt operator*(const VeryLongInt &other) const;

    VeryLongInt operator/(const VeryLongInt &other) const;

    VeryLongInt operator%(const VeryLongInt &other) const;

    VeryLongInt operator=(VeryLongInt other);

    VeryLongInt operator+=(const VeryLongInt &other);

    VeryLongInt operator-=(const VeryLongInt &other);

    VeryLongInt operator*=(const VeryLongInt &other);

    VeryLongInt operator/=(const VeryLongInt &other);

    VeryLongInt operator%=(const VeryLongInt &other);
//===========================================================重载<< >>==============================================================
    friend std::ostream &operator<<(std::ostream &os, const VeryLongInt &num);

    friend std::istream &operator>>(std::istream &is, VeryLongInt &num);

    void is_negative(){
        if(negative)
            std::cout<<"is negative!"<<std::endl;
        else{
            std::cout<<"is not negative!"<<std::endl;
        }
    }


    //重载++(VeryLongInt)
    VeryLongInt operator++();

    //重载--(VeryLongInt)
    VeryLongInt operator--();

    //重载(VeryLongInt)++
    VeryLongInt operator++(int);

    //重载(VeryLongInt)--
    VeryLongInt operator--(int);

//============================================任意长整数类op长整数==============================
    VeryLongInt operator+(const long int &other) const;

    VeryLongInt operator-(const long int &other) const;

    VeryLongInt operator*(const long int &other) const;

    VeryLongInt operator/(const long int &other) const;

    VeryLongInt operator%(const long int &other) const;

    VeryLongInt operator+=(const long int &other);

    VeryLongInt operator-=(const long int &other);

    VeryLongInt operator*=(const long int &other);

    VeryLongInt operator/=(const long int &other);

    VeryLongInt operator%=(const long int &other);

//============================================任意长整数类op字符串==============================

    VeryLongInt operator+(const std::string &other) const;

    VeryLongInt operator-(const std::string &other) const;

    VeryLongInt operator*(const std::string &other) const;

    VeryLongInt operator/(const std::string &other) const;

    VeryLongInt operator%(const std::string &other) const;

    VeryLongInt operator+=(const std::string &other);

    VeryLongInt operator-=(const std::string &other);

    VeryLongInt operator*=(const std::string &other);

    VeryLongInt operator/=(const std::string &other);

    VeryLongInt operator%=(const std::string &other);
    // 重载<
    bool operator<(const std::string &other) const;

    //重载>
    bool operator>(const std::string &other) const;

    //重载>=
    bool operator>=(const std::string &other) const;

    //重载<=
    bool operator<=(const std::string &other) const;


//===========================================逻辑运算符==============================
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

    // 判断相等
    bool operator!=(const VeryLongInt &other) const;



static VeryLongInt halve(const VeryLongInt &num) {
        VeryLongInt result(num);
        int carry=0;
        for (int i=num.digits.size()-1; i>=0; i--) {
            int current=num.digits[i]+carry*10;
            result.digits[i]=current/2;
            carry=current%2;
        }
        return result;
    }
};

//存放非法十六进制和非法八进制字符串
class invalic_number_exception : public std::logic_error {
public:
    invalic_number_exception(const std::string &num) : m_message(num), logic_error("注意，该数字不合法！！") {}

    const char *get() const {
        return m_message.c_str();
    }

private:
    std::string m_message;

};

std::string convert_base(const std::string &number, int oldBase, int newBase);

std::string as_base(int number, int base);

std::string convert_to_decimal(const std::vector<int> &digits);

bool is_hexadecimal(long int number);

bool is_octal(long int number);

long int hexadecimal_to_decimal(long int hexadecimal_number);

long int octal_to_decimal(long int octalNumber);

void show_copyright();

void show_time();

#endif //UNTITLED_VERYLONGINT_H
