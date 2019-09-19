//
//  list.cpp
//  Exercise C
//
//  Created by Thomas Kahessay on 2019-06-14.
//  Copyright © 2019 Thomas Kahessay. All rights reserved.
//

#include "list.h"
#include <stdio.h>
#include <iostream>
#include <assert.h>
using namespace std;

FlowList::FlowList()
{
    headM = 0;
    cursorM = 0;
}

FlowList::~FlowList()
{
    destroy();
}

FlowList::FlowList (const FlowList &source)
{
    copy(source);
}

FlowList& FlowList::operator=(const FlowList& rhs)
{
    if (this != &rhs)
    {
        destroy();
        copy(rhs);
    }
    return *this;
}
//CONSTRUCTOR, DESTRUCTOR, ETC. GOES HERE
//...

const ListItem& FlowList::getItem() const
{
    assert(cursorM != 0);
    return cursorM->item;
}
// REQUIRES: cursorM != NULL.
//PROMISES: returns the item to which cursorM is attached to

void FlowList::reset()
{
    cursorM = headM;
}
//PROMISES: cursorM is equal to headM

bool FlowList::isOn() const
{
    if(cursorM != 0)
        return true;
    return false;
}
// PROMISES: returns true if cursorM != NULL, otherwise // returns false

const Node* FlowList::cursor()const
{
    return cursorM;
}
// PROMISES: returns cursorM.

void FlowList::forward()
{
    if(isOn())
        cursorM = cursorM->next;
    else
        cursorM = 0;
}
// PROMISES: if cursorM != NULL, moves cursorM to the next.

void FlowList::insert(const ListItem& itemA)
{
    Node *temp = createNode(itemA.year, itemA.flow);
    if(headM == 0 || itemA.flow <= headM ->item.flow)
    {
        temp -> next = headM;
        headM = temp;
    }
    else
    {
        Node * before = headM;
        Node *after = headM -> next;
        
        while(after != 0 && itemA.flow > after -> item.flow)
        {
            before = after;
            after = after -> next;
        }
        temp -> next = after;
        before -> next = temp;
    }
    cursorM = 0;
}
// PROMISES: A node with a copy of itemA is added in a way
// that preserves the non-decreasing order of flows
// in nodes. Then, sets cursorM to NULL.

void FlowList::remove(int target_year)
{
    reset();
    Node *remove = 0;
    Node *before = headM;
    Node *after  = headM ->next;
    
    if(target_year == headM->item.year)
    {
        remove = headM;
        headM = remove ->next;
    }
    
    else
    {
        while(after != 0 )
        {
            if(target_year == after ->item.year)
            {
                remove = after;
                break;
            }
            before = after;
            after = after -> next;
        }
    }
    if(remove == 0)
    {
        cout << "The target year (" << target_year << ") was not found." << endl;
        return;
    }
    cout << "Record was successfully removed." << endl;
    delete remove;
    before -> next = after -> next;
    cursorM = 0;
}
// PROMISES: If a node has an item matching the
// target_year, list is unchanged and gives a clear message // that the target_year (e.g. 2000) Not Found. Otherwise
// exactly one node with its item.year == itemA.year is
// removed. Then, sets cursorM to NULL.

int FlowList::count()const
{
    int length = 0;
    Node *temp = headM;
    if(headM == 0)
        return length;
    while(temp->next != 0)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
// PROMISES: returns the number of nodes in the list.

void FlowList::copy(const FlowList& source)
{
    headM = createNode(source.headM->item.year, source.headM->item.flow);
    Node* sourceCursor = source.headM->next;
    Node* thisCursor = headM;
    
    while (sourceCursor != 0)
    {
        Node *temp = createNode(sourceCursor->item.year, sourceCursor->item.flow);
        thisCursor->next = temp;
        sourceCursor = sourceCursor->next;
        thisCursor = thisCursor->next;
    }
}

void FlowList::destroy()
{
    if (headM == 0)
        return;
    while (headM != 0)
    {
        if (headM->next == 0)
        {
            delete headM;
            headM = 0;
        }
        else
        {
            Node *back = headM;
            Node *front = headM ->next;
            while (front->next != 0)
            {
                back = front;
                front = front->next;
                
            }
            delete front;
            back->next = 0;
        }
    }
}

Node* FlowList::createNode (int year, double flow)
{
    Node *temp = new Node;
    temp->item.year = year;
    temp->item.flow = flow;
    temp->next = 0;
    return temp;
}

