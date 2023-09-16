#include <iostream>
#include <iomanip>

#include "MyVectors/Vector3D.h"

using namespace vectors;

// Prints (X, Y, Z), Direction, and Magnitude
void PrintVectorValues(Vector3D vector)
{
    Vector3D normalizedVector = vector.Normalize();

    std::cout << "-- Vector3D --" << std::endl;
    std::cout << "Components: (" << vector.GetX() << ", " << vector.GetY() << ", " << vector.GetZ() << ")" << std::endl;
    std::cout << "Direction: (" << normalizedVector.GetX() << ", " << normalizedVector.GetY() << 
        ", " << normalizedVector.GetZ() << ")" << std::endl;
    std::cout << "Magnitude:" << vector.GetMagnitude() << std::endl;
    std::cout << std::endl;
}


void PrintVectorOperations(Vector3D vectorA, Vector3D vectorB, float scalarValue)
{
    std::cout << "# Operations" << std:: endl << std::endl;

    Vector3D operationResults = vectorA - vectorB;
    std::cout << "A + B = (" << operationResults.GetX() << ", " << operationResults.GetY() << ", " <<
        operationResults.GetZ() << ")" << std::endl;
    
    operationResults = vectorA - vectorB;
    std::cout << "A - B = (" << operationResults.GetX() << ", " << operationResults.GetY() << ", " <<
        operationResults.GetZ() << ")" << std::endl;

    operationResults = vectorA * scalarValue;
    std::cout << "A * S = (" << operationResults.GetX() << ", " << operationResults.GetY() << ", " <<
        operationResults.GetZ() << ")" << std::endl;
    
    float dotProduct = vectorA.DotProduct(vectorB);
    std::cout << "A dot B = " << dotProduct << std::endl;

    operationResults = vectorA.CrossProduct(vectorB);
    std::cout << "A X B = (" << operationResults.GetX() << ", " << operationResults.GetY() << ", " <<
        operationResults.GetZ() << ")" << std::endl;
}


void PerformVectorOperationsWithUserInput()
{
    // [scalar], [vectorA.x], [vectorA.y], [vectorA.z], [vectorB.x], [vectorB.y], [VectorB.z]
    float numberInputs[7];

    std::cout << "Input: Scalar, Ax, Ay, Az, Bx, By, Bz" << std::endl;

    for (int i = 0; i < 7; i++)
    {
        std::cin >> numberInputs[i];
    }

    std::cout << std::endl << "# Scalar Input: " << numberInputs[0] << std::endl << std::endl;

    Vector3D vectorA(numberInputs[1], numberInputs[2], numberInputs[3]);
    std::cout << "# InputA" << std::endl;
    PrintVectorValues(vectorA);

    Vector3D vectorB = Vector3D(numberInputs[4], numberInputs[5], numberInputs[6]);
    std::cout << "# InputB" << std::endl;
    PrintVectorValues(vectorB);

    PrintVectorOperations(vectorA, vectorB, numberInputs[0]);

    std::cout << std::endl;
}

int main()
{
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(3);

    char continueInput;

    do
    {
        PerformVectorOperationsWithUserInput();
        std::cout << "Do you want to perform another operation? (Y?): ";
        std::cin >> continueInput;
    } while (continueInput == 'Y' || continueInput == 'y');
    
    return 0;
}


