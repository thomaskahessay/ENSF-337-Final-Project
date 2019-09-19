//
//  list.hpp
//  Exercise C
//
//  Created by Thomas Kahessay on 2019-06-14.
//  Copyright © 2019 Thomas Kahessay. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>

struct  ListItem {
    int year;
    double flow;
};

struct Node {
    ListItem item;
    Node *next;
};

class FlowList
{
public:
    FlowList();
    ~FlowList();
    FlowList (const FlowList&);
    FlowList& operator=(const FlowList&);
    //CONSTRUCTOR, DESTRUCTOR, ETC. GOES HERE
    //...
    const ListItem& getItem() const;
    // REQUIRES: cursorM != NULL.
    //PROMISES: returns the item to which cursorM is attached to 
    void reset();
    //PROMISES: cursorM is equal to headM
    bool isOn() const;
    // PROMISES: returns true if cursorM != NULL, otherwise // returns false
    const Node* cursor()const;
    // PROMISES: returns cursorM.
    void forward();
    // PROMISES: if cursorM != NULL, moves cursorM to the next.
    void insert(const ListItem& itemA);
    // PROMISES: A node with a copy of itemA is added in a way
    // that preserves the non-decreasing order of flows
    // in nodes. Then, sets cursorM to NULL.
    void remove(int target_year);
    // PROMISES: If a node has an item matching the
    // target_year, list is unchanged and gives a clear message // that the target_year (e.g. 2000) Not Found. Otherwise
    // exactly one node with its item.year == itemA.year is
    // removed. Then, sets cursorM to NULL.
    int count ()const;
    // PROMISES: returns the number of nodes in the list.
private:
    // always points to the first node in the list. Node *headM;
    
private:
    // always points to the first node in the list.
    Node *headM;
    // Initially is set to NULL, but it may point to any node.
    Node *cursorM;
    void copy(const FlowList& source);
    void destroy();
    Node* createNode (int year, double flow);
};

#endif /* list_h */
