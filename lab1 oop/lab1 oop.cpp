#include <iostream>
#include <cmath>

class Triangle 
{
private:
    int a, b, c;
public:
    Triangle(double sideA = 1.0, double sideB = 1.0, double sideC = 1.0) 
    {
        a = sideA;
        b = sideB;
        c = sideC;
    }
    int operator[](int index) const
    {
        switch (index)
        {
        case 0: return a;
        case 1: return b;
        case 2: return c;
        default:
            std::cout << "Invalid index. Use 0 for a, 1 for b, 2 for c."<<std::endl;
            return -1;
        }
    }
    bool isValid() const 
    {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }
    double getPerimeter() const 
    {
        if (isValid()) 
        {
            return a + b + c;
        }
        else 
        {
            std::cout << "Triangle doesn't exist";
            return 0;
        }
    }
    double getArea() const 
    {
        if (isValid()) 
        {
            double s = getPerimeter() / 2;
            return sqrt(s * (s - a) * (s - b) * (s - c));
        }
        else 
        {
            std::cout << "Triangle doesnt exist";
            return 0;
        }
    }
    void inputSides() 
    {
        std::cout<<"Enter a,b,c: ";
        bool isInputRight = false;
        do
        {
            std::cin >> a >> b >> c;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Invalid input. Please enter valid numbers for sides a, b, c" << std::endl;
                isInputRight = false;
            }
            else
            {
                std::cin.ignore(32767, '\n');
                isInputRight = true;
            }
        } while (!isInputRight);
    }
    void display() const 
    {
        if (isValid()) 
        {
            std::cout<<"Perimetr: "<<getPerimeter()<<std::endl;
            std::cout<<"Square: "<<getArea()<<std::endl;
        }
        else 
        {
            std::cout << "Triangle doesnt exist";
        }
    }
};
int main() 
{
    Triangle t;
    t.inputSides();
    t.display();
    std::cout<<"Side a through indexter: "<<t[0]<<std::endl;
    std::cout<<"Side b through indexter: "<<t[1]<<std::endl;
    std::cout<<"Side c through indexter: "<<t[2]<<std::endl;
    return 0;
}
