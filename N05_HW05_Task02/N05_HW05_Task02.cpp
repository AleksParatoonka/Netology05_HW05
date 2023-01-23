// N05_HW05_Task02.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    Shape(int a) {
        edges = a;
    }
    int get_edges() { return edges; }
};
class Poly :public Shape {
public:
    //Poly() :Shape(4) {}
    Poly(double edge_a, double edge_b, double edge_c, double edge_d, double angle_a, double angle_b, double angle_c, double angle_d) :Shape(4) {
        this->edge_a = edge_a;
        this->edge_b = edge_b;
        this->edge_c = edge_c;
        this->edge_d = edge_d;
        this->angle_a = angle_a;
        this->angle_b = angle_b;
        this->angle_c = angle_c;
        this->angle_d = angle_d;
    }
    double get_edge(char x) {
        switch (x) {
        case 'a':
            return edge_a;
        case 'b':
            return edge_b;
        case 'c':
            return edge_c;
        case 'd':
            return edge_d;
        }
    }
    double get_angle(char x) {
        switch (x) {
        case 'a':
            return angle_a;
        case 'b':
            return angle_b;
        case 'c':
            return angle_c;
        case 'd':
            return angle_d;
        }
    }
    void print_info() {
        std::cout << "Стороны: a=" << get_edge('a') << " b=" << get_edge('b') << " c=" << get_edge('c') << " d=" << get_edge('d') << std::endl;
        std::cout << "Углы: A=" << get_angle('a') << " B=" << get_angle('b') << " C=" << get_angle('c') << " D=" << get_angle('d') << std::endl;
        std::cout << std::endl;
    }
protected:
    double edge_a;
    double edge_b;
    double edge_c;
    double edge_d;

    double angle_a;
    double angle_b;
    double angle_c;
    double angle_d;

};
class Triangle :public Shape {

protected:
    double edge_a;
    double edge_b;
    double edge_c;

    double angle_a;
    double angle_b;
    double angle_c;

public:
    Triangle() :Shape(3) {
    }
    Triangle(double edge_a, double edge_b, double edge_c, double angle_a, double angle_b, double angle_c) :Shape(3) {
        this->edge_a = edge_a;
        this->edge_b = edge_b;
        this->edge_c = edge_c;
        this->angle_a = angle_a;
        this->angle_b = angle_b;
        this->angle_c = angle_c;
    }

    double get_edge(char x) {
        switch (x) {
            case 'a':
                return edge_a;
            case 'b':
                return edge_b;
            case 'c':
                return edge_c;
        }
    }
    double get_angle(char x) {
        switch (x) {
        case 'a':
            return angle_a;
        case 'b':
            return angle_b;
        case 'c':
            return angle_c;
        }
    }
    void print_info() {
        std::cout << "Стороны: a=" << get_edge('a') << " b=" << get_edge('b') << " c=" << get_edge('c') << std::endl;
        std::cout << "Углы: A=" << get_angle('a') << " B=" << get_angle('b') << " C=" << get_angle('c') << std::endl;
        std::cout << std::endl;
    }
};
class Square_Triangle :public Triangle {
public:
    Square_Triangle(double edge_a, double edge_b, double edge_c, double angle_a, double angle_b) :Triangle(edge_a, edge_b, edge_c, angle_a, angle_b, 90) {}
};
class Isosceles_Triangle :public Triangle {
public:
    Isosceles_Triangle(double edge_a, double edge_b, double angle_a, double angle_b) :Triangle(edge_a, edge_b, edge_a, angle_a, angle_b, angle_a) {}
};
class Equilateral_Triangle :public Triangle {
public:
    Equilateral_Triangle(double edge_a) :Triangle(edge_a, edge_a, edge_a, 60, 60, 60) {}
};

class Parallelogram :public Poly {
public:
    Parallelogram(double edge_a, double edge_b, double angle_a, double angle_b) :Poly(edge_a, edge_b, edge_a, edge_b, angle_a, angle_b, angle_a, angle_b) {}
};
class Rect :public Parallelogram {
public:
    Rect(double edge_a, double edge_b) :Parallelogram(edge_a, edge_b, 90, 90) {}
};
class Square :public Rect {
public:
    Square(double edge_a) :Rect(edge_a, edge_a) {}
};
class Rhombus :public Parallelogram {
public:
    Rhombus(double edge_a, double angle_a, double angle_b) :Parallelogram(edge_a, edge_a, angle_a, angle_b) {}
};


int main()
{
    setlocale(LC_ALL, "Russian");

    //Shape shape;
    Poly poly( 10, 20, 30, 40, 50, 60, 70, 80);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rect rectangle(10, 20);
    Square square(20);
    Rhombus rhombus(30, 30, 40);

    Triangle triangle(10, 20, 30, 50, 60, 70);
    Square_Triangle square_triangle(10, 20, 30, 50, 60);
    Isosceles_Triangle isosceles_triangle(10, 20, 60, 50);
    Equilateral_Triangle equilateral_triangle(30);

    std::cout << "Треугольник: " << std::endl;
    Triangle* par_triangle = &triangle;
    par_triangle->print_info();
    /*std::cout << "Стороны: a=: " << triangle.get_edge('a') << " b=" << triangle.get_edge('b') << " c=" << triangle.get_edge('c') << std::endl;
    std::cout << "Углы: A=" << triangle.get_angle('a') << " B=" << triangle.get_angle('b') << " C=" << triangle.get_angle('c') << std::endl;
    std::cout << std::endl;*/

    std::cout << "Прямоугольный треугольник: " << std::endl;
    Triangle* par_square_triangle = &square_triangle;
    par_square_triangle->print_info();
    /*std::cout << "Стороны: a=" << square_triangle.get_edge('a') << " b=" << square_triangle.get_edge('b') << " c=" << square_triangle.get_edge('c') << std::endl;
    std::cout << "Углы: A=" << square_triangle.get_angle('a') << " B=" << square_triangle.get_angle('b') << " C=" << square_triangle.get_angle('c') << std::endl;
    std::cout << std::endl;*/

    std::cout << "Равнобедренный треугольник: " << std::endl;
    Triangle* par_isosceles_triangle = &isosceles_triangle;
    par_isosceles_triangle->print_info();
    /*std::cout << "Стороны: a=" << square_triangle.get_edge('a') << " b=" << square_triangle.get_edge('b') << " c=" << square_triangle.get_edge('c') << std::endl;
    std::cout << "Углы: A=" << square_triangle.get_angle('a') << " B=" << square_triangle.get_angle('b') << " C=" << square_triangle.get_angle('c') << std::endl;
    std::cout << std::endl;*/

    std::cout << "Равносторонний треугольник: " << std::endl;
    Triangle* par_equilateral_triangle = &equilateral_triangle;
    par_equilateral_triangle->print_info();
    /*std::cout << "Стороны: a=" << square_triangle.get_edge('a') << " b=" << square_triangle.get_edge('b') << " c=" << square_triangle.get_edge('c') << std::endl;
    std::cout << "Углы: A=" << square_triangle.get_angle('a') << " B=" << square_triangle.get_angle('b') << " C=" << square_triangle.get_angle('c') << std::endl;
    std::cout << std::endl;*/

    std::cout << "Четырёхугольник: " << std::endl;
    Poly* par_poly = &poly;
    par_poly->print_info();
    /*std::cout << "Стороны: a=" << poly.get_edge('a') << " b=" << poly.get_edge('b') << " c=" << poly.get_edge('c') << " d=" << poly.get_edge('d') << std::endl;
    std::cout << "Углы: A=" << poly.get_angle('a') << " B=" << poly.get_angle('b') << " C=" << poly.get_angle('c') << " D=" << poly.get_angle('d') << std::endl;
    std::cout << std::endl;*/

    std::cout << "Прямоугольник: "<< std::endl;
    Poly* par_rectangle = &rectangle;
    par_rectangle->print_info();
    /*std::cout << "Стороны: a=" << rectangle.get_edge('a') << " b=" << rectangle.get_edge('b') << " c=" << rectangle.get_edge('c') << " d=" << rectangle.get_edge('d') << std::endl;
    std::cout << "Углы: A=" << rectangle.get_angle('a') << " B=" << rectangle.get_angle('b') << " C=" << rectangle.get_angle('c') << " D=" << rectangle.get_angle('d') << std::endl;
    std::cout << std::endl;*/

    std::cout << "Квадрат: "<< std::endl;
    Poly* par_square = &square;
    par_square->print_info();
    /*std::cout << "Стороны: a=" << square.get_edge('a') << " b=" << square.get_edge('b') << " c=" << square.get_edge('c') << " d=" << square.get_edge('d') << std::endl;
    std::cout << "Углы: A=" << square.get_angle('a') << " B=" << square.get_angle('b') << " C=" << square.get_angle('c') << " D=" << square.get_angle('d') << std::endl;
    std::cout << std::endl;*/

    std::cout << "Параллелограмм: " << std::endl;
    Poly* par_parallelogram = &parallelogram;
    par_parallelogram->print_info();
    /*std::cout << "Стороны: a=" << parallelogram.get_edge('a') << " b=" << parallelogram.get_edge('b') << " c=" << parallelogram.get_edge('c') << " d=" << parallelogram.get_edge('d') << std::endl;
    std::cout << "Углы: A=" << parallelogram.get_angle('a') << " B=" << parallelogram.get_angle('b') << " C=" << parallelogram.get_angle('c') << " D=" << parallelogram.get_angle('d') << std::endl;
    std::cout << std::endl;*/

    std::cout << "Ромб: " << std::endl;
    Poly* par_rhombus = &rhombus;
    par_rhombus->print_info();
    /*std::cout << "Стороны: a=" << rhombus.get_edge('a') << " b=" << rhombus.get_edge('b') << " c=" << rhombus.get_edge('c') << " d=" << rhombus.get_edge('d') << std::endl;
    std::cout << "Углы: A=" << rhombus.get_angle('a') << " B=" << rhombus.get_angle('b') << " C=" << rhombus.get_angle('c') << " D=" << rhombus.get_angle('d') << std::endl;
    std::cout << std::endl;*/
}