#include "ListQueue.h"

void ListQueue:: enqueue(const ValueType& value) {
    pushBack(value);
}
void ListQueue:: dequeue() {
    removeFront();
}
ValueType& ListQueue:: front() {
    return getNode(0)->value;
}
const ValueType& ListQueue:: front() const {
    return getNode(0)->value;
}
bool ListQueue:: isEmpty() const {
    if (getNode(0)) {
        if (getNode(0)->value) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}
size_t ListQueue:: size() const {
    return LinkedList::size();
}
