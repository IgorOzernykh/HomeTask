#include <iostream>
#include <fstream>

int findAuthor(int *array, int copiedfrom)
{
	if (copiedfrom >= 1 && copiedfrom <= 3)
		return copiedfrom;
	else findAuthor(array, array[copiedfrom]);
}

int main()
{
	char filename[1000];
	std::cout << "Enter file name: ";
	std::cin >> filename;
	std::ifstream file(filename);
	int number;
	file >> number;
	int *array = new int[number + 1];
	for (int i = 1; i <= number; i++)
	{
		int studentNum;
		file >> studentNum;
		int copiedfrom;
		file >> copiedfrom;
		array[studentNum] = copiedfrom;
	}
	for (int i = 1; i <= 3; i++)
		std::cout << "Student " << i << " did it himself\n";
	for (int i = 4; i <= number; i++)
	{
		if (array[i] != 0)
		{
			std::cout << "Student " << i << " copied from ";
			int copiedfrom = findAuthor(array, i);
			std::cout << copiedfrom;
		}
			if (array[i] == 0)
			std::cout << "Student " << i << " - to exclude";
		std::cout << "\n";
	}
	file.close();
	delete []array;
}
