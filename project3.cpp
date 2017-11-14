#include<iostream.h> //Sayaja Rose Adhikari
#include<fstream.h>
#include<iomanip.h>
#include<string.h>

void openFile (ofstream& myOutFile);
void getRecordFromUser(char stockNumber[],char description[],float& cost, float& price,int& quantityInStock);
void validateCost (float& cost);
void writeRecord(ofstream& myOutfile,char stockNumber[],char description[],float& cost,float&price,int& quantityInStock);

int main()
{
  char stockNumber[6];
  char description[21];
  char myFileName [100];
  float cost;
  float price;
  int quantityInStock;

  ofstream myOutFile;
  openFile (myOutFile);
  getRecordFromUser(stockNumber,description,cost,price,quantityInStock);
  while (strlen(stockNumber) != 0)
  {
	  if (cost != -999.00)
	  {
	   writeRecord(myOutFile,stockNumber,description,cost,price,quantityInStock);
	   getRecordFromUser(stockNumber,description,cost,price,quantityInStock);
      }
      else if (cost == -999.00)
      {
		  getRecordFromUser(stockNumber,description,cost,price,quantityInStock);
		  writeRecord(myOutFile,stockNumber,description,cost,price,quantityInStock);
	  }
  }
 myOutFile.close();

 } // end of main

 void openFile (ofstream& myOutFile)
 {
 char myFileName [100];
 cout<<"File name?";
 cin.getline (myFileName,100,'\n');
 	if (strlen(myFileName) == 0)
 	{
 		strcpy(myFileName,"stock.dat");
 	}
 	else if (!strstr(myFileName,"." ))
 	{
 		strcat(myFileName,".dat");
 	}
 myOutFile.open(myFileName);
    while(myOutFile.fail())
    {
 	   cout<<"Error opening "<<myFileName<< endl;
 	   myOutFile.clear();
 	   cout<<"New filename?";
 	   cin.getline(myFileName,100,'\n');
 	   myOutFile.open(myFileName);
 	   }
}

void getRecordFromUser (char stockNumber[],char description[],float& cost, float& price,int& quantityInStock )
  {
 	 cout<<"Enter stock number?" ;
 	 cin.getline(stockNumber,6,'\n');

 	 if (strlen(stockNumber) != 0)
 	 {

 	 cout<<"Enter description?";
 	 cin.getline(description,20,'\n');


     cout<<"Enter cost?";
	 cin>>cost;
	 cin.ignore(999,'\n');

 	 validateCost(cost);
 	   if ( cost != -999.00 )
 	   {
 	     cout<<"Enter price?";
 	     cin>>price;
 	     cout<<"Enter quantity in stock?";
 	     cin>>quantityInStock;
 	     cin.ignore(999,'\n');
 	  }
  }

}

void validateCost(float& cost)
{

	while((cost>10000.00 || cost<0.00)&& cost!= -999.00)
	{
		cout<<"Illegal Cost!";

		cout<<"Enter cost?";
        cin>>cost;
        cin.ignore(999,'\n');
	}
}

void writeRecord(ofstream& myOutFile,char stockNumber[],char description[],float& cost,float& price,int& quantityInStock)
 {

	myOutFile<<setw(6)<<left<<stockNumber;
	myOutFile<<setw(21)<<left<<description;
	myOutFile<<fixed<<setprecision(2)<< ' ' <<cost;
	myOutFile<<fixed<<setprecision(2)<< ' ' <<price;
	myOutFile<<fixed<< ' ' << quantityInStock<<endl;
}





