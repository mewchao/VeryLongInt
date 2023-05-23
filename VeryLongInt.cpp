# include "VeryLongInt.h"

//字符串构造
VeryLongInt::VeryLongInt(std::string str) {
    //字符串为负数
    if (str[0]=='-') {
        //去除负号
        str.erase(0, 1);
        if (str[0]=='0') {
            //十六进制或者八进制的字符串->转化为十进制的长整型
            //十进制的长整型
            long int int_10=0;
            //十六进制字符串
            if (str[1]=='x'||str[1]=='X') {
                str.erase(0, 2);
                for (int i=str.size()-1, j=0; i>=0; i--, j++) {
                    //0x123->123
                    if (str[i]>='0'&&str[i]<='9')
                        int_10+=(str[i]-'0')*pow(16, j);

                    else if (str[i]>='a'&&str[i]<='f')
                        int_10+=(str[i]-'W')*pow(16, j);

                    else if (str[i]>='A'&&str[i]<='F')
                        int_10+=(str[i]-'7')*pow(16, j);

                    else {
                        //十六进制数不合法！！抛出异常
                        throw invalic_number_exception(str);
                    }
                }
            }
                //八进制字符串
            else {
                str.erase(0, 1);
                for (int i=str.size()-1, j=0; i>=0; i--, j++) {
                    //0x123->123
                    if (str[i]>='0'&&str[i]<='7')
                        int_10+=(str[i]-'0')*pow(8, j);
                    else {
                        //八进制数不合法！！抛出异常
                        throw invalic_number_exception(str);
                    }
                }
            }
            this->negative=true;
            while (int_10) {
                this->digits.push_back(int_10%10);
                int_10/=10;
            }

        } else {
            //十进制字符串
            this->negative=true;
//            std::cout<<"进入负数十进制"<<std::endl;
//            std::cout<<"str"<<str<<std::endl;
            for (int i=str.size()-1; i>=0; i--) {
                digits.push_back(str[i]-'0');
            }
        }
    } else {
        //字符串为正数
        if (str[0]=='0') {
            //十六进制或者八进制的字符串->转化为十进制的长整型
            //十进制的长整型
            long int int_10=0;
            //十六进制字符串
            if (str[1]=='x'||str[1]=='X') {
                str.erase(0, 2);
                for (int i=str.size()-1, j=0; i>=0; i--, j++) {
                    //0x123->123
                    if (str[i]>='0'&&str[i]<='9')
                        int_10+=(str[i]-'0')*pow(16, j);

                    else if (str[i]>='a'&&str[i]<='f')
                        int_10+=(str[i]-'W')*pow(16, j);

                    else if (str[i]>='A'&&str[i]<='F')
                        int_10+=(str[i]-'7')*pow(16, j);

                    else {
                        //十六进制数不合法！！抛出异常
                        throw invalic_number_exception(str);
                    }
                }
            }
                //八进制字符串
            else {
                str.erase(0, 1);
                for (int i=str.size()-1, j=0; i>=0; i--, j++) {
                    if (str[i]>='0'&&str[i]<='7')
                        int_10+=(str[i]-'0')*pow(8, j);
                    else {
                        //八进制数不合法！！抛出异常
                        throw invalic_number_exception(str);
                    }
                }
            }
            this->negative=false;
            while (int_10) {
                this->digits.push_back(int_10%10);
                int_10/=10;
            }
        } else {
            this->negative=false;
            for (int i=str.size()-1; i>=0; i--) {
                digits.push_back(str[i]-'0');
            }
        }

    }
}

//十进制的长整形构造
VeryLongInt::VeryLongInt(long int other) {
    if(isOctal(other)){
        other=octalToDecimal(other);
    }
    if(isHexadecimal(other)){
        other=hexadecimalToDecimal(other);
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


bool isOctal(long int number) {
    std::string strNumber = std::to_string(number);
    if (strNumber.length() > 1 && strNumber[0] == '0') {
        for (size_t i = 1; i < strNumber.length(); ++i) {
            if (strNumber[i] < '0' || strNumber[i] > '7') {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isHexadecimal(long int number) {
    std::string strNumber = std::to_string(number);
    if (strNumber.length() > 2 && strNumber[0] == '0' &&
        (strNumber[1] == 'x' || strNumber[1] == 'X')) {
        for (size_t i = 2; i < strNumber.length(); ++i) {
            if (!((strNumber[i] >= '0' && strNumber[i] <= '9') ||
                  (strNumber[i] >= 'A' && strNumber[i] <= 'F') ||
                  (strNumber[i] >= 'a' && strNumber[i] <= 'f'))) {
                return false;
            }
        }
        return true;
    }
    return false;
}


long int octalToDecimal(long int octalNumber) {
    std::string strOctal = std::to_string(octalNumber);
    long int decimalNumber = std::stol(strOctal, nullptr, 8);
    return decimalNumber;
}

long int hexadecimalToDecimal(long int hexadecimalNumber) {
    std::string strHexadecimal = std::to_string(hexadecimalNumber);
    long int decimalNumber = std::stol(strHexadecimal, nullptr, 16);
    return decimalNumber;
}

//用一个向量和正负号来构造
VeryLongInt::VeryLongInt(std::vector<int> v, bool negative) {
    this->digits=v;
    this->negative=negative;
}

//打印
void VeryLongInt::print() {
    if (digits.empty()) {
        std::cout<<"0"<<std::endl;
        return;
    }
    if (negative) {
        std::cout<<"-";
    }
    for (int i=digits.size()-1; i>=0; i--) {
        std::cout<<digits[i];
    }
    std::cout<<std::endl;
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
    // 判断除数是否为零
    if (other.digits.size() == 1 && other.digits[0] == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return VeryLongInt(""); // 返回一个默认的 VeryLongInt 对象
    }

    // 检查除数和被除数的位数大小关系
    if (digits.size() < other.digits.size()) {
        return VeryLongInt(0); // 如果被除数小于除数，结果为0
    }

    // 初始化结果和临时被除数
    int resultSize = digits.size() - other.digits.size() + 1;
    std::vector<int> result(resultSize, 0);
    std::vector<int> temp(digits); // 临时被除数

    // 长除法的迭代计算
    for (int i = resultSize - 1; i >= 0; --i) {
        int q = 0; // 商
        int tempSize = temp.size();

        // 将临时被除数左移至与除数对齐
        while (tempSize > other.digits.size()) {
            --tempSize;
            temp[tempSize] = temp[tempSize - 1];
        }
        temp[tempSize] = digits[i + other.digits.size() - 1];

        // 计算当前位的商
        while (tempSize >= other.digits.size()) {
            int t = temp[tempSize] / other.digits.back();
            q = q * 10 + t;

            // 更新临时被除数
            for (int j = 0; j < other.digits.size(); ++j) {
                temp[tempSize - j] -= t * other.digits[other.digits.size() - j - 1];
            }

            --tempSize;
        }

        // 更新结果的当前位
        result[i] = q;
    }

    return VeryLongInt(result,negative);
}




VeryLongInt VeryLongInt::operator%(const VeryLongInt &other) const {
    // 处理除数为0的情况
    if (other == 0) {
        throw std::runtime_error("Divide by zero.");
    }

    // 如果被除数小于除数，则余数为被除数本身
    if (*this < other) {
        return *this;
    }

    // 使用Knuth算法进行大整数除法
    VeryLongInt dividend = *this; // 被除数

    int n = dividend.digits.size(); // 被除数的位数
    int m = other.digits.size(); // 除数的位数

    // 对被除数和除数进行标准化，使得除数的最高位为BASE
    unsigned int d = BASE / (other.digits.back() + 1);
    dividend *= d;
    VeryLongInt normalizedDivisor = other * d;

    for (int j = n - m; j >= 0; --j) {
        // 估计商的当前位
        int qt = (dividend.digits[j + m] * BASE + dividend.digits[j + m - 1]) / normalizedDivisor.digits.back();
        int rt = (dividend.digits[j + m] * BASE + dividend.digits[j + m - 1]) % normalizedDivisor.digits.back();

        // 调整估计值，确保 qt <= BASE
        while (qt > 0 && (qt * normalizedDivisor.digits[m - 2] > BASE * rt + dividend.digits[j + m - 2])) {
            --qt;
            rt += normalizedDivisor.digits.back();
        }

        // 将被除数减去除数的估计乘以除数
        VeryLongInt tmp = normalizedDivisor * qt;
        bool borrow = false;

        for (int i = 0; i < m; ++i) {
            int diff = dividend.digits[j + i] - tmp.digits[i] - (borrow ? 1 : 0);
            if (diff < 0) {
                diff += BASE;
                borrow = true;
            } else {
                borrow = false;
            }
            dividend.digits[j + i] = diff;
        }

        if (borrow) {
            int diff = dividend.digits[j + m] - 1;
            if (diff < 0) {
                diff += BASE;
                borrow = true;
            } else {
                borrow = false;
            }
            dividend.digits[j + m] = diff;
        }
    }

    // 去除余数前导零
    while (!dividend.digits.empty() && dividend.digits.back() == 0) {
        dividend.digits.pop_back();
    }

    dividend.negative = negative;

    // 如果余数为0，则设置其正负号为正
    if (dividend.digits.empty()) {
        dividend.negative = false;
    }

    return dividend;
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

VeryLongInt VeryLongInt::operator=(VeryLongInt other) {
    this->digits=other.digits;
    this->negative=other.negative;
    return *this;
}

VeryLongInt VeryLongInt::operator+(const std::string &other) const {
    VeryLongInt other_int(other);
    return *this+other_int;
}

VeryLongInt VeryLongInt::operator-(const std::string &other) const {
    VeryLongInt other_int(other);
    return *this-other_int;
}
//先+1后返回
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


VeryLongInt VeryLongInt::operator*(const std::string &other) const {
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

// 判断相等
bool VeryLongInt::operator!=(const VeryLongInt &other) const{
    return !(negative==other.negative&&digits==other.digits);
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
    std::cout<<std::endl<<"        当前日期、时间 :"<<ltm->tm_year+1900<<"."<<1+ltm->tm_mon<<"."<<ltm->tm_mday<<" "<<ltm->tm_hour
        <<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<"("<<week[now2.wDayOfWeek]<<") "<<std::endl;
}