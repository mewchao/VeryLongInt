/*************************************************
Copyright (C), 2023-2023, �ο���.
FileName: main.cpp
Author: �ο���
Version : ����
Date: 2023.5.25
Description:
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
<�ο���> <2023.5.25> <latest > <main.cpp>
***********************************************************/
#include "VeryLongInt.h"


int main() {
    show_copyright();
    //һ��������ݵ�һ��������Ϊ�Լ���18λ���֤���루���һλ���ΪX��0ȡ��������һ��������Ϊ�Լ���9λѧ��
    VeryLongInt verylongint1("350627200407240014");
    VeryLongInt verylongint2("222200231");
    std::cout<<"verylongint1:"<<verylongint1<<"verylongint2:"<<verylongint2;
    std::cout<<"verylongint1+verylongint2:"<<verylongint1+verylongint2;
    std::cout<<"verylongint1-verylongint2:"<<verylongint1-verylongint2;
    std::cout<<"verylongint1*verylongint2:"<<verylongint1*verylongint2;
    std::cout<<"verylongint1/verylongint2:"<<verylongint1/verylongint2;
    std::cout<<"verylongint1%verylongint2:"<<verylongint1%verylongint2;
    //��ҳ����
    system("pause");
    system("cls");
    //һ��2����������������92λ����ֵ
    VeryLongInt verylongint3("71628373872638493782649873264792647362482674628347283648764932746298347623487236472384627846");
    VeryLongInt verylongint4("56893472983746329834763298476392746928374692837469283469283746928347692843769283746928374628");
    std::cout<<"verylongint3:"<<verylongint3<<"verylongint4:"<<verylongint4;
    std::cout<<"verylongint3+verylongint4:"<<verylongint3+verylongint4;
    std::cout<<"verylongint3-verylongint4:"<<verylongint3-verylongint4;
    std::cout<<"verylongint3*verylongint4:"<<verylongint3*verylongint4;
    std::cout<<"verylongint3/verylongint4:"<<verylongint3/verylongint4;
    std::cout<<"verylongint3%verylongint4:"<<verylongint3%verylongint4;
    //��ҳ����
    system("pause");
    system("cls");
    //default
    long int long_int_max=LONG_MAX;
    long int long_int_min=LONG_MIN;
    VeryLongInt verylongint5(0);
    std::cout<<"verylongint5:"<<verylongint5;
//    VeryLongInt verylongint6("0o0");
    VeryLongInt verylongint7("0x0");
//    VeryLongInt verylongint8(long_int_max);
//    VeryLongInt verylongint9("");
//    VeryLongInt verylongint10("");
//    VeryLongInt verylongint11(long_int_min);
//    VeryLongInt verylongint12("");
//    VeryLongInt verylongint13("");
//    std::cout<<"verylongint9:"<<verylongint9<<"verylongint10:"<<verylongint10;
//    std::cout<<"verylongint11:"<<verylongint11<<"verylongint12:"<<verylongint12;
    system("pause");
    system("cls");
    return 0;
}