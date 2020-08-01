#include <iostream>
using namespace std;
struct RationalNumber
{
	int numerator, denominator;
};
RationalNumber rationalAdd(RationalNumber num1, RationalNumber num2)
{
	RationalNumber result;
	if (num1.denominator==num2.denominator)
	{
		result.numerator=num1.numerator+num2.numerator;
		result.denominator=num1.denominator;
		return result;
	}
	else
	{
		result.numerator=num1.numerator*num2.denominator+num2.numerator*num1.denominator;
		result.denominator=num1.denominator*num2.denominator;
		return result;
	}
}
RationalNumber rationalSub(RationalNumber num1, RationalNumber num2)
{
	RationalNumber result;
	if (num1.denominator==num2.denominator)
	{
		result.numerator=num1.numerator-num2.numerator;
		result.denominator=num1.denominator;
		return result;
	}
	else
	{
		result.numerator=num1.numerator*num2.denominator-num2.numerator*num1.denominator;
		result.denominator=num1.denominator*num2.denominator;
		return result;
	}
}
void printRational(RationalNumber result)
{
	cout<<result.numerator<<"/"<<result.denominator<<endl;
}
int main()
{
	RationalNumber num1, num2;
	num1.numerator=2;
	num1.denominator=7;
	num2.numerator=3;
	num2.denominator=7;
	printRational(rationalAdd(num1, num2));
	printRational(rationalSub(num1, num2));


}