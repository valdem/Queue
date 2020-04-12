#pragma once

#include "QueueImplementation.h"
#include "MyVector.h"

class VectorQueue : public QueueImplementation, public MyVector
{
    void enqueue(const ValueType& value);
    void dequeue();
    ValueType& front();
    const ValueType& front() const;
    bool isEmpty() const;
    size_t size() const;
    
};

