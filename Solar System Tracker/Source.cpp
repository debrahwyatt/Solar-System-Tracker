#include <iostream>
#include <iomanip> 
#include <Windows.h>

using std::cout;
using std::endl;
using std::setprecision; 
using std::fixed;
using std::setw;

double Pi = 3.14159265359;
bool B1;

//Earth's Information
double AstronomicalUnit = 149597870700; //In meters 
double EarthX, EarthY; //Earths coordinates from Sun

double EarthSecond = ((2*Pi) / (365.24*24*60*60)); // angle change per second
double EarthVelocity = EarthSecond*AstronomicalUnit; // Distance traveled per second

double EarthCurrentTime; //In seconds
double EarthCurrentDistance; //In meters

double EarthCircumfrance = 4007500; //in meters
double EarthSpin = EarthCircumfrance*EarthSecond; //in m/s
double EarthCurrentSpin; // in meters



int main()
{
	//Earth's Orbit
	
	cout << "Earth:\n";

	while (EarthCurrentTime >= 0)
	{
		EarthCurrentTime = EarthCurrentTime + EarthSecond;
		EarthCurrentDistance = EarthCurrentDistance + EarthVelocity;
		EarthCurrentSpin = EarthCurrentSpin + EarthSpin;

		EarthX = cos(EarthCurrentTime)*AstronomicalUnit;
		EarthY = sin(EarthCurrentTime)*AstronomicalUnit;


		cout << setprecision(3) << fixed << "X: " << EarthX << "m, Y: " << EarthY
			<< "km, Distance Traveled: " << EarthCurrentDistance << "m, Travel Velocity: " << EarthVelocity << "m/s\r";
		if (B1 == false)
		{
			cout << endl;
			B1 = true;
		}
		cout << "Angular Velocity: " << EarthSpin << "m/s, Distance spun: " <<EarthCurrentSpin << "m\r";


		Sleep(1000);
	}
	
}