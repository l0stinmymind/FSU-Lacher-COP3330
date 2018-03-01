#include <shapes.h>

enum VehicleType
  {
    badReg, vehicle, carriage, bus, limo, truck, van, tanker, flatbed
  };

class CommercialVehicle
{
public:
  CommercialVehicle();
  CommercialVehicle(const char* registration, const char* operatorID, const char* operatorCDL, unsigned short passengerCapacity, bool verbose = 0);
  virtual~CommercialVehicle();
  virtual const char* Registration() const; // returns vehicle registration
                                            // number
  virtual const char* Operator() const; // returns operator ID   
  virtual const char* CDL() const; // returns operator CDL  
  virtual unsigned int PassengerCapacity() const; // returns passenger capacity 
  virtual float LoadCapacity() const; // returns volume or area of cargo space 
  virtual const char* ShortName() const; // returns "UNK"
  static VehicleType RegDecode(const char* sn);
private:
  CommercialVehicle(const CommercialVehicle&); // copy construcotr
  CommercialVehicle& operator=(const CommercialVehicle&); // assignment operator
  char* vehicleRegistration_;
  char* operatorID_;
  char* operatorCDL_;
  unsigned short passengerCapacity_;
protected:
  bool verbose_; // default value 0 given in constructor prototype
};

class Carriage : public CommercialVehicle
{
public:
  Carriage();
  Carriage(const char* registration, const char* operatorID, const char* operatorCDL, unsigned short passengerCapacity, bool verbose = 0);
  virtual~Carriage();
  virtual const char* ShortName() const; // returns "CAR" 
private:
  Carriage(const Carriage&); // copy construcotr
  Carriage& operator=(const Carriage&); // assignment operator
};

class Bus : public Carriage
{
public:
  Bus();
  Bus(const char* registration, const char* operatorID, const char* operatorCDL, unsigned short passengerCapacity, bool verbose = 0);
  virtual~Bus();
  virtual const char* ShortName() const; // returns "BUS" 
private:
  Bus(const Bus&); // copy construcotr
  Bus& operator=(const Bus&); // assignment operator
};

class Limo : public Carriage
{
public:
  Limo();
  Limo(const char* registration, const char* operatorID, const char* operatorCDL, unsigned short ppassengerCapacity, bool verbose = 0);
  virtual~Limo();
  virtual const char* ShortName() const; // returns "LIM"
private:
  Limo(const Limo&); // copy construcotr
  Limo& operator=(const Limo&); // assignment operator
};

class Truck : public CommercialVehicle
{
public:
  Truck();
  Truck(const char* registration, const char* operatorID, const char* operatorCDL, bool verbose = 0);
  virtual~Truck();
  virtual const char* ShortName() const; // returns "TRK"
private:
  Truck(const Truck&); // copy construcotr
  Truck& operator=(const Truck&); // assignment operator
};

class Van : public Truck,public Box
{
public:
  Van();
  Van(const char* registration, const char* operatorID, const char* operatorCDL, float width, float length, float height, bool verbose = 0);
  virtual~Van();
  virtual float LoadCapacity() const;  // returns volume of box  
  virtual const char* ShortName() const;     // returns "VAN"
private:
  Van(const Van&); // copy construcotr
  Van& operator=(const Van&); // assignment operator
};

class Tanker : public Truck, public Cylinder
{
public:
  Tanker();
  Tanker(const char* registration, const char* operatorID, const char* operatorCDL, float radius, float length, bool verbose = 0);
  virtual~Tanker();
  virtual float LoadCapacity() const;  // returns volume of cylinder  
  virtual const char* ShortName() const;     // returns "TNK"
private:
  Tanker(const Tanker&); // copy construcotr
  Tanker& operator=(const Tanker&); // assignment operator
};

class Flatbed : public Truck, public Rectangle
{
public:
  Flatbed();
  Flatbed(const char* registration, const char* operatorID, const char* operatorCDL, float width, float length, bool verbose = 0);
  virtual~Flatbed();
  virtual float LoadCapacity() const;  // returns area of rectangle  
  virtual const char* ShortName() const;     // returns "FLT" 
private:
  Flatbed(const Flatbed&); // copy construcotr
  Flatbed& operator=(const Flatbed&); // assignment operator
};
