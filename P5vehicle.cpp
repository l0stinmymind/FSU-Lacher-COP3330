#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vehicles.h>



CommercialVehicle::CommercialVehicle()
{
}  

CommercialVehicle::CommercialVehicle(const char* registration, const char* operatorID, const char* operatorCDL, unsigned short passengerCapacity, bool verbose)
{
  vehicleRegistration_ = new char[1 + strlen(registration)];
  strcpy(vehicleRegistration_,  registration);
  operatorID_ = new char[1 + strlen(operatorID)];
  strcpy(operatorID_,  operatorID);
  operatorCDL_ = new char[1 + strlen(operatorCDL)];
  strcpy(operatorCDL_, operatorCDL);
  passengerCapacity_ = passengerCapacity;
  verbose_ = verbose;
  if (verbose_== 1)
  {
    std::cout << "CommercialVehicle(" << registration << "," << operatorID << "," << operatorCDL << "," << passengerCapacity << "," << verbose << ")" << std::endl;
  }
}

CommercialVehicle::~CommercialVehicle()
{
  if (verbose_== 1)
  {
    std::cout << "~CommercialVehicle()" << std::endl;
  }
}

const char* CommercialVehicle::Registration() const
{
  return vehicleRegistration_;
}// returns vehicle registration number


const char* CommercialVehicle::Operator() const
{
  return operatorID_;
}// returns operator ID   


const char* CommercialVehicle::CDL() const
{
  return operatorCDL_;
}// returns operator CDL  


unsigned int CommercialVehicle::PassengerCapacity() const
{
  return passengerCapacity_;
}// returns passenger capacity 


float CommercialVehicle::LoadCapacity() const
{
  return 0.00;
}// returns volume or area of cargo space 


const char* CommercialVehicle::ShortName() const
{
  return "UNK";
}
// returns "UNK"

VehicleType CommercialVehicle::RegDecode(const char* sn)
{
  switch (sn[0])
  {
    case '1':
      return vehicle;
    case '2':
      return carriage;
    case '3':
      return bus;
    case '4':
      return limo;
    case '5':
      return truck;
    case '6':
      return van;
    case '7':
      return tanker;
    case '8':
      return flatbed;
    default:
      return badReg;
  }
}

Carriage::Carriage()
{
  CommercialVehicle::Registration();
  CommercialVehicle::Operator();
  CommercialVehicle::CDL();
  CommercialVehicle::PassengerCapacity();
  CommercialVehicle::verbose_ = 0;
}

Carriage::Carriage(const char* registration, const char* operatorID, const char* operatorCDL, unsigned short passengerCapacity, bool verbose): CommercialVehicle(registration,operatorID,operatorCDL,passengerCapacity,verbose)
{
  if (verbose_ == 1)
  {
    std::cout << "Carriage(" << registration << "," << operatorID << "," << operatorCDL << "," << passengerCapacity << "," << verbose << ")" << std::endl;
  }
}

Carriage::~Carriage()
{
  if (verbose_==1)
  {
    std::cout << "~Carriage()" << std::endl;
  }
}

const char* Carriage:: ShortName() const
{
  return "CAR";
}// returns "CAR" 

Bus::Bus()
{
  CommercialVehicle::Registration();
  CommercialVehicle::Operator();
  CommercialVehicle::CDL();
  CommercialVehicle::PassengerCapacity();
  CommercialVehicle::verbose_ = 0;
}

Bus::Bus(const char* registration, const char* operatorID, const char* operatorCDL, unsigned short passengerCapacity, bool verbose) :Carriage(registration, operatorID, operatorCDL, passengerCapacity, verbose)
{
  if (verbose_ == 1)
  {
    std::cout << "Bus(" << registration << "," << operatorID << "," << operatorCDL << "," << passengerCapacity << "," << verbose << ")" << std::endl;
  }
}

Bus::~Bus()
{
  if (verbose_==1)
  {
    std::cout << "~Bus()" << std::endl;
  }
}

const char* Bus::ShortName() const
{
  return "BUS";
}// returns "BUS" 


Limo::Limo()
{
  CommercialVehicle::Registration();
  CommercialVehicle::Operator();
  CommercialVehicle::CDL();
  CommercialVehicle::PassengerCapacity();
  CommercialVehicle::verbose_ = 0;
}

Limo::Limo(const char* registration, const char* operatorID, const char* operatorCDL, unsigned short passengerCapacity, bool verbose) :Carriage(registration, operatorID, operatorCDL, passengerCapacity, verbose)
{
  if (verbose_ == 1)
  {
    std::cout << "Limo(" << registration << "," << operatorID << "," << operatorCDL << "," << passengerCapacity << "," << verbose << ")" << std::endl;
  }
}

Limo::~Limo()
{
  if (verbose_==1)
  {
    std::cout << "~Limo()" << std::endl;
  }
}

const char* Limo::ShortName() const
{
  return "LIM";
} // returns "LIM"

Truck::Truck()
{
  CommercialVehicle::Registration();
  CommercialVehicle::Operator();
  CommercialVehicle::CDL();
  CommercialVehicle::PassengerCapacity();
  CommercialVehicle::verbose_ = 0;
}

Truck::Truck(const char* registration, const char* operatorID, const char* operatorCDL, bool verbose) : CommercialVehicle(registration, operatorID, operatorCDL, 0, verbose)
{
  if (verbose_ == 1)
  {
    std::cout << "Truck(" << registration << "," << operatorID << "," << operatorCDL << "," << verbose << ")" << std::endl;
  }
}
Truck::~Truck()
{
  if (verbose_ ==1)
  {
    std::cout << "~Truck()" << std::endl;
  }
}

const char* Truck::ShortName() const
{
  return "TRK";
}// returns "TRK"

Van::Van()
{
  CommercialVehicle::Registration();
  CommercialVehicle::Operator();
  CommercialVehicle::CDL();
  CommercialVehicle::PassengerCapacity();
  CommercialVehicle::verbose_ = 0;
}

Van::Van(const char* registration, const char* operatorID, const char* operatorCDL, float width, float length, float height, bool verbose) 
  : Truck(registration, operatorID, operatorCDL, verbose), Box(width, length, height,verbose)
{
  if (CommercialVehicle::verbose_ == 1)
  {
    std::cout << "Van(" << registration << "," << operatorID << "," << operatorCDL << "," << width << "," << length << "," << height << "," <<verbose << ")" << std::endl;
  }
}

Van::~Van()
{
  if (CommercialVehicle::verbose_==1)
  {
    std::cout << "~Van()" << std::endl;
  }
}

float Van::LoadCapacity() const
{
  return Box::Volume();
}// returns volume of box  

const char* Van::ShortName() const
{
  return "VAN";
}     // returns "VAN"

Tanker::Tanker()
{
  CommercialVehicle::Registration();
  CommercialVehicle::Operator();
  CommercialVehicle::CDL();
  CommercialVehicle::PassengerCapacity();
  CommercialVehicle::verbose_ = 0;
}

Tanker::Tanker(const char* registration, const char* operatorID, const char* operatorCDL, float radius, float length, bool verbose) : Truck(registration, operatorID, operatorCDL, verbose), Cylinder(radius, length, verbose)
{
  if (CommercialVehicle::verbose_ == 1)
  {
    std::cout << "Tanker(" << registration << "," << operatorID << "," << operatorCDL << "," << radius << "," << length << "," << verbose << ")" << std::endl;
}
}

Tanker::~Tanker()
{
  if (CommercialVehicle::verbose_==1)
  {
    std::cout << "~Tanker()" << std::endl;
  }
}

float Tanker:: LoadCapacity() const
{
return Cylinder::Volume();
}// returns volume of cylinder  

const char* Tanker::ShortName() const
{
return "TNK";
}// returns "TNK"


Flatbed::Flatbed()
{
  CommercialVehicle::Registration();
  CommercialVehicle::Operator();
  CommercialVehicle::CDL();
  CommercialVehicle::PassengerCapacity();
  CommercialVehicle::verbose_ = 0;
}

Flatbed::Flatbed(const char* registration, const char* operatorID, const char* operatorCDL, float width, float length, bool verbose) : Truck(registration, operatorID, operatorCDL, verbose), Rectangle(width, length, verbose)
{
  if (CommercialVehicle::verbose_== 1)
  {
    std::cout << "Flatbed(" << registration << "," << operatorID << "," << operatorCDL << "," << width << "," << length << "," << verbose << ")" << std::endl;
  }
}

Flatbed::~Flatbed()
{
  if (CommercialVehicle::verbose_==1)
  {
    std::cout << "~Flatbed()" << std::endl;
  }
}

float Flatbed::LoadCapacity() const
{
  return Rectangle::Area();
}// returns area of rectangle  


const char* Flatbed::ShortName() const
{
  return "FLT";
}// returns "FLT" 


