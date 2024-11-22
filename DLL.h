//
// Created by win on 10/30/2024.
//

#ifndef DATA_STRUCTURES_DLL_H
#define DATA_STRUCTURES_DLL_H
#include "NodeTwoPtr.h"
using namespace std;
template<class type>
class DLL{
private:
    NodeTwoPtr<type>* head;
    NodeTwoPtr<type>* tail;
    int length;
public:
    DLL(){
       head=tail=nullptr;
       length=0;
    }
    ~DLL(){
        while (!empty()){
            pop_front();
        }
    }
    type& operator[](int rank){
        auto temp = head;
        for(int i=1;i<=rank;i++){
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
    NodeTwoPtr<type>* begin(){return head;}
    NodeTwoPtr<type>* end(){return tail;}
    void push_front(type value){ // o(1)
        if(empty()) {
            head = tail = new NodeTwoPtr<type>(nullptr, value, nullptr);
            length++;
            return;
        }
        head = head->prev=new NodeTwoPtr<type>(nullptr,value,head);
        length++;
    }
    void push_back(type value){ // o(1)
        if(empty()){
            head=tail=new NodeTwoPtr<type>(nullptr,value, nullptr);
            length++;
            return;
        }
        tail=tail->next=new NodeTwoPtr<type>(tail,value, nullptr);
        length++;
    }
    void pop_front(){
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
    void pop_back(){
        if(empty())return;
        if (head->next==nullptr){
            pop_front();
            return;
        }
        auto temp=tail;
        tail=tail->prev;
        tail->next= nullptr;
        delete temp;
        length--;
    }
    void pop_inner(int rank){
        if(rank<=0||rank>length||empty()) return;
        if(rank==1){
            pop_front();
            return;
        }
        if(rank==length){
            pop_back();
            return;
        }
        int cnt=0;
        auto temp=head;
        while (cnt!=rank-1){
            temp=temp->next;
            cnt++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
        length--;
    }
    void push_inner(int rank,type value){
        if(rank<=0||rank>length||empty()) return;
        if(rank==1){
            push_front(value);
            return;
        }
        if(rank==length){
            auto node=new NodeTwoPtr(tail->prev,value,tail);
            tail->prev->next=node;
            tail->prev=node;
            length++;
            return;
        }
        int cnt=0;
        auto temp=head;
        while (cnt!=rank-1){
            temp=temp->next;
            cnt++;
        }
        auto node=new NodeTwoPtr(temp->prev,value,temp);
        temp->prev->next=node;
        temp->prev=node;
        length++;
    }
    class iterator{
    public:
        NodeTwoPtr<type>* move;
        void operator=(NodeTwoPtr<type>* temp){
            move=temp;
        }
        bool operator!=(NodeTwoPtr<type>* temp){
            return move!=temp;
        }
        bool operator==(NodeTwoPtr<type>* temp){
            return move==temp;
        }
        void operator++(int){
            move=move->next;
        }
        void operator++(){
            move=move->next;
        }
        type operator*(){
            return move->value;
        }
        type operator*(int){
            return move->value;
        }
        NodeTwoPtr<type>* operator+(int place) {
            for (int i = 1; i <= place; i++) {
                move = move->next;
            }
            return move;
        }

    };

};
#endif //DATA_STRUCTURES_DLL_H
