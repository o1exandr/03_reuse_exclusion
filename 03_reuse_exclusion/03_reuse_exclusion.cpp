/*
Завдання 3. Створити програму, яка демонструє, що  функція зі своїм власним try–блоком не зобов’язана перехоплювати всі можливі виключення, 
викинуті у блоці  try. Деякі виключення можуть бути випущені у зовнішні області дії і оброблятися у них.

*/

#include "stdafx.h"
#include <iostream> 
#include <string>

using namespace std;

class Some
{
private:
	double a, b;


public:

	// встановлення значень дробу
	double setFraction(double a, double b)
	{
		try
		{
			if (a == 0)	throw a;
			if (b < 0)	throw invalid_argument("\tnegative b = " + to_string(b));
			if (b > 100) throw "\tb more than 100";
		}

		catch (double ex)
		{
			cout << "\tdouble: " << ex << endl;
		}

		catch (const char* ex)
		{
			cout << "\tchar*: " << ex << endl;
		}

		catch (invalid_argument ex)
		{
			cout << "\tinvalid_argument: " << ex.what() << endl;
		}
		
		return a / b;
	}

};



int main()
{
	Some some;

	try
	{
		//виключення описані у функції
		//cout << some.setFraction(0, 1); // double
		//cout << some.setFraction(1, -1); // invalid_argument
		//cout << some.setFraction(1, 101); // char*

		//виключення ділення на 0 не описане у функції
		double a = 1, b = 0;
		if (b == 0) throw 0; //цю помилку перехопить  catch (...)
		cout << some.setFraction(a, b);
	}

	
	catch (...)
	{
		cout << "\tAnother error";
	}

	cout << endl;
	system("pause");
	return 0;

}

