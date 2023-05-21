//
// Created by 86150 on 2023-05-20.
//
#include "VeryLongInt.h"

//�ַ�������
VeryLongInt::VeryLongInt(string str) {
    //ʮ�����ƻ��߰˽��Ƶ��ַ���->ת��Ϊʮ���Ƶĳ�����
    if(str[0]=='0'){
        long int ;
        //ʮ�������ַ���
        if(str[1]=='x'||str[1]=='X'){



        }
        //�˽����ַ���
        else{






        }
    }
    //ʮ�����ַ���
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

//�����ι���
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


//��һ��������������������
VeryLongInt::VeryLongInt(vector<int> v, bool negative) {
    this->digits=v;
    this->negative=negative;
}

//��ӡ
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
        vector<int> result;  //��Ž��
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
        vector<int> result;  // ��Ž��
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
    vector<int> result(digits.size()+other.digits.size(), 0);

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
    cout<<endl<<"    ---Copyright---(c++) 2023-2023 �ο���(222200231). All Rights Reserved.---    ";
    cout<<endl;
    show_time();
    cout<<endl;
}

void show_time() {
    string week[7]={"������", "����һ", "���ڶ�", "������", "������", "������", "������"};
    SYSTEMTIME now2;
    GetLocalTime(&now2);
    time_t now=time(0);
    tm *ltm=localtime(&now);
    cout<<endl<<"        ��ǰ���ڡ�ʱ�� :"<<ltm->tm_year+1900<<"."<<1+ltm->tm_mon<<"."<<ltm->tm_mday<<" "<<ltm->tm_hour
        <<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<"("<<week[now2.wDayOfWeek]<<") "<<endl;
}