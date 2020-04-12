#include "Queue.h"
#include "ListQueue.h"
#include "VectorQueue.h"
#include "QueueImplementation.h"

#include <stdexcept>

Queue::Queue(QueueContainer container)
    : _containerType(container)
{
    switch (container)
    {
    case QueueContainer::List: {
        _pimpl = new ListQueue();
        break;
    }
    case QueueContainer::Vector: {
        _pimpl = new VectorQueue();
        break;
    }
    default:
        throw std::runtime_error("Неизвестный тип контейнера");
    }
    
}

Queue::Queue(const ValueType* valueArray, const size_t arraySize,
             QueueContainer container)
    :_containerType(container)
{
    switch (container)
    {
    case QueueContainer::List: {
        _pimpl = new ListQueue();
        for (size_t i = 0; i<arraySize; i++) {
            _pimpl->enqueue(*valueArray);
        }
        break;
    }
    case QueueContainer::Vector: {
        _pimpl = new VectorQueue();
        for (size_t i = 0; i<arraySize; i++) {
            _pimpl->enqueue(*valueArray);
        }
        break;
    }
    default:
        throw std::runtime_error("Неизвестный тип контейнера");
    }
    
}

Queue::Queue(const Queue& copyQueue) {
    this->_pimpl = copyQueue._pimpl;
    this->_containerType = copyQueue._containerType;
}
Queue& Queue:: operator=(const Queue& copyQueue) {
    if (this == &copyQueue) {
        return *this;
    }
    Queue bufStack(copyQueue);
    this->_pimpl = bufStack._pimpl;
    this->_containerType = bufStack._containerType;
    
    return *this;
}

Queue::Queue(Queue&& moveQueue) noexcept {
    this->_pimpl = moveQueue._pimpl;
    this->_containerType = moveQueue._containerType;
    
    moveQueue._pimpl = 0;
}
Queue& Queue:: operator=(Queue&& moveQueue) noexcept {
    if (this == &moveQueue) {
        return *this;
    }
    delete this;
    this->_pimpl = moveQueue._pimpl;
    this->_containerType = moveQueue._containerType;
    
    moveQueue._pimpl = 0;
    
    return *this;
}

Queue:: ~Queue() {
    delete _pimpl;
}

void Queue:: enqueue(const ValueType& value) {
    _pimpl->enqueue(value);
}
void Queue:: dequeue() {
    _pimpl->dequeue();
}
ValueType& Queue:: front() {
    return _pimpl->front();
}
const ValueType& Queue:: front() const {
    return _pimpl->front();
}
bool Queue:: isEmpty() const {
    return _pimpl->isEmpty();
}
size_t Queue:: size() const {
    return _pimpl->size();
}
