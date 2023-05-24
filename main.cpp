#include "VeryLongInt.h"


int main() {
    show_copyright();
    VeryLongInt verylongint1("350627200407240014");
    verylongint1.print_decimal();
    verylongint1.print_hex();
    verylongint1.print_oct();
    VeryLongInt verylongint2("222200231");
    verylongint2.print_decimal();
    verylongint2.print_hex();
    verylongint2.print_oct();
    std::cout<<verylongint1<<verylongint2;



//    std::cout << "int1+int2=" << int1 + int2 << std::endl;
//    std::cout << "int1-int2=" << int1 - int2 << std::endl;//
//    std::cout << "int2-int1=" << int2 - int1 << std::endl;
//    std::cout << "int2*int1=" << int2 * int1 << std::endl;
//    std::cout<<"int2*int1="<<int2/int1<<std::endl;
//    std::cout<<"int2/int1="<<int2/int1<<std::endl;
//    std::cout<<"int2%int1="<<int2%int1<<std::endl;
//    std::cout << "int1   " << int1 << std::endl;
//    std::cout << "int1++   " << int1++ << std::endl;
//    std::cout << "int1   " << int1 << std::endl;
//    std::cout << "++int1   " << ++int1 << std::endl;
//    std::cout << "int1   " << int1 << std::endl;
//    VeryLongInt int3("35062720286896758757828722004072675875782872240407240014");
//    int3.print();
//    VeryLongInt int4("3506758752028689675875778287226");
//    int4.print();
//    std::cout << "int3+int4=" << int3 + int4 << std::endl;
//    std::cout << "int3-int4=" << int3 - int4 << std::endl;//
//    std::cout << "int4-int3=" << int4 - int3 << std::endl;
//    std::cout << "int3*int4=" << int3 * int4 << std::endl;
//    std::cout << "int3/int4=" << int3 / int4 << std::endl;
//    std::cout << "int3%int4=" << int3 % int4 << std::endl;
//    std::cout << "test:" << int3.to_oct() << std::endl;
//    std::cout << "test:" << int3.to_hex() << std::endl;
//    VeryLongInt int5("0123");
//    int5.print();
//    VeryLongInt int6("-0456");
//    int6.print();
//    VeryLongInt int7("0x123");
//    int7.print();
//    VeryLongInt int8("-0x456");
//    int8.print();
//    std::cout<<"test1"<<VeryLongInt(213123213213324313)/VeryLongInt(3424234234)<<std::endl;
//    std::cout<<"test2"<<VeryLongInt(213123213213324313)/VeryLongInt(-3424234234)<<std::endl;
//    std::cout<<"test3"<<VeryLongInt("0x423423654747655761415557557614141e61414155576141415857f7754432")/VeryLongInt(-3424234234)<<std::endl;
//    std::cout<<"test4"<<VeryLongInt("0x423423654747656557557614141ad1415857614655761414a25754432")%VeryLongInt(3424234234)<<std::endl;
//
//    std::cout  << std::endl;
//    std::cout  << std::endl;
//    std::cout  << std::endl;
//    VeryLongInt int9("0x255989856255989856385625598985633633143145875968725598914587596872559898562559898558759687255989856255989856331458759687");
//
//    std::cout << "int9=" << int9 << std::endl;
//
//    VeryLongInt int10("0152165315457135614674161566514741617616147516");
//    std::cout << "int9/int10 " << int9 /int10<< std::endl;
//    std::cout << "int9%int10 " << int9 %int10<< std::endl;
//
//    std::cout  << std::endl;
//    std::cout  << std::endl;
//    std::cout  << std::endl;
////	int9.print();
//
//    std::cout << "int9=" << int9 << std::endl;
//    try {
//        VeryLongInt int7("0x123");
//    }
//    CATCH_INVALID_NUMBER_EXCEPTION;
    system("pause");
    return 0;
}