class Shape
{
public:
  Shape();
  Shape(float x, float y, float z, bool verbose = 0);
  virtual ~Shape();
  virtual const char* Name() const;  // returns "generic"
  virtual float Volume() const;  // returns volume of object  
  virtual float Area() const;  // returns area of object
private:
  Shape(const Shape&); // copy construcotr
  Shape& operator=(const Shape&); // assignment operator
protected:
  float x_, y_, z_; // dimensions of shape
  bool  verbose_;   // default value 0 given in constructor prototype 
};

class Box : public Shape
{
public:
  Box();
  Box(float width, float length, float height, bool verbose = 0);
  virtual ~Box();
  virtual const char* Name() const;  // returns "box"
  virtual float       Volume() const;  // returns volume of box object  
  virtual float       Area() const;  // returns surface area of box object
private:
  Box(const Box&); // copy construcotr
  Box& operator=(const Box&); // assignment operator
};

class Cylinder : public Shape
{
public:
  Cylinder();
  Cylinder(float radius, float height, bool verbose = 0);
  virtual ~Cylinder();
  virtual const char* Name() const;  // returns "cylinder"
  virtual float       Volume() const;  // returns volume of cylinder object  
  virtual float       Area() const;  // returns surface area of cylinder object
private:
  Cylinder(const Cylinder&); // copy construcotr
  Cylinder& operator=(const Cylinder&); // assignment operator
};

class Rectangle : public Shape
{
public:
  Rectangle();
  Rectangle(float width, float length, bool verbose = 0);
  virtual ~Rectangle();
  virtual const char* Name() const;  // returns "rectangle"
  virtual float       Area() const;  // returns area of rectangle object 
private:
  Rectangle(const Rectangle&); // copy construcotr
  Rectangle& operator=(const Rectangle&); // assignment operator
};
