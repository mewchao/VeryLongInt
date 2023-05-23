# include "VeryLongInt.h"

//�ַ�������
VeryLongInt::VeryLongInt(std::string str) {
    //�ַ���Ϊ����
    if (str[0]=='-') {
        //ȥ������
        str.erase(0, 1);
        if (str[0]=='0') {
            //ʮ�����ƻ��߰˽��Ƶ��ַ���->ת��Ϊʮ���Ƶĳ�����
            //ʮ���Ƶĳ�����
            long int int_10=0;
            //ʮ�������ַ���
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
                        //ʮ�����������Ϸ������׳��쳣
                        throw invalic_number_exception(str);
                    }
                }
            }
                //�˽����ַ���
            else {
                str.erase(0, 1);
                for (int i=str.size()-1, j=0; i>=0; i--, j++) {
                    //0x123->123
                    if (str[i]>='0'&&str[i]<='7')
                        int_10+=(str[i]-'0')*pow(8, j);
                    else {
                        //�˽��������Ϸ������׳��쳣
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
            //ʮ�����ַ���
            this->negative=true;
//            std::cout<<"���븺��ʮ����"<<std::endl;
//            std::cout<<"str"<<str<<std::endl;
            for (int i=str.size()-1; i>=0; i--) {
                digits.push_back(str[i]-'0');
            }
        }
    } else {
        //�ַ���Ϊ����
        if (str[0]=='0') {
            //ʮ�����ƻ��߰˽��Ƶ��ַ���->ת��Ϊʮ���Ƶĳ�����
            //ʮ���Ƶĳ�����
            long int int_10=0;
            //ʮ�������ַ���
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
                        //ʮ�����������Ϸ������׳��쳣
                        throw invalic_number_exception(str);
                    }
                }
            }
                //�˽����ַ���
            else {
                str.erase(0, 1);
                for (int i=str.size()-1, j=0; i>=0; i--, j++) {
                    if (str[i]>='0'&&str[i]<='7')
                        int_10+=(str[i]-'0')*pow(8, j);
                    else {
                        //�˽��������Ϸ������׳��쳣
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

//ʮ���Ƶĳ����ι���
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

//��һ��������������������
VeryLongInt::VeryLongInt(std::vector<int> v, bool negative) {
    this->digits=v;
    this->negative=negative;
}

//��ӡ
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
    // �жϳ����Ƿ�Ϊ��
    if (other.digits.size() == 1 && other.digits[0] == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return VeryLongInt(""); // ����һ��Ĭ�ϵ� VeryLongInt ����
    }

    // �������ͱ�������λ����С��ϵ
    if (digits.size() < other.digits.size()) {
        return VeryLongInt(0); // ���������С�ڳ��������Ϊ0
    }

    // ��ʼ���������ʱ������
    int resultSize = digits.size() - other.digits.size() + 1;
    std::vector<int> result(resultSize, 0);
    std::vector<int> temp(digits); // ��ʱ������

    // �������ĵ�������
    for (int i = resultSize - 1; i >= 0; --i) {
        int q = 0; // ��
        int tempSize = temp.size();

        // ����ʱ���������������������
        while (tempSize > other.digits.size()) {
            --tempSize;
            temp[tempSize] = temp[tempSize - 1];
        }
        temp[tempSize] = digits[i + other.digits.size() - 1];

        // ���㵱ǰλ����
        while (tempSize >= other.digits.size()) {
            int t = temp[tempSize] / other.digits.back();
            q = q * 10 + t;

            // ������ʱ������
            for (int j = 0; j < other.digits.size(); ++j) {
                temp[tempSize - j] -= t * other.digits[other.digits.size() - j - 1];
            }

            --tempSize;
        }

        // ���½���ĵ�ǰλ
        result[i] = q;
    }

    return VeryLongInt(result,negative);
}




VeryLongInt VeryLongInt::operator%(const VeryLongInt &other) const {
    // �������Ϊ0�����
    if (other == 0) {
        throw std::runtime_error("Divide by zero.");
    }

    // ���������С�ڳ�����������Ϊ����������
    if (*this < other) {
        return *this;
    }

    // ʹ��Knuth�㷨���д���������
    VeryLongInt dividend = *this; // ������

    int n = dividend.digits.size(); // ��������λ��
    int m = other.digits.size(); // ������λ��

    // �Ա������ͳ������б�׼����ʹ�ó��������λΪBASE
    unsigned int d = BASE / (other.digits.back() + 1);
    dividend *= d;
    VeryLongInt normalizedDivisor = other * d;

    for (int j = n - m; j >= 0; --j) {
        // �����̵ĵ�ǰλ
        int qt = (dividend.digits[j + m] * BASE + dividend.digits[j + m - 1]) / normalizedDivisor.digits.back();
        int rt = (dividend.digits[j + m] * BASE + dividend.digits[j + m - 1]) % normalizedDivisor.digits.back();

        // ��������ֵ��ȷ�� qt <= BASE
        while (qt > 0 && (qt * normalizedDivisor.digits[m - 2] > BASE * rt + dividend.digits[j + m - 2])) {
            --qt;
            rt += normalizedDivisor.digits.back();
        }

        // ����������ȥ�����Ĺ��Ƴ��Գ���
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

    // ȥ������ǰ����
    while (!dividend.digits.empty() && dividend.digits.back() == 0) {
        dividend.digits.pop_back();
    }

    dividend.negative = negative;

    // �������Ϊ0����������������Ϊ��
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
//��+1�󷵻�
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

// ����<
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
bool VeryLongInt::operator!=(const VeryLongInt &other) const{
    return !(negative==other.negative&&digits==other.digits);
}
// �������
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

//��ʾʱ����ʾ��Ȩ�Ĳ˵�
void show_copyright() {
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
    std::cout<<std::endl<<"        ��ǰ���ڡ�ʱ�� :"<<ltm->tm_year+1900<<"."<<1+ltm->tm_mon<<"."<<ltm->tm_mday<<" "<<ltm->tm_hour
        <<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<"("<<week[now2.wDayOfWeek]<<") "<<std::endl;
}