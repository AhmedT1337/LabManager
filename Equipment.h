#pragma once
#include <string>
#include <map>

enum class EquipmentCategory{
    Microcontroller,
    PowerDevice,
    Electronics,
    Motor,
    Connector
};

enum class Status{
    Available,
    Borrowed,
    UnderMaintenance,
    Damaged
};

inline std::map<EquipmentCategory, std::string> CategoryToString = {
    {EquipmentCategory::Connector, "Connector"},
    {EquipmentCategory::Electronics, "Electronics"},
    {EquipmentCategory::Microcontroller, "Microcontroller"},
    {EquipmentCategory::Motor, "Motor"},
    {EquipmentCategory::PowerDevice, "PowerDevice"},
};

inline std::map<Status, std::string> StatusToString = {
    {Status::Available, "Available"},
    {Status::Borrowed, "Borrowed"},
    {Status::Damaged, "Damaged"},
    {Status::UnderMaintenance, "In Maintenance"}
};

inline EquipmentCategory stringToCategory(std::string category){
    if (category == "Microcontroller"){
        return EquipmentCategory::Microcontroller;
    } else if (category == "PowerDevice"){
        return EquipmentCategory::PowerDevice;
    } else if (category == "Electronics"){
        return EquipmentCategory::Electronics;
    } else if (category == "Motor"){
        return EquipmentCategory::Motor;
    }else if (category == "Connector"){
        return EquipmentCategory::Connector;
    }
    else{
        return EquipmentCategory::Electronics;
    }
}

inline Status stringToStatus(std::string status){
    if (status == "Available")
    {
        return Status::Available;
    } else if (status == "Borrowed"){
        return Status::Borrowed;
    } else if (status == "Damaged"){
        return Status::Damaged;
    } else if (status == "UnderMaintenance"){
        return Status::UnderMaintenance;
    } else {
        return Status::Available;
    }
}

class Equipment{
    public:
    std::string id;
    std::string name;
    EquipmentCategory category;
    Status status;
    std::string borrowerName;
    
    Equipment(std::string id_, std::string name_, EquipmentCategory cat, Status stat)
    : id{id_}, name{name_}, category{cat}, status{stat}
    {
    }
    void returnThisItem();
    void Display();
    bool Borrow(std::string forWhom);
};