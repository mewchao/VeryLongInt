/*************************************************
Copyright (C), 1988-1999, Tech. Co., Ltd.
File name: // �ļ���
Author:
Version:
Date: // ���ߡ��汾���������
Description: // ������ϸ˵���˳����ļ���ɵ���Ҫ���ܣ�������ģ��
// �����Ľӿڣ����ֵ��ȡֵ��Χ�����弰������Ŀ�
// �ơ�˳�򡢶����������ȹ�ϵ
Others: // �������ݵ�˵��
Function List: // ��Ҫ�����б�ÿ����¼Ӧ���������������ܼ�Ҫ˵��
1. ....
History: // �޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸�
// �߼��޸����ݼ���
1. Date:
Author:
Modification:
2. ...
*************************************************/
//3��Դ�ļ�ͷ��Ӧ����ע�ͣ��г�����Ȩ˵�����汾�š��������ڡ����ߡ�ģ��Ŀ��/���ܡ���Ҫ�������书�ܡ��޸���־�ȡ�
//ʾ�����������Դ�ļ���ͷע�ͱȽϱ�׼����Ȼ�����������ڴ˸�ʽ����������Ϣ����Ҫ�������ڡ�
/************************************************************
Copyright (C), 2023-2023, �ο���., Ltd.
FileName: VeryLongInt.h
Author: �ο���
Version : ����
Date: 2023.5.25
Description: Contains declarations of large integer c
             lasses and member functions, declarations of ordinary functions
Function List: // ��Ҫ�������书��
1. -------
History:
<�ο���> <time> <version > <desc>
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

//����Ƿ�ʮ�����ƣ��˽����쳣
#ifndef CATCH_INVALID_NUMBER_EXCEPTION
#define CATCH_INVALID_NUMBER_EXCEPTION \
catch (invalic_number_exception & ex) {     std::cout<<ex.get()<<ex.what();     }
#endif //CATCH_INVALID_NUMBER_EXCEPTION

const int BASE = 10;
//"    ---Copyright---(c++) 2023-2023 �ο���(222200231). All Rights Reserved.---    "

class VeryLongInt {
private:
    //�������������
    //��̬��������
    std::vector<int> digits;
    //����->true
    bool negative = false;

public:
    const std::vector<int> &getDigits() const{return digits;};

    //�ַ�������
    VeryLongInt(std::string str = "");

    //�����͹���
    VeryLongInt(long long other = 0);

    //��һ��������������������
    VeryLongInt(std::vector<int> v, bool negative);

    //�����10����
    void print_decimal();

    //�����16����
    void print_hex();

    //�����8����
    void print_oct();

    //�����10����
    void print_decimal(std::ostream & os) const;

    //�����16����
    void print_hex(std::ostream & os) const;

    //�����8����
    void print_oct(std::ostream & os) const;

    // ȡ�෴��
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


    //����++(VeryLongInt)
    VeryLongInt operator++();

    //����--(VeryLongInt)
    VeryLongInt operator--();

    //����(VeryLongInt)++
    VeryLongInt operator++(int);

    //����(VeryLongInt)--
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



    // �����ֵ�����������
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

//��ŷǷ�ʮ�����ƺͷǷ��˽����ַ���
class invalic_number_exception : public std::logic_error {
public:
    invalic_number_exception(const std::string &num) : m_message(num), logic_error("ע�⣬�����ֲ��Ϸ�����") {}

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
