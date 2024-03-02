#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
using namespace std;

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack: private std::vector<T>
{
public:
    Stack() = default;
    ~Stack() = default;
    bool empty() const{
        return vector<T>::empty();
    }
    size_t size() const{
        return vector<T>::size();
    }
    void push(const T& item){
        this->vector<T>::push_back(item);
    }
    void pop(){
        if (this->empty()) {
            throw std::underflow_error("underflow error (pop)");
        }
        this->vector<T>::pop_back(); 
    }  // throws std::underflow_error if empty
    const T& top() const{
        if (this->empty()) {
            throw std::underflow_error("underflow error (top)");
        }
        return this->vector<T>::back();
    } // throws std::underflow_error if empty
    
    // Add other members only if necessary
};


#endif