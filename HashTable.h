//
// Created by win on 11/22/2024.
//

#ifndef DATA_STRUCTURES_HASHTABLE_H
#define DATA_STRUCTURES_HASHTABLE_H
using namespace std;
class NodeHash {
public:
    int key;
    int value;
    NodeHash* next;
    NodeHash(int key,int value,NodeHash* next) : key(key),value(value),next(next){
    }
};
class LinkedListHash{
private:
    NodeHash* head;
    int length;
    void pop(){
        if(empty())return;
        auto temp=head;
        head=head->next;
        delete temp;
        length--;
    }
    int size(){
        return length;
    }
    bool empty(){
        return head==nullptr;
    }
public:
    LinkedListHash(){
        head=nullptr;
        length=0;
    }
    ~LinkedListHash(){
        while (!empty()){
            pop();
        }
    }

    int get(int key)
    {
        if(empty()) {
            return -1;
        }
        auto temp=head;
        while(temp!= nullptr&&temp->key!=key){
            temp=temp->next;
        }
        return temp == nullptr ? -1 : temp->value;
    }
    void put(int key, int value)
    {
        if(empty()) {
            head = new NodeHash(key,value, nullptr);
            length++;
            return;
        }
        auto temp=head;
        while(temp->next!= nullptr&&temp->key!=key){
            temp=temp->next;
        }
        if(temp->next == nullptr){
            temp->next=new NodeHash(key,value, nullptr);
        }
        else{
            temp->value=value;
        }
        length++;
    }
    void remove(int key)
    {
        if(empty()){
            return;
        }
        if(size()==1){
            auto del_node=head;
            head = nullptr;
            delete del_node;
            length--;
            return;
        }
        auto temp=head;
        while(temp->next!= nullptr&&temp->next->key!=key){
            temp=temp->next;
        }
        auto del_node=temp->next;
        temp->next=temp->next->next;
        delete del_node;
        length--;
    }



};
const int TABLE_SIZE = 128;
class HashTable{
private:
    LinkedListHash **table;
    int hash(int key){
     return (key % TABLE_SIZE);
    }
public:
    HashTable(){
        table = new LinkedListHash*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] =  new LinkedListHash();
    }
    int find(int key)
    {
        return table[hash(key)]->get(key);
    }
    void put(int key, int value)
    {
        table[hash(key)]->put(key,value);
    }
    void remove(int key)
    {
        table[hash(key)]->remove(key);
    }
    ~HashTable(){
        for (int i = 0; i < TABLE_SIZE; i++) {
            delete table[i];
        }
        delete[] table;
    }

};
#endif //DATA_STRUCTURES_HASHTABLE_H
