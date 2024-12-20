// main.cpp

#include <iostream>
#include "chain.h"
#include "xcept.h"

using namespace std;

int main() {
    try {
        Chain<int> L;
        cout << "Length = " << L.Length() << endl;
        cout << "IsEmpty = " << L.IsEmpty() << endl;

        L.Insert(0, 2).Insert(1, 6).Insert(2, 100).Insert(3, 4);
        cout << "List is " << L << endl;
        cout << "IsEmpty = " << L.IsEmpty() << endl;

        int z;
        L.Find(1, z);
        cout << "First element is " << z << endl;

        // Find the maximum value
        ChainNode<int>* maxNode = L.Max();
        if (maxNode) {
            cout << "Maximum value is " << maxNode->getData() << endl; // استخدام الدالة
        }
        else {
            cout << "The list is empty!" << endl;
        }

        cout << "Length = " << L.Length() << endl;
        L.Delete(1, z);
        cout << "Deleted element is " << z << endl;
        cout << "List is " << L << endl;
    }
    catch (const OutOfBounds& e) {
        cerr << "OutOfBounds exception: " << e.what() << endl;
    }
    catch (const NoMem& e) {
        cerr << "NoMem exception: " << e.what() << endl;
    }

    return 0;
}


/*
output :
Length = 0
IsEmpty = 1
List is 2  6  100  4
IsEmpty = 0
First element is 2
Maximum value is 100
Length = 3
Deleted element is 2
List is 6  100  4

*/