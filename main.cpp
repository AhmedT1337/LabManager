#include "Equipment.cpp"
#include "LabManager.cpp"
#include <cstdlib>


int main()
{
    LabManager lab;
    lab.loadFromFile();
    while (true){
        std::cout << "Hello, Welcome to Lab Manager!\n";
        std::cout << "Choose what you want to do\n";
        int swtch{};
        std::cout << "1. add new equipment\n";
        std::cout << "2. display all \n";
        std::cout << "3. search with ID \n";
        std::cout << "4. Borrow a piece\n";
        std::cout << "5. return a piece\n";
        std::cout << "6. quit the program\n";
        std::cin >> swtch;
        switch (swtch)
        {
        case 1:
            {
            std::string ID{};
            std::string name{};
            std::string category{};
            std::string status{};
            std::cout << "Ok, Enter ID: ";
            std::cin >> ID;
            std::cout << "Ok, Enter name: ";
            std::cin >> name;
            std::cout << "Ok, Enter category[Microcontroller, POWERDEVICE, Electronics, MOTOR, Connector]: ";
            std::cin >> category;
            std::cout << "Ok, Enter Status [Available, Borrowed, UnderMaintenance, Damaged]: ";
            std::cin >> status;
            lab.addEquipment(ID, name, stringToCategory(category), stringToStatus(status));
            lab.saveToFile();
            std::cout << "Added!\n";
            }
            break;
        case 2:
            lab.displayAll();
            break;
        case 3:
            {
                std::string ID;
                std::cout << "Enter ID: ";
                std::cin >> ID;
                lab.searchById(ID);
            }
            break;
        case 4:
            {
                std::string ID;
                std::string who;
                std::cout << "Enter ID: ";
                std::cin >> ID;
                std::cout << "Enter who's borrowing it: ";
                std::cin >> who;
                lab.borrowEquipment(ID, who);
                lab.saveToFile();
            }
            break;
        case 5:
            {
                std::string ID;
                std::cout << "Enter the ID of the borrowed piece:";
                std::cin>>ID;
                lab.returnAnItem(ID);
                lab.saveToFile();
            }
            break;
        case 6:
            lab.saveToFile();
            std::exit(0);
            break;
        default:
            continue;
            break;
        }
    }
    

}