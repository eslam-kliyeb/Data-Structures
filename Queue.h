//
// Created by win on 10/31/2024.
//

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H
#include "NodeTwoPtr.h"
using namespace std;
template<class type>
class Queue{
private:
    NodeTwoPtr<type>* head;
    NodeTwoPtr<type>* tail;
    int length;
public:
    Queue(){
        head=tail=nullptr;
        length=0;
    }
    ~Queue(){
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
    void push(type value){
        if(empty()){
            head=tail=new NodeTwoPtr<type>(nullptr,value, nullptr);
            length++;
            return;
        }
        tail=tail->next=new NodeTwoPtr<type>(tail,value, nullptr);
        length++;
    }
    void pop(){
        if(empty())return;
        else if(head->next== nullptr){
            delete head;
            tail=head= nullptr;
        }
        else {
            auto temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        length--;
    }
    type& front(){return head->value;}
    type& back(){return tail->value;}
};
#endif //DATA_STRUCTURES_QUEUE_H
