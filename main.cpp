#include "VeryLongInt.h"


int main() {
    std::string decimal_str = "1234548545154";
    std::cout<<decimalToHexadecimal(decimal_str)<<std::endl;
//    show_copyright();
//    VeryLongInt int1("0x2124568675755");
//
//    int1.print_decimal();
//    VeryLongInt int2("-0212456675755");
//    int2.print_decimal();
//    VeryLongInt int3(0212456);
//    int3.print_decimal();
//    std::cout<<"int1+int2="<<int1+int2<<std::endl;
//    std::cout<<"int1-int2="<<int1-int2<<std::endl;//
//    std::cout<<"int2-int1="<<int2-int1<<std::endl;
//    std::cout<<"int2*int1="<<int2*int1<<std::endl;
////    std::cout<<"int2/int1="<<int2/int1<<std::endl;
////    std::cout<<"int2%int1="<<int2%int1<<std::endl;
//    std::cout<<"int1   "<<int1<<std::endl;
//    std::cout<<"int1++   "<<int1++<<std::endl;
//    std::cout<<"int1   "<<int1<<std::endl;
//    std::cout<<"++int1   "<<++int1<<std::endl;
//    std::cout<<"int1   "<<int1<<std::endl;
    VeryLongInt int3("64841885494");
//    int3.print_decimal();
    VeryLongInt int4("3506");
//    int4.print_decimal();
//    std::cout<<"int3+int4="<<int3+int4<<std::endl;
//    std::cout<<"int3-int4="<<int3-int4<<std::endl;//
//    std::cout<<"int4-int3="<<int4-int3<<std::endl;
//    std::cout<<"int3*int4="<<int3*int4<<std::endl;
    std::cout<<"int3/int4="<<int3/int4<<std::endl;
//    VeryLongInt int5("0123");
//    int5.print_decimal();
//    VeryLongInt int6("-0456");
//    int6.print_decimal();
//    VeryLongInt int7("0x123");
//    int7.print_decimal();
//    VeryLongInt int8("-0x456");
//    int8.print_decimal();
//    try{
//        VeryLongInt int7("0x123");
//    }
//
//    CATCH_INVALID_NUMBER_EXCEPTION;
    ::system("pause");
    return 0;
}