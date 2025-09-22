#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

public:
    BoardArray() {
        array = new Entry[SIZE];
        index = 0;
    }

    void add(Entry* entry) {
        int pos = -1;

        // Para ini sa paghanap san position kun diin ma-insert
        for (int i = 0; i < index; i++) {
            if (entry->compare(&array[i])) {
                pos = i;
                break;
            }
        }

        // Pag array is full kag an entry kay dli valid
        if (index == SIZE && pos == -1) {
            cout << entry->name << "'s score is too low to be added!" << endl;
            return;
        }

        // Insertion sa dulo kun wala na labaw
        if (pos == -1) {
            pos = index;
        }

        // Limitation kun pila na elements an ishishift
        int limit;
        if (index < SIZE) {
            limit = index;
        } else {
            limit = SIZE - 1;
        }

        // Shifting to the right
        for (int i = limit; i > pos; i--) {
            array[i] = array[i - 1];
        }

        // Insert na an bago na entry
        array[pos] = *entry;

        // Increase index
        if (index < SIZE) {
            index++;
        }
    }

    void print() {
        for (int i = 0; i < index; i++) {
            cout << i + 1 << ". ";
            array[i].print();
        }
    }
};
