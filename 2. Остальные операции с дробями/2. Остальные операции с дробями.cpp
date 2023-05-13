// 2. Остальные операции с дробями.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include <numeric> 

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction() = default;
	Fraction(int numerator_1, int denominator_1) 
	{ 
		numerator_ = numerator_1;
		denominator_ = denominator_1;
}

	///////////////////////////////f1+f2

	Fraction operator+(const Fraction& other) const {
		Fraction temp;
		temp.numerator_ = this->numerator_ * other.denominator_ + this->denominator_ * other.numerator_;
		temp.denominator_ = this->denominator_ * other.denominator_;
		return temp;
	}

	Fraction operator-(const Fraction& other) const {
		Fraction temp;
		temp.numerator_ = this->numerator_ * other.denominator_ - other.numerator_ * this->denominator_;
		temp.denominator_ = this->denominator_ * other.denominator_;
		return temp;
	}


	Fraction operator*(const Fraction& other) const {
		Fraction temp;
		temp.numerator_ = this->numerator_ * other.numerator_;
		temp.denominator_ = this->denominator_ * other.denominator_;

		// Находим наибольший общий делитель числителя и знаменателя
		int gcd = 1;
		int min_num = std::min(temp.numerator_, temp.denominator_);
		for (int i = 2; i <= min_num; ++i) {
			if (temp.numerator_ % i == 0 && temp.denominator_ % i == 0) {
				gcd = i;
			}
		}

		// Делим числитель и знаменатель на наибольший общий делитель
		if (gcd > 1) {
			temp.numerator_ /= gcd;
			temp.denominator_ /= gcd;
		}

		return temp;
	}


	Fraction operator/(const Fraction& other) const {
		Fraction temp;
		temp.numerator_ = this->numerator_ * other.denominator_;
		temp.denominator_ = this->denominator_ * other.numerator_;
		return temp;
	}
	
	friend std::ostream& operator << (std::ostream& os, const Fraction& f);

	Fraction operator-() const {
		return Fraction(-numerator_, denominator_);
	}
	// перегрузка инкремента префиксной формы
	Fraction& operator++()
	{
		numerator_ += denominator_;
		return *this;
	}

	// перегрузка инкремента постфиксной формы
	Fraction operator++(int)
	{
		Fraction temp(*this);
		numerator_ += denominator_;
		return temp;
	}
	// перегрузка дек префиксной формы
	Fraction& operator--()
	{
		numerator_ -= denominator_;
		return *this;
	}

	// перегрузка дек постфиксной формы
	Fraction operator--(int)
	{
		Fraction temp(*this);
		numerator_ -= denominator_;
		return temp;
	}
};
//эта функция возвращает ссылку на ostream второй параметр ссыль на класс//для записи в дробь
std::ostream& operator<<(std::ostream& os, const Fraction& f) {
	os << f.numerator_ << '/' << f.denominator_;

	return os;
}
int main()
{	
	setlocale(LC_ALL, "ru");
	int a; int b;
	int c; int d;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> a;
	std::cout << "Введите знаменатель дроби 1 : ";
	std::cin >> b;

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> c;
	std::cout << "Введите знаменатель дроби 2 : ";
	std::cin >> d;

	Fraction f1(a, b);
	Fraction f2(c, d);
	Fraction f1_copy = f1; // создаем копию f1
	Fraction f2_copy = f2; // создаем копию f2
	

	Fraction result = f1 + f2;
	Fraction result1 = f1 - f2;
	Fraction result2 = f1 * f2;
	Fraction result3 = f1 / f2;
	//унарный минус;
	Fraction result4 = -f1;
	Fraction result5 = -f2;
	Fraction result6 = ++f1;
	Fraction result7 = f1++;
	Fraction result8 = --f2;
	Fraction result9 = f2--;


	std::cout << f1_copy << " + " << f2_copy << " = " << result << std::endl;
	std::cout << f1_copy << " - " << f2_copy << " = "<<result1 << std::endl;
	std::cout << f1_copy << " * " << f2_copy << " = " << result2 << std::endl;
	std::cout << f1_copy << " / " << f2_copy << " = " << result3 << std::endl;
	//унарный минус
	std::cout << "унарный минус: " <<  '\n';
	std::cout  << result4<<"  " << result5 << '\n';
	//инкремент постфиксный и префиксный;
	std::cout << "инкремент постфиксный и префиксный: "<<result6 << "  " << result7 << '\n';

	//декремент постфиксный и префиксный.
	std::cout << "декремент постфиксный и префиксный: " << result8 << "  " << result9 << '\n';
	
	
	return 0;
}
/*если вы определите конструктор по умолчанию явно, 
то обязательно нужно его определить как default,
чтобы гарантировать его правильное создание.
Например, если у вас есть другие пользовательские конструкторы, 
и вы хотите определить конструктор по умолчанию, но не знаете, как его реализовать,
вы можете объявить его как Fraction() = default;.*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
