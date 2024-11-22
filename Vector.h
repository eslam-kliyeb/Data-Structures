//
// Created by win on 9/7/2024.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
using namespace std;
template<class type>
class Vector {
private:
    int Size,Capacity;
    type* array;
    bool isFull(){
        return (Size == Capacity);
    }
    void expand(){
        Capacity*=2;
        type* temp = new type[Capacity]{};
        for(int i=0; i < Size; i++){
            temp[i]=array[i];
        }
        delete[] array;
        array=temp;
    }
public:
    Vector(){
        Capacity = 2;
        Size = 0;
        array = new type[Capacity]{};
    }
    Vector(int Capacity){
        this->Capacity=Capacity;
        Size = 0;
        array = new type[this->Capacity]{};
    }
    ~Vector(){
        delete[] array;
    }
    using iterator  = type*;
    int capacity(){
        return Capacity;
    }
    int size(){
        return Size;
    }
    type& operator[](int index){
        return array[index];
    };
    type& at(int index){
        return array[index];
    }
    void push_front(type value){
        if(isFull()){
            expand();
        }
        for(int i=Size;i>=1;i--){
            array[i]=array[i-1];
        }
        array[0]=value;
        Size++;
    }
    bool empty(){
        return Size==0;
    }
    void pop_front(){
        if(!empty()) {
            for (int i = 0; i <= Size - 2; i++) {
                array[i] = array[i + 1];
            }
            array[Size - 1] = 0;
            Size--;
        }
    }
    void pop_back(){
        if(!empty()){
            Size--;
        }
    }
    void shrink_to_fit(){
        Capacity=Size;
        type* temp = new type[Capacity]{};
        for(int i=0; i < Size; i++){
            temp[i]=array[i];
        }
        delete[] array;
        array=temp;
    }
    void push_back(type value){
        if(isFull()){
            expand();
        }
        array[Size]=value;
        Size++;
    }
    size_t max_size() const noexcept{
        //const ensures the method doesn't modify the object.
        //noexcept guarantees the method doesn't throw exceptions.
        return size_t(-1)/sizeof(type);
    }
    void resize(int new_size,int value=0){
        if(new_size>Size){
            for(int i=0; i < new_size-Size; i++){
                push_back(value);
            }
        }
        else{ //new_size<Size
            for(int i=0; i < Size-new_size; i++){
                pop_back();
            }
        }
        Size=new_size;
    }
    type front(){
        return at(0);
    }
    type back(){
        return at(Size-1);
    }
    void clear(){
        Capacity=2;
        Size=0;
        type* temp = new type[Capacity]{};
        delete[] array;
        array=temp;
    }
    type& begin(){
        return array[0];
    }
    type& end(){
        return array[Size-1];
    }
    const type* cbegin(){
        return array;
    }
    const type* cend(){
        return array+Size-1;
    }
    void reserve(){
        type* temp = new type[Capacity]{};
        for(int i=0; i < Size; i++){
            temp[Size-1-i]=array[i];
        }
        delete[] array;
        array=temp;
    }
    void insert(type position,type value){
        int index =(position)-begin();
        if(index>Size)return;
        Size++;
        for (int i = Size; i > index; i--) {
            array[i] = array[i-1];
        }
        array[index] = value;
    }
};
#endif //VECTOR_VECTOR_H
