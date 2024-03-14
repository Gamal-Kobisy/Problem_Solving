#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;


int main()
{
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    int key, first = 0, mid, last = (sizeof data)/4;
    bool found =  false;

    cout << "Please enter a number to search for: ";
    cin >> key;

    for (int i: data) {
        cout << setw(4) << i ;
    }

    cout << endl << setw(2 + 4 * (sizeof data)/4) << setfill('-') << "\n";
    cout << setfill(' ');

    while (first <= last) {
        // Get middle index
        mid = (first + last) / 2;

        cout << setw (first * 4) << "";
        for (int i = first; i < last; i++){
            cout << setw(4) << data[i] ;
        }
        cout << endl;

        // Is the middle the required key?
        if (data[mid] == key) {
            found = true;
            break;
        }

            // If key is in the smaller half
        else if (key < data[mid]) {
            last = mid - 1;
        }

            // If key is in bigger half
        else {
            first = mid + 1;
        }
    }
    if (found) {
        cout << "\nFound " << key << " at " << mid << endl;
    }
    else {
        cout << "\nNot found \n";
    }
}