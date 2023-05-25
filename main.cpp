/*************************************************
Copyright (C), 2023-2023, 游竣超.
FileName: main.cpp
Author: 游竣超
Version : 最新
Date: 2023.5.25
Description:
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
<游竣超> <2023.5.25> <latest > <main.cpp>
***********************************************************/
#include "VeryLongInt.h"


int main() {
    show_copyright();
    //一组测试数据的一个操作数为自己的18位身份证号码（最后一位如果为X用0取代），另一个操作数为自己的9位学号
    VeryLongInt verylongint1("350627200407240014");
    VeryLongInt verylongint2("222200231");
    //任意长整数op任意长整形
    std::cout<<"verylongint1:"<<verylongint1<<"verylongint2:"<<verylongint2;
    std::cout<<"verylongint1+verylongint2:"<<verylongint1+verylongint2;
    std::cout<<"verylongint1-verylongint2:"<<verylongint1-verylongint2;
    std::cout<<"verylongint1*verylongint2:"<<verylongint1*verylongint2;
    std::cout<<"verylongint1/verylongint2:"<<verylongint1/verylongint2;
    std::cout<<"verylongint1%verylongint2:"<<verylongint1%verylongint2;
    //分页处理
    system("pause");
    system("cls");

    //任意长整数op字符串
    std::cout<<"verylongint1+\"0x124896819ab4879498e4f8c8948aef\""<<verylongint1+"0x124896819ab4879498e4f8c8948aef";
    std::cout<<"verylongint1-\"0x124896819ab4879498e4f8c8948aef\":"<<verylongint1-"0x124896819ab4879498e4f8c8948aef";
    std::cout<<"verylongint1*\"0x124896819ab4879498e4f8c8948aef\":"<<verylongint1*"0x124896819ab4879498e4f8c8948aef";
    std::cout<<"verylongint1/\"0x124896819ab4879498e4f8c8948aef\":"<<verylongint1/"0x124896819ab4879498e4f8c8948aef";
    std::cout<<"verylongint1%\"0x124896819ab4879498e4f8c8948aef\":"<<verylongint1%"0x124896819ab4879498e4f8c8948aef";

    system("pause");
    system("cls");
    //一组2个操作数都正好是92位的数值
    VeryLongInt verylongint3("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846");
    VeryLongInt verylongint4("56893472983746329834763298476392746928374692837469283469283746928347692843769283746928374628");
    std::cout<<"verylongint3:"<<verylongint3<<"verylongint4:"<<verylongint4;
    std::cout<<"verylongint3+verylongint4:"<<verylongint3+verylongint4;
    std::cout<<"verylongint3-verylongint4:"<<verylongint3-verylongint4;
    std::cout<<"verylongint3*verylongint4:"<<verylongint3*verylongint4;
    std::cout<<"verylongint3/verylongint4:"<<verylongint3/verylongint4;
    std::cout<<"verylongint3%verylongint4:"<<verylongint3%verylongint4;
    //分页处理
    system("pause");
    system("cls");
    //任意长整数op长整型
    std::cout<<"verylongint3+165465196"<<verylongint3+165465196;
    std::cout<<"verylongint3-165465196:"<<verylongint3-165465196;
    std::cout<<"verylongint3*165465196:"<<verylongint3*165465196;
    std::cout<<"verylongint3/165465196:"<<verylongint3/165465196;
    std::cout<<"verylongint3%165465196:"<<verylongint3%165465196;



    system("pause");
    system("cls");
    //default
    long int long_int_max=LONG_MAX;
    long int long_int_min=LONG_MIN;
    VeryLongInt verylongint5(0);
    VeryLongInt verylongint6("0o0");
    VeryLongInt verylongint7("0x0");
    VeryLongInt verylongint8(long_int_max);
    VeryLongInt verylongint9("0o17777777777");
    VeryLongInt verylongint10("0X7FFFFFFF");
    VeryLongInt verylongint11(long_int_min);
    VeryLongInt verylongint12("-0o20000000000");
    VeryLongInt verylongint13("-0X80000000");
    std::cout<<"verylongint5:"<<verylongint5;
    std::cout<<"verylongint6:"<<verylongint6;
    std::cout<<"verylongint7:"<<verylongint7;
    std::cout<<"verylongint8:"<<verylongint8;
    std::cout<<"verylongint9:"<<verylongint9;
    std::cout<<"verylongint10:"<<verylongint10;
    std::cout<<"verylongint11:"<<verylongint11;
    std::cout<<"verylongint12:"<<verylongint12;
//    verylongint12.is_negative();
    std::cout<<"verylongint13:"<<verylongint13;
    system("pause");
    system("cls");








    system("pause");
    system("cls");






    return 0;
}