#include"Point.h"
#include"Line.h"
#include"Triangle.h"
#include"Polygon.h"
using namespace std;

int main(int argc, const char * argv[])
{
	int x;
	int size = 2;
	int number = 0;
	float* numbers = new float[size];
	Shape* shapes;

	ifstream inFile;
	inFile.open(argv[1]);

	if (!inFile)
	{
		cout << "Could not open file!" << endl;
	}
	else
	{
		cout << "Input: ";
		while (inFile >> x)
		{
			if (number<size)
			{
			
				numbers[number] = x;
				number++;
			}
			else
			{
				float* temp = new float[size];
				for (int i = 0; i < size; i++)
				{
					temp[i] = numbers[i];
				}
				delete[] numbers;
				size++;
				numbers = new float[size];
				for (int i = 0; i < size - 1; i++)
				{
					numbers[i] = temp[i];
				}
				delete[] temp;

				
				numbers[number] = x;
				number++;
			}
			cout << to_string(x) << " ";
		}


		if (number == 2)
		{
			
			shapes = new Point(numbers[0], numbers[1]);
		}
		else if (number == 4)
		{
			
			shapes = new Line(numbers[0], numbers[1], numbers[2], numbers[3]);
		}
		else if (number == 6)
		{
			shapes = new Triangle(numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5]);
		}
		else
		{
			shapes = new Polygon(numbers, number);
		}
	
		cout << "        output:" << shapes->area() << endl;
		
		delete shapes;


	}
	delete[] numbers;
	
	system("pause");
	return 0;
}