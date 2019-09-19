//
//  main.cpp
//  Exercise C
//
//  Created by Thomas Kahessay on 2019-06-14.
//  Copyright © 2019 Thomas Kahessay. All rights reserved.
//

#include "list.h"
#include "hydro.h"
#include <iostream>
using namespace std;

int main()
{
    FlowList x;
    int numRecords;
    displayHeader();
    numRecords = readData(x);
    int quit =0;
    while(1){
        switch(menu())
        {
            case 1:
                display(x);
                pressEnter();
                break;
            case 2:
                numRecords += addData(x);
                pressEnter();
                break;
            case 3:
                saveData(x);
                pressEnter();
                break;
            case 4:
                removeData(x);
                pressEnter();
                break;
            case 5:
                cout << "\nProgram terminated!\n\n"; quit = 1;
                break;
            default:
                cout << "\nNot a valid input.\n";
        }
        if(quit == 1) break;
    }
    pressEnter();
    // Creating a copy of FlowList x called copy1
    FlowList copy1;
    copy1 = x;
    // In the following section call addData to add // following records (year, flow) to copy1:
    addData(copy1);
    addData(copy1);
    // 2012 459.99
    // 2013 2000.34
    // Use the following code to create a copy of copy1 called copy2 //
    FlowList copy2 = copy1;
    // removing three records from copy2
    copy2.remove(1922);
    copy2.remove(2003);
    copy2.remove(2001);
    // Display the values in three list copy 2, copy1, and x
    cout << "\nValues in copy2 are: " << endl;
    display(copy2);
    cout << "\nValues in copy1 are: " << endl;
    display(copy1);
    cout << "\nValues in x are: " << endl;
    display(x);
    
    return 0;
}
