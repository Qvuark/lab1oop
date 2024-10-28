#include <iostream>
#include <cmath>

class TETriangle
{
protected:
    double side;
public:
    TETriangle() : side(1) {}
    TETriangle(double s) : side(s) {}
    TETriangle(const TETriangle& other) : side(other.side) {}
    double area() const
    {
        return (sqrt(3)/4)*side*side;
    }
    double perimeter() const
    {
        return 3*side;
    }
    virtual void output() const
    {
        std::cout<<"Triangle with side: "<<side<<std::endl;
        std::cout<<"Triangle area: "<<area()<<std::endl;
        std::cout<<"Triangle perimeter: "<<perimeter()<<std::endl;
    }
    bool operator==(const TETriangle& other) const
    {
        return side == other.side;
    }
    TETriangle operator*(double multiplier) const
    {
        return TETriangle(side * multiplier);
    }
    friend TETriangle operator*(double scalar, const TETriangle& triangle)
    {
        return TETriangle(triangle.side * scalar);
    }
    double getLength()
    {
        return side;
    }
};
class TEPiramid : public TETriangle
{
private:
    double height;
public:
    TEPiramid() : TETriangle(), height(1) {}
    TEPiramid(double s, double h) : TETriangle(s), height(h) {}
    TEPiramid(const TETriangle& triangle, double h) : TETriangle(triangle), height(h) {}
    double volume() const
    {
        return (1.0/3.0)*area()*height;
    }
    void output() const override
    {
        std::cout<<"Pyramid with side "<<side<< " and height "<<height<<" :"<<std::endl;
        std::cout<<"Triangle base area: "<<area()<<std::endl;
        std::cout<<"Pyramid volume: "<<volume()<<std::endl;
        std::cout<<"Triangle perimeter (base): "<<perimeter()<<std::endl;
    }
    double getHeight() const
    {
        return height;
    }
    void setHeight(double h)
    {
        height = h;
    }
};
int main()
{
    //triangle
    TETriangle triangle; 
    TETriangle copyTriangle;
    std::cout<<"How do you want to enter first triangle?"<<std::endl;
    std::cout<<"1 for no parameter input"<< std::endl;
    std::cout<<"2 to enter with parameter"<< std::endl;
    std::cout<<"3 to copy input from another triangle"<< std::endl;
    int input;
    std::cin>>input;
    switch (input)
    {
    case 1:
        std::cout<<"Triangle created with no parameters (side = 0 by default)."<< std::endl;
        triangle.output();
        break;
    case 2:
        double sideLength;
        std::cout<<"Enter the side length of the triangle: ";
        std::cin>>sideLength;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        triangle = TETriangle(sideLength);
        triangle.output();
        break;

    case 3:
        double copySide;
        std::cout<<"Enter the side length for the triangle to copy:";
        std::cin>>copySide;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        copyTriangle = TETriangle(copySide);
        triangle = TETriangle(copyTriangle);
        std::cout<<"Copied triangle:\n";
        triangle.output();
        break;
    default:
        std::cout<<"Invalid input! Please enter 1, 2, or 3."<<std::endl;
        return 1; 
    }
    std::cout<<"Enter side for second triangle: ";
    double triangleInput;
    std::cin>>triangleInput;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
    TETriangle secondTriangle = triangleInput;
    secondTriangle.output();
    std::cout<<"\n=== Additional Operations ===\n";
    if (triangle == secondTriangle)
        std::cout<<"Triangles are equal."<<std::endl;
    else
        std::cout<<"Triangles are not equal."<<std::endl;
    std::cout<<"Enter number which you want to multiply to triangle: ";
    double number;
    std::cin>>number;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
    TETriangle largerTriangle1 = triangle * number;
    std::cout<<"Triangle after "<<triangle.getLength()<<" * "<<number<<":"<<std::endl;
    largerTriangle1.output();
    std::cout<<std::endl;
    TETriangle largerTriangle2 = number * triangle;
    std::cout<<"Triangle after "<<number<<" * "<< triangle.getLength()<<":"<<std::endl;
    largerTriangle2.output();
    //piramid
    std::cout<<std::endl;
    std::cout<<"Enter height for the pyramid: ";
    double height;
    std::cin>>height;
    TEPiramid pyramid(triangle, height);
    pyramid.output();
    return 0;
}
