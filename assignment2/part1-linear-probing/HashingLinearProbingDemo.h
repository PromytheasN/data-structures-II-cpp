#ifndef HASHINGLINEARPROBINGDEMO_H
#define HASHINGLINEARPROBINGDEMO_H
#include <iostream>
#include <functional>
using namespace std;
class HashingLinearProbingDemo{
private:
    int* hashTable; //Array to store hashtable
    int hashTableSize; //Hashtable size
    int numberOfKeys; //Num of keys stored 
    double loadFactorThreshold; //Load factor threshold for rehashing
public:
    //Default constructor
    HashingLinearProbingDemo(){
        hashTable = nullptr;
        hashTableSize = 0;
        numberOfKeys = 0;
        loadFactorThreshold = 1.0;
    }

    //Parameterized constructor w given table size and threshold
    HashingLinearProbingDemo(int size, double lft){
        hashTableSize = size;
        hashTable = new int[hashTableSize];
        for(int i = 0; i < hashTableSize; i++){
            hashTable[i] = 0;
        }
        numberOfKeys = 0;
        loadFactorThreshold = lft;
    }

    //Insert value into hash table if not 0
    void Insert(int value){

        //Check if vallue equals 0
        if(value == 0){
            cout << "0 not allowed\n";
            return;
        }

        //Check if value already exists in hashtable
        if(!Search(value)){
            //Calculate load factor
            double currentLoadFactor = (double)(numberOfKeys + 1) / hashTableSize;
            if(currentLoadFactor > loadFactorThreshold){ //If current load factor > threshold, rehash
                ReHash();
            }

            int index = LinearProbe(value); //Find an empty spot in hashtable

            if(index != -1){
                //Insert value in hashtable
                hashTable[index] = value;
                numberOfKeys++; //Increment keys total number
            }else{
                cout <<"Hash table is full." << endl;
            }
        }
        else{
            cout << value << " already exists!" << endl;
        }
    }

    //Perform linear probing
    int LinearProbe(int value){
        hash<int> builtInHashFunction; //Initialize hash function to hash integers
        int hashCode = builtInHashFunction(value); //Initialize and store hash code for given value
        int hashTableIndex = hashCode % hashTableSize; //Map hashcode within hashtable size
        int originalIndex = hashTableIndex; //Keep truck of original index

        //Use linear probing to resolve collision
        //Loop until finding an empty slot or until finding the target value
        while(hashTable[hashTableIndex] != 0 && hashTable[hashTableIndex] != value){
            hashTableIndex = (hashTableIndex + 1) % hashTableSize; //Move to next index

            //Check if we looped throughout the whole hashmap
            if(hashTableIndex == originalIndex){
                cout << "Table is full or value not found" << endl;
                return -1;
            }
        }
        //Return empty slot index
        return hashTableIndex;
    }

    //Delete value from hashtable if it exists,
    //set value to 0 to signify delete.
    void Delete(int value){
        //Check if vallue equals 0
        if(value == 0){
            cout << "0 not allowed\n";
            return;
        }

        //Search for value using linear probing
        int index = LinearProbe(value);

        //If found, set value to 0
        if(index != -1 && hashTable[index] == value){
            hashTable[index] = 0; //Set value found to 0
            numberOfKeys--; //Decrease total num of keys
            cout << value << " deleted from the hash table." << endl;
        }
        else{
            //If value not found
            cout << value << " value not found in the hash table." << endl;
        }
    }

    //ReHash to increase size of hash table and transfer data to new table
    void ReHash(){

        int* oldHashTable = hashTable; //Create pointer for current hash table
        int oldHashTableSize = hashTableSize; //Store old hashtable size

        hashTableSize = 2 * oldHashTableSize; //Douple up the old hashTableSize
        hashTable = new int[hashTableSize]; //Initialize new hash table
        
        //Populate new hash table
        for(int i = 0; i < hashTableSize; i++){
            hashTable[i] = 0;
        }
        numberOfKeys = 0; //Reset key numbers

        //Insert values from old to new hash table
        for(int i = 0; i < oldHashTableSize; i++){
            if(oldHashTable[i] != 0){
              Insert(oldHashTable[i]); //Copy values from original to new hashtable using built-in hash from Insert function  
            }
        }
        delete[] oldHashTable; //Delete old hash table
    }

    bool Search(int value){
        int index = LinearProbe(value); //Find the value
        return (index != -1 && hashTable[index] == value); //Return true if value is found
    }

    //Display hashtable, table size, number of keys, current load, and load factor threshold
    void Display(){

        cout << "Current table size: " << hashTableSize 
            << ". Number of keys: " << numberOfKeys 
            << ". Current Load: " << (double)numberOfKeys/hashTableSize 
            << ". Load factor threshold: " 
            << loadFactorThreshold << ". " << endl;

        //Display hash table
        for(int i = 0; i < hashTableSize; i++){
            cout << "[" << i << "] " << hashTable[i] << endl;
        }
    }

    //Destructor 
    ~HashingLinearProbingDemo(){
        delete[] hashTable;
    }

};
#endif