//
// Created by win on 9/9/2024.
//

#ifndef DATA_STRUCTURES_SLL_H
#define DATA_STRUCTURES_SLL_H
#include "Node.h"
using namespace std;
template<class type>
class SLL {
private:
    Node<type>* head;
    int length;
public:
    SLL(){
        head=nullptr;
        length=0;
    }
   ~SLL(){
        while (!empty()){
            pop_front();
        }
    }
   type& operator[](int rank){
        auto temp = head;
        for(int i=0;i<rank;i++){
            temp=temp->next;
        }
       return temp->value;
    }
   int size(){
       return length;
   }
   bool empty(){
       return head==nullptr;
   }
   void push_front(type value){ // o(1)
        head=new Node<type>(head,value);
        length++;
    }
   void push_back(type value){
       if(empty()){
            push_front(value);
            return;
       }
       auto temp=head;
       while (temp->next!= nullptr){
           temp= temp->next;
       }
       temp->next=new Node<type>(nullptr,value);
       length++;
   }
   void pop_front(){
        if(empty())return;
        auto temp=head;
        head=head->next;
        delete temp;
        length--;
    }
   void pop_back(){
       if(empty()){
            return;
       }
       if (head->next==nullptr){
           pop_front();
           return;
       }
       auto temp=head;
       while (temp->next->next!= nullptr){
           temp= temp->next;
       }
       delete temp->next;
       temp->next= nullptr;
       length--;
   }
   void push_after(int position,type value){
        if(position>length){
            return;
        }
        auto temp=head;
        for(int i=0;i<position;i++){
            temp=temp->next;
        }
        temp->next=new Node<type>(temp->next,value);
        length++;
   }
   void push_at(int position,type value){
        if(position>length) return;
        if(position==0){push_front(value);return;}
        auto temp=head;
        for(int i=0;i<position-1;i++){
            temp=temp->next;
        }
        temp->next=new Node<type>(temp->next,value);
        length++;
    }
   void pop_at(int position){
        if(position>length||empty()) return;
        if(position==0){pop_front();return;}
        auto temp=head;
        for(int i=0;i<position-1;i++){
            temp=temp->next;
        }
        auto del_node=temp->next;
        temp->next=temp->next->next;
        delete del_node;
        length--;
    }
   Node<type>* begin(){return head;}
   Node<type>* end(){return nullptr;}
   class iterator{
   public:
        Node<type>* move;
        void operator=(Node<type>* temp){
            move=temp;
        }
        bool operator!=(Node<type>* temp){
            return (move!=temp);
        }
       bool operator==(Node<type>* temp){
           return move==temp;
       }
        void operator++(int){
            move = move->next;
        }
       void operator++(){
           move = move->next;
       }
        type operator*(){
            return move->value;
        }
       type operator*(int){
           return move->value;
       }
       Node<type>* operator+(int place) {
           for (int i = 1; i <= place; i++) {
               move = move->next;
           }
           return move;
       }

    };
};


#endif //DATA_STRUCTURES_SLL_H
