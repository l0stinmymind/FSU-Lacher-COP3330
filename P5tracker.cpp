#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vehicles.h>

// global constants
const unsigned int C1 = 6;    // short name
const unsigned int C2 = 10;   // pass cap
const unsigned int C3 = 10;   // load cap
const unsigned int maxShiftSize = 100;
const unsigned int maxStringSize = 50;

int main()
{
  const unsigned int c4 = 2;    // variable C4 = max Operator ID length + c4
  const unsigned int c5 = 2;    // variable C5 = max Operator CDL length + c5
  const unsigned int c6 = 2;    // variable C6 = max Vehicle Registration Number
                                // length + c6

  // bad message strings
  const char* const badRegMsg = "BadRegistration";
  const char* const badIDMsg = "BadOperatorID";
  const char* const badCDLMsg = "BadOperatorCDL";

  std::cout << "FastLane Tracker started...\n\n";

  unsigned short shift;
  char sn[maxStringSize];
  char opID[maxStringSize];
  char opCDL[maxStringSize];
  CommercialVehicle * Vptr[maxShiftSize];      // pointer to dynamically
                                               // allocated CommercialVehicle
                                               // object
  VehicleType v;
  char reg[1];
  int shiftCount = 1;

do
 {
   int pc;
   float width = 0.00;
   float length = 0.00;
   float height= 0.00;
   float radius = 0.00;
   int unknownctr = 0;
   int carctr = 0;
   int busctr = 0;
   int limctr = 0;
   int tructr = 0;
   int vanctr = 0;
   int tanctr = 0;
   int flactr = 0;
   int badregsctr = 0;
   int passengerCap = 0;
   float freightCap = 0.00;
   int snlengths[maxStringSize];
   int idlengths [maxStringSize];
   int cdllengths[maxStringSize];

    std::cin >> shift;
   
    if (shift == 0 || shift > maxShiftSize)
    {
      exit(EXIT_FAILURE);
    }

    for ( size_t i = 0; i < shift; ++i)
    {
      std::cin >> sn;
      snlengths [i] = strlen(sn);
      reg[0] = sn[0];
      
      v= CommercialVehicle::RegDecode(reg);

      switch (v)
      {
        case vehicle:
          std::cin >> opID;
          std::cin >> opCDL;
          Vptr[i] = new CommercialVehicle(sn, opID, opCDL, 0);
          unknownctr+=1;
          idlengths [i] = strlen(opID);
          cdllengths[i] = strlen(opCDL);
          break;
        case carriage:
          std::cin >> opID;
          std::cin >> opCDL;
          std::cin >> pc;
          idlengths[i] = strlen(opID);
          cdllengths[i] = strlen(opCDL);
          Vptr[i] = new Carriage(sn, opID, opCDL, pc);
          carctr+=1;
          passengerCap += pc;
          break;
        case bus:
          std::cin >> opID;
          std::cin >> opCDL;
          std::cin >> pc;
          idlengths[i] = strlen(opID);
          cdllengths[i] = strlen(opCDL);
          Vptr[i] = new Bus(sn, opID, opCDL, pc);
          busctr+=1;
          passengerCap += pc;
          break;
        case limo:
          std::cin >> opID;
          std::cin >> opCDL;
          std::cin >> pc;
          cdllengths[i] = strlen(opCDL);
          idlengths[i] = strlen(opID);
          Vptr[i] = new Limo(sn, opID, opCDL, pc);
          limctr+=1;
          passengerCap += pc;
          break;
        case truck:
          std::cin >> opID;
          std::cin >> opCDL;
          idlengths[i] = strlen(opID);
          cdllengths[i] = strlen(opCDL);
          Vptr[i] = new Truck(sn, opID, opCDL, 0);
          tructr+=1;
          break;
        case van:
          std::cin >> opID;
          std::cin >> opCDL;
          std::cin >> width;
          std::cin >> length;
          std::cin >> height;
          idlengths[i] = strlen(opID);
          cdllengths[i] = strlen(opCDL);
          Vptr[i] = new Van(sn, opID, opCDL, width, length, height);
          vanctr+=1;
          freightCap += Vptr[i]->LoadCapacity();
          break;
        case tanker:
          std::cin >> opID;
          std::cin >> opCDL;
          std::cin >> radius;
          std::cin >> length;
          idlengths[i] = strlen(opID);
          cdllengths[i] = strlen(opCDL);
          Vptr[i] = new Tanker(sn, opID, opCDL, radius, length);
          tanctr+=1;
          freightCap += Vptr[i]->LoadCapacity();
          break;
        case flatbed:
          std::cin >> opID;
          std::cin >> opCDL;
          std::cin >> width;
          std::cin >> length;
          idlengths[i] = strlen(opID);
          cdllengths[i] = strlen(opCDL);
          Vptr[i] = new Flatbed(sn, opID, opCDL, width, length);
          flactr+=1;
          freightCap += Vptr[i]->LoadCapacity();
          break;
        case badReg:
          Vptr[i] = new CommercialVehicle(badRegMsg, badIDMsg, badCDLMsg, 0, 0);
          break;
        default:  // should never get here
          std::cerr << "** ERROR: bad VehicleType passed to decision logic\n";
          break;
      } // end switch
    }
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << " Shift " << shiftCount << " Summary\n"
              << " ===============\n";
    std::cout << '\n'
              << "  Carriages:            " << carctr << '\n'
              << "  Buses:                " << busctr << '\n'
              << "  Limos:                " << limctr << '\n'
              << "  Trucks:               " << tructr << '\n'
              << "  Vans:                 " << vanctr << '\n'
              << "  Tankers:              " << tanctr << '\n'
              << "  Flatbeds:             " << flactr << '\n'
              << "  Unknowns:             " << unknownctr << '\n'
              << "  Badregs:              " << badregsctr << '\n'
              << "  Total Passenger Cap:  " << passengerCap << '\n'
              << "  Total Freight Cap:    " << freightCap << '\n'
              << '\n';

    unsigned int maxVehicleRegistrationNumber;
    
    int largestsn = snlengths[0];
    for(int i=0; i<shift; i++)
    {
      if(largestsn<snlengths[i])
      {
        largestsn=snlengths[i];
      }
    }

    if (largestsn < 12)
    {
      maxVehicleRegistrationNumber = 12;
    }
    else
    {
      maxVehicleRegistrationNumber = largestsn; 
    }

    unsigned int maxOperatorCDL;

    int largestCDL = cdllengths[0];
    for(int i=0; i<shift; i++)
    {
      if(largestCDL<cdllengths[i])
      {
        largestCDL=cdllengths[i];
      }
    }

    if (largestCDL < 12)
    {
      maxOperatorCDL = 12;
    }
    else
    {
      maxOperatorCDL = largestCDL;
    }

    unsigned int maxOperatorID;
    
    int largestID = idlengths[0];
    for(int i=0; i<shift; i++)
    {
      if(largestID<idlengths[i])
      {
        largestID=idlengths[i];
      }
    }

    if (largestID< 12)
    {
      maxOperatorID = 12;
    }
    else
    {
      maxOperatorID = largestID;
    }

    const unsigned int C4 = maxVehicleRegistrationNumber + c4;
    const unsigned int C5 = maxOperatorID + c5;
    const unsigned int C6 = maxOperatorCDL + c6;

    std::cout << " Shift " << shiftCount << " Log\n"
              << " ===============\n";
    std::cout << '\n'
              << std::setw(C1) << "Type"
              << std::setw(C2) << "Pass Cap"
              << std::setw(C3) << "Load Cap"
              << std::left << "  "
              << std::setw(C4) << "Registration"
              << std::setw(C5) << "Operator ID"
              << std::setw(C6) << "Operator CDL"
              << std::right
              << '\n';

    std::cout
      << std::setw(C1) << "----"
      << std::setw(C2) << "--------"
      << std::setw(C3) << "--------"
      << std::left << "  "
      << std::setw(C4) << "------------"
      << std::setw(C5) << "-----------"
      << std::setw(C6) << "------------"
      << std::right
      << '\n';


    for (size_t i= 0; i < shift; i++)
    {
      std::cout
        << std::setw(C1) << Vptr[i]->ShortName()
        << std::setw(C2) << Vptr[i]->PassengerCapacity()
        << std::setw(C3) << Vptr[i]->LoadCapacity()
        << std::left << "  "
        << std::setw(C4) << Vptr[i]->Registration()
        << std::setw(C5) << Vptr[i]->Operator()
        << std::setw(C6) << Vptr[i]->CDL()
        << std::right
        << '\n';
      delete Vptr[i];
    }    
   shiftCount+=1;

 }
 while (shift <= maxShiftSize);

 std::cout << "\n...Thank you for using FastLane Tracker\n";

 return 0;
}

  
