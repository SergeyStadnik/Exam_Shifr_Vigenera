#include<iostream>
#include<string>
#include <Windows.h> 
#include<stdio.h>
#include <fstream>
using namespace std;
string lib;

string MakeLib()
{
	for (int i = 0; i < 256; i++) //Добавляем спецсимволы
	{
		lib += (char)i;
	}

	return lib;
}

void PrintLib(string str)
{

	for (size_t i = 0; i < str.length(); i++)
	{
		cout << i << " : " << str[i] << "\t";
	}
	cout << "-----------------------------" << endl;
}
void ShifrKey(string str, string shifr, string &newshifr)
{int j = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		
		newshifr += shifr[j];
		j++;
		if (j == shifr.length())
			j = 0;
			
		
	}
	


 }
void shifrCript(string str, string key, string &newstr)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		newstr += char((int(str[i]) + int(key[i])) % 256);
	}

	
}
void shifrDecript(string str, string key, string& newstr)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		newstr += char((int(str[i]) - int(key[i])) % 256);
	}


}
int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string encryptText;
	string* pencryptText = &encryptText;
	string dencryptText;
	string* pdencryptText = &dencryptText;
	string shifr;
	string addShifr;
	string* pAddShifr = &addShifr;
	string str1 = "orig_text.txt";// наш начальный текст
	string str2 = "";
	string str3 = "cipher.txt";// зашифрованный текст
	//string str4; 
	ofstream out_text;
	out_text.open(str1);
	if (out_text.fail())
	{
		cout << "Error";
		return 404;
	}
	//getline(cin, str4);
	out_text << "Было очень весело делать эти задания";// записываю в текстовый документ
	
	out_text.close();

	ifstream in_text(str1);


	if (in_text.fail())
	{
		cout << "error" << endl;
		return 404;
	}
	while (getline(in_text, str1))
	{
		str2 += str1;//извлекаю из текста и записываю в строку, чтобы передать в функцию
	}
	in_text.close();
	cin >> shifr;
	ShifrKey(str2, shifr, *pAddShifr);
	shifrCript(str2, addShifr, *pencryptText);
	shifrDecript(encryptText, addShifr, *pdencryptText);
	cout << addShifr<<endl;
	cout << encryptText<<endl;
	cout << dencryptText << endl;
	ofstream out_text1;
	out_text1.open(str3);
	if (out_text1.fail())
	{
		cout << "Error";
		return 404;
	}
	out_text1 << encryptText;
	out_text1.close();
	system("pause");
	return 0;
}