/*
 John Abendroth
 Hash Table Lab
*/

#include <iostream>
using namespace std;

class HashTable{
public:
    int hash_arr[27];
    int Hash(int x);
    void AddHash(int x);
    int search(int x);
    HashTable(){
        for(int i = 0; i < 27; i++)
            hash_arr[i] = 0;
    };
};

int HashTable::Hash(int input){
    return input % 27;
}

void HashTable::AddHash(int input){
    int count = 0;
    int hash_val = Hash(input);

    while(count < 27)
    {
        if (hash_arr[hash_val] == 0)
        {
            hash_arr[hash_val] = input;
            break;
        }
        else
        {
            hash_val = (hash_val + 1) % 27;
            count ++;
        }
    }
}

int HashTable::search(int input){
    int count = 0;
    int hash_val = Hash(input);

    while (count < 27)
    {
        if (hash_arr[hash_val] == input)
            return input;
        else
        {
            hash_val = (hash_val + 1) % 27;
            count ++;
        }
    }
    return -1;
}

int main(){
    int test = 0, test2, input;
    HashTable H;

    while (test != -1)
    {
        cout << "Enter number to add to hash table: " << endl;
        cin >> input;

        H.AddHash(input);

        cout << "Enter -1 to stop or anything else to continue adding numbers: " << endl;
        cin >> test;
    }

    test = 0;

    while (test != -1)
    {
        cout << "Enter number to search hash table for: " << endl;
        cin >> input;

        test2 = H.search(input);

        if (test2 == -1)
            cout << input << " does not exist in the table" << endl;
        else
            cout << "Found!" << endl;

        cout << "Enter -1 to stop or anything else to continue searching numbers: " << endl;
        cin >> test;
    }
}
