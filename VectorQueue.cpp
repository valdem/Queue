#include "VectorQueue.h"

void VectorQueue:: enqueue(const ValueType& value) {
    pushBack(value);
}
void VectorQueue:: dequeue() {
    erase(0);
}
ValueType& VectorQueue:: front() {
    return MyVector:: operator[](0);
}
const ValueType& VectorQueue:: front() const {
    return MyVector:: operator[](0);
}
bool VectorQueue:: isEmpty() const {
    if (MyVector:: operator[](0)) {
        return false;
    }
    else {
        return true;
    }
}
size_t VectorQueue:: size() const {
    return MyVector::size();
}
