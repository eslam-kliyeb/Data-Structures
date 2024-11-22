//
// Created by win on 10/30/2024.
//

#ifndef DATA_STRUCTURES_NODETWOPTR_H
#define DATA_STRUCTURES_NODETWOPTR_H
using namespace std;
template<class type>
class NodeTwoPtr {
public:
    type value;
    NodeTwoPtr* next;
    NodeTwoPtr* prev;
    NodeTwoPtr(NodeTwoPtr* prev,type value,NodeTwoPtr* next) : prev(prev),value(value),next(next){
    }
};
#endif //DATA_STRUCTURES_NODETWOPTR_H
