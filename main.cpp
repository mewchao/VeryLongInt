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




//    //一组测试数据的一个操作数为自己的18位身份证号码（最后一位如果为X用0取代），另一个操作数为自己的9位学号
    VeryLongInt verylongint1("350627200407240014");
    VeryLongInt verylongint2("222200231");

    verylongint1=VeryLongInt("56893472983746329834763298476392746928374692837469283469283746928347692843769283746928374628");
    cout<<"verylongint1[5]"<<verylongint1[5]<<endl;
    cout<<"verylongint1.getlength():"<<verylongint1.get_length()<<endl;


    cout<<"verylongint1"<<verylongint1<<endl;
    verylongint1=VeryLongInt("56893472983746329834763298476392746928374692837469283469283746928347692843769283746928374628");
    cout<<"verylongint1"<<-verylongint1<<endl;
    system("pause");
    system("cls");

    try{
        verylongint1/0;
    }
    CATCH_INVALID_DIVISION
    try{
        verylongint1%0;
    }
    CATCH_INVALID_DIVISION
    long int long_int_max=LONG_MAX;
    long int long_int_min=LONG_MIN;
    try{
        VeryLongInt verylongint1("0x23g5");
    }
    CATCH_INVALID_NUMBER_EXCEPTION;

    try{
        VeryLongInt verylongint2("0X7&9B");
    }
    CATCH_INVALID_NUMBER_EXCEPTION;

    cout<<"verylongint1+\"0\""<<verylongint1+"0"<<endl;
    cout<<"verylongint1-\"0\""<<verylongint1-"0"<<endl;
    cout<<"verylongint1*\"0\""<<verylongint1*"0"<<endl;
    system("pause");
    system("cls");


    verylongint1=VeryLongInt("56893472983746329834763298476392746928374692837469283469283746928347692843769283746928374628");
    cout<<"verylongint1++"<<verylongint1++<<endl;
    cout<<"verylongint1"<<verylongint1<<endl;
    verylongint1=VeryLongInt("56893472983746329834763298476392746928374692837469283469283746928347692843769283746928374628");
    cout<<"++verylongint1"<<++verylongint1<<endl;
    cout<<"verylongint1"<<verylongint1<<endl;
    verylongint1=VeryLongInt("56893472983746329834763298476392746928374692837469283469283746928347692843769283746928374628");
    cout<<"verylongint1--"<<verylongint1--<<endl;
    cout<<"verylongint1"<<verylongint1<<endl;
    verylongint1=VeryLongInt("56893472983746329834763298476392746928374692837469283469283746928347692843769283746928374628");
    cout<<"--verylongint1"<<--verylongint1<<endl;
    cout<<"verylongint1"<<verylongint1<<endl;






    system("pause");
    system("cls");


    if(verylongint1>verylongint2)cout<<"verylongint1>verylongint2"<<endl;
    else cout<<"verylongint1<=verylongint2"<<endl;
    if(verylongint1<verylongint2)cout<<"verylongint1<verylongint2"<<endl;
    else cout<<"verylongint1>=verylongint2"<<endl;
    if(verylongint1>=verylongint2)cout<<"verylongint1>=verylongint2"<<endl;
    else cout<<"verylongint1<verylongint2"<<endl;
    if(verylongint1<=verylongint2)cout<<"verylongint1<=verylongint2"<<endl;
    else cout<<"verylongint1>verylongint2"<<endl;
    if(verylongint1==verylongint2)cout<<"verylongint1==verylongint2"<<endl;
    else cout<<"verylongint1!=verylongint2"<<endl;
    if(verylongint1!=verylongint2)cout<<"verylongint1!=verylongint2"<<endl;
    else cout<<"verylongint1==verylongint2"<<endl;

    system("pause");
    system("cls");





    //任意长整数op任意长整形
    cout<<"verylongint1:"<<verylongint1<<"verylongint2:"<<verylongint2;
    cout<<"verylongint1+=verylongint2:"<<verylongint1;
    cout<<"verylongint1-=verylongint2:"<<verylongint1;
    cout<<"verylongint1*=verylongint2:"<<verylongint1;
    cout<<"verylongint1/=verylongint2:"<<verylongint1;
    cout<<"verylongint1%=verylongint2:"<<verylongint1;
    //分页处理
    system("pause");
    system("cls");

    verylongint1=VeryLongInt("350627200407240014"); verylongint1+=verylongint2; cout<<"verylongint1+=verylongint2:"<<verylongint1;
    verylongint1=VeryLongInt("350627200407240014"); verylongint1-=verylongint2; cout<<"verylongint1-=verylongint2:"<<verylongint1;
    verylongint1=VeryLongInt("350627200407240014"); verylongint1*=verylongint2; cout<<"verylongint1*=verylongint2:"<<verylongint1;
    verylongint1=VeryLongInt("350627200407240014"); verylongint1/=verylongint2; cout<<"verylongint1/=verylongint2:"<<verylongint1;
    verylongint1=VeryLongInt("350627200407240014"); verylongint1%=verylongint2; cout<<"verylongint1%=verylongint2:"<<verylongint1;




    system("pause");
    system("cls");



//


    //任意长整数op字符串
    cout<<"verylongint1+\"0x124896819ab4879498e4f8c8948aef\""<<verylongint1+"0x124896819ab4879498e4f8c8948aef";
    cout<<"verylongint1-\"0x124896819ab4879498e4f8c8948aef\":"<<verylongint1-"0x124896819ab4879498e4f8c8948aef";
    cout<<"verylongint1*\"0x124896819ab4879498e4f8c8948aef\":"<<verylongint1*"0x124896819ab4879498e4f8c8948aef";
    cout<<"verylongint1/\"0x124896819ab4879498e4f8c8948aef\":"<<verylongint1/"0x124896819ab4879498e4f8c8948aef";
    cout<<"verylongint1%\"0x124896819ab4879498e4f8c8948aef\":"<<verylongint1%"0x124896819ab4879498e4f8c8948aef";

    system("pause");
    system("cls");
    //一组2个操作数都正好是92位的数值
    VeryLongInt verylongint3("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846");
    VeryLongInt verylongint4("56893472983746329834763298476392746928374692837469283469283746928347692843769283746928374628");
    cout<<"verylongint3:"<<verylongint3<<"verylongint4:"<<verylongint4;
    cout<<"verylongint3+verylongint4:"<<verylongint3+verylongint4;
    cout<<"verylongint3-verylongint4:"<<verylongint3-verylongint4;
    cout<<"verylongint3*verylongint4:"<<verylongint3*verylongint4;
    cout<<"verylongint3/verylongint4:"<<verylongint3/verylongint4;
    cout<<"verylongint3%verylongint4:"<<verylongint3%verylongint4;
    //分页处理
    system("pause");
    system("cls");

    cout<<"verylongint3+123456789L:"<<verylongint3+123456789L;
    cout<<"verylongint3-123456789L:"<<verylongint3-123456789L;
    cout<<"verylongint3*123456789L:"<<verylongint3*123456789L;
    cout<<"verylongint3/123456789L:"<<verylongint3/123456789L;
    cout<<"verylongint3%123456789L:"<<verylongint3%123456789L;
    verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846");
    verylongint3+=123456789L;
    cout<<"verylongint3+=123456789L:"<<verylongint3;
    verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846");
    verylongint3-=123456789L;
    cout<<"verylongint3-=123456789L:"<<verylongint3;
    verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846");
    verylongint3*=123456789L;
    cout<<"verylongint3*=123456789L:"<<verylongint3;
    verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846");
    verylongint3/=123456789L;
    cout<<"verylongint3/=123456789L:"<<verylongint3;
    verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846");
    verylongint3%=123456789L;
    cout<<"verylongint3%=123456789L:"<<verylongint3;


    if(verylongint3>123456789L)cout<<"verylongint3>123456789L"<<endl;
    else cout<<"verylongint3<=123456789L"<<endl;
    if(verylongint3<123456789L)cout<<"verylongint3<123456789L"<<endl;
    else cout<<"verylongint3>=123456789L"<<endl;
    if(verylongint3>=123456789L)cout<<"verylongint3>=123456789L"<<endl;
    else cout<<"verylongint3<123456789L"<<endl;
    if(verylongint3<=123456789L)cout<<"verylongint3<=123456789L"<<endl;
    else cout<<"verylongint3>123456789L"<<endl;
    if(verylongint3==123456789L)cout<<"verylongint3==123456789L"<<endl;
    else cout<<"verylongint3!=123456789L"<<endl;
    if(verylongint3!=123456789L)cout<<"verylongint3!=123456789L"<<endl;
    else cout<<"verylongint3==123456789L"<<endl;


    cout<<"verylongint3+123456789L:"<<verylongint3+"12345678987654321";
    cout<<"verylongint3-123456789L:"<<verylongint3-"12345678987654321";
    cout<<"verylongint3*123456789L:"<<verylongint3*"12345678987654321";
    cout<<"verylongint3/123456789L:"<<verylongint3/"12345678987654321";
    cout<<"verylongint3%123456789L:"<<verylongint3%"12345678987654321";
    verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846");
    verylongint3+="12345678987654321";
    cout<<"verylongint3+=123456789L:"<<verylongint3;
    verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846");
    verylongint3-="12345678987654321";
    cout<<"verylongint3-=123456789L:"<<verylongint3;
    verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846");
    verylongint3*="12345678987654321";
    cout<<"verylongint3*=123456789L:"<<verylongint3;
    verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846");
    verylongint3/="12345678987654321";
    cout<<"verylongint3/=123456789L:"<<verylongint3;
    verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846");
    verylongint3%="12345678987654321";
    cout<<"verylongint3%=123456789L:"<<verylongint3;


    if(verylongint3>"12345678987654321")cout<<"verylongint3>123456789L"<<endl;
    else cout<<"verylongint3<=123456789L"<<endl;
    if(verylongint3<"12345678987654321")cout<<"verylongint3<123456789L"<<endl;
    else cout<<"verylongint3>=123456789L"<<endl;
    if(verylongint3>="12345678987654321")cout<<"verylongint3>=123456789L"<<endl;
    else cout<<"verylongint3<123456789L"<<endl;
    if(verylongint3<="12345678987654321")cout<<"verylongint3<=123456789L"<<endl;
    else cout<<"verylongint3>123456789L"<<endl;



    system("pause");
    system("cls");

verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846"); verylongint3+=verylongint4; cout<<"verylongint3+=verylongint4:"<<verylongint3;
verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846"); verylongint3-=verylongint4; cout<<"verylongint3-=verylongint4:"<<verylongint3;
verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846"); verylongint3*=verylongint4; cout<<"verylongint3*=verylongint4:"<<verylongint3;
verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846"); verylongint3/=verylongint4; cout<<"verylongint3/=verylongint4:"<<verylongint3;
verylongint3=VeryLongInt("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846"); verylongint3%=verylongint4; cout<<"verylongint3%=verylongint4:"<<verylongint3;
    //任意长整数op长整型
    cout<<"verylongint3+165465196"<<verylongint3+165465196;
    cout<<"verylongint3-165465196:"<<verylongint3-165465196;
    cout<<"verylongint3*165465196:"<<verylongint3*165465196;
    cout<<"verylongint3/165465196:"<<verylongint3/165465196;
    cout<<"verylongint3%165465196:"<<verylongint3%165465196;



    system("pause");
    system("cls");
    //default
    VeryLongInt verylongint5(0);
    VeryLongInt verylongint6("0o0");
    VeryLongInt verylongint7("0x0");
    VeryLongInt verylongint8(long_int_max);
    VeryLongInt verylongint9("0o17777777777");
    VeryLongInt verylongint10("0X7FFFFFFF");
    VeryLongInt verylongint11(long_int_min);
    VeryLongInt verylongint12("-0o20000000000");
    VeryLongInt verylongint13("-0X80000000");
    cout<<"verylongint5:"<<verylongint5;
    cout<<"verylongint6:"<<verylongint6;
    cout<<"verylongint7:"<<verylongint7;
    cout<<"verylongint8:"<<verylongint8;
    cout<<"verylongint9:"<<verylongint9;
    cout<<"verylongint10:"<<verylongint10;
    cout<<"verylongint11:"<<verylongint11;
    cout<<"verylongint12:"<<verylongint12;
//    verylongint12.is_negative();
    cout<<"verylongint13:"<<verylongint13;
    system("pause");
    system("cls");

    system("pause");
    system("cls");


    return 0;
}