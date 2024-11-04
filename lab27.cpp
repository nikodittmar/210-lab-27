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
    // declarations
    map<string, tuple<int, string, string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    villagerColors["Raymond"] = {"Black", "Gray", "White"};
    villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

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
    cout << "Friendship level: ";
    int level = getInt(0, 10);
    cout << "Species: ";
    string species;
    cin >> species;
    cout << "Catchphrase: ";
    string catchphrase;
    cin >> catchphrase;

    villagerData->insert({name, {level, species, catchphrase}});
    cout << name << " added." << endl;
}

void deleteVillager(map<string, tuple<int, string, string>> *villagerData) {

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