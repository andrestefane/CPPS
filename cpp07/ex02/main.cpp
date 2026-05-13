#include "Array.hpp"

template <typename T>
void printArray(Array<T> const &array, std::string const &label)
{
	std::cout << label << " (size=" << array.size() << "): [";
	unsigned int i = 0;
	while (i < array.size())
	{
		std::cout << array[i] << (i + 1 < array.size() ? ", " : " ");
		i++;
	}
	std::cout << "]" << std::endl;
}

int main(void)
{
	std::cout << "Empty constructor" << std::endl;
	Array<int> empty;
	std::cout << "empty.size() = " << empty.size() << std::endl;

	std::cout << "Constructor with int = 5 " << std::endl;
	Array<int> intArray(5);
	unsigned int i = 0;
	while (i < intArray.size())
	{
		intArray[i] = (int)(i * 10);
		i++;
	}
	printArray(intArray, "IntArray");

	std::cout << "Copy constructor" << std::endl;
	Array<int> copyArray(intArray);
	printArray(copyArray, "copyArray");

	intArray[0] = 999;
	std::cout << "After intArray[0] = 999:" << std::endl;
	printArray(intArray, "intArray");
	printArray(copyArray, "copyArray");

	std::cout << "Assignment operator" << std::endl;
	Array<int> assignmentArray(3);
	assignmentArray = intArray;
	printArray(assignmentArray, "AssignmentArray");

	assignmentArray[1] = 777;
	std::cout << "After assignment[1] = 777:" << std::endl;
	printArray(intArray, "intArray");
	printArray(assignmentArray, "assignmentArray");
	   std::cout << "\n=== Array<std::string> ===" << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "hello";
    strArr[1] = "world";
    strArr[2] = "42";
    printArray(strArr, "strArr");

    std::cout << "\n=== Array<double> ===" << std::endl;
    Array<double> doubleArray(4);
    doubleArray[0] = 1.1; doubleArray[1] = 2.2;
    doubleArray[2] = 3.3; doubleArray[3] = 4.4;
    printArray(doubleArray, "doubleArray");

    std::cout << "\n=== Out of bounds exception ===" << std::endl;
    try
    {
        std::cout << intArray[100] << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << empty[0] << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << "Caught on empty[0]: " << e.what() << std::endl;
    }

    std::cout << "\n=== Const array access ===" << std::endl;
    Array<int> const constArray(intArray);
    printArray(constArray, "constArray");
    try
    {
        std::cout << constArray[99] << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << "Caught on constArray[99]: " << e.what() << std::endl;
    }

    return 0;
}