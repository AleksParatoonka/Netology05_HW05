// N05_HW05_Task03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <windows.h>

class Shape {
protected:
    int edges;
    std::string name;
public:
    Shape() {
        name = "Фигура";
        edges = 0;
    }
    Shape(int a) {
        edges = a;
        //name = "Неизвестно";
    }
    int get_edges() { return edges; }

    virtual bool is_shape_ideal(){
        if (edges == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    virtual void print_about() {
        std::cout << name << std::endl;
        if ( is_shape_ideal() == 1 ) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "У фигуры " << edges << " сторон" << std::endl;
    }
};

void print_info(Shape* ptr)
{
    ptr->print_about();
}

class Poly :public Shape {
protected:
    double edge_a;
    double edge_b;
    double edge_c;
    double edge_d;

    double angle_a;
    double angle_b;
    double angle_c;
    double angle_d;
public:
    Poly(double edge_a, double edge_b, double edge_c, double edge_d, double angle_a, double angle_b, double angle_c, double angle_d, std::string name) :Shape(4) {
        this->edge_a = edge_a;
        this->edge_b = edge_b;
        this->edge_c = edge_c;
        this->edge_d = edge_d;
        this->angle_a = angle_a;
        this->angle_b = angle_b;
        this->angle_c = angle_c;
        this->angle_d = angle_d;
        this->name = name;
    }
    Poly(double edge_a, double edge_b, double edge_c, double edge_d, double angle_a, double angle_b, double angle_c, double angle_d) :Shape(4) {
        this->edge_a = edge_a;
        this->edge_b = edge_b;
        this->edge_c = edge_c;
        this->edge_d = edge_d;
        this->angle_a = angle_a;
        this->angle_b = angle_b;
        this->angle_c = angle_c;
        this->angle_d = angle_d;
        name = "Четырёхугольник";
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
    bool is_shape_ideal() override {
        if (edges == 4 && (angle_a + angle_b + angle_c + angle_d) == 360) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void print_about() override {
        Shape::print_about();
        std::cout << "Стороны: a= " << edge_a << " b=" << edge_b << " c=" << edge_c << " d=" << edge_d << std::endl;
        std::cout << "Углы: A=" << angle_a << " B=" << angle_b << " C=" << angle_c << " D=" << angle_d << std::endl;
    }

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
    Triangle() :Shape(3) {}
    Triangle(double edge_a, double edge_b, double edge_c, double angle_a, double angle_b, double angle_c, std::string name) :Shape(3) {
        this->edge_a = edge_a;
        this->edge_b = edge_b;
        this->edge_c = edge_c;
        this->angle_a = angle_a;
        this->angle_b = angle_b;
        this->angle_c = angle_c;
        this->name = name;
    }
    Triangle(double edge_a, double edge_b, double edge_c, double angle_a, double angle_b, double angle_c) :Shape(3) {
        this->edge_a = edge_a;
        this->edge_b = edge_b;
        this->edge_c = edge_c;
        this->angle_a = angle_a;
        this->angle_b = angle_b;
        this->angle_c = angle_c;
        name = "Треугольник";
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
    bool is_shape_ideal() override {
        if (edges == 3 && (angle_a + angle_b + angle_c) == 180) {
            return true;
        }
        else {
            return false;
        }
    }
    void print_about() override {
        Shape::print_about();
        std::cout << "Стороны: a= " << edge_a << " b=" << edge_b << " c=" << edge_c << std::endl;
        std::cout << "Углы: A=" << angle_a << " B=" << angle_b << " C=" << angle_c << std::endl;
    }

};
class Square_Triangle :public Triangle {
public:
    Square_Triangle(double edge_a, double edge_b, double edge_c, double angle_a, double angle_b) :Triangle(edge_a, edge_b, edge_c, angle_a, angle_b, 90, "Прямоугольный треугольник") {}
	bool is_shape_ideal() override {
	
		bool result = Triangle::is_shape_ideal(); // Проверим треугольник
		return result;		
	}
};
class Isosceles_Triangle :public Triangle {
public:
    Isosceles_Triangle(double edge_a, double edge_b, double angle_a, double angle_b) :Triangle(edge_a, edge_b, edge_a, angle_a, angle_b, angle_a, "Равнобедренный треугольник") {}
	bool is_shape_ideal() override {
	
		bool result = Triangle::is_shape_ideal(); // Проверим треугольник
		return result;		
	}
};
class Equilateral_Triangle :public Triangle {
public:
    Equilateral_Triangle(double edge_a) :Triangle(edge_a, edge_a, edge_a, 60, 60, 60, "Равносторонний треугольник") {}
	bool is_shape_ideal() override {
	
		bool result = Triangle::is_shape_ideal(); // Проверим треугольник
		return result;		
	}
};

class Parallelogram :public Poly {
public:
    Parallelogram(double edge_a, double edge_b, double angle_a, double angle_b) :Poly(edge_a, edge_b, edge_a, edge_b, angle_a, angle_b, angle_a, angle_b, "Параллелограмм") {}
    Parallelogram(double edge_a, double edge_b, double angle_a, double angle_b, std::string name) :Poly(edge_a, edge_b, edge_a, edge_b, angle_a, angle_b, angle_a, angle_b, name) {}
	bool is_shape_ideal() override {
		bool result = Poly::is_shape_ideal(); // Проверим четырехугольник
		return result;		
	}
};
class Rect :public Parallelogram {
public:
    Rect(double edge_a, double edge_b) :Parallelogram(edge_a, edge_b, 90, 90, "Прямоугольник") {}
    Rect(double edge_a, double edge_b, std::string name) :Parallelogram(edge_a, edge_b, 90, 90, name) {}
	bool is_shape_ideal() override {
		bool result = Poly::is_shape_ideal(); // Проверим четырехугольник
		return result;		
	}
};
class Square :public Rect {
public:
    Square(double edge_a) :Rect(edge_a, edge_a, "Квадрат") {}
	bool is_shape_ideal() override {
		bool result = Poly::is_shape_ideal(); // Проверим четырехугольник
		return result;		
	}
};
class Rhombus :public Parallelogram {
public:
    Rhombus(double edge_a, double angle_a, double angle_b) :Parallelogram(edge_a, edge_a, angle_a, angle_b, "Ромб") {}
	bool is_shape_ideal() override {
		bool result = Poly::is_shape_ideal(); // Проверим четырехугольник
		return result;		
	}
};


int main()
{

    setlocale(LC_ALL, "Russian");

    Shape shape;

    Triangle triangle(10, 20, 30, 50, 60, 70);
    Square_Triangle square_triangle1(10, 20, 30, 50, 60);
    Square_Triangle square_triangle2(10, 20, 30, 50, 40);
    Isosceles_Triangle isosceles_triangle(10, 20, 50, 60);
    Equilateral_Triangle equilateral_triangle(30);

    Poly poly(10, 20, 30, 40, 50, 60, 70, 80);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rect rectangle(10, 20);
    Square square(20);
    Rhombus rhombus(30, 30, 40);

    
    Shape* par_shape = &shape;
    print_info(par_shape);
    //shape.print_about();
    std::cout << std::endl;

    Triangle* par_triangle = &triangle;
    print_info(par_triangle);    
    //triangle.print_about();
    std::cout << std::endl;
    
    Square_Triangle* par_square_triangle1 = &square_triangle1;
    print_info(par_square_triangle1);
    //square_triangle1.print_about();
    std::cout << std::endl;

    Square_Triangle* par_square_triangle2 = &square_triangle2;
    print_info(par_square_triangle2);
    //square_triangle2.print_about();
    std::cout << std::endl;

    Isosceles_Triangle* par_isosceles_triangle = &isosceles_triangle;
    print_info(par_isosceles_triangle);
    //isosceles_triangle.print_about();
    std::cout << std::endl;

    Equilateral_Triangle* par_equilateral_triangle = &equilateral_triangle;
    print_info(par_equilateral_triangle);
    //equilateral_triangle.print_about();
    std::cout << std::endl;

    std::cout << std::endl;

    Poly* par_poly = &poly;
    print_info(par_poly);
    //poly.print_about();
    std::cout << std::endl;

    Rect* par_rectangle = &rectangle;
    print_info(par_rectangle);
	//rectangle.print_about();
    std::cout << std::endl;

    Square* par_square = &square;
    print_info(par_square);
    //square.print_about();
    std::cout << std::endl;

    Parallelogram* par_parallelogram = &parallelogram;
    print_info(par_parallelogram);
    //parallelogram.print_about();
    std::cout << std::endl;
        
    Rhombus* par_rhombus = &rhombus;
    print_info(par_rhombus);
    //rhombus.print_about();
    std::cout << std::endl;

}