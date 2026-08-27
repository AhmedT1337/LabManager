#pragma once
#include "Equipment.h"
#include <vector>

class LabManager
{
    public:
    std::vector<Equipment*> Equipments{};
    void addEquipment(std::string id, std::string name, 
    EquipmentCategory category, Status status);
    void displayAll();
    Equipment* searchById(std::string Id);
    bool borrowEquipment(std::string Id, std::string Bname);
    void saveToFile();
    void loadFromFile();
    ~LabManager() {
    for (auto eq : Equipments) {
        delete eq;
    }
    Equipments.clear();
    }
    void returnAnItem(std::string Id);
    LabManager(const LabManager&) = delete;
    LabManager& operator=(const LabManager&) = delete;
};

