//
// Created by win on 10/31/2024.
//

#ifndef DATA_STRUCTURES_BST_H
#define DATA_STRUCTURES_BST_H
#include "NodeLRPtr.h"
using namespace std;
template<class type>
class BST{
private:
    NodeRLPtr<type>* root;
    int length;
public:
    BST(){
        root = nullptr;
        length=0;
    }
    ~BST(){
        while (!empty()){
            erase(root->value);
        }
    }
    bool empty(){
        return (root== nullptr);
    }
    int size(){
        return length;
    }
    void insert(type value){
        if(empty()){
            root=new NodeRLPtr<type>(value);
            length++;
            return;
        }
        auto iterator=root;
        while (iterator->value!=value){ // not duplicate
            //if value is greater
            if(iterator->value<value){
                if(iterator->right== nullptr){
                    iterator->right=new NodeRLPtr(value);
                    length++;
                    return;
                }
                else{
                    //right not empty
                    iterator = iterator->right;
                }
            }
            //if value is smaller
            else{
                if(iterator->left== nullptr){
                    iterator->left=new NodeRLPtr(value);
                    length++;
                    return;
                }
                else{
                    //left not empty
                    iterator=iterator->left;
                }
            }
        }
    }
    bool find(type value){
        if(empty()) return false;
        auto iterator = root;
        while (iterator->value!=value){
            if(iterator->value<value&&iterator->right!= nullptr) {
                iterator = iterator->right;
            }
            else if(iterator->value>value&&iterator->left!= nullptr){
                iterator=iterator->left;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void erase(type value){
        if(empty()) return;
        auto iterator = root;
        auto parent = root;
        while (true){
            //if the value is greater
            if(value>iterator->value){
                if(iterator->right!= nullptr){
                    parent=iterator;
                    iterator=iterator->right;
                }
                else{
                    return;
                }
            }
            else if(value<iterator->value){ //if the value is smaller
                if(iterator->left!= nullptr){
                    parent=iterator;
                    iterator=iterator->left;
                }
                else{
                    return;
                }
            }
            else{ // equal--->node will be deleted
                //1st case-leaf-(no child)
                if(iterator->left== nullptr&&iterator->right== nullptr){
                    //root (leaf) will be deleted
                    if(root==iterator){
                        delete root;
                        root= nullptr;
                        length=0;
                        return;
                    }
                    if(parent->left==iterator){
                        parent->left= nullptr;
                    }
                    else{ // parent->right==iterator
                        parent->right= nullptr;
                    }
                    delete iterator;
                    length--;
                    return;
                }
                //2end case-one child
                else if(iterator->left== nullptr||iterator->right== nullptr){
                    //root (one child) will be deleted
                    if (root==iterator){
                        root = (root->right!= nullptr?root->right:root->left);
                        delete iterator;
                        length--;
                        return;
                    }
                    auto temp =(iterator->right!= nullptr?iterator->right:iterator->left);
                    if(parent->left==iterator) parent->left=temp;
                    else parent->right=temp;
                    delete iterator;
                    length--;
                    return;
                }
                //3rd case-two child
                else{
                    auto smallestBig= iterator->right;
                    while(smallestBig->left!= nullptr){
                        smallestBig=smallestBig->left;
                    }
                    value=iterator->value=smallestBig->value;
                    iterator=iterator->right;
                }
            }
        }
    }
};
#endif //DATA_STRUCTURES_BST_H
