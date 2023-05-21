//
// Created by 86150 on 2023-05-20.
//
#include "VeryLongInt.h"

//字符串构造
VeryLongInt::VeryLongInt(string str) {
    //十六进制或者八进制的字符串->转化为十进制的长整型
    if(str[0]=='0'){
        long int ;
        //十六进制字符串
        if(str[1]=='x'||str[1]=='X'){



        }
        //八进制字符串
        else{






        }
    }
    //十进制字符串
    if (str[0]=='-') {
        negative=true;
        for (int i=str.size()-1; i>=1; i--) {
            digits.push_back(str[i]-'0');
        }
    } else {
        negative=false;
        for (int i=str.size()-1; i>=0; i--) {
            digits.push_back(str[i]-'0');
        }
    }

}

//长整形构造
VeryLongInt::VeryLongInt(long int other) {
    if (other<0) {
        negative=true;
        other=-other;
    } else {
        negative=false;
    }
    while (other) {
        digits.push_back(other%10);
        other/=10;
    }
}


//用一个向量和正负号来构造
VeryLongInt::VeryLongInt(vector<int> v, bool negative) {
    this->digits=v;
    this->negative=negative;
}

//打印
void VeryLongInt::print() {
    if (digits.empty()) {
        cout<<"0"<<endl;
        return;
    }
    if (negative) {
        cout<<"-";
    }
    for (int i=digits.size()-1; i>=0; i--) {
        cout<<digits[i];
    }
    cout<<endl;
}

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


VeryLongInt VeryLongInt::operator+(const VeryLongInt &other) const {
    //两个数字的正负性相同，直接相加
    if (negative==other.negative) {
        int carry=0;  //进位
        vector<int> result;  //存放结果
        //123456->654321
        //789->987
        for (int i=0; i<max(digits.size(), other.digits.size()); i++) {
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
        vector<int> result;  // 存放结果
        // 123456->654321
        // 789->987
        for (int i=0; i<max(digits.size(), other.digits.size()); i++) {
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
    vector<int> result(digits.size()+other.digits.size(), 0);

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

VeryLongInt VeryLongInt::operator=(const VeryLongInt &other) {
    this->digits=other.digits;
    this->negative=other.negative;
}

VeryLongInt VeryLongInt::operator+(const string &other) const {
    VeryLongInt other_int(other);
    return *this+other_int;
}

VeryLongInt VeryLongInt::operator-(const string &other) const {
    VeryLongInt other_int(other);
    return *this-other_int;
}

VeryLongInt VeryLongInt::operator*(const string &other) const {
    VeryLongInt other_int(other);
    return *this*other_int;
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

VeryLongInt VeryLongInt::operator+=(const string &other) {
    VeryLongInt other_int(other);
    *this=*this+other_int;
    return *this;
}

VeryLongInt VeryLongInt::operator-=(const string &other) {
    VeryLongInt other_int(other);
    *this=*this-other_int;
    return *this;
}

VeryLongInt VeryLongInt::operator*=(const string &other) {
    VeryLongInt other_int(other);
    *this=*this*other_int;
    return *this;
}

// 重载<
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

// 输出到流
std::ostream &operator<<(std::ostream &os, const VeryLongInt &num) {
    if (num.digits.empty()) {
        os<<"0";
    } else {
        if (num.negative) {
            os<<"-";
        }
        for (int i=num.digits.size()-1; i>=0; --i) {
            os<<num.digits[i];
        }
    }
    return os;
}

//显示时间显示版权的菜单
void show_copyright() {
    cout<<endl<<"    ---Copyright---(c++) 2023-2023 游竣超(222200231). All Rights Reserved.---    ";
    cout<<endl;
    show_time();
    cout<<endl;
}

void show_time() {
    string week[7]={"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};
    SYSTEMTIME now2;
    GetLocalTime(&now2);
    time_t now=time(0);
    tm *ltm=localtime(&now);
    cout<<endl<<"        当前日期、时间 :"<<ltm->tm_year+1900<<"."<<1+ltm->tm_mon<<"."<<ltm->tm_mday<<" "<<ltm->tm_hour
        <<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<"("<<week[now2.wDayOfWeek]<<") "<<endl;
}