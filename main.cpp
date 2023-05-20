#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//"    ---Copyright---(c++) 2023-2023 游竣超(222200231). All Rights Reserved.---    "

class VeryLongInt {
private:
    //用向量存放数据
    //动态数组容器
    vector<int> digits;
    //负数->true
    bool negative=false;

public:
    //字符串构造
    VeryLongInt(string str) {
        //"123456" size=6 -->654321
        //"-123456" size=7 -->654321  -3
        if (str[0]=='-') {
            negative=true;
        } else {
            negative=false;
        }

        for (int i=str.size()-1; i>=0; i--) {
            digits.push_back(str[i]-'0');
        }

    }

    //打印
    void print() {
        if (digits.empty()) {
            cout<<"0"<<endl;
            return;
        }
        //"-123456" size=7 -->654321  -3
        if (negative) {
            cout<<"-";
            for (int i=digits.size()-2; i>=0; i--) {
                cout<<digits[i];
            }
        } else {
            for (int i=digits.size()-1; i>=0; i--) {
                cout<<digits[i];
            }
        }
        cout<<endl;
    }

    // 取相反数
    VeryLongInt operator-() const {
        VeryLongInt redis(*this);
        //改变正负
        redis.negative=!negative;
        return redis;
    }

    VeryLongInt operator+(const VeryLongInt &other) const {

        // 空向量
        VeryLongInt result("");
        int carry=0, sum=0;
        //负数+负数
        if(negative&&other.negative){

        }
        //正数+正数
        else if(!negative&&!other.negative){

        }
        else if(negative&&!other.negative){

        }
        else{

        }









//        //"3245"    size=4 -->5423
//        //"123456"  size=6 -->654321
//        //"-123456" size=7 -->654321  -3
//        int m=digits.size(), n=other.digits.size();
//        //下标可以使用到size-1
//        for (int i=0; i<max(m, n); i++) {
//            //防止下标越界
//            int digit1, digit2;
//            if (i<=m-1) {
//                digit1=digits[i];
//            } else {
//                digit1=0;
//            }
//            if (i<=n-1) {
//                digit2=other.digits[i];
//            } else {
//                digit2=0;
//            }
//            sum=digit1+digit2+carry;
//            //进位
//            carry=sum/10;
//            //余下
//            result.digits.push_back(sum%10);
//        }
//        //最后一次进位
//        if (carry>0) {
//            result.digits.push_back(carry);
//        }
//        return result;
    }




    // 比较大小
    bool operator<(const VeryLongInt &other) const {
        if (negative!=other.negative) {
            //负数！=正数->return true
            return negative;
        }
        //符号都为正
        else if(!negative){
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
        else{
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

    // 判断相等
    bool operator==(const VeryLongInt& other) const {
        return negative == other.negative && digits == other.digits;
    }

    // 输出到流
    friend std::ostream& operator<<(std::ostream& os, const VeryLongInt& num) {
        int flag=0;
        if(num.negative) flag=1;
        if (num.digits.empty()) {
            os << "0";
        } else {
            if (num.negative) {
                os << "-";
            }
            for (int i = num.digits.size() - 1- flag; i >= 0; --i) {
                os << num.digits[i];
            }
        }
        return os;
    }
};

int main() {
    VeryLongInt int1("123456");
    int1.print();
    VeryLongInt int2("-123456");
    int2.print();
    cout<<int1<<int2;
//    (int1+int2).print();
//    cout<<'-'-'0';


    return 0;
}