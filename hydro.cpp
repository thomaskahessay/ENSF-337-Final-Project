//
//  hydro.cpp
//  Exercise C
//
//  Created by Thomas Kahessay on 2019-06-15.
//  Copyright © 2019 Thomas Kahessay. All rights reserved.
//

#include "hydro.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;


void displayHeader()
{
    cout << "HEF Hydropower Studies – Spring 2019" << endl;
    cout << "Program: Flow Studies" << endl;
    cout << "Version: 1.0" << endl;
    cout << "Lab section: B01" << endl;
    cout << "Instructor : Mohammad Moshirpour" << endl;
    cout << "Teaching Assistant: Mehdi Afsar" << endl;
    cout << "Produced by: Thomas Kahessay" << endl << endl;
    pressEnter();
}

int readData(FlowList& source)
{
    int i = 0;
    ifstream file;
    file.open("flow.txt");
    if(!file.is_open())
    {
        cout << "Error reading file..." << endl;
        exit(1);
    }
    while(1)
    {
        ListItem item;
        file >> item.year;
        file >> item.flow;
        if(file.eof())
            break;
        source.insert(item);
        i++;
    }
    file.close();
    return i;
}

int menu()
{
    int choice = 0;
    cout << "Please select one of the following operations: " << endl;
    cout << "   1. Display flow list, average and median." << endl;
    cout << "   2. Add data." << endl;
    cout << "   3. Save data into the file." << endl;
    cout << "   4. Remove data." << endl;
    cout << "   5. Quit" << endl;
    cout << "   Enter your choice (1, 2, 3, 4, of 5): ";
    cin >> choice;
    cout << endl;
    return choice;
}

void display(FlowList& source)
{
    cout << "Year           " << "Flow (in billions of cubic meters" << endl;
    cout << "----           " << "---------------------------------" << endl;
    source.reset();
    while(source.isOn())
    {
        cout << source.getItem().year << "           " << source.getItem().flow << endl;
        source.forward();
    }
    cout << "The annual average of the flow is: " << average(source) << " million cubic meters" << endl;
    cout << "The median flow is: " << median(source) << " million cubic meters" << endl;
}

int addData(FlowList &source)
{
    ListItem temp;
    cout << "Please enter a year: ";
    cin >> temp.year;
    cout << "Please enter the flow: ";
    cin >> temp.flow;
    
    source.reset();
    while(source.isOn())
    {
        if(source.getItem().year == temp.year && source.getItem().flow == temp.flow)
        {
            cout << "Error: duplicate data" << endl;
            return 0;
        }
        source.forward();
    }
    source.reset();
    source.insert(temp);
    cout << "New record inserted successfully" << endl;
    return 1;
}

int removeData(FlowList &source)
{
    int target;
    cout << "Please enter the year you want to remove: ";
    cin >> target;
    cout << endl;
    
    source.reset();
    while(source.isOn())
    {
        if(source.getItem().year == target)
        {
            source.remove(target);
            return -1;
        }
        source.forward();
    }
    cout << "Error: No such data" << endl;
    return 0;
}

double average(FlowList &source)
{
    int numRecords = 0;
    double totalFlow = 0;
    source.reset();
    while(source.isOn())
    {
        totalFlow += source.getItem().flow;
        numRecords++;
        source.forward();
    }
    return (totalFlow/numRecords);
}

double median(FlowList &source)
{
    int i = 0;
    int count = 0;
    source.reset();
    while(source.cursor() != 0)
    {
        i++;
        source.forward();
    }
    source.reset();
    if(i %2 != 0)
    {
        while(count != i/2)
        {
            count++;
            source.forward();
        }
        return source.getItem().flow;
    }
    if(i%2 == 0)
    {
        while(count != i/2-1)
        {
            count++;
            source.forward();
        }
        double before = source.getItem().flow;
        source.forward();
        double after = source.getItem().flow;
        return (before +after)/2;
    }
    return 0;
}

void saveData(FlowList &source)
{
    ofstream output;
    output.open("flow.txt");
    source.reset();
    while(source.isOn())
    {
        output << source.getItem().year;
        output << setw(15) << source.getItem().flow << endl;
        source.forward();
    }
    output.close();
    cout << "The data was saved." << endl;
}

void pressEnter()
{
    cout << "<<< Press Enter to Continue >>>" << endl;
    cin.ignore();
    cin.get();
}
