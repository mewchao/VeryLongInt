#ifndef UNTITLED_VERYLONGINT_H
#define UNTITLED_VERYLONGINT_H

#ifndef IOSTREAM
#define IOSTREAM

#include <iostream>

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

const int BASE=10;
//"    ---Copyright---(c++) 2023-2023 游竣超(222200231). All Rights Reserved.---    "

class VeryLongInt {
private:
    //用向量存放数据
    //动态数组容器
    std::vector<int> digits;
    //负数->true
    bool negative=false;

public:
    //字符串构造
    VeryLongInt(std::string str="");

    //长整型构造
    VeryLongInt(long int other=0);

    //用一个向量和正负号来构造
    VeryLongInt(std::vector<int> v, bool negative);

    void print();

    // 取相反数
    VeryLongInt operator-() const;

    VeryLongInt Negative() const;

    VeryLongInt operator+(const VeryLongInt &other) const;

    VeryLongInt operator-(const VeryLongInt &other) const;

    VeryLongInt operator*(const VeryLongInt &other) const;

    VeryLongInt operator/(const VeryLongInt &other) const;

    VeryLongInt operator%(const VeryLongInt &other) const;

    VeryLongInt operator=( VeryLongInt other);

    VeryLongInt operator+=(const VeryLongInt &other);

    VeryLongInt operator-=(const VeryLongInt &other);

    VeryLongInt operator*=(const VeryLongInt &other);

    void normalize(const VeryLongInt& divisor);

    //重载++(VeryLongInt)
    VeryLongInt operator++() ;

    //重载--(VeryLongInt)
    VeryLongInt operator--() ;

    //重载(VeryLongInt)++
    VeryLongInt operator++(int) ;

    //重载(VeryLongInt)--
    VeryLongInt operator--(int) ;

    VeryLongInt operator+(const long int &other) const;

    VeryLongInt operator-(const long int &other) const;

    VeryLongInt operator*(const long int &other) const;

    VeryLongInt operator+=(const long int &other);

    VeryLongInt operator-=(const long int &other);

    VeryLongInt operator*=(const long int &other);

    VeryLongInt operator+(const std::string &other) const;

    VeryLongInt operator-(const std::string &other) const;

    VeryLongInt operator*(const std::string &other) const;

    VeryLongInt operator+=(const std::string &other);

    VeryLongInt operator-=(const std::string &other);

    VeryLongInt operator*=(const std::string &other);

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
};

//存放非法十六进制和非法八进制字符串
class invalic_number_exception : public std::logic_error {
public:
    invalic_number_exception(const std::string& num) : m_message(num), logic_error("注意，该数字不合法！！") {}

    const char* get() const  {
        return m_message.c_str();
    }

private:
    std::string m_message;
};
bool isHexadecimal(long int number);

bool isOctal(long int number);

long int hexadecimalToDecimal(long int hexadecimalNumber);

long int octalToDecimal(long int octalNumber);

void show_copyright();

void show_time();

#endif //UNTITLED_VERYLONGINT_H
