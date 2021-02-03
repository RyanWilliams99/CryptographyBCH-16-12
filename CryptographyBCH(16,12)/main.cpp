#include <ctype.h>      
#include <iostream>     
#include <string>       
#include <vector>    
#include <math.h> 

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

struct  ModularArithmatic
{
	static int mod(int a, int b)
	{
		return (a % b + b) % b;
	}

	static int LookUpRoot(int a)
	{
		switch (a)
		{
		case 1:
			return 1;
		case 2:
			return 6;
		case 4:
			return 2;
		case 8:
			return 5;
		case 9:
			return 3;
		case 13:
			return 8;
		case 15:
			return 7;
		case 16:
			return 4;
		default:
			return 0;
			break;
		}
	}

	static int LookUpInverse(int a)
	{
		switch (a)
		{
		case 1:
			return 1;
		case 2:
			return 9;
		case 3:
			return 6;
		case 4:
			return 13;
		case 5:
			return 7;
		case 6:
			return 3;
		case 7:
			return 5;
		case 8:
			return 15;
		case 9:
			return 2;
		case 10:
			return 12;
		case 11:
			return 14;
		case 12:
			return 10;
		case 13:
			return 4;
		case 14:
			return 11;
		case 15:
			return 8;
		case 16:
			return 16;

		default:
			return 0;
			break;
		}
	}

};

vector<int> split(const string& str)
{

	//std::string str = "1,2,3,4,5,6";
	std::vector<int> result;

	std::stringstream ss(str);

	for (int i; ss >> i;) {
		result.push_back(i);
		if (ss.peek() == ',')
			ss.ignore();
	}




	return result;

	/*vector<char> result;

	for (char ch : str)
	{
		if (isalnum(ch))
		{
			result.push_back(ch);
		}
	}

	return result;*/
}

int ConvertToInt(int i)
{
	return i;
}

void PrintInput(vector<int> c)
{
	cout << "Input  (";

	for (size_t i = 0; i < c.size(); i++)
	{
		cout << c[i];
		if (i == 15)
		{

		}
		else
		{
			cout << ",";
		}
	}

	cout << ")" << endl;
}

void PrintOutput(vector<int> c)
{
	cout << "Output (";

	for (size_t i = 0; i < c.size(); i++)
	{
		cout << c[i];
		if (i == 15)
		{

		}
		else
		{
			cout << ",";
		}
	}

	cout << ")";
}

void PrintUnknown()
{
	cout << "Output (";

	for (size_t i = 0; i < 16; i++)
	{
		cout << "?";
		if (i == 15)
		{

		}
		else
		{
			cout << ",";
		}
			

	}

	cout << ")";
}


int BCHDecode(string s)
{

	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	vector<int> input = split(s);
	vector<int> output;

	for (int i = 0; i < input.size(); i++)
		output.push_back(ConvertToInt(input[i]));


	//calculate s1 s2 s3 s4
	int s1 = ConvertToInt(input[0]) + ConvertToInt(input[1]) + ConvertToInt(input[2]) + ConvertToInt(input[3]) + ConvertToInt(input[4]) + ConvertToInt(input[5]) + ConvertToInt(input[6]) + ConvertToInt(input[7]) + ConvertToInt(input[8]) + ConvertToInt(input[9]) + ConvertToInt(input[10]) + ConvertToInt(input[11]) + ConvertToInt(input[12]) + ConvertToInt(input[13]) + ConvertToInt(input[14]) + ConvertToInt(input[15]);
	int s2 = ConvertToInt(input[0]) + (2 * ConvertToInt(input[1])) + (3 * ConvertToInt(input[2])) + (4 * ConvertToInt(input[3])) + (5 * ConvertToInt(input[4])) + (6 * ConvertToInt(input[5])) + (7 * ConvertToInt(input[6])) + (8 * ConvertToInt(input[7])) + (9 * ConvertToInt(input[8])) + (10 * ConvertToInt(input[9])) + (11 * ConvertToInt(input[10])) + (12 * ConvertToInt(input[11])) + (13 * ConvertToInt(input[12])) + (14 * ConvertToInt(input[13])) + (15 * ConvertToInt(input[14])) + (16 * ConvertToInt(input[15]));
	int s3 = ConvertToInt(input[0]) + (4 * ConvertToInt(input[1])) + (9 * ConvertToInt(input[2])) + (16 * ConvertToInt(input[3])) + (8 * ConvertToInt(input[4])) + (2 * ConvertToInt(input[5])) + (15 * ConvertToInt(input[6])) + (13 * ConvertToInt(input[7])) + (13 * ConvertToInt(input[8])) + (15 * ConvertToInt(input[9])) + (2 * ConvertToInt(input[10])) + (8 * ConvertToInt(input[11])) + (16 * ConvertToInt(input[12])) + (9 * ConvertToInt(input[13])) + (4 * ConvertToInt(input[14])) + (1 * ConvertToInt(input[15]));
	int s4 = ConvertToInt(input[0]) + (8 * ConvertToInt(input[1])) + (10 * ConvertToInt(input[2])) + (13 * ConvertToInt(input[3])) + (6 * ConvertToInt(input[4])) + (12 * ConvertToInt(input[5])) + (3 * ConvertToInt(input[6])) + (2 * ConvertToInt(input[7])) + (15 * ConvertToInt(input[8])) + (14 * ConvertToInt(input[9])) + (5 * ConvertToInt(input[10])) + (11 * ConvertToInt(input[11])) + (4 * ConvertToInt(input[12])) + (7 * ConvertToInt(input[13])) + (9 * ConvertToInt(input[14])) + (16 * ConvertToInt(input[15]));


	//mod 11 all syndromes
	s1 = s1 % 17;
	s2 = s2 % 17;
	s3 = s3 % 17;
	s4 = s4 % 17;

	//Get PQR (from powerpoint)
	int p = int(pow(s2, 2)) - (s1 * s3);
	int q = (s1 * s4) - (s2 * s3);

	int s3Squreard = int(pow(s3, 2));

	int r = s3Squreard - (s2 * s4);


	p = ModularArithmatic::mod(p, 17);
	q = ModularArithmatic::mod(q, 17);
	r = ModularArithmatic::mod(r, 17);


	PrintInput(input);

	if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0) //No Error
	{
		PrintOutput(output);
		cout << " No Error" << endl;
	}
	else if (p == 0 && q == 0 && r == 0) //Single Error
	{

		int a = s1;

		//  i = s2/s1 = s2 * inverse(s1 mod 11)
		int i = s2 * ModularArithmatic::LookUpInverse(s1);

		i = ModularArithmatic::mod(i, 17);


		if (i == 0)
		{
			PrintUnknown();
			cout << " More than 2 Errors, cant do single error correcting because index of error is 0 " << "syn(" << s1 << ", " << s2 << ", " << s3 << ", " << s4 << "), PQR(" << p << ", " << q << ", " << r << "))" << endl;
			return 0;
		}

		int wrongValue = ConvertToInt(input[i - 1]);

		int correctedValue = ModularArithmatic::mod(wrongValue - a, 17);

		output[i - 1] = correctedValue;


		PrintOutput(output);
		cout << " Single Error (i = " << i << ", a= " << a << ", syn(" << s1 << ", " << s2 << ", " << s3 << ", " << s4 << ")," << endl;
	}
	else
	{

		//Calculations broken up for readability
		//----------------------------------------------------Get i
		//step 1
		int v1 = int(pow(q, 2)) - 4 * p * r;

		int v2 = ModularArithmatic::mod(v1, 17);

		int v3 = ModularArithmatic::LookUpRoot(v2);

		int v4 = -q + v3;

		//step 2
		int v5 = 2 * p;

		int v6 = v4 * ModularArithmatic::LookUpInverse(ModularArithmatic::mod(v5, 17));


		int i = ModularArithmatic::mod(v6, 17);


		//----------------------------------------------------Get j
		//step 1
		v1 = int(pow(q, 2)) - 4 * p * r;

		v2 = ModularArithmatic::mod(v1, 17);

		v3 = ModularArithmatic::LookUpRoot(v2);

		v4 = -q - v3;

		//step 2
		v5 = 2 * p;

		v6 = v4 * ModularArithmatic::LookUpInverse(ModularArithmatic::mod(v5, 17));

		int j = ModularArithmatic::mod(v6, 17);


		//----------------------------------------------------Get b

		int b1 = (i * s1) - s2;

		int b2 = i - j;

		int inverse = ModularArithmatic::LookUpInverse(ModularArithmatic::mod(b2, 17));


		int b = ModularArithmatic::mod(b1 * inverse, 17);

		//-----------------------------------------------------Get a

		int a = ModularArithmatic::mod(s1 - b, 17);

		//Checks to see if more than 2 errors

		if (ModularArithmatic::LookUpRoot(ModularArithmatic::mod(v1, 17)) == 0)
		{
			PrintUnknown();
			cout << " More than 2 Errors no square root " << "syn(" << s1 << ", " << s2 << ", " << s3 << ", " << s4 << "), PQR(" << p << ", " << q << ", " << r << "))" << endl;
			return 0;

		}
		else if (i == 0 || j == 0)
		{
			cout << "More than 2 Errors, i or j = 0 " << "syn(" << s1 << ", " << s2 << ", " << s3 << ", " << s4 << "), PQR(" << p << ", " << q << ", " << r << "))" << endl;
			return 0;
		}


		//-----------------------------correct error at i

		int wrongValue = ConvertToInt(input[i - 1]);

		int correctedValue = ModularArithmatic::mod(wrongValue - a, 17);

		output[i - 1] = correctedValue;

		//-----------------------------correct error at j

		int wrongValue1 = ConvertToInt(input[j - 1]);

		int correctedValue1 = ModularArithmatic::mod(wrongValue1 - b, 17);

		output[j - 1] = correctedValue1;

		//Check that any of the corrected values is not 10

		if (correctedValue == 10)
		{
			if (correctedValue1 == 10)
			{
				PrintUnknown();
				cout << " More than 2 Errors, an output value is 10 at" << " (i = " << i << ", a = " << a << ", j = " << j << ", b = " << b << ", syn(" << s1 << ", " << s2 << ", " << s3 << ", " << s4 << "), PQR(" << p << ", " << q << ", " << r << "))" << endl;
				return 0;
			}
		}

		PrintOutput(output);

		cout << " Double Error" << " (i = " << i << ", a = " << a << ", j = " << j << ", b = " << b << ", syn(" << s1 << ", " << s2 << ", " << s3 << ", " << s4 << "), PQR(" << p << ", " << q << ", " << r << "))" << endl;

	}

}


int main()
{

	string input;
	//cout << "Enter 16 digits or 'test' to run all tests : ";
	//getline(cin, input);

	//if (input == "test")
	//{
		BCHDecode("1,2,3,4,5,6,7,8,9,10,11,2,2,5,4,6"); //no error.

		BCHDecode("2,5,1,9,10,15,2,6,7,4,2,2,2,3,4,0"); //single error at the position 9, and the correct code should be (2, 5, 1, 9, 10, 15, 2, 6, 1, 4, 2, 2, 2, 3, 4, 0)
		BCHDecode("4,2,1,2,7,5,6,5,8,9,11,0,6,3,3,12"); //single error at positions 10, and the correct code should be (4, 2, 1, 2, 7, 5, 6, 5, 8, 10, 11, 0, 6, 3, 3, 12)

		BCHDecode("1,0,0,0,0,0,0,0,0,0,0,0,1,1,3,7"); //two errors at positions 13, and 14, and the correct code should be (1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 3, 7)

		BCHDecode("11,11,11,11,12,12,12,12,13,13,13,13,14,14,14,14"); //more than 2 errors.


	/*}
	else if (input.size() == 10)
	{
		BCHDecode(input);
	}
	else
	{
		cout << "Invalid input\n";
	}*/

	/*main();*/
}