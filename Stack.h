//
// Created by win on 10/31/2024.
//

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H
#include "Node.h"
using namespace std;
template<class type>
class Stack{
private:
    Node<type>* head;
    int length;
public:
    Stack(){
        head= nullptr;
        length=0;
    }
    ~Stack(){
        while (!empty()){
            pop();
        }
    }
    int size(){
        return length;
    }
    bool empty(){
        return head==nullptr;
    }
    void pop(){
        if(empty()) return;
        auto temp=head;
        head=head->next;
        delete temp;
        length--;
    }
    void push(type value){
        head=new Node<type>(head,value);
        length++;
    }
    type& top(){return head->value;}

};
#endif //DATA_STRUCTURES_STACK_H
