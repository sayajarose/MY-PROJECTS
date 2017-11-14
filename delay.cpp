#include<iostream.h> //Sayaja Rose Adhikari
#include<math.h>
#include<string.h>
#include<iomanip.h>

void getInput(int& startingHours,int& startingMinutes,char& timeFormat,int& delayHours, int& delayMinutes);
void computeOutput(int extraHours,int startingHours, int delayHours,int delayMinutes, int startingMinutes, int& currentHours,
                                                                                                         int& currentMinutes);
void displayEndTime(int currentHours,int currentMinutes,char timeFormat);

int main()
{
int startingHours;
int startingMinutes;
int delayHours;
int delayMinutes;
char timeFormat;
char startingTime;
char delayTime;
int currentHours;
int currentMinutes;
int extraHours;
getInput(startingHours, startingMinutes, timeFormat, delayHours, delayMinutes);
while (startingHours!= 999)
{
computeOutput(extraHours,startingHours,delayHours,startingMinutes,delayMinutes,currentHours,currentMinutes);
displayEndTime(currentHours,currentMinutes,timeFormat);
getInput (startingHours, startingMinutes, timeFormat, delayHours, delayMinutes);
}
}// end of main

void getInput (int& startingHours,int& startingMinutes,char& timeFormat,int& delayHours,int& delayMinutes)
{
cout << " startingTime? " ;
cin >>startingHours>>startingMinutes>>timeFormat;
   if ( timeFormat == 'a' || timeFormat == 'A' || timeFormat=='P' || timeFormat=='p')
   {

      if ( startingHours != 12 && (timeFormat == 'p' || timeFormat =='P') )
      {
       startingHours = startingHours + 12;
      }
      else if (startingHours == 12 && (timeFormat == 'a' || timeFormat == 'A'))
      {
      startingHours = 0;
      }
      cout << "Delay Time? ";
      cin>>delayHours>>delayMinutes;
    }
    else
     cout << "Type 'a' or 'A' for am and 'p' or 'P' for pm";
}

void computeOutput (int extraHours,int startingHours, int delayHours,int delayMinutes, int startingMinutes,
                                                                                               int& currentHours,int& currentMinutes)
{
currentMinutes = startingMinutes + delayMinutes;
extraHours = currentMinutes/60;
currentMinutes = currentMinutes%60;
currentHours = startingHours + delayHours + extraHours;
currentHours = currentHours%24;

}

void displayEndTime(int currentHours,int currentMinutes, char timeFormat)
{
   if ( currentHours>12)
    {
     currentHours = currentHours-12 ;
     timeFormat = 'p';
    }
   else if ( currentHours>0 && currentHours<12)
     {
	 timeFormat = 'a';
     }
    else if ( currentHours == 12)
     {
	  timeFormat = 'p' ;
     }
    else if ( currentHours == 0)
    {
		currentHours = 12;
		timeFormat= 'a';
    }
cout << " End-Time is :" <<setw(2)<< currentHours<< ":" << setfill('0')<<setw(2)<<currentMinutes<< timeFormat << "m" << endl;
}
