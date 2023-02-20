#include <iostream>
#include<fstream>
using namespace std;
#define WRITE_TO_FILE
//# define READ_TO_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	char filename[_MAX_FNAME] = {};
	cout << "Введите имя файла: ";
	cin.getline(filename, _MAX_FNAME);
	if (strcmp(filename + strlen(filename) - 4, ".txt"))strcat_s(filename,_MAX_FNAME,
		".txt");

	ofstream fout;                 //1) Создаем поток
	fout.open(filename, std::ios_base::app); //2)Открываем поток
	fout << "Hello Files" << endl;            //3)Пишем в поток
	fout.close();      //4) Закрываем поток

	char sz_command[_MAX_FNAME] = "notepad ";
	strcat_s(sz_command, _MAX_FNAME, filename);
	system(sz_command);
#endif // WRITE_TO_FILE
#ifdef READ_TO_FILE
	ifstream fin;
	fin.open("File.txt");
	if (fin.is_open())
	{
		const int SIZE = 1256;
		char sz_buffer[SIZE]{};
		while (!fin.eof())
		{
			fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error:file not found" << endl;
		// cout-console out
		//cerr- console error
	}
#endif // READ_TO_FILE

}