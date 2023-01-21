#include<iostream>
#include<fstream>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "RU");

	int countN, countM;
	int *arrN, *arrM;

	std::ifstream infile;
	infile.open("in.txt");
	if (infile.is_open()) 
	{
		//чтение массива N из файла in.txt
		infile >> countN;
		arrN = new int[countN];
		for (int i = 0; i < countN; ++i)
		{
			infile >> arrN[i];
		}
		//чтение массива M из файла in.txt
		infile >> countM;
		arrM = new int[countM];
		for (int i = 0; i < countM; ++i)
		{
			infile >> arrM[i];
		}
		infile.close();
				
		std::ofstream outfile;
		outfile.open("out.txt");
		if (outfile.is_open())
		{
			//запись в файл out.txt массива M со сдвигом вправо на 1 элемент
			outfile << countM << "\n" << arrM[countM - 1] << " ";
			for (int i = 0; i < countM - 1; ++i)
			{
				if (i == countM - 2)
				{
					outfile << arrM[i];
				}
				else
				{
					outfile << arrM[i] << " ";
				}
			}			
			//запись в файл out.txt массива N со сдвигом влево на 1 элемент
			outfile << "\n" << countN << "\n";
			for (int i = 1; i < countN; ++i)
			{
				outfile << arrN[i] << " ";
			}
			outfile << arrN[0];
			outfile.flush();
			outfile.close();
		}
		else
		{
			std::cout << "Ошибка открытия файла out.txt!" << std::endl;
		}
		delete[] arrN;
		delete[] arrM;
		arrN = nullptr;
		arrM = nullptr;
	} 
	else 
	{
		std::cout << "Ошибка открытия файла in.txt!" << std::endl;
	}
	return(0);
}
