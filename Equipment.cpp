#pragma once
#include <iostream>
#include "Equipment.h"

void Equipment::Display(){
    std::cout << "[" << this->id << "] " << this->name
    << " | Category: " << CategoryToString[category] <<
     " | Status: " << StatusToString[status] << " | BorrowerName: " << 
    borrowerName << "\n";
}

bool Equipment::Borrow(std::string forWhom){
    if (status == Status::Borrowed){
        std::cout << "Can't Borrow This piece, it's borrowed wait..\n";
        return false;
    }
    this->borrowerName = forWhom;
    this->status = Status::Borrowed;
    return true;
}

void Equipment::returnThisItem(){
    
    if (status == Status::Borrowed){
        this->status = Status::Available;
        this->borrowerName = "";
    }
}