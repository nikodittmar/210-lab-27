// COMSC 210 | Lab 27 | Niko Dittmar
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int mainMenu();
void printVillagerData(map<string, tuple<int, string, string>>*);
void addVillager(map<string, tuple<int, string, string>>*);
void deleteVillager(map<string, tuple<int, string, string>>*);
void increaseFriendship(map<string, tuple<int, string, string>>*);
void decreaseFriendship(map<string, tuple<int, string, string>>*);
void searchForVillager(map<string, tuple<int, string, string>>*);
int getInt(int, int);

int main() {

    map<string, tuple<int, string, string>> villagerData;

    int input = mainMenu();
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
        cout << endl;
        printVillagerData(&villagerData);
        cout << endl;
        input = mainMenu();
    }


    return 0;
}

// mainMenu() presents the user the possible options and receives their response.
// arguments: none
// returns: the users choice.
int mainMenu() {
    cout << "1. Add Villager" << endl;
    cout << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
    return getInt(1, 6);
}

// printVillagerData() prints the villager data to the console.
// arguments: the villager data to print.
// returns: none
void printVillagerData(map<string, tuple<int, string, string>> *villagerData) {
    cout << "Villager details:" << endl;
    for (auto villager : *villagerData) {
        cout << villager.first << " [" << get<0>(villager.second) << ", " << get<1>(villager.second) << ", " << get<2>(villager.second) << "]" << endl;
    }
}

// addVillager() Adds a villager to the villager map.
// arguments: the villager map to add a villager to.
// returns: none
void addVillager(map<string, tuple<int, string, string>> *villagerData) {
    cout << "Villager name: ";
    string name;
    cin >> name;
    cout << "Friendship level: ";
    int level = getInt(0, 10);
    cout << "Species: ";
    string species;
    cin >> species;
    cout << "Catchphrase: ";
    string catchphrase;
    cin >> catchphrase;

    villagerData->insert({name, {level, species, catchphrase}});
    cout << endl << name << " added." << endl;
}

// deleteVillager() deletes a villager from the villager map.
// arguments: the villager map to delete a villager from.
// returns: none
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

// increaseFriendship() increments the friendship level villager for a villager in the villager map.
// arguments: the villager map with the villager to increment friendship level.
// returns: none
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

// decreaseFriendship() decrements the friendship level villager for a villager in the villager map.
// arguments: the villager map with the villager to decrement friendship level.
// returns: none
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
        get<0>(it->second) -= 1;
        cout << endl << toDecrease << " friendship was decreased." << endl;
    } else {
        cout << endl << toDecrease << " friendship is already at it max!" << endl;
    }
}

// searchForVillager() finds and prints a villager in the villager map
// arguments: the villager map to search from.
// returns: none
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

// getInt() gets an integer input from the user within a certain range.
// arguments: minimum and maximum value to get.
// returns: the number inputted.
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