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
