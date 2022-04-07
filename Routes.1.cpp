#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<fstream>
using namespace std;
class Leg
{
  const char* const startCity;
  const char* const endCity;
  const double distance;
public:
  Leg(const char* const, const char* const, const double);
  Leg& operator=(const Leg&);
  double getDistance() const;
  void output(ostream&) const;
};

ostream& roundingOne(ostream&);
ostream& roundingOff(ostream&);

int main()
{
  cout << "Programmer: Younghyun Kwon\n";
  cout << "Programmer's ID: 1651849\n";

  Leg legs[] = {
    Leg("Davis", "Sacramento", 14.2),
    Leg("Novato", "San Rafael", 6.2),
    Leg("San Jose", "Cupertino", 7.5),
    Leg("San Leandro", "Hayward", 7.8),
    Leg("Union City", "Milpitas", 8.4),
    Leg("San Ramon", "Pleasanton", 6.7),
    Leg("Hayward", "Union City", 6.9),
    Leg("Fremont", "Union City", 8.5),
    Leg("Milpitas", "Sunnyvale", 9.3),
    Leg("Morgan Hill", "Gilroy", 9.8),
    Leg("Pleasanton", "Livermore", 10.2),
    Leg("Martinez", "Pleasant Hill", 4.9),
    Leg("Pleasant Hill", "Pacheco", 3.9),
    Leg("Walnut Creek", "Fremont", 30.8),
    Leg("Daly City", "San Mateo", 14.5),
    Leg("Marin", "Richmond", 14.9),
    Leg("Vacaville", "Davis", 13.1),
    Leg("Fremont", "Milpitas", 13.6),
    Leg("San Jose", "Santa Cruz", 30.5),
    Leg("Fremont", "San Ramon", 19.1),
    Leg("Livermore", "Tracy", 19.2),
    Leg("Tracy", "Stockton", 20.2),
    Leg("Benicia", "Vallejo", 10.2),
    Leg("Martinez", "Benicia", 11.5),
    Leg("Morgan Hill", "San Jose", 11.6),
    Leg("San Francisco", "Daly City", 12.6),
    Leg("Emeryville", "Berkeley", 16.9),
    Leg("Concord", "Walnut Creek", 2.1),
    Leg("Marin", "San Rafael", 2.9),
    Leg("Pleasnat Hill", "Concord", 3.1),
    Leg("Richmomd", "Berkeley", 4.5),
    Leg("San Rafael", "San Francisco", 20.8),
    Leg("Fairfield", "Davis", 24.8),
    Leg("Vallejo", "Fairfield", 25),
    Leg("Vallejo", "Napa", 26),
    Leg("Oakland", "Richmond", 15.2),
    Leg("Vallejo", "Novato", 16.3),
    Leg("Sunnyvale", "Cupertino", 16.4),
    Leg("Alameda", "Oakland", 4.3),
    Leg("El Cerrito", "Richmond", 5.2),
    Leg("Fairfield", "Vacaville", 14.9)
  };

  const int SIZE = sizeof(legs) / sizeof(legs[0]);

  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE-1; j++)
    {
      if(legs[j].getDistance() > legs[j+1].getDistance())
      {
        Leg temp = legs[j];
        legs[j] = legs[j+1];
        legs[j+1] = temp;
      }
    }
  }

  for(int i = 0; i < SIZE; i++)
  {
    legs[i].output(cout);
  }
}

Leg::Leg(const char* const startCity, const char* const endCity, const double distance)
: startCity(startCity), endCity(endCity), distance(distance)
{
}

Leg& Leg::operator=(const Leg& leg)
{
  Leg& host = *this;
  if(this != &leg)
  {
    const_cast<const char*&>(host.startCity) = leg.startCity;
    const_cast<const char*&>(host.endCity) = leg.endCity;
    const_cast<double&>(host.distance) = leg.distance;
  }
  return *this;
}

double Leg::getDistance() const
{
  return distance;
}

void Leg::output(ostream& out) const
{
  roundingOne(out);
  out << "Leg: " << startCity << " to " << endCity << ", " << distance << " miles\n";
  roundingOff(out);
}

ostream& roundingOne(ostream& out)
  {
    out.setf(ios::fixed);
    out.precision(1);
    return out;
  }

ostream& roundingOff(ostream& out)
  {
    out.unsetf(ios::fixed);
    out.precision(6);
    return out;
  }
