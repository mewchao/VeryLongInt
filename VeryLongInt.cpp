# include "VeryLongInt.h"


//ʮ���Ƶĳ����ι���
VeryLongInt::VeryLongInt(long long other) {
	if (isOctal(other)) {
		other = octalToDecimal(other);
	}
	if (isHexadecimal(other)) {
		other = hexadecimalToDecimal(other);
	}
	if (other < 0) {
		this->negative = true;
		other = -other;
	} else {
		this->negative = false;
	}
	while (other) {
		this->digits.push_back(other % 10);
		other /= 10;
	}
}


bool isOctal(long int number) {
	std::string strNumber = std::to_string(number);
	if (strNumber.length() > 1 && strNumber[0] == '0') {
		for (size_t i = 1; i < strNumber.length(); ++i) {
			if (strNumber[i] < '0' || strNumber[i] > '7') {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool isHexadecimal(long int number) {
	std::string strNumber = std::to_string(number);
	if (strNumber.length() > 2 && strNumber[0] == '0' &&
	    (strNumber[1] == 'x' || strNumber[1] == 'X')) {
		for (size_t i = 2; i < strNumber.length(); ++i) {
			if (!((strNumber[i] >= '0' && strNumber[i] <= '9') ||
			      (strNumber[i] >= 'A' && strNumber[i] <= 'F') ||
			      (strNumber[i] >= 'a' && strNumber[i] <= 'f'))) {
				return false;
			}
		}
		return true;
	}
	return false;
}


long int octalToDecimal(long int octalNumber) {
	std::string strOctal = std::to_string(octalNumber);
	long int decimalNumber = std::stol(strOctal, nullptr, 8);
	return decimalNumber;
}

long int hexadecimalToDecimal(long int hexadecimalNumber) {
	std::string strHexadecimal = std::to_string(hexadecimalNumber);
	long int decimalNumber = std::stol(strHexadecimal, nullptr, 16);
	return decimalNumber;
}

//��һ��������������������
VeryLongInt::VeryLongInt(std::vector<int> v, bool negative) {
	this->digits = v;
	this->negative = negative;
}

//��ӡ
void VeryLongInt::print() {
	if (digits.empty()) {
		std::cout << "0" << std::endl;
		return;
	}
	if (negative) {
		std::cout << "-";
	}
	for (int i = digits.size() - 1; i >= 0; i--) {
		std::cout << digits[i];
	}
	std::cout << std::endl;
}

// ȡ�෴��
VeryLongInt VeryLongInt::operator-() const {
	VeryLongInt redis(*this);
	//�ı�����
	redis.negative = !negative;
	return redis;
}

VeryLongInt VeryLongInt::Negative() const {
	return VeryLongInt(digits, !negative);
}


VeryLongInt VeryLongInt::operator+(const VeryLongInt &other) const {
	//�������ֵ���������ͬ��ֱ�����
	if (negative == other.negative) {
		int carry = 0;  //��λ
		std::vector<int> result;  //��Ž��
		//123456->654321
		//789->987
		for (int i = 0; i < std::max(digits.size(), other.digits.size()); i++) {
			int sum = carry;
			if (i < digits.size()) {
				sum += digits[i];
			}
			if (i < other.digits.size()) {
				sum += other.digits[i];
			}
			result.push_back(sum % 10);
			carry = sum / 10;
		}
		//�������һ�εĽ�λ
		if (carry != 0) {
			result.push_back(carry);
		}

		return VeryLongInt(result, negative);
	} else {
		// �������ֵ������Բ�ͬ�����ü���
		//��+��ʱ����-�����෴��->���Ϊ����-����    ��+��ʱ����-�����෴��->���Ϊ��-��
		VeryLongInt neg_other = other;
		neg_other.negative = !neg_other.negative;
		return *this - neg_other;
	}
}

VeryLongInt VeryLongInt::operator-(const VeryLongInt &other) const {
	// �������ֵ���������ͬ��ֱ�����
	if (negative == other.negative) {
		// �ж��������Ĵ�С��ϵ��ȷ��������ʱ���������ڵ��ڼ���(this����ֵ�Ƚϴ�)
		bool swap_flag = false;
		if (digits.size() < other.digits.size()) {
			swap_flag = true;
		} else if (digits.size() == other.digits.size()) {
			for (int i = digits.size() - 1; i >= 0; i--) {
				if (digits[i] < other.digits[i]) {
					swap_flag = true;
					break;
				} else if (digits[i] > other.digits[i]) {
					break;
				}
			}
		}
		//this����ֵ�Ƚ�С��ʱ��->swap_flag=true
		// ���������С�ڼ������������ǵ�λ�ã�����¼���Ϊ����
		if (swap_flag) {
			//�Լ������Լ�
			VeryLongInt result = other - *this;
			result.negative = true;
			return result;
		}
		int borrow = 0;  // ��λ
		std::vector<int> result;  // ��Ž��
		// 123456->654321
		// 789->987
		for (int i = 0; i < std::max(digits.size(), other.digits.size()); i++) {
			int diff = borrow;
			if (i < digits.size()) {
				diff += digits[i];
			}
			if (i < other.digits.size()) {
				diff -= other.digits[i];
			}
			if (diff < 0) {
				diff += 10;
				borrow = -1;
			} else {
				borrow = 0;
			}
			result.push_back(diff);
		}
		// ȥ�������ǰ����
		while (result.size() > 1 && result.back() == 0) {
			result.pop_back();
		}
		return VeryLongInt(result, negative);
	}
	// �������ֵ������Բ�ͬ�����üӷ�
	//��-��ʱ����+�����෴��->���Ϊ��+��    ��-��ʱ����+�����෴��->���Ϊ��+��
	VeryLongInt neg_other = other;
	neg_other.negative = !neg_other.negative;
	return *this + neg_other;
}

VeryLongInt VeryLongInt::operator*(const VeryLongInt &other) const {
	//��ʼ��һ������Ϊ������������λ��֮�͵����飬����Ԫ�ض�Ϊ0�����ڴ洢�˻��Ľ��
	std::vector<int> result(digits.size() + other.digits.size(), 0);

	for (int i = 0; i < digits.size(); i++) {
//        ��λ��ˣ����ڵ�һ������ÿһλ����һ��ڶ�������ÿһλ��ˡ���
//        ͬʱ��Ҫ����ǰһ�γ˷��Ľ�λ�����
//        ����أ����ڵں͵�jλ��ˣ���Ҫ�����ǵĳ˻�����ǰһλ�Ľ�λ�ͽ��������ԭ����ֵ������У���Ȼ��ֱ�ȡ��ͳ���10�õ���ǰλ�Ľ���ͽ�λ��
		int carry = 0;
		for (int j = 0; j < other.digits.size(); j++) {
			int prod = digits[i] * other.digits[j] + carry + result[i + j];
			result[i + j] = prod % 10;
			carry = prod / 10;
		}
		if (carry != 0) {
			result[i + other.digits.size()] += carry;
		}
	}
	// ���ڿ��ܻ����һЩ����Ҫ��ǰ���㣬������Ҫ�ڷ��ؽ��ǰ������ȥ����
	while (result.size() > 1 && result.back() == 0) {
		result.pop_back();
	}
	return VeryLongInt(result, negative != other.negative);
}


VeryLongInt VeryLongInt::operator/(const VeryLongInt &other) const {
	if (other == 0) {
		throw std::invalid_argument("��������Ϊ0"); // �������Ϊ0�����׳��쳣
	}

	VeryLongInt dividend = *this;

	// ��¼����ķ���
	bool negativeResult = false;
	if (dividend.negative != other.negative) {
		negativeResult = true; // ���ݱ������ͳ����ķ���ȷ������ķ���
	}

	dividend.negative = false;
	VeryLongInt divisorPositive = other;
	divisorPositive.negative = false; // ȷ��divisorPositiveʼ��Ϊ����

	VeryLongInt quotient(0);
	VeryLongInt remainder(0);
	quotient.digits.resize(dividend.digits.size(), 0); // ����quotient��digits������С��ƥ�䱻�����Ĵ�С

	// �������㷨
	for (int i = dividend.digits.size() - 1; i >= 0; --i) {
		remainder = remainder * 10 + dividend.digits[i]; // ���������Ʋ����ϱ���������һλ����
		while (remainder >= divisorPositive) {
			remainder = remainder - divisorPositive; // ͨ���������м�ȥdivisorPositiveִ�г�������
			quotient.digits[i]++; // �������е�����
		}
	}

	// �Ƴ����е�ǰ����
	while (quotient.digits.size() > 1 && quotient.digits.back() == 0) {
		quotient.digits.pop_back();
	}

	quotient.negative = negativeResult; // �����̵ķ���
	return quotient; // ������
}

VeryLongInt VeryLongInt::operator%(const VeryLongInt &other) const {
	// �жϱ������Ƿ�Ϊ��
	if (other == 0) {
		// �׳��쳣����д�����
		throw invalic_number_exception("��������Ϊ0");
	}

	// ��������ת��Ϊ����ֵ��������洢����ʱ����absDividend��
	VeryLongInt absDividend = *this;
	absDividend.negative = false;

	// ������ת��Ϊ����ֵ��������洢����ʱ����absDivisor��
	VeryLongInt absDivisor = other;
	absDivisor.negative = false;

	// ִ�о���ֵ����ģ����
	VeryLongInt quotient = absDividend / absDivisor;
	VeryLongInt product = absDivisor * quotient;
	VeryLongInt remainder = absDividend - product;

	// ���ݱ������ͳ����ķ���ȷ�����յĽ���ķ���
	if (negative)
		remainder.negative = true;

	return remainder;
}

//--------------------------------------

std::vector<char> tblIntToChar(36);
std::vector<int> tblCharToInt(256, 0);

// ��ʼ�����
bool InitTables() {
	for (int i = 0; i < 10; i++) {
		tblIntToChar[i] = '0' + i;
		tblCharToInt['0' + i] = i;
	}
	for (int i = 10; i < 36; i++) {
		tblIntToChar[i] = 'A' + i - 10;
		tblCharToInt['A' + i - 10] = i;
		tblCharToInt['a' + i - 10] = i;
	}
	return true;
}

bool init_l = InitTables();

// �ڸ��������µļӷ�
std::string Add(const std::string &num1, const std::string &num2, int base) {
	int carry = 0;
	int length = std::max(num1.size(), num2.size());

	std::string result(length, '0');
	for (int i = 0; i < length; i++) {
		int digit1 = i < num1.size() ? tblCharToInt[(unsigned char) num1[num1.size() - 1 - i]] : 0;
		int digit2 = i < num2.size() ? tblCharToInt[(unsigned char) num2[num2.size() - 1 - i]] : 0;

		int sum = digit1 + digit2 + carry;
		carry = sum / base;
		result[length - 1 - i] = tblIntToChar[sum % base];
	}

	if (carry > 0) {
		result.insert(result.begin(), tblIntToChar[carry]);
	}

	return result;
}

// ��ʮ������ת��Ϊ�����������ַ���
std::string AsBase(int number, int base) {
	std::string result;
	do {
		result += tblIntToChar[number % base];
		number /= base;
	} while (number != 0);
	std::reverse(result.begin(), result.end());
	return result;
}

std::string ConvertBase(const std::string &number, int oldBase, int newBase) {
	InitTables();
	std::string result = "0";

	for (unsigned digit = 0; digit < number.size(); digit++) {
		int value = tblCharToInt[(unsigned char) number[digit]];
		std::string temp = result;
		for (int i = 1; i < oldBase; i++) {
			temp = Add(result, temp, newBase);
		}
		result = Add(temp, AsBase(value, newBase), newBase);
	}

	return result;
}


std::string convertToDecimal(const std::vector<int> &digits) {
	std::stringstream decimalTextStream;

	// ����ÿ��Ԫ�ز�ת��Ϊ�ַ�����
	for (int i = digits.size() - 1; i >= 0; i--) {
		decimalTextStream << digits[i];
	}

	std::string decimalText = decimalTextStream.str();

	return decimalText;
}

//--------------------------------------

std::string VeryLongInt::toHex() {
	auto numberStr = convertToDecimal(digits);
	return ConvertBase(numberStr, 10, 16);
}

std::string VeryLongInt::toOct() {
	auto numberStr = convertToDecimal(digits);
	return ConvertBase(numberStr, 10, 8);
}


VeryLongInt VeryLongInt::operator+(const long int &other) const {
	VeryLongInt other_int(other);
	return *this + other_int;
}

VeryLongInt VeryLongInt::operator-(const long int &other) const {
	VeryLongInt other_int(other);
	return *this - other_int;
}

VeryLongInt VeryLongInt::operator*(const long int &other) const {
	VeryLongInt other_int(other);
	return *this * other_int;
}

VeryLongInt VeryLongInt::operator=(VeryLongInt other) {
	this->digits = other.digits;
	this->negative = other.negative;
	return *this;
}

VeryLongInt VeryLongInt::operator+(const std::string &other) const {
	VeryLongInt other_int(other);
	return *this + other_int;
}

VeryLongInt VeryLongInt::operator-(const std::string &other) const {
	VeryLongInt other_int(other);
	return *this - other_int;
}

//��+1�󷵻�
VeryLongInt VeryLongInt::operator++() {
	*this += 1;
	return *this;
}

VeryLongInt VeryLongInt::operator--() {
	*this -= 1;
	return *this;
}

VeryLongInt VeryLongInt::operator++(int) {
	VeryLongInt temp = *this;
	*this += 1;
	return temp;
}

VeryLongInt VeryLongInt::operator--(int) {
	VeryLongInt temp = *this;
	*this -= 1;
	return temp;
}


VeryLongInt VeryLongInt::operator*(const std::string &other) const {
	VeryLongInt other_int(other);
	return *this * other_int;
}

VeryLongInt VeryLongInt::operator+=(const VeryLongInt &other) {
	VeryLongInt other_int(other);
	*this = *this + other_int;
	return *this;
}

VeryLongInt VeryLongInt::operator-=(const VeryLongInt &other) {
	VeryLongInt other_int(other);
	*this = *this - other_int;
	return *this;
}

VeryLongInt VeryLongInt::operator*=(const VeryLongInt &other) {
	VeryLongInt other_int(other);
	*this = *this * other_int;
	return *this;
}

VeryLongInt VeryLongInt::operator+=(const long int &other) {
	VeryLongInt other_int(other);
	*this = *this + other_int;
	return *this;
}

VeryLongInt VeryLongInt::operator-=(const long int &other) {
	VeryLongInt other_int(other);
	*this = *this - other_int;
	return *this;
}

VeryLongInt VeryLongInt::operator*=(const long int &other) {
	VeryLongInt other_int(other);
	*this = *this * other_int;
	return *this;
}

VeryLongInt VeryLongInt::operator/=(const VeryLongInt &other) {
	VeryLongInt other_int(other);
	*this = *this / other_int;
	return *this;
}

VeryLongInt VeryLongInt::operator%=(const VeryLongInt &other) {
	VeryLongInt other_int(other);
	*this = *this % other_int;
	return *this;
}

VeryLongInt VeryLongInt::operator+=(const std::string &other) {
	VeryLongInt other_int(other);
	*this = *this + other_int;
	return *this;
}

VeryLongInt VeryLongInt::operator-=(const std::string &other) {
	VeryLongInt other_int(other);
	*this = *this - other_int;
	return *this;
}

VeryLongInt VeryLongInt::operator*=(const std::string &other) {
	VeryLongInt other_int(other);
	*this = *this * other_int;
	return *this;
}

// ����<
bool VeryLongInt::operator<(const VeryLongInt &other) const {
	if (negative != other.negative) {
		//������=����->return true
		return negative;
	}
		//���Ŷ�Ϊ��
	else if (!negative) {
		if (digits.size() != other.digits.size()) {
			if (digits.size() < other.digits.size())return true;
			if (digits.size() > other.digits.size())return false;
		}
		//������ͬ
		for (int i = digits.size() - 1; i >= 0; --i) {
			//�����λ��ʼ�Ƚ�
			if (digits[i] != other.digits[i]) {
				if (digits[i] < other.digits[i])return true;
				if (digits[i] > other.digits[i])return false;
			}
		}
		//���
		return false;
	}
		//���Ŷ�Ϊ��
	else {
		if (digits.size() != other.digits.size()) {
			if (digits.size() < other.digits.size())return false;
			if (digits.size() > other.digits.size())return true;
		}
		//������ͬ
		for (int i = digits.size() - 1; i >= 0; --i) {
			//�����λ��ʼ�Ƚ�
			if (digits[i] != other.digits[i]) {
				if (digits[i] < other.digits[i])return false;
				if (digits[i] > other.digits[i])return true;
			}
		}
		//���
		return false;
	}
}


//����>
bool VeryLongInt::operator>(const VeryLongInt &other) const {
	if (negative != other.negative) {
		//������=����->return false
		return other.negative;
	}
		//���Ŷ�Ϊ��
	else if (!negative) {
		if (digits.size() != other.digits.size()) {
			if (digits.size() < other.digits.size())return false;
			if (digits.size() > other.digits.size())return true;
		}
		//������ͬ
		for (int i = digits.size() - 1; i >= 0; --i) {
			//�����λ��ʼ�Ƚ�
			if (digits[i] != other.digits[i]) {
				if (digits[i] < other.digits[i])return false;
				if (digits[i] > other.digits[i])return true;
			}
		}
		//���
		return false;
	}
		//���Ŷ�Ϊ��
	else {
		if (digits.size() != other.digits.size()) {
			if (digits.size() < other.digits.size())return true;
			if (digits.size() > other.digits.size())return false;
		}
		//������ͬ
		for (int i = digits.size() - 1; i >= 0; --i) {
			//�����λ��ʼ�Ƚ�
			if (digits[i] != other.digits[i]) {
				if (digits[i] < other.digits[i])return true;
				if (digits[i] > other.digits[i])return false;
			}
		}
		//���
		return false;
	}
}

//����>=
bool VeryLongInt::operator>=(const VeryLongInt &other) const {
	if (*this > other || *this == other) {
		return true;
	} else {
		return false;
	}
}

//����<=
bool VeryLongInt::operator<=(const VeryLongInt &other) const {
	if (*this < other || *this == other) {
		return true;
	} else {
		return false;
	}
}

// �ж����
bool VeryLongInt::operator==(const VeryLongInt &other) const {
	return negative == other.negative && digits == other.digits;
}

// �ж����
bool VeryLongInt::operator!=(const VeryLongInt &other) const {
	return !(negative == other.negative && digits == other.digits);
}

VeryLongInt::VeryLongInt(std::string str) {
	if (str[0] == '-') {
		str.erase(0, 1);
		this->negative = true;
	}

	if (str[0] == '0') {
		if (str[1] == 'x' || str[1] == 'X') { // Hexadecimal
			str.erase(0, 2);


			for (int i = str.size() - 1; i >= 0; i--) {
				int hex_digit;
				if (str[i] >= '0' && str[i] <= '9')
					hex_digit = (str[i] - '0');
				else if (str[i] >= 'a' && str[i] <= 'f')
					hex_digit = (str[i] - 'a' + 10);
				else if (str[i] >= 'A' && str[i] <= 'F')
					hex_digit = (str[i] - 'A' + 10);
				else
					throw invalic_number_exception(str);
			}
			std::string rts = ConvertBase(str, 16, 10);
			*this = VeryLongInt(rts);
		} else { // Octal
			str.erase(0, 1);


			for (int i = str.size() - 1; i >= 0; i--) {
				int hex_digit;
				if (str[i] >= '0' && str[i] <= '9')
					hex_digit = (str[i] - '0');
				else if (str[i] >= 'a' && str[i] <= 'f')
					hex_digit = (str[i] - 'a' + 10);
				else if (str[i] >= 'A' && str[i] <= 'F')
					hex_digit = (str[i] - 'A' + 10);
				else
					throw invalic_number_exception(str);
			}
			std::string rts = ConvertBase(str, 8, 10);
			*this = VeryLongInt(rts);
		}
	} else { // Decimal
		for (int i = str.size() - 1; i >= 0; i--) {
			if (str[i] < '0' || str[i] > '9')
				throw invalic_number_exception(str);
			digits.push_back(str[i] - '0');
		}
	}
}

//��ʾʱ����ʾ��Ȩ�Ĳ˵�
void show_copyright() {
	std::cout << std::endl << "    ---Copyright---(c++) 2023-2023 �ο���(222200231). All Rights Reserved.---    ";
	std::cout << std::endl;
	show_time();
	std::cout << std::endl;
}

void show_time() {
	std::string week[7] = {"������", "����һ", "���ڶ�", "������", "������", "������", "������"};
	SYSTEMTIME now2;
	GetLocalTime(&now2);
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::cout << std::endl << "        ��ǰ���ڡ�ʱ�� :" << ltm->tm_year + 1900 << "." << 1 + ltm->tm_mon << "."
	          << ltm->tm_mday << " " << ltm->tm_hour
	          << ":" << ltm->tm_min << ":" << ltm->tm_sec << "(" << week[now2.wDayOfWeek] << ") " << std::endl;
}