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
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT

            for(int i = 0; i < index; i++){
                Entry existing = array[i];
                array[i] = array->compare(entry);
                Entry current = array[i];

                if( > current){

                }


                /*if(array[i.compare] > array[i]){
                    for(int j = index; j > i; j--){
                        array[j] = array[j - 1];
                    }
                    array[i] = *entry;
                }
                */
                
            }
           
            return;
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};