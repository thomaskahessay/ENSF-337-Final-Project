//
//  hydro.hpp
//  Exercise C
//
//  Created by Thomas Kahessay on 2019-06-15.
//  Copyright © 2019 Thomas Kahessay. All rights reserved.
//

#ifndef hydro_h
#define hydro_h

#include <stdio.h>
#include "list.h"
#include <fstream>

void displayHeader();
int readData(FlowList&);
int menu();
void display(FlowList&);
int addData(FlowList&);
int removeData(FlowList&);
double average(FlowList&);
double median(FlowList&);
void saveData(FlowList&);
void pressEnter();

#endif /* hydro_h */
