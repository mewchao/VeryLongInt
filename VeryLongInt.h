/*************************************************
Copyright (C), 1988-1999, Tech. Co., Ltd.
File name: // 文件名
Author:
Version:
Date: // 作者、版本及完成日期
Description: // 用于详细说明此程序文件完成的主要功能，与其他模块
// 或函数的接口，输出值、取值范围、含义及参数间的控
// 制、顺序、独立或依赖等关系
Others: // 其它内容的说明
Function List: // 主要函数列表，每条记录应包括函数名及功能简要说明
1. ....
History: // 修改历史记录列表，每条修改记录应包括修改日期、修改
// 者及修改内容简述
1. Date:
Author:
Modification:
2. ...
*************************************************/
//3：源文件头部应进行注释，列出：版权说明、版本号、生成日期、作者、模块目的/功能、主要函数及其功能、修改日志等。
//示例：下面这段源文件的头注释比较标准，当然，并不局限于此格式，但上述信息建议要包含在内。
/************************************************************
Copyright (C), 2023-2023, 游竣超., Ltd.
FileName: VeryLongInt.h
Author: 游竣超
Version : 最新
Date: 2023.5.25
Description: Contains declarations of large integer c
             lasses and member functions, declarations of ordinary functions
Function List: // 主要函数及其功能
1. -------
History:
<游竣超> <time> <version > <desc>
David 96/10/12 1.0 build this moudle
***********************************************************/
#ifndef UNTITLED_VERYLONGINT_H
#define UNTITLED_VERYLONGINT_H

#ifndef IOSTREAM
#define IOSTREAM

#include <iostream>
#include <sstream>
#include <iomanip>

#endif // IOSTREAM_H

#ifndef VECTOR
#define VECTOR

#include <vector>

#endif // VECTOR

#ifndef ITERATOR
#define ITERATOR

#include <iterator>

#endif // ITERATOR_H

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
catch (invalic_number_exception & ex) {     std::cout<<ex.get()<<ex.what();     }
#endif //CATCH_INVALID_NUMBER_EXCEPTION

const int BASE = 10;
//"    ---Copyright---(c++) 2023-2023 游竣超(222200231). All Rights Reserved.---    "

class VeryLongInt {
private:
    //用向量存放数据
    //动态数组容器
    std::vector<int> digits;
    //负数->true
    bool negative = false;

public:
    const std::vector<int> &getDigits() const{return digits;};

    //字符串构造
    VeryLongInt(std::string str = "");

    //长整型构造
    VeryLongInt(long long other = 0);

    //用一个向量和正负号来构造
    VeryLongInt(std::vector<int> v, bool negative);

    //输出到10进制
    void print_decimal();

    //输出到16进制
    void print_hex();

    //输出到8进制
    void print_oct();

    //输出到10进制
    void print_decimal(std::ostream & os) const;

    //输出到16进制
    void print_hex(std::ostream & os) const;

    //输出到8进制
    void print_oct(std::ostream & os) const;

    // 取相反数
    VeryLongInt operator-() const;

    VeryLongInt Negative() const;

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

    friend std::ostream &operator<<(std::ostream &os, const VeryLongInt &num);

    friend std::istream &operator>>(std::istream &is, VeryLongInt &num);


    //重载++(VeryLongInt)
    VeryLongInt operator++();

    //重载--(VeryLongInt)
    VeryLongInt operator--();

    //重载(VeryLongInt)++
    VeryLongInt operator++(int);

    //重载(VeryLongInt)--
    VeryLongInt operator--(int);

    VeryLongInt operator+(const long int &other) const;

    VeryLongInt operator-(const long int &other) const;

    VeryLongInt operator*(const long int &other) const;

    VeryLongInt operator/(const long int &other) const;

    VeryLongInt operator%(const long int &other) const;

    VeryLongInt operator+=(const long int &other);

    VeryLongInt operator-=(const long int &other);

    VeryLongInt operator*=(const long int &other);

    VeryLongInt operator/=(const long int &other) ;

    VeryLongInt operator%=(const long int &other) ;

    VeryLongInt operator+(const std::string &other) const;

    VeryLongInt operator-(const std::string &other) const;

    VeryLongInt operator*(const std::string &other) const;

    VeryLongInt operator/(const std::string &other) const;

    VeryLongInt operator%(const std::string &other) const;

    VeryLongInt operator+=(const std::string &other);

    VeryLongInt operator-=(const std::string &other);

    VeryLongInt operator*=(const std::string &other);

    VeryLongInt operator/=(const std::string &other) ;

    VeryLongInt operator%=(const std::string &other);

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

    // 输出到流
    friend std::ostream &operator<<(std::ostream &os, const VeryLongInt &num);



    // 输出赋值运算符的重载
    void operator<<=(std::ostream &os) const {
        os << *this;
    }

    static VeryLongInt halve(const VeryLongInt &num) {
        VeryLongInt result(num);
        int carry = 0;
        for (int i = num.digits.size() - 1; i >= 0; i--) {
            int current = num.digits[i] + carry * 10;
            result.digits[i] = current / 2;
            carry = current % 2;
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
