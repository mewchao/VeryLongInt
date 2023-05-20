//
// Created by 86150 on 2023-05-20.
//
#include "VeryLongInt.h"

//字符串构造
VeryLongInt::VeryLongInt(string str) {
//"123456" size=6 -->654321
//"-123456" size=6 -->654321
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