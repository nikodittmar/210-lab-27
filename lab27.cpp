#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int mainMenu();
void addVillager();
void deleteVillager();
void increaseFriendship();
void decreaseFriendship();
void searchForVillager();
int getInt(int min, int max);

int main() {

    map<string, tuple<int, string, string>> villagerData;

    int input = main_menu();
    while (input != 6) {
        switch(input) {
            case 1:
                addVillager(&villagerData);
                break;
            case 2:
                deleteVillager(&villagerData);
                break;
            case 3:
                increaseFriendship(&villagerData);
                break;
            case 4:
                decreaseFriendship(&villagerData);
                break;
            case 5:
                searchForVillager(&villagerData);
                break;
        }
    }


    return 0;
}

int main_menu() {
    cout << "1. Add Villager" << endl;
    cout << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
    return getInt(1, 6);
}

void printVillagerData(map<string, tuple<int, string, string>> *villagerData) {
    cout << "Villager details:" << endl;
    for (auto villager : *villagerData) {
        cout << villager.first << " [" << get<0>(villager.second) << ", " << get<1>(villager.second) << ", " << get<2>(villager.second) << "]" << endl;
    }
}

void addVillager(map<string, tuple<int, string, string>> *villagerData) {
    cout << "Villager name: ";
    string name;
    cin >> name;
    cout << endl << "Friendship level: ";
    int level = getInt(0, 10);
    cout << endl << "Species: ";
    string species;
    cin >> species;
    cout << endl << "Catchphrase: ";
    string catchphrase;
    cin >> catchphrase;

    villagerData->insert({name, {level, species, catchphrase}});
    cout << endl << name << " added." << endl;
}

void deleteVillager(map<string, tuple<int, string, string>> *villagerData) {
    cout << "What is the name of the villager to delete: ";
    string toDelete;
    cin >> toDelete;

    while (villagerData->find(toDelete) == villagerData->end()) {
        cout << endl << "Villager not found! Reenter the villager name: ";
        cin.clear();
        cin.ignore();
        cin >> toDelete;
    }

    villagerData->erase(toDelete);
    cout << endl << toDelete << " was deleted." << endl;
}

void increaseFriendship(map<string, tuple<int, string, string>> *villagerData) {
    cout << "What is the name of the villager to increase friendship: ";
    string toIncrease;
    cin >> toIncrease;

    while (villagerData->find(toIncrease) == villagerData->end()) {
        cout << endl << "Villager not found! Reenter the villager name: ";
        cin.clear();
        cin.ignore();
        cin >> toIncrease;
    }

    auto it = villagerData->find(toIncrease);
    if (get<0>(it->second) < 10) {
        get<0>(it->second) += 1;
        cout << endl << toIncrease << " friendship was increased." << endl;
    } else {
        cout << endl << toIncrease << " friendship is already at it max!" << endl;
    }
}

void decreaseFriendship(map<string, tuple<int, string, string>> *villagerData) {
    cout << "What is the name of the villager to decrease friendship: ";
    string toDecrease;
    cin >> toDecrease;

    while (villagerData->find(toDecrease) == villagerData->end()) {
        cout << endl << "Villager not found! Reenter the villager name: ";
        cin.clear();
        cin.ignore();
        cin >> toDecrease;
    }

    auto it = villagerData->find(toDecrease);
    if (get<0>(it->second) < 10) {
        get<0>(it->second) += 1;
        cout << endl << toDecrease << " friendship was decreased." << endl;
    } else {
        cout << endl << toDecrease << " friendship is already at it max!" << endl;
    }
}

void searchForVillager(map<string, tuple<int, string, string>> *villagerData) {
    cout << "Enter the name of the villager to search for: ";
    string searchKey;
    cin >> searchKey;
    auto it = villagerData->find(searchKey);
    if (it == villagerData->end()) {
        cout << endl << "Villager not found!" << endl;
    } else {
        cout << endl << it->first << " [" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
    }
}

int getInt(int min, int max) {
    int input;
    cin >> input;
    while (input > max || input < min) {
        cout << "Invalid input! Please try again: ";
        cin.clear();
        cin.ignore();
        cin >> input;
    }
    return input;
}