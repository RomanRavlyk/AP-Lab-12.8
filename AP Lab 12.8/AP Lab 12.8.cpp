#include <iostream>
#include <fstream>
#include <list>

using namespace std;

void removeEvenNumbers(list<int>& myList) {
    auto it = myList.begin();
    while (it != myList.end()) {
        if (*it % 2 == 0) {
            it = myList.erase(it);
        }
        else {
            ++it;
        }
    }
}

void doubleOddIndexedElements(list<int>& myList) {
    int index = 0;
    for (auto& element : myList) {
        if (index % 2 != 0) {
            element *= 2;
        }
        index++;
    }
}


void insertSublist(list<int>& myList, int position, const list<int>& sublist) {
    auto it = myList.begin();
    advance(it, position);
    myList.insert(it, sublist.begin(), sublist.end());
}

int main() {
    list<int> myList;

    ifstream file("input.txt");
    if (file.is_open()) {
        int num;
        while (file >> num) {
            myList.push_back(num);
        }
        file.close();
    }
    else {
        cout << "Unable to open file!" << endl;
        return 1;
    }

    cout << "Input List:" << endl;
    for (const auto& element : myList) {
        cout << element << " ";
    }
    cout << endl;

    removeEvenNumbers(myList);
    doubleOddIndexedElements(myList);
    list<int> sublist = { 100, 200, 300 };
    int position = 2; 
    insertSublist(myList, position, sublist);

    cout << "Output List:" << endl;
    for (const auto& element : myList) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
