# VeryLongInt
编写一个任意长的整数类(类名统一规定为：VeryLongInt)，
可以用默认值0或（C/C++本身的）长整型数（十进制值、八进制值、十六进制值）或（十进制值、0打头的八进制值、0x或0X打头的十六进制值的）字符串进行对象的初始化(构造)，
然后用合适的成员函数、友元函数或普通函数等（很多函数可以用这三者之一实现，所以这里是发现是否抄袭的一个地方）重载相应的运算符实现下述功能：
“任意长的整数/长整型数/字符串”op“任意长的整数/长整型数/字符串”的算术运算(op为：加+、减-、乘*、整除/、求余%)，即：任意长的整数op任意长的整数、任意长的整数op长整型数、
任意长的整数op字符串，长整型数op任意长的整数、字符串op任意长的整数；关系运算(>、>=、<、<=、!=、==)和复合运算(+=、-=、*=、/=、%=)；-任意长的整数；++任意长的整数、任意长的整数++，
--任意长的整数、任意长的整数--，插入(输出)运算符<<和>>，可以用八进制值和十六进制值输出（你定义的整数值），
如果需要务必要重载赋值运算符=和拷贝构造函数，同时编写析构函数。最后编写一个主函数(测试程序)对以上的所有功能进行全面的测试，主函数也要求大家自己独立设计和编写。
