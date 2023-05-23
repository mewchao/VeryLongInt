#include "VeryLongInt.h"


int main() {
    show_copyright();
    VeryLongInt int1(123456);
    int1.print();
    VeryLongInt int2(0x123456);
    int2.print();
    std::cout<<"int1+int2="<<int1+int2<<std::endl;
    std::cout<<"int1-int2="<<int1-int2<<std::endl;//
    std::cout<<"int2-int1="<<int2-int1<<std::endl;
    std::cout<<"int2*int1="<<int2*int1<<std::endl;
//    std::cout<<"int2/int1="<<int2/int1<<std::endl;
//    std::cout<<"int2%int1="<<int2%int1<<std::endl;
    std::cout<<"int1   "<<int1<<std::endl;
    std::cout<<"int1++   "<<int1++<<std::endl;
    std::cout<<"int1   "<<int1<<std::endl;
    std::cout<<"++int1   "<<++int1<<std::endl;
    std::cout<<"int1   "<<int1<<std::endl;
    VeryLongInt int3("350627200407240014");
    int3.print();
    VeryLongInt int4("3506");
    int4.print();
    std::cout<<"int3+int4="<<int3+int4<<std::endl;
    std::cout<<"int3-int4="<<int3-int4<<std::endl;//
    std::cout<<"int4-int3="<<int4-int3<<std::endl;
    std::cout<<"int3*int4="<<int3*int4<<std::endl;
//    std::cout<<"int3/int4="<<int3/int4<<std::endl;
    VeryLongInt int5("0123");
    int5.print();
    VeryLongInt int6("-0456");
    int6.print();
    VeryLongInt int7("0x123");
    int7.print();
    VeryLongInt int8("-0x456");
    int8.print();
    try{
        VeryLongInt int7("0x123");
    }

    CATCH_INVALID_NUMBER_EXCEPTION;
    ::system("pause");
    return 0;
}