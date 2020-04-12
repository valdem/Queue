#pragma once

#include "QueueImplementation.h"
#include "LinkedList.h"

class ListQueue : public QueueImplementation, public LinkedList
{
    void enqueue(const ValueType& value);
    void dequeue();
    ValueType& front();
    const ValueType& front() const;
    bool isEmpty() const;
    size_t size() const;
    
};
