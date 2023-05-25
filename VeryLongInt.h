/*************************************************
 *  class:02
 *  id:   222200231
 *  name: �ο���
 *  phone number:15059635473
 *  email :2835190741@qq.com
 *  ����������clion 2022�汾�� githubԶ�ֿ̲�����
 *  ���л�����CMake��һ����ƽ̨�İ�װ�����룩����
Copyright (C), 2023-2023, �ο���.
FileName: VeryLongInt.h
Author: �ο���
Version : ����
Date: 2023.5.25
Description: Contains declarations of large integer c
             lasses and member functions, declarations of ordinary functions
Function List: class VeryLongInt ;                                                             //��������
               class invalic_number_exception ;                                                //����쳣ʮ�����ư˽���
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
                 ���ƼӼ�������                 2023.5.18
                 ���Ƴ˷��������غ��������͵�op    2023.5.19
                  �޸��˼���bug                2023.5.20
                  ������ʮ�����ư˽��ƵĹ���       2023.5.20
                  ������ʮ�����ư˽��Ƶ����       2023.5.21
                  �޸����ַ��������bug          2023.5.22
                  fix                        2023.5.22
                  ���������                  2023.5.23
                  ���¸�ʽ���������ʽ������       2023.5.23
                  ����ע��                     2023.5.24
                  ����main����                 2023.5.24
<�ο���> <2023.5.25> <latest > <VeryLongInt.h>��
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

//����Ƿ�ʮ�����ƣ��˽����쳣
#ifndef CATCH_INVALID_NUMBER_EXCEPTION
#define CATCH_INVALID_NUMBER_EXCEPTION \
catch (invalic_number_exception & ex) {\
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);\
SetConsoleTextAttribute(hConsole, 4);  \
std::cout<<ex.get()<<ex.what()<<std::endl;     }
#endif //CATCH_INVALID_NUMBER_EXCEPTION

//�������0��
#ifndef CATCH_INVALID_DIVISION
#define CATCH_INVALID_DIVISION \
catch (std::invalid_argument & ex) {\
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);\
SetConsoleTextAttribute(hConsole, 4);             \
std::cout<<ex.what()<<std::endl;     }
#endif //CATCH_INVALID_DIVISION

//����ģ��0��
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
    //�������������
    //��̬��������
    std::vector<int> digits;
    //����->true
    bool negative=false;

public:
    const std::vector<int> &getDigits() const { return digits; };

    //�ַ�������
    VeryLongInt(std::string str="");

    //�����͹���
    VeryLongInt(long long other);

    //��һ��������������������
    VeryLongInt(std::vector<int> v, bool negative);

    //�����10����
    void print_decimal();

    //�����16����
    void print_hex();

    //�����8����
    void print_oct();

    //�����10����
    void print_decimal(std::ostream &os) const;

    //�����16����
    void print_hex(std::ostream &os) const;

    //�����8����
    void print_oct(std::ostream &os) const;

    // ȡ�෴��
    VeryLongInt operator-() const;

    VeryLongInt Negative() const;

//============================================���ⳤ������op���ⳤ������==============================
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
//===========================================================����<< >>==============================================================
    friend std::ostream &operator<<(std::ostream &os, const VeryLongInt &num);

    friend std::istream &operator>>(std::istream &is, VeryLongInt &num);

    void is_negative(){
        if(negative)
            std::cout<<"is negative!"<<std::endl;
        else{
            std::cout<<"is not negative!"<<std::endl;
        }
    }


    //����++(VeryLongInt)
    VeryLongInt operator++();

    //����--(VeryLongInt)
    VeryLongInt operator--();

    //����(VeryLongInt)++
    VeryLongInt operator++(int);

    //����(VeryLongInt)--
    VeryLongInt operator--(int);

//============================================���ⳤ������op������==============================
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

//============================================���ⳤ������op�ַ���==============================

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
    // ����<
    bool operator<(const std::string &other) const;

    //����>
    bool operator>(const std::string &other) const;

    //����>=
    bool operator>=(const std::string &other) const;

    //����<=
    bool operator<=(const std::string &other) const;


//===========================================�߼������==============================
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
