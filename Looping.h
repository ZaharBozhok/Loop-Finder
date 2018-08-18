//
// Created by User on 8/19/18.
//

#ifndef CYCLEDLIST_LOOPING_H
#define CYCLEDLIST_LOOPING_H

#include "SimpleList.h"


template<class T>
bool isLooping(const SimpleList<T> & list);

template<class T>
bool isSimpleLooping(const SimpleList<T> & list, const size_t & amount);

template <class T>
const typename SimpleList<T>::Node * stepOver(const typename SimpleList<T>::Node * node, const size_t & steps);

template<class T>
bool isPartsEquals(const typename SimpleList<T>::Node * primary, const typename SimpleList<T>::Node * comparable, const size_t & amount);

template<class T>
bool isLooping(const SimpleList<T> & list)
{
    if(list.Size() <= 1)
        return true;
    for(size_t i = 1; i<list.Size()/2+1; i++)
        if (isSimpleLooping(list,i))
            return true;
    return false;
}

template<class T>
bool isSimpleLooping(const SimpleList<T> & list, const size_t & amount)
{
    const typename SimpleList<T>::Node* start = list.Head();
    const typename SimpleList<T>::Node* comparableStart = start;
    for(size_t i=0; i<list.Size() - amount; i+=amount) {
        comparableStart = stepOver<T>(comparableStart,amount);
        if (!comparableStart || !isPartsEquals<T>(start, comparableStart, amount))
            return false;
    }
    return true;
}

template <class T>
const typename SimpleList<T>::Node * stepOver(const typename SimpleList<T>::Node * node, const size_t & steps)
{
    for(size_t j=0; j<steps; j++)
        if(!(node = node->Next()))
            return nullptr;
    return node;
}

template<class T>
bool isPartsEquals(const typename SimpleList<T>::Node * primary, const typename SimpleList<T>::Node * comparable, const size_t & amount)
{
    for(size_t j=0; j<amount; j++,primary=primary->Next(),comparable=comparable->Next())
        if(!primary || !comparable || primary->Value() != comparable->Value())
            return false;
    return true;
}

#endif //CYCLEDLIST_LOOPING_H
