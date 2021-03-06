#include "periodical.h"

/*
Periodical::Periodical()       // Class default constructor
{

}
*/

Periodical::~Periodical()     // Class destructor
{
makeEmpty();
}

LibraryItem* Periodical::createIt() const
{

    Periodical* newPeriodical = new Periodical;
    // assume file initializes as title, month, year
    // sorts from year->month->title
    
    newPeriodical->ArrayOfParameters = new string[3];
    
    newPeriodical->sizeOfArrayOfParameters = 3;
    newPeriodical->CopiesLeft = 1;
newPeriodical->MaxCopies = 1;
    
    newPeriodical->ArrayOfSortingPrio = new string*[3];
    
    newPeriodical->sizeOfArrayOfSortingPrio = 3;

    newPeriodical->ArrayOfSortingPrio[0] = &newPeriodical->ArrayOfParameters[2];
    newPeriodical->ArrayOfSortingPrio[1] = &newPeriodical->ArrayOfParameters[1];
    newPeriodical->ArrayOfSortingPrio[2] = &newPeriodical->ArrayOfParameters[0];


    return newPeriodical;
}

bool Periodical::setData2(ifstream& file){
    file.get();
    string dataOfFile;
    getline(file, dataOfFile, ' ');
    //cout<<"Year: "<<dataOfFile<<"SPACE"<<endl;
    *ArrayOfSortingPrio[0] = dataOfFile;

    
    getline(file, dataOfFile, ' ');
    //cout<<"Month: "<<dataOfFile<<"SPACE"<<endl;
    *ArrayOfSortingPrio[1] = dataOfFile;

    
    getline(file, dataOfFile, ',');
    //cout<<"Title: "<<dataOfFile<<"SPACE"<<endl;
    *ArrayOfSortingPrio[2] = dataOfFile;
 initialize = true;
 
 
 getline(file, dataOfFile);

    return true;


}

//set data should set initialize to true after initializing everything
bool Periodical::setData(ifstream& file) 
{
    
        string TitleOfPeriodical;
        char checkEOL;
checkEOL = file.get();
//if (checkEOL == '\n') return false;
getline(file, TitleOfPeriodical, ',');
//if (TitleOfPeriodical.size() == 0) return false;

ArrayOfParameters[0] = TitleOfPeriodical;
   
// this assumes that rest of line is valid
    

file.get();

        string MonthOfPeriodical;
        getline(file, MonthOfPeriodical,' ');
     //   if (MonthOfPeriodical.size() == 0) return false;
        ArrayOfParameters[1] = MonthOfPeriodical;



string YearOfPeriodical;

file>>YearOfPeriodical;

ArrayOfParameters[2] = YearOfPeriodical;
    initialize = true;
    string clearLine;
    getline(file, clearLine);
    return true;
    
}