#include "LabManager.h"
#include "Equipment.cpp"
#include <fstream>
#include <sstream>

void LabManager::addEquipment(std::string id, std::string name, 
    EquipmentCategory category, Status status){
        Equipment* eqi {new Equipment{id, name, category, status}};
        Equipments.push_back(eqi);
    }

void LabManager::displayAll(){
    int i{};
    for (auto e: Equipments){
        std::cout << "[" << i << "] " ;
        e->Display();
        ++i;
    }
}

Equipment* LabManager::searchById(std::string Id)
{
    for (auto e: Equipments){
        if (e->id == Id){
            e->Display();
            return e;
        }
    }
    std::cout << "Not found\n";
    return nullptr;
}

bool LabManager::borrowEquipment(std::string Id, std::string Bname){
    Equipment* piece {searchById(Id)};
    if (piece != nullptr){
        bool s{piece->Borrow(Bname)};
        return s;
    }
    return false;
}

void LabManager::saveToFile(){
    std::ofstream file("inventory.csv");
    if (!file.is_open()){
        std::cout << "Error opening file!\n";
        return;
    }
    file << "ID,name,category,status,borrower\n";
    for (auto e: Equipments){
        file << e->id << "," << e->name << "," << CategoryToString[e->category] 
        << "," << StatusToString[e->status] << "," << e->borrowerName << "\n";
    }
    file.close();
    std::cout << ">> Data saved to inventory.csv successfully!\n";
}

void LabManager::loadFromFile()
{
    std::ifstream file("inventory.csv");
    if (!file.is_open()){
        std::cout << "Error opening file!\n";
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)){
        if(line.empty()){
            continue;
        }
        std::stringstream ss(line);
        std::string Id, name, category, status, borrower;
        std::getline(ss, Id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, category, ',');
        std::getline(ss, status, ',');
        std::getline(ss, borrower, ',');
        
        Equipment* eq{new Equipment{Id, name, stringToCategory(category), stringToStatus(status)}};
        eq->borrowerName = borrower;
        
        Equipments.push_back(eq);
    }
    std::cout << ">> Data loaded from inventory.csv successfully!\n";
}

void LabManager::returnAnItem(std::string Id)
{
    Equipment* piece {searchById(Id)};
    if (piece != nullptr){
        piece->returnThisItem();
        std::cout << "Item returned successfully!\n";
        return;
    }
    std::cout << "This item is not currently borrowed!\n";
}