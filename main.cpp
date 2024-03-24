#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void normalizeLength(string &I1, string&I2)
{
	int length_1 = I1.length();
	int length_2 = I2.length();
	if(length_1 <length_2)
	{
		I1.insert(0, length_2-length_1, '0');
	}
	else if(length_2 < length_1)
	{
		I2.insert(0, length_1-length_2, '0');
	}
}

int charToInt(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'F')
        return 10 + c - 'A';
    else if (c >= 'a' && c <= 'f')
        return 10 + c - 'a';
    else
        return -1; // Error
}

char intToChar(int num) {
    if (num >= 0 && num <= 9)
        return '0' + num;
    else if (num >= 10 && num <= 15)
        return 'A' + num - 10;
    else
        return ' '; // Error
}

string add(string I1, string I2, int B) {
    normalizeLength(I1, I2);
    int length = I1.length();
    int carry = 0;
    string result;
    int this_result;
    for(int i = length - 1; i >= 0; i--) {
        int num1 = charToInt(I1[i]);
        int num2 = charToInt(I2[i]);
        if (num1 == -1 || num2 == -1) {
            return "Error: Invalid input";
        }
        this_result = num1 + num2 + carry;
        result = intToChar(this_result % B) + result;
        carry = this_result / B;
    }
    
    if(carry != 0) {
        result = intToChar(carry) + result;
    }
    
    return result;
}

string sub(string I1, string I2, int B)
{
	normalizeLength(I1, I2);
	int length = I1.length();
	int carry = 0;
	string result;
	int this_result;
	for(int i= length-1; i>=0; i--)
	{
		this_result = (I1[i]-'0')-(I2[i]-'0')-carry;
		if(this_result<0)
		{
			this_result = this_result + B;
			carry = 1;
		}
		else
		{
			carry=0;
		}
		result = to_string(this_result) + result;
	}
	while(result.size()>1 && result[0]=='0')
	{
		result.erase(0,1);
	}
	return result;
}

string convertBase(int num, int B)
{
	if(num==0)
	{
		return "0";
	}
	string result = "";
	while(num>0)
	{
		int reminder = num % B;
		result = char(reminder+'0') + result;
		num /= B;
	}
	return result;
}

string multiply(string num1, string num2, int B)
{
    normalizeLength(num1,num2);
    string result;
    int length = num1.length();
    if(num1.length() == num2.length() && num2.length() == 1)
    {
        // 注意这里的修正
        result = convertBase((num1[0]-'0')*(num2[0]-'0'),B);
        return result;
    }
    int middle = length/2;
    int k = length - middle;
    string a1 = num1.substr(0,middle);
    string a0 = num1.substr(middle, k);
    
    string b1 = num2.substr(0,middle);
    string b0 = num2.substr(middle, k);

    string part1 = multiply(a1,b1,B);
    string part2 = multiply(a0,b0,B);
    string part3 = sub(multiply(add(a1,a0,B),add(b1,b0,B),B),add(part1,part2,B),B);
    
    // 创建有 2*k 个 '0' 的字符串，用于 part1
    string zeros_2k(2*k, '0');
    part1 += zeros_2k; 
    
    // 创建有 k 个 '0' 的字符串，用于 part3
    string zeros_k(k, '0');
    part3 += zeros_k;
    
    string temp_res = add(part1, part3, B);
    result = add(temp_res, part2, B);
    
    while(result.size() > 1 && result[0] == '0')
    {
        result.erase(0, 1);
    }
    return result;
}

int main()
{
	string I1, I2;
	int B;
	std::cin >>I1 >>I2 >> B;
	string sum = add(I1,I2,B);
	string mul = multiply(I1,I2,B);
	string subnum = sub(I1, I2, B);
	cout << sum <<" "<<mul<<" "<<subnum<<endl;
	return 0;
}