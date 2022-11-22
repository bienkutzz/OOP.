#include <iostream>
using namespace std;

class ComplexNumber
{
private:
	double real;
	double imaginary;
public:
	void setReal(double input) //setters
	{
		real = input;
	}
	void setImaginary(double input)
	{
		imaginary = input;
	}

	double getReal()//getters
	{
		return real;
	}
	double getImaginary()
	{
		return imaginary;
	}

	ComplexNumber() //constructors
	{
		real = 0;
		imaginary = 0;
	}
	ComplexNumber(double inputReal)
	{
		real = inputReal;
		imaginary = 0;
	}
	ComplexNumber(double inputReal, double inputImaginary)
	{
		real = inputReal;
		imaginary = inputImaginary;
	}
};

ComplexNumber sum(ComplexNumber no1, ComplexNumber no2) 
{
	ComplexNumber sum;
	sum.setReal(no1.getReal() + no2.getReal()); //add the real parts
	sum.setImaginary(no1.getImaginary() + no2.getImaginary()); //add the imaginary parts
	return sum;
}

int main()
{
	ComplexNumber no1(2.5, 6), no2(1.35, 4.45), sumofno;
	sumofno = sum(no1, no2);
	cout << "The number is " << sumofno.getReal() << "+" << sumofno.getImaginary() << "*i";


}