//
// Created by win on 10/31/2024.
//

#ifndef DATA_STRUCTURES_NODELRPTR_H
#define DATA_STRUCTURES_NODELRPTR_H
template<class type>
class NodeRLPtr{
public:
    NodeRLPtr* left;
    NodeRLPtr* right;
    type value;
    NodeRLPtr(type value){
        this->value=value;
        left=right= nullptr;
    }

};
#endif //DATA_STRUCTURES_NODELRPTR_H
