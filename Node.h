//
// Created by win on 9/9/2024.
//

#ifndef DATA_STRUCTURES_NODE_H
#define DATA_STRUCTURES_NODE_H
using namespace std;
template<class type>
class Node {
public:
    type value;
    Node* next;
    Node(Node* next,type value) : value(value),next(next){
    }
};


#endif //DATA_STRUCTURES_NODE_H
