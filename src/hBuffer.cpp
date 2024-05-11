/*
  hBuffer.cpp
  Created: May 10, 2024
*/

#include <hBuffer.h>

template <typename T>
hBuffer<T>::hBuffer() : m_InternalData()
{
}

template <typename T>
hBuffer<T>::hBuffer(const hBuffer<T> &hbuffer) : m_InternalData(*hbuffer.m_InternalData) {}

template <typename T>
hBuffer<T>::hBuffer(const std::vector<T> &data) : m_InternalData(data) {}

template <typename T>
hBuffer<T>::hBuffer(const T *data, const int &length) : m_InternalData(data, data + length){};

template <typename T>
hBuffer<T>::~hBuffer()
{
}

template <typename T>
std::string hBuffer<T>::Stringify(const std::function<std::string(const T &)> &converter, const int &spaces) const
{
  std::stringstream ss;

  if (spaces == 0)
  {
    ss << "[";
    for (size_t i = 0; i < m_InternalData->size(); ++i)
    {
      ss << " " << converter((*m_InternalData)[i]);
      if (i != m_InternalData->size() - 1)
      {
        ss << ",";
      }
    }
    ss << " ]";
  }
  else
  {
    std::string spaceStr(spaces, ' ');

    ss << "[\n";
    for (size_t i = 0; i < m_InternalData->size(); ++i)
    {
      ss << spaceStr << "  " << converter((*m_InternalData)[i]);
      if (i != m_InternalData->size() - 1)
      {
        ss << ",\n";
      }
      else
      {
        ss << "\n";
      }
    }
    ss << spaceStr << "]";
  }
  return ss.str();
}

template <typename T>
std::string hBuffer<T>::Stringify(const int &spaces) const
{
  std::stringstream ss;

  if (spaces == 0)
  {
    ss << "[";
    for (size_t i = 0; i < m_InternalData->size(); ++i)
    {
      ss << " " << (*m_InternalData)[i];
      if (i != m_InternalData->size() - 1)
      {
        ss << ",";
      }
    }
    ss << " ]";
  }
  else
  {
    std::string spaceStr(spaces, ' ');

    ss << "[\n";
    for (size_t i = 0; i < m_InternalData->size(); ++i)
    {
      ss << spaceStr << "  " << (*m_InternalData)[i];
      if (i != m_InternalData->size() - 1)
      {
        ss << ",\n";
      }
      else
      {
        ss << "\n";
      }
    }
    ss << spaceStr << "]";
  }
  return ss.str();
};

template <typename T>
void hBuffer<T>::Push(const T &data)
{
  m_InternalData->push_back(data);
};
template <typename T>
void hBuffer<T>::Push(const std::vector<T> &data)
{
  for (T d : data)
  {
    Push(d);
  }
};

template <typename T>
void hBuffer<T>::Pop(const int &count)
{
  for (int i = 0; i < count; i++)
  {
    m_InternalData->pop_back();
  }
};

template <typename T>
void hBuffer<T>::UnShift(const std::vector<T> &data)
{
  m_InternalData->insert(data.begin(), data.size());
};

template <typename T>
void hBuffer<T>::UnShift(const T &data)
{
  std::vector<T> d;
  d.push_back(data);
  UnShift(d);
};

template <typename T>
void hBuffer<T>::Shift(const int &count)
{

  for (int i = 0; i < count; i++)
  {
    if (m_InternalData->begin() != nullptr)
      m_InternalData->erase(m_InternalData->begin());
  }
};

template <typename T>
T hBuffer<T>::Read(const int &offset) const
{
  return m_InternalData[offset];
};

template <typename T>
std::vector<T> hBuffer<T>::Read(const int &count, const int &offset) const
{
  int start = m_InternalData->begin() + offset;
  int end = m_InternalData->begin() + offset + count + 1;
  std::vector<T> data(count);

  copy(start, end, data.begin());

  return data;
};