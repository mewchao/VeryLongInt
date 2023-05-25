/*************************************************
Copyright (C), 2023-2023, �ο���.
FileName: VeryLongInt.cpp
Author: �ο���
Version : ����
Date: 2023.5.25
Description: Contains large integer member function, common function definition implementation
Function List:
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
<�ο���> <2023.5.25> <latest > <VeryLongInt.cpp>
***********************************************************/
# include "VeryLongInt.h"

//ʮ���Ƶĳ����ι���
VeryLongInt::VeryLongInt(long long other) {
    if (is_octal(other)) {
        other=octal_to_decimal(other);
    }
    if (is_hexadecimal(other)) {
        other=hexadecimal_to_decimal(other);
    }
    if (other<0) {
        this->negative=true;
        other=-other;
    } else {
        this->negative=false;
    }
    while (other) {
        this->digits.push_back(other%10);
        other/=10;
    }
}

//�ø��ֽ��Ƶ��ַ����������������
VeryLongInt::VeryLongInt(std::string str) {
    //default
    if (str==""||str=="0") {
        *this=VeryLongInt(0);
        return;
    }

    if (str[0]=='-') {
        str.erase(0, 1);
        this->negative=true;
    }
    else this->negative=false;
    if (str[0]=='0') {
        if (str[1]=='x'||str[1]=='X') { // Hexadecimal
            str.erase(0, 2);
            for (int i=str.size()-1; i>=0; i--) {
                int hex_digit;
                if (str[i]>='0'&&str[i]<='9')
                    hex_digit=(str[i]-'0');
                else if (str[i]>='a'&&str[i]<='f')
                    hex_digit=(str[i]-'a'+10);
                else if (str[i]>='A'&&str[i]<='F')
                    hex_digit=(str[i]-'A'+10);
                else
                    throw invalic_number_exception(str);
            }
            std::string rts=convert_base(str, 16, 10);
            *this=VeryLongInt(rts);
        } else { // Octal
            if (str[1]=='O'||str[1]=='o') {
                str.erase(0, 2);
            } else {
                str.erase(0, 1);
            }
            for (int i=str.size()-1; i>=0; i--) {
                int hex_digit;
                if (str[i]>='0'&&str[i]<'8')
                    hex_digit=(str[i]-'0');
                else
                    throw invalic_number_exception(str);
            }
            std::string rts=convert_base(str, 8, 10);
            *this=VeryLongInt(rts);
        }
    } else { // Decimal
        for (int i=str.size()-1; i>=0; i--) {
            if (str[i]<'0'||str[i]>'9')
                throw invalic_number_exception(str);
            digits.push_back(str[i]-'0');
        }
    }
}


bool is_octal(long int number) {
    std::string str_number=std::to_string(number);
    if (str_number.length()>1&&str_number[0]=='0') {
        for (size_t i=1; i<str_number.length(); ++i) {
            if (str_number[i]<'0'||str_number[i]>'7') {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool is_hexadecimal(long int number) {
    std::string str_number=std::to_string(number);
    if (str_number.length()>2&&str_number[0]=='0'&&
        (str_number[1]=='x'||str_number[1]=='X')) {
        for (size_t i=2; i<str_number.length(); ++i) {
            if (!((str_number[i]>='0'&&str_number[i]<='9')||
                  (str_number[i]>='A'&&str_number[i]<='F')||
                  (str_number[i]>='a'&&str_number[i]<='f'))) {
                return false;
            }
        }
        return true;
    }
    return false;
}


long int octal_to_decimal(long int octalNumber) {
    std::string strOctal=std::to_string(octalNumber);
    long int decimal_number=std::stol(strOctal, nullptr, 8);
    return decimal_number;
}

long int hexadecimal_to_decimal(long int hexadecimal_number) {
    std::string str_hexadecimal=std::to_string(hexadecimal_number);
    long int decimal_number=std::stol(str_hexadecimal, nullptr, 16);
    return decimal_number;
}

//��һ��������������������
VeryLongInt::VeryLongInt(std::vector<int> v, bool negative) {
    this->digits=v;
    this->negative=negative;
}

//���ʮ����
void VeryLongInt::print_decimal() {
    if (negative)std::cout<<"-";
    std::cout<<"decimal: ";
    if (digits.empty()) {
        std::cout<<"0"<<std::endl;
        return;
    }
    if (negative) {
        std::cout<<"-";
    }
//    350627200407240014 ->size=18%4=2 ->
    int size=digits.size()%4;
    int flag=1;
    for (int i=digits.size()-1, j=1; i>=0; i--, j++) {
        if (j-1==size&&flag) {
            //�ҵ���һ������ո��λ��size
            j=1;
            flag=0;
            std::cout<<" ";
        }
        std::cout<<digits[i];
        if (j%4==0) std::cout<<" ";

    }
    std::cout<<std::endl;
}


//���ʮ������
void VeryLongInt::print_hex() {
    if (negative)std::cout<<"-";
    std::cout<<"hex: ";
    auto number_str=convert_to_decimal(digits);
    std::string hex=convert_base(number_str, 10, 16);
    hex="0X"+hex;
    int size=hex.size()%4;
    int flag=1;
    for (int i=0, j=1; i<hex.size(); i++, j++) {
        if (j-1==size&&flag&&size!=0) {
            //�ҵ���һ������ո��λ��size
            j=1;
            flag=0;
            std::cout<<" ";
        }
        std::cout<<hex[i];
        if (j%4==0) std::cout<<" ";
    }
    std::cout<<std::endl;
}

//����˽���
void VeryLongInt::print_oct() {
    if (negative)std::cout<<"-";
    std::cout<<"oct: ";
    auto number_str=convert_to_decimal(digits);
    std::string oct=convert_base(number_str, 10, 8);
    oct="0o"+oct;
    int size=oct.size()%4;
    int flag=1;
    for (int i=0, j=1; i<oct.size(); i++, j++) {
        if (j-1==size&&flag&&size!=0) {
            //�ҵ���һ������ո��λ��size
            j=1;
            flag=0;
            std::cout<<" ";
        }
        std::cout<<oct[i];
        if (j%4==0) std::cout<<" ";
    }
    std::cout<<std::endl;
}


//���ʮ����
void VeryLongInt::print_decimal(std::ostream &os) const {
    if (digits.empty()) {
        os<<"0"<<std::endl;
        return;
    }
    if (negative) {
        os<<"-";
    }
//    350627200407240014 ->size=18%4=2 ->
    int size=digits.size()%4;
    int flag=1;
    for (int i=digits.size()-1, j=1; i>=0; i--, j++) {
        if (j-1==size&&flag&&size!=0) {
            //�ҵ���һ������ո��λ��size
            j=1;
            flag=0;
            os<<" ";
        }
        os<<digits[i];
        if (j%4==0) os<<" ";
    }
    os<<std::endl;
}


//���ʮ������
void VeryLongInt::print_hex(std::ostream &os) const {
    if (digits.empty()) {
        os<<"0x0"<<std::endl;
        return;
    }
    if (negative) {
        os<<"-";
    }
    auto number_str=convert_to_decimal(digits);
    std::string hex=convert_base(number_str, 10, 16);
    hex="0X"+hex;
    int size=hex.size()%4;
    int flag=1;
    for (int i=0, j=1; i<hex.size(); i++, j++) {
        if (j-1==size&&flag&&size!=0) {
            //�ҵ���һ������ո��λ��size
            j=1;
            flag=0;
            os<<" ";
        }
        os<<hex[i];
        if (j%4==0) os<<" ";
    }
    os<<std::endl;
}


//����˽���
void VeryLongInt::print_oct(std::ostream &os) const {
    if (digits.empty()) {
        os<<"0o0"<<std::endl;
        return;
    }
    if (negative) {
        os<<"-";
    }
    auto number_str=convert_to_decimal(digits);
    std::string oct=convert_base(number_str, 10, 8);
    oct="0o"+oct;
    int size=oct.size()%4;
    int flag=1;
    for (int i=0, j=1; i<oct.size(); i++, j++) {
        if (j-1==size&&flag&&size!=0) {
            //�ҵ���һ������ո��λ��size
            j=1;
            flag=0;
            os<<" ";
        }
        os<<oct[i];
        if (j%4==0) os<<" ";
    }
    os<<std::endl;
}


//===========================================================����<< >>==============================================================
std::ostream &operator<<(std::ostream &os, const VeryLongInt &num) {
    //Windows API�е�SetConsoleTextAttribute���������������ɫ��
    //������˵��GetStdHandle(STD_OUTPUT_HANDLE)��ȡ��׼��������Ȼ���䴫�ݸ�SetConsoleTextAttribute���������������ɫ��
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    os<<std::endl;
    SetConsoleTextAttribute(hConsole, 15);
    os<<"decimal: ";
    SetConsoleTextAttribute(hConsole, 2);
    num.print_decimal(os);
    SetConsoleTextAttribute(hConsole, 15);
    os<<"oct: ";
    SetConsoleTextAttribute(hConsole, 11);
    num.print_oct(os);
    SetConsoleTextAttribute(hConsole, 15);
    os<<"hex: ";
    SetConsoleTextAttribute(hConsole, 3);
    num.print_hex(os);
    SetConsoleTextAttribute(hConsole, 4);
    os<<std::endl;
    return os;
};

std::istream &operator>>(std::istream &is, VeryLongInt &num) {
    std::string inputStr;
    is>>inputStr;
    num=VeryLongInt(inputStr);
    return is;
}
//===========================================================����<< >>����==============================================================

// ȡ�෴��
VeryLongInt VeryLongInt::operator-() const {
    VeryLongInt redis(*this);
    //�ı�����
    redis.negative=!negative;
    return redis;
}

VeryLongInt VeryLongInt::Negative() const {
    return VeryLongInt(digits, !negative);
}

//============================================���ⳤ������op���ⳤ������==============================
VeryLongInt VeryLongInt::operator=(VeryLongInt other) {
    this->digits=other.digits;
    this->negative=other.negative;
    return *this;
}

VeryLongInt VeryLongInt::operator+(const VeryLongInt &other) const {
    //�������ֵ���������ͬ��ֱ�����
    if (negative==other.negative) {
        int carry=0;  //��λ
        std::vector<int> result;  //��Ž��
        //123456->654321
        //789->987
        for (int i=0; i<std::max(digits.size(), other.digits.size()); i++) {
            int sum=carry;
            if (i<digits.size()) {
                sum+=digits[i];
            }
            if (i<other.digits.size()) {
                sum+=other.digits[i];
            }
            result.push_back(sum%10);
            carry=sum/10;
        }
        //�������һ�εĽ�λ
        if (carry!=0) {
            result.push_back(carry);
        }

        return VeryLongInt(result, negative);
    } else {
        // �������ֵ������Բ�ͬ�����ü���
        //��+��ʱ����-�����෴��->���Ϊ����-����    ��+��ʱ����-�����෴��->���Ϊ��-��
        VeryLongInt neg_other=other;
        neg_other.negative=!neg_other.negative;
        return *this-neg_other;
    }
}

VeryLongInt VeryLongInt::operator-(const VeryLongInt &other) const {
    // �������ֵ���������ͬ��ֱ�����
    if (negative==other.negative) {
        // �ж��������Ĵ�С��ϵ��ȷ��������ʱ���������ڵ��ڼ���(this����ֵ�Ƚϴ�)
        bool swap_flag=false;
        if (digits.size()<other.digits.size()) {
            swap_flag=true;
        } else if (digits.size()==other.digits.size()) {
            for (int i=digits.size()-1; i>=0; i--) {
                if (digits[i]<other.digits[i]) {
                    swap_flag=true;
                    break;
                } else if (digits[i]>other.digits[i]) {
                    break;
                }
            }
        }
        //this����ֵ�Ƚ�С��ʱ��->swap_flag=true
        // ���������С�ڼ������������ǵ�λ�ã�����¼���Ϊ����
        if (swap_flag) {
            //�Լ������Լ�
            VeryLongInt result=other-*this;
            result.negative=true;
            return result;
        }
        int borrow=0;  // ��λ
        std::vector<int> result;  // ��Ž��
        // 123456->654321
        // 789->987
        for (int i=0; i<std::max(digits.size(), other.digits.size()); i++) {
            int diff=borrow;
            if (i<digits.size()) {
                diff+=digits[i];
            }
            if (i<other.digits.size()) {
                diff-=other.digits[i];
            }
            if (diff<0) {
                diff+=10;
                borrow=-1;
            } else {
                borrow=0;
            }
            result.push_back(diff);
        }
        // ȥ�������ǰ����
        while (result.size()>1&&result.back()==0) {
            result.pop_back();
        }
        return VeryLongInt(result, negative);
    }
    // �������ֵ������Բ�ͬ�����üӷ�
    //��-��ʱ����+�����෴��->���Ϊ��+��    ��-��ʱ����+�����෴��->���Ϊ��+��
    VeryLongInt neg_other=other;
    neg_other.negative=!neg_other.negative;
    return *this+neg_other;
}

VeryLongInt VeryLongInt::operator*(const VeryLongInt &other) const {
    //��ʼ��һ������Ϊ������������λ��֮�͵����飬����Ԫ�ض�Ϊ0�����ڴ洢�˻��Ľ��
    std::vector<int> result(digits.size()+other.digits.size(), 0);

    for (int i=0; i<digits.size(); i++) {
//        ��λ��ˣ����ڵ�һ������ÿһλ����һ��ڶ�������ÿһλ��ˡ���
//        ͬʱ��Ҫ����ǰһ�γ˷��Ľ�λ�����
//        ����أ����ڵں͵�jλ��ˣ���Ҫ�����ǵĳ˻�����ǰһλ�Ľ�λ�ͽ��������ԭ����ֵ������У���Ȼ��ֱ�ȡ��ͳ���10�õ���ǰλ�Ľ���ͽ�λ��
        int carry=0;
        for (int j=0; j<other.digits.size(); j++) {
            int prod=digits[i]*other.digits[j]+carry+result[i+j];
            result[i+j]=prod%10;
            carry=prod/10;
        }
        if (carry!=0) {
            result[i+other.digits.size()]+=carry;
        }
    }
    // ���ڿ��ܻ����һЩ����Ҫ��ǰ���㣬������Ҫ�ڷ��ؽ��ǰ������ȥ����
    while (result.size()>1&&result.back()==0) {
        result.pop_back();
    }
    return VeryLongInt(result, negative!=other.negative);
}


VeryLongInt VeryLongInt::operator/(const VeryLongInt &other) const {
    if (other==0) {
        throw std::invalid_argument("��������Ϊ0"); // �������Ϊ0�����׳��쳣
    }

    VeryLongInt dividend=*this;

    // ��¼����ķ���
    bool negative_result=false;
    if (dividend.negative!=other.negative) {
        negative_result=true; // ���ݱ������ͳ����ķ���ȷ������ķ���
    }

    dividend.negative=false;
    VeryLongInt divisor_positive=other;
    divisor_positive.negative=false; // ȷ��divisor_positiveʼ��Ϊ����

    VeryLongInt quotient(0);
    VeryLongInt remainder(0);
    quotient.digits.resize(dividend.digits.size(), 0); // ����quotient��digits������С��ƥ�䱻�����Ĵ�С

    // �������㷨
    for (int i=dividend.digits.size()-1; i>=0; --i) {
        remainder=remainder*10+dividend.digits[i]; // ���������Ʋ����ϱ���������һλ����
        while (remainder>=divisor_positive) {
            remainder=remainder-divisor_positive; // ͨ���������м�ȥdivisor_positiveִ�г�������
            quotient.digits[i]++; // �������е�����
        }
    }
    // �Ƴ����е�ǰ����
    while (quotient.digits.size()>1&&quotient.digits.back()==0) {
        quotient.digits.pop_back();
    }

    quotient.negative=negative_result; // �����̵ķ���
    return quotient; // ������
}

VeryLongInt VeryLongInt::operator%(const VeryLongInt &other) const {
    // �жϱ������Ƿ�Ϊ��
    if (other==0) {
        // �׳��쳣����д�����
        throw invalic_number_exception("��������Ϊ0");
    }

    // ��������ת��Ϊ����ֵ��������洢����ʱ����abs_dividend��
    VeryLongInt abs_dividend=*this;
    abs_dividend.negative=false;

    // ������ת��Ϊ����ֵ��������洢����ʱ����abs_divisor��
    VeryLongInt abs_divisor=other;
    abs_divisor.negative=false;

    // ִ�о���ֵ����ģ����
    VeryLongInt quotient=abs_dividend/abs_divisor;
    VeryLongInt product=abs_divisor*quotient;
    VeryLongInt remainder=abs_dividend-product;

    // ���ݱ������ͳ����ķ���ȷ�����յĽ���ķ���
    if (negative)
        remainder.negative=true;

    return remainder;
}

VeryLongInt VeryLongInt::operator+=(const VeryLongInt &other) {
    VeryLongInt other_int(other);
    *this=*this+other_int;
    return *this;
}

VeryLongInt VeryLongInt::operator-=(const VeryLongInt &other) {
    VeryLongInt other_int(other);
    *this=*this-other_int;
    return *this;
}

VeryLongInt VeryLongInt::operator*=(const VeryLongInt &other) {
    VeryLongInt other_int(other);
    *this=*this*other_int;
    return *this;
}


VeryLongInt VeryLongInt::operator/=(const VeryLongInt &other) {
    VeryLongInt other_int(other);
    *this=*this/other_int;
    return *this;
}

VeryLongInt VeryLongInt::operator%=(const VeryLongInt &other) {
    VeryLongInt other_int(other);
    *this=*this%other_int;
    return *this;
}
//--------------------------------------

std::vector<char> tbl_int_to_char(36);
std::vector<int> tbl_char_to_int(256, 0);

// ��ʼ�����
bool init_tables() {
    for (int i=0; i<10; i++) {
        tbl_int_to_char[i]='0'+i;
        tbl_char_to_int['0'+i]=i;
    }
    for (int i=10; i<36; i++) {
        tbl_int_to_char[i]='A'+i-10;
        tbl_char_to_int['A'+i-10]=i;
        tbl_char_to_int['a'+i-10]=i;
    }
    return true;
}

bool init_l=init_tables();

// �ڸ��������µļӷ�
std::string Add(const std::string &num1, const std::string &num2, int base) {
    int carry=0;
    int length=std::max(num1.size(), num2.size());

    std::string result(length, '0');
    for (int i=0; i<length; i++) {
        int digit1=i<num1.size() ? tbl_char_to_int[(unsigned char) num1[num1.size()-1-i]] : 0;
        int digit2=i<num2.size() ? tbl_char_to_int[(unsigned char) num2[num2.size()-1-i]] : 0;

        int sum=digit1+digit2+carry;
        carry=sum/base;
        result[length-1-i]=tbl_int_to_char[sum%base];
    }

    if (carry>0) {
        result.insert(result.begin(), tbl_int_to_char[carry]);
    }

    return result;
}

// ��ʮ������ת��Ϊ�����������ַ���
std::string as_base(int number, int base) {
    std::string result;
    do {
        result+=tbl_int_to_char[number%base];
        number/=base;
    } while (number!=0);
    std::reverse(result.begin(), result.end());
    return result;
}

std::string convert_base(const std::string &number, int oldBase, int newBase) {
    init_tables();
    std::string result="0";

    for (unsigned digit=0; digit<number.size(); digit++) {
        int value=tbl_char_to_int[(unsigned char) number[digit]];
        std::string temp=result;
        for (int i=1; i<oldBase; i++) {
            temp=Add(result, temp, newBase);
        }
        result=Add(temp, as_base(value, newBase), newBase);
    }

    return result;
}


std::string convert_to_decimal(const std::vector<int> &digits) {
    std::stringstream decimal_text_stream;

    // ����ÿ��Ԫ�ز�ת��Ϊ�ַ�����
    for (int i=digits.size()-1; i>=0; i--) {
        decimal_text_stream<<digits[i];
    }

    std::string decimal_text=decimal_text_stream.str();

    return decimal_text;
}


//============================================���ⳤ������op������=======================
VeryLongInt VeryLongInt::operator+(const long int &other) const {
    VeryLongInt other_int(other);
    return *this+other_int;
}

VeryLongInt VeryLongInt::operator-(const long int &other) const {
    VeryLongInt other_int(other);
    return *this-other_int;
}

VeryLongInt VeryLongInt::operator*(const long int &other) const {
    VeryLongInt other_int(other);
    return *this*other_int;
}

VeryLongInt VeryLongInt::operator/(const long int &other) const {
    VeryLongInt other_int(other);
    return *this/other_int;
}

VeryLongInt VeryLongInt::operator%(const long int &other) const {
    VeryLongInt other_int(other);
    return *this%other_int;
}

VeryLongInt VeryLongInt::operator+=(const long int &other) {
    VeryLongInt other_int(other);
    *this=*this+other_int;
    return *this;
}

VeryLongInt VeryLongInt::operator-=(const long int &other) {
    VeryLongInt other_int(other);
    *this=*this-other_int;
    return *this;
}

VeryLongInt VeryLongInt::operator*=(const long int &other) {
    VeryLongInt other_int(other);
    *this=*this*other_int;
    return *this;
}

VeryLongInt VeryLongInt::operator/=(const long int &other) {
    VeryLongInt other_int(other);
    *this=*this/other_int;
    return *this;
}

VeryLongInt VeryLongInt::operator%=(const long int &other) {
    VeryLongInt other_int(other);
    *this=*this%other_int;
    return *this;
}
//============================================���ⳤ������op����������=========================

//============================================���ⳤ������op�ַ���==============================
VeryLongInt VeryLongInt::operator+(const std::string &other) const {
    VeryLongInt other_int(other);
    return *this+other_int;
}

VeryLongInt VeryLongInt::operator-(const std::string &other) const {
    VeryLongInt other_int(other);
    return *this-other_int;
}

VeryLongInt VeryLongInt::operator*(const std::string &other) const {
    VeryLongInt other_int(other);
    return *this*other_int;
}

VeryLongInt VeryLongInt::operator/(const std::string &other) const {
    VeryLongInt other_int(other);
    return *this/other_int;
}

VeryLongInt VeryLongInt::operator%(const std::string &other) const {
    VeryLongInt other_int(other);
    return *this%other_int;
}

VeryLongInt VeryLongInt::operator+=(const std::string &other) {
    VeryLongInt other_int(other);
    *this=*this+other_int;
    return *this;
}

VeryLongInt VeryLongInt::operator-=(const std::string &other) {
    VeryLongInt other_int(other);
    *this=*this-other_int;
    return *this;
}

VeryLongInt VeryLongInt::operator*=(const std::string &other) {
    VeryLongInt other_int(other);
    *this=*this*other_int;
    return *this;
}

VeryLongInt VeryLongInt::operator/=(const std::string &other) {
    VeryLongInt other_int(other);
    *this=*this/other_int;
    return *this;
}

VeryLongInt VeryLongInt::operator%=(const std::string &other) {
    VeryLongInt other_int(other);
    *this=*this%other_int;
    return *this;
}
//============================================���ⳤ������op�ַ�������==============================



//============================================���ⳤ������++--==============================
VeryLongInt VeryLongInt::operator++() {
    *this+=1;
    return *this;
}

VeryLongInt VeryLongInt::operator--() {
    *this-=1;
    return *this;
}

VeryLongInt VeryLongInt::operator++(int) {
    VeryLongInt temp=*this;
    *this+=1;
    return temp;
}

VeryLongInt VeryLongInt::operator--(int) {
    VeryLongInt temp=*this;
    *this-=1;
    return temp;
}
//============================================���ⳤ������++--����==============================






//============================================�����߼������==============================
bool VeryLongInt::operator<(const VeryLongInt &other) const {
    if (negative!=other.negative) {
        //������=����->return true
        return negative;
    }
        //���Ŷ�Ϊ��
    else if (!negative) {
        if (digits.size()!=other.digits.size()) {
            if (digits.size()<other.digits.size())return true;
            if (digits.size()>other.digits.size())return false;
        }
        //������ͬ
        for (int i=digits.size()-1; i>=0; --i) {
            //�����λ��ʼ�Ƚ�
            if (digits[i]!=other.digits[i]) {
                if (digits[i]<other.digits[i])return true;
                if (digits[i]>other.digits[i])return false;
            }
        }
        //���
        return false;
    }
        //���Ŷ�Ϊ��
    else {
        if (digits.size()!=other.digits.size()) {
            if (digits.size()<other.digits.size())return false;
            if (digits.size()>other.digits.size())return true;
        }
        //������ͬ
        for (int i=digits.size()-1; i>=0; --i) {
            //�����λ��ʼ�Ƚ�
            if (digits[i]!=other.digits[i]) {
                if (digits[i]<other.digits[i])return false;
                if (digits[i]>other.digits[i])return true;
            }
        }
        //���
        return false;
    }
}

//����>
bool VeryLongInt::operator>(const VeryLongInt &other) const {
    if (negative!=other.negative) {
        //������=����->return false
        return other.negative;
    }
        //���Ŷ�Ϊ��
    else if (!negative) {
        if (digits.size()!=other.digits.size()) {
            if (digits.size()<other.digits.size())return false;
            if (digits.size()>other.digits.size())return true;
        }
        //������ͬ
        for (int i=digits.size()-1; i>=0; --i) {
            //�����λ��ʼ�Ƚ�
            if (digits[i]!=other.digits[i]) {
                if (digits[i]<other.digits[i])return false;
                if (digits[i]>other.digits[i])return true;
            }
        }
        //���
        return false;
    }
        //���Ŷ�Ϊ��
    else {
        if (digits.size()!=other.digits.size()) {
            if (digits.size()<other.digits.size())return true;
            if (digits.size()>other.digits.size())return false;
        }
        //������ͬ
        for (int i=digits.size()-1; i>=0; --i) {
            //�����λ��ʼ�Ƚ�
            if (digits[i]!=other.digits[i]) {
                if (digits[i]<other.digits[i])return true;
                if (digits[i]>other.digits[i])return false;
            }
        }
        //���
        return false;
    }
}

//����>=
bool VeryLongInt::operator>=(const VeryLongInt &other) const {
    if (*this>other||*this==other) {
        return true;
    } else {
        return false;
    }
}

//����<=
bool VeryLongInt::operator<=(const VeryLongInt &other) const {
    if (*this<other||*this==other) {
        return true;
    } else {
        return false;
    }
}

// �ж����
bool VeryLongInt::operator==(const VeryLongInt &other) const {
    return negative==other.negative&&digits==other.digits;
}

// �ж����
bool VeryLongInt::operator!=(const VeryLongInt &other) const {
    return !(negative==other.negative&&digits==other.digits);
}
//============================================�����߼����������==============================

//===========================================================�ַ���Ȩ����==============================================================
//��ʾʱ����ʾ��Ȩ�Ĳ˵�
void show_copyright() {
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    std::cout<<std::endl<<"    ---Copyright---(c++) 2023-2023 �ο���(222200231). All Rights Reserved.---    ";
    std::cout<<std::endl;
    show_time();
    std::cout<<std::endl;
}

void show_time() {
    std::string week[7]={"������", "����һ", "���ڶ�", "������", "������", "������", "������"};
    SYSTEMTIME now2;
    GetLocalTime(&now2);
    time_t now=time(0);
    tm *ltm=localtime(&now);
    std::cout<<std::endl<<"        ��ǰ���ڡ�ʱ�� :"<<ltm->tm_year+1900<<"."<<1+ltm->tm_mon<<"."
             <<ltm->tm_mday<<" "<<ltm->tm_hour
             <<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<"("<<week[now2.wDayOfWeek]<<") "<<std::endl;
}
//===========================================================�ַ���Ȩ��������===========================================================