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

//����Ƿ�ʮ�����ƣ��˽����쳣
#ifndef CATCH_INVALID_NUMBER_EXCEPTION
#define CATCH_INVALID_NUMBER_EXCEPTION \
catch (invalic_number_exception & ex) {     std::cout<<ex.get()<<ex.what();     }
#endif //CATCH_INVALID_NUMBER_EXCEPTION

const int BASE=10;
//"    ---Copyright---(c++) 2023-2023 �ο���(222200231). All Rights Reserved.---    "

class VeryLongInt {
private:
    //�������������
    //��̬��������
    std::vector<int> digits;
    //����->true
    bool negative=false;

public:
    //�ַ�������
    VeryLongInt(std::string str="");

    //�����͹���
    VeryLongInt(long int other=0);

    //��һ��������������������
    VeryLongInt(std::vector<int> v, bool negative);

    void print();

    // ȡ�෴��
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

    //����++(VeryLongInt)
    VeryLongInt operator++() ;

    //����--(VeryLongInt)
    VeryLongInt operator--() ;

    //����(VeryLongInt)++
    VeryLongInt operator++(int) ;

    //����(VeryLongInt)--
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

    // ����<
    bool operator<(const VeryLongInt &other) const;

    //����>
    bool operator>(const VeryLongInt &other) const;

    //����>=
    bool operator>=(const VeryLongInt &other) const;

    //����<=
    bool operator<=(const VeryLongInt &other) const;

    // �ж����
    bool operator==(const VeryLongInt &other) const;

    // �ж����
    bool operator!=(const VeryLongInt &other) const;

    // �������
    friend std::ostream &operator<<(std::ostream &os, const VeryLongInt &num);
};

//��ŷǷ�ʮ�����ƺͷǷ��˽����ַ���
class invalic_number_exception : public std::logic_error {
public:
    invalic_number_exception(const std::string& num) : m_message(num), logic_error("ע�⣬�����ֲ��Ϸ�����") {}

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
