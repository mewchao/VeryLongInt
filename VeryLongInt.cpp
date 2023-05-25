/*************************************************
Copyright (C), 2023-2023, 游竣超.
FileName: VeryLongInt.cpp
Author: 游竣超
Version : 最新
Date: 2023.5.25
Description: Contains large integer member function, common function definition implementation
Function List:
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
<游竣超> <2023.5.25> <latest > <VeryLongInt.cpp>
***********************************************************/
# include "VeryLongInt.h"

//十进制的长整形构造
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

//用各种进制的字符串构造巨型整数类
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

//用一个向量和正负号来构造
VeryLongInt::VeryLongInt(std::vector<int> v, bool negative) {
    this->digits=v;
    this->negative=negative;
}

//输出十进制
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
            //找到第一次输出空格的位置size
            j=1;
            flag=0;
            std::cout<<" ";
        }
        std::cout<<digits[i];
        if (j%4==0) std::cout<<" ";

    }
    std::cout<<std::endl;
}


//输出十六进制
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
            //找到第一次输出空格的位置size
            j=1;
            flag=0;
            std::cout<<" ";
        }
        std::cout<<hex[i];
        if (j%4==0) std::cout<<" ";
    }
    std::cout<<std::endl;
}

//输出八进制
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
            //找到第一次输出空格的位置size
            j=1;
            flag=0;
            std::cout<<" ";
        }
        std::cout<<oct[i];
        if (j%4==0) std::cout<<" ";
    }
    std::cout<<std::endl;
}


//输出十进制
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
            //找到第一次输出空格的位置size
            j=1;
            flag=0;
            os<<" ";
        }
        os<<digits[i];
        if (j%4==0) os<<" ";
    }
    os<<std::endl;
}


//输出十六进制
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
            //找到第一次输出空格的位置size
            j=1;
            flag=0;
            os<<" ";
        }
        os<<hex[i];
        if (j%4==0) os<<" ";
    }
    os<<std::endl;
}


//输出八进制
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
            //找到第一次输出空格的位置size
            j=1;
            flag=0;
            os<<" ";
        }
        os<<oct[i];
        if (j%4==0) os<<" ";
    }
    os<<std::endl;
}


//===========================================================重载<< >>==============================================================
std::ostream &operator<<(std::ostream &os, const VeryLongInt &num) {
    //Windows API中的SetConsoleTextAttribute函数来设置输出颜色。
    //具体来说，GetStdHandle(STD_OUTPUT_HANDLE)获取标准输出句柄，然后将其传递给SetConsoleTextAttribute函数以设置输出颜色。
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
//===========================================================重载<< >>结束==============================================================

// 取相反数
VeryLongInt VeryLongInt::operator-() const {
    VeryLongInt redis(*this);
    //改变正负
    redis.negative=!negative;
    return redis;
}

VeryLongInt VeryLongInt::Negative() const {
    return VeryLongInt(digits, !negative);
}

//============================================任意长整数类op任意长整数类==============================
VeryLongInt VeryLongInt::operator=(VeryLongInt other) {
    this->digits=other.digits;
    this->negative=other.negative;
    return *this;
}

VeryLongInt VeryLongInt::operator+(const VeryLongInt &other) const {
    //两个数字的正负性相同，直接相加
    if (negative==other.negative) {
        int carry=0;  //进位
        std::vector<int> result;  //存放结果
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
        //补上最后一次的进位
        if (carry!=0) {
            result.push_back(carry);
        }

        return VeryLongInt(result, negative);
    } else {
        // 两个数字的正负性不同，调用减法
        //正+负时，正-负数相反数->结果为正数-正数    负+正时，负-正的相反数->结果为负-负
        VeryLongInt neg_other=other;
        neg_other.negative=!neg_other.negative;
        return *this-neg_other;
    }
}

VeryLongInt VeryLongInt::operator-(const VeryLongInt &other) const {
    // 两个数字的正负性相同，直接相减
    if (negative==other.negative) {
        // 判断两个数的大小关系，确保做减法时被减数大于等于减数(this绝对值比较大)
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
        //this绝对值比较小的时候->swap_flag=true
        // 如果被减数小于减数，交换它们的位置，并记录结果为负数
        if (swap_flag) {
            //自己调用自己
            VeryLongInt result=other-*this;
            result.negative=true;
            return result;
        }
        int borrow=0;  // 借位
        std::vector<int> result;  // 存放结果
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
        // 去除结果中前导零
        while (result.size()>1&&result.back()==0) {
            result.pop_back();
        }
        return VeryLongInt(result, negative);
    }
    // 两个数字的正负性不同，调用加法
    //正-负时，正+负数相反数->结果为正+正    负-正时，负+正的相反数->结果为负+负
    VeryLongInt neg_other=other;
    neg_other.negative=!neg_other.negative;
    return *this+neg_other;
}

VeryLongInt VeryLongInt::operator*(const VeryLongInt &other) const {
    //初始化一个长度为两个输入数字位数之和的数组，所有元素都为0，用于存储乘积的结果
    std::vector<int> result(digits.size()+other.digits.size(), 0);

    for (int i=0; i<digits.size(); i++) {
//        逐位相乘：对于第一个数的每一位，逐一与第二个数的每一位相乘。、
//        同时需要考虑前一次乘法的进位情况。
//        具体地，对于第和第j位相乘，需要将它们的乘积加上前一位的进位和结果数组中原本的值（如果有），然后分别取余和除以10得到当前位的结果和进位。
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
    // 由于可能会出现一些不必要的前导零，所以需要在返回结果前将它们去除。
    while (result.size()>1&&result.back()==0) {
        result.pop_back();
    }
    return VeryLongInt(result, negative!=other.negative);
}


VeryLongInt VeryLongInt::operator/(const VeryLongInt &other) const {
    if (other==0) {
        throw std::invalid_argument("除数不能为0"); // 如果除数为0，则抛出异常
    }

    VeryLongInt dividend=*this;

    // 记录结果的符号
    bool negative_result=false;
    if (dividend.negative!=other.negative) {
        negative_result=true; // 根据被除数和除数的符号确定结果的符号
    }

    dividend.negative=false;
    VeryLongInt divisor_positive=other;
    divisor_positive.negative=false; // 确保divisor_positive始终为正数

    VeryLongInt quotient(0);
    VeryLongInt remainder(0);
    quotient.digits.resize(dividend.digits.size(), 0); // 调整quotient的digits向量大小以匹配被除数的大小

    // 长除法算法
    for (int i=dividend.digits.size()-1; i>=0; --i) {
        remainder=remainder*10+dividend.digits[i]; // 将余数左移并加上被除数的下一位数字
        while (remainder>=divisor_positive) {
            remainder=remainder-divisor_positive; // 通过从余数中减去divisor_positive执行除法步骤
            quotient.digits[i]++; // 增加商中的数字
        }
    }
    // 移除商中的前导零
    while (quotient.digits.size()>1&&quotient.digits.back()==0) {
        quotient.digits.pop_back();
    }

    quotient.negative=negative_result; // 设置商的符号
    return quotient; // 返回商
}

VeryLongInt VeryLongInt::operator%(const VeryLongInt &other) const {
    // 判断被除数是否为零
    if (other==0) {
        // 抛出异常或进行错误处理
        throw invalic_number_exception("除数不能为0");
    }

    // 将被除数转换为绝对值，并将其存储在临时变量abs_dividend中
    VeryLongInt abs_dividend=*this;
    abs_dividend.negative=false;

    // 将除数转换为绝对值，并将其存储在临时变量abs_divisor中
    VeryLongInt abs_divisor=other;
    abs_divisor.negative=false;

    // 执行绝对值的求模运算
    VeryLongInt quotient=abs_dividend/abs_divisor;
    VeryLongInt product=abs_divisor*quotient;
    VeryLongInt remainder=abs_dividend-product;

    // 根据被除数和除数的符号确定最终的结果的符号
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

// 初始化表格
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

// 在给定基数下的加法
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

// 将十进制数转换为给定基数的字符串
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

    // 遍历每个元素并转换为字符类型
    for (int i=digits.size()-1; i>=0; i--) {
        decimal_text_stream<<digits[i];
    }

    std::string decimal_text=decimal_text_stream.str();

    return decimal_text;
}


//============================================任意长整数类op长整数=======================
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
//============================================任意长整数类op长整数结束=========================

//============================================任意长整数类op字符串==============================
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
//============================================任意长整数类op字符串结束==============================



//============================================任意长整数类++--==============================
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
//============================================任意长整数类++--结束==============================






//============================================重载逻辑运算符==============================
bool VeryLongInt::operator<(const VeryLongInt &other) const {
    if (negative!=other.negative) {
        //负数！=正数->return true
        return negative;
    }
        //符号都为正
    else if (!negative) {
        if (digits.size()!=other.digits.size()) {
            if (digits.size()<other.digits.size())return true;
            if (digits.size()>other.digits.size())return false;
        }
        //长度相同
        for (int i=digits.size()-1; i>=0; --i) {
            //从最大位开始比较
            if (digits[i]!=other.digits[i]) {
                if (digits[i]<other.digits[i])return true;
                if (digits[i]>other.digits[i])return false;
            }
        }
        //相等
        return false;
    }
        //符号都为负
    else {
        if (digits.size()!=other.digits.size()) {
            if (digits.size()<other.digits.size())return false;
            if (digits.size()>other.digits.size())return true;
        }
        //长度相同
        for (int i=digits.size()-1; i>=0; --i) {
            //从最大位开始比较
            if (digits[i]!=other.digits[i]) {
                if (digits[i]<other.digits[i])return false;
                if (digits[i]>other.digits[i])return true;
            }
        }
        //相等
        return false;
    }
}

//重载>
bool VeryLongInt::operator>(const VeryLongInt &other) const {
    if (negative!=other.negative) {
        //负数！=正数->return false
        return other.negative;
    }
        //符号都为正
    else if (!negative) {
        if (digits.size()!=other.digits.size()) {
            if (digits.size()<other.digits.size())return false;
            if (digits.size()>other.digits.size())return true;
        }
        //长度相同
        for (int i=digits.size()-1; i>=0; --i) {
            //从最大位开始比较
            if (digits[i]!=other.digits[i]) {
                if (digits[i]<other.digits[i])return false;
                if (digits[i]>other.digits[i])return true;
            }
        }
        //相等
        return false;
    }
        //符号都为负
    else {
        if (digits.size()!=other.digits.size()) {
            if (digits.size()<other.digits.size())return true;
            if (digits.size()>other.digits.size())return false;
        }
        //长度相同
        for (int i=digits.size()-1; i>=0; --i) {
            //从最大位开始比较
            if (digits[i]!=other.digits[i]) {
                if (digits[i]<other.digits[i])return true;
                if (digits[i]>other.digits[i])return false;
            }
        }
        //相等
        return false;
    }
}

//重载>=
bool VeryLongInt::operator>=(const VeryLongInt &other) const {
    if (*this>other||*this==other) {
        return true;
    } else {
        return false;
    }
}

//重载<=
bool VeryLongInt::operator<=(const VeryLongInt &other) const {
    if (*this<other||*this==other) {
        return true;
    } else {
        return false;
    }
}

// 判断相等
bool VeryLongInt::operator==(const VeryLongInt &other) const {
    return negative==other.negative&&digits==other.digits;
}

// 判断相等
bool VeryLongInt::operator!=(const VeryLongInt &other) const {
    return !(negative==other.negative&&digits==other.digits);
}
//============================================重载逻辑运算符结束==============================

//===========================================================字符版权函数==============================================================
//显示时间显示版权的菜单
void show_copyright() {
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    std::cout<<std::endl<<"    ---Copyright---(c++) 2023-2023 游竣超(222200231). All Rights Reserved.---    ";
    std::cout<<std::endl;
    show_time();
    std::cout<<std::endl;
}

void show_time() {
    std::string week[7]={"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};
    SYSTEMTIME now2;
    GetLocalTime(&now2);
    time_t now=time(0);
    tm *ltm=localtime(&now);
    std::cout<<std::endl<<"        当前日期、时间 :"<<ltm->tm_year+1900<<"."<<1+ltm->tm_mon<<"."
             <<ltm->tm_mday<<" "<<ltm->tm_hour
             <<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<"("<<week[now2.wDayOfWeek]<<") "<<std::endl;
}
//===========================================================字符版权函数结束===========================================================