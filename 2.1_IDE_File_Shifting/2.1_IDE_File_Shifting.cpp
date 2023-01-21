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
		//������ ������� N �� ����� in.txt
		infile >> countN;
		arrN = new int[countN];
		for (int i = 0; i < countN; ++i)
		{
			infile >> arrN[i];
		}
		//������ ������� M �� ����� in.txt
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
			//������ � ���� out.txt ������� M �� ������� ������ �� 1 �������
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
			//������ � ���� out.txt ������� N �� ������� ����� �� 1 �������
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
			std::cout << "������ �������� ����� out.txt!" << std::endl;
		}
		delete[] arrN;
		delete[] arrM;
		arrN = nullptr;
		arrM = nullptr;
	} 
	else 
	{
		std::cout << "������ �������� ����� in.txt!" << std::endl;
	}
	return(0);
}
