
#include "VeryLongInt.h"
int main() {
    show_copyright();
    VeryLongInt int1("123456");
    int1.print();
    VeryLongInt int2("-123456");
    int2.print();
    cout<<"int1+int2="<<int1+int2<<endl;
    cout<<"int1-int2="<<int1-int2<<endl;//
    cout<<"int2-int1="<<int2-int1<<endl;
    cout<<"int2*int1="<<int2*int1<<endl;
    VeryLongInt int3("350627200407240014");
    int3.print();
    VeryLongInt int4("-350627200407240014");
    int4.print();
    cout<<"int3+int4="<<int3+int4<<endl;
    cout<<"int3-int4="<<int3-int4<<endl;//
    cout<<"int3-int4="<<int3-int4<<endl;
    cout<<"int3*int4="<<int3*int4<<endl;
    int a=-0xf;
    cout<<(a+=2)<<endl;
    return 0;
}