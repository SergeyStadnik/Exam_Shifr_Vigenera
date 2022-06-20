#include<iostream>
#include<string>
#include <Windows.h> 
#include<stdio.h>
#include <fstream>
using namespace std;
//string lib;
//
//string MakeLib()
//{
//	for (int i = 0; i < 256; i++) //Добавляем спецсимволы
//	{
//		lib += (char)i;// библиотека
//	}
//
//	return lib;
//}
//
//void PrintLib(string str)//функция вывода библиотеки
//{
//
//	for (size_t i = 0; i < str.length(); i++)
//	{
//		cout << i << " : " << str[i] << "\t";
//	}
//	cout << "-----------------------------" << endl;
//}
void ShifrKey(string str, string shifr, string &newshifr)// функция удлинения ключа
{    int j = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		newshifr += shifr[j];
		j++;
		if (j == shifr.length())
			j = 0;
			}
	}
void shifrCript(string str, string key, string &newstr)//функция шифровки
{
	for (size_t i = 0; i < str.length(); i++)
	{
		newstr += char((int(str[i]) + int(key[i])) % 256);
	}

	
}
void shifrDecript(string str, string key, string& newstr)//функция дешифровки
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
	//PrintLib(MakeLib());
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
	int x;
	//string str4; 
	ofstream out_text;
	out_text.open(str1);
	if (out_text.fail())
	{
		cout << "Error";
		return 404;
	}
	//getline(cin, str4);//если что можно записать руками
	out_text << "Шифр Виженера — это последовательность шифров Цезаря с различными значениями сдвига";// записываю в текстовый документ
	
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
	cout << "Шифрование по методу Виженера" << endl;
	cout << "Перед вами текст который мы будем шифровать" << endl;
	cout << str2 << endl;;
	cout << "Введите шифр, он может состоять из букв, цифр,\nили спецсимволов, не должен содержать пробелы" << endl;
	cin >> shifr;
	if (shifr.length() > str2.length())
	{
		cout << "ERROR" << endl;
		cout << "Шифр слишком длинный, пожалуйста введите заново" << endl;
		cin >> shifr;
	}
	cout << "Начинаем шифровать, нажмите любую цифру" << endl;
	cin >> x;
	ShifrKey(str2, shifr, *pAddShifr);
    shifrCript(str2, addShifr, *pencryptText);
	cout << "Так выглядит зашифрованное сообщение" << endl;
    cout << encryptText<<endl;
	cout << "Теперь расшифруем его и запишем в текстовый документ" << endl;
	cout << "Начинаем дешифровку, нажмите любую цифру" << endl;
	cin >> x;
	shifrDecript(encryptText, addShifr, *pdencryptText);
	cout << "Cобщение расшифрованно" << endl;
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