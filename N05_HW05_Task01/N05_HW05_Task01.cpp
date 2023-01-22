// N05_HW05_Task01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

class Shape {
    protected:
        int edges;
    public:
        Shape() {
            edges = 0;
        }
        Shape(int a ) {
            edges = a;
        }
        int get_edges() { return edges; }
};
class Poly :public Shape {
public:
    Poly() :Shape(4) {}
        
};
class Triangle :public Shape {
public:
    Triangle() :Shape(3) {}
};
int main()
{
    //SetConsoleCP(CP_UTF8);
    //SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");

    Shape shape;
    Poly poly;
    Triangle triangle;

    std::cout << "Количество сторон: " << std::endl;
    std::cout << "Фигура: " << shape.get_edges() << std::endl;
    std::cout << "Треугольник: " << poly.get_edges() << std::endl;
    std::cout << "Четырёхугольник: "<<  triangle.get_edges() << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
