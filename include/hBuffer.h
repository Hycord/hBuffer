/*
  hBuffer.h
  Created: May 10, 2024
*/

#pragma once


#include <vector>
#include <string>
#include <functional>
#include <sstream>
#include <iostream>

template <typename T>
class hBuffer
{
private:
    // Holds the internal data for the hBuffer.
    // Should _never_ be touched by derived classes or instances.
    // Derived classes should have public methods which wrap protected methods to disclose data to instances.
    std::vector<T> m_InternalData;

protected:
public:
    // Cleans up m_InternalData
    ~hBuffer();
    // Creates an empty hBuffer;
    hBuffer();
    // Creates a new hBuffer based on the data of another hBuffer;
    hBuffer(const hBuffer<T> &hBuffer);
    // Creates a new hBuffer based on the data of a vector of the same type as the hBuffer's internal data
    hBuffer(const std::vector<T> &data);
    // Creates a new hBuffer based on a pointer to the first element of a pointer array as well as the length of the array.
    hBuffer(const T *data, const int &length);

    // Gives the stringified version of the hBuffer.
    std::string Stringify(const int &spaces = 0) const;
    std::string Stringify(const std::function<std::string(const T &)> &converter, const int &spaces = 0) const;

    // Adds an element to the end of the hBuffer
    void Push(const T &data);
    // Add multiple elements to the end of the hBuffer
    void Push(const std::vector<T> &data);

    // Adds an element to the beginning of the hBuffer
    void UnShift(const T &data);
    // Adds multiple elements to the beginning of the hBuffer
    void UnShift(const std::vector<T> &data);

    // Removes count values from the beginning of the hBuffer
    void Shift(const int &count = 1);
    // Removes count values from the end of the hBuffer
    void Pop(const int &count = 1);

    // Get the current data at a specific offset
    T Read(const int &offset) const;
    // Get multiple instances of the current data at a specific offset
    std::vector<T> Read(const int &count, const int &offset) const;
};