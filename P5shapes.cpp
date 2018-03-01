#include <iostream>
#include <cmath>
#include <shapes.h>


Shape::Shape()
{
  x_ = 0.00;
  y_ = 0.00;
  z_ = 0.00;
}

Shape::Shape(float x, float y, float z, bool verbose) : x_(x), y_(y), z_(z)
{
  verbose_=verbose;
  if (verbose_ == 1)
  {
    std::cout << "Shape(" << x << "," << y << "," << z << "," << verbose << ")" << std::endl;
  }
}

Shape::~Shape()
{
  if (verbose_==1)
  {
    std::cout << "~Shape()" << std::endl;
  }    
}

const char* Shape::Name() const
{
  return "generic";
}  // returns "generic"

float Shape::Volume() const
{
  float volumn;
  volumn = 0;
  return volumn;
}
// returns volume of object  


float Shape::Area() const
{
  float area;
  area = 0;
  return area;
}
// returns area of object



Box::Box()
{
  x_ = 0.00;
  y_ = 0.00;
  z_ = 0.00;
}

Box::Box(float width, float length, float height, bool verbose) : Shape(width, length, height, verbose)
{
  if (verbose_ == 1)
  {
    std::cout << "Box(" << width << "," << length << "," << height << "," << verbose << ")" << std::endl;
  }
}

Box::~Box() 
{
  if (verbose_==1)
  {
    std::cout << "~Box() " << std::endl;
  }
}

const char* Box::Name() const
{
  return "box";
}// returns "box"


float Box::Volume() const
{
  float volumn;
  volumn = x_ * y_ * z_;
  return volumn;
}
// returns volume of box object  


float Box::Area() const
{
  float area;
  area = (2 * x_ * y_) + (2 * x_ * z_) + (2 * y_ * z_);
  return area;
}
// returns surface area of box object


Cylinder::Cylinder()
{
  x_ = 0.00;
  y_ = 0.00;
  z_ = 0.00;
}
Cylinder::Cylinder(float radius, float height, bool verbose) : Shape(radius, 0, height, verbose)
{
  if (verbose_ == 1)
  {
    std::cout << "Cylinder(" << radius << ","  << height << "," << verbose << ")" << std::endl;
  }
}
Cylinder::~Cylinder()
{
  if(verbose_ == 1)
  {
    std::cout << "~Cylinder() " << std::endl;
  }
}


const char* Cylinder::Name() const
{
  return "cylinder";
}// returns "cylinder"

float Cylinder::Volume() const
{
  float volumn;
  volumn = M_PI * x_ * x_ *z_;
  return volumn;
}
// returns volume of cylinder object  
float Cylinder::Area() const
{
  float area;
  area = (2 * M_PI * x_ * z_) + (2 * M_PI * x_ * x_);
  return area;
}// returns surface area of cylinder object



Rectangle::Rectangle()
{
  x_ = 0.00;
  y_ = 0.00;
  z_ = 0.00;
}

Rectangle::Rectangle(float width, float length, bool verbose) : Shape(width, length, 0, verbose)
{
  if (verbose_ == 1)
  {
    std::cout << "Rectangle(" << width << "," << length << "," << verbose << ")" << std::endl;
  }
}

Rectangle::~Rectangle()
{
  if (verbose_==1)
  {
    std::cout << "~Rectangle() " << std::endl;
  }
}

const char* Rectangle::Name() const
{
  return "rectangle";
}// returns "rectangle"

float Rectangle::Area() const
{
  float area;
  area = (x_ * y_);
  return area;
}// returns area of rectangle object 

