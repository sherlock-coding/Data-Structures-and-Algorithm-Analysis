/*
 * =====================================================================================
 *
 *       Filename:  dlist.cpp
 *
 *    Description: 双向链表 
 *
 *        Version:  1.0
 *        Created:  2015年03月24日 21时10分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "dlist.h"

template <typename T>
DList<T>::DList()
    :m_nCount(0), m_pNodeHead(nullptr)
{

}

template <typename T>
DList<T>::DList(const T& initdata)
    :m_nCount(1)
{
    Node<T> *p = new Node<T>(initdata);
    m_pNodeHead = p;
}

template <typename T>
DList<T>::~DList()
{
    RemoveAll();
}

template <typename T>
int DList<T>::IsEmpty() const 
{
    return m_nCount == 0;
}

template <typename T>
int DList<T>::GetCount() const
{
    return m_nCount;
}

template <typename T>
T& DList<T>::GetHead()
{
    if (m_pNodeHead == nullptr) {
        // error
        return;
    }

    return m_pNodeHead->data;
}

template <typename T>
const T& DList<T>::GetHead() const
{
    if (m_pNodeHead == nullptr) {
        //error
        return ;
    }

    return m_pNodeHead->data;
}

template <typename T>
T& DList<T>::GetTail()
{
    if (m_pNodeHead == nullptr) {
        // error
        return ;
    }

    return m_pNodeHead->prior->data;
}

template <typename T>
const T& DList<T>::GetTail() const
{
    if (m_pNodeHead == nullptr) {
        // error
        return;
    }

    return m_pNodeHead->prior->data;
}

template <typename T> 
const T& DList<T>::GetAt(const int pos) const
{
    if (pos > m_nCount) {
        //error
        return ;
    }

    Node<T> *p = m_nCount;

    for (int i = 0; i < pos; ++i) {
        p = p->next;
    }

    return p->data;
}

template <typename T>
void DList<T>::SetAt(const int pos, const T& data)
{
     if (pos > m_nCount) {
        //error
        return ;
    }

    Node<T> *p = m_nCount;

    for (int i = 0; i < pos; ++i) {
        p = p->next;
    }

    p->data = data;

}

template <typename T>
int DList<T>::Find(const T& data)
{
    if (m_nCount == 0) {
        //error
        return ;
    }

    int i;
    Node<T> *p = m_pNodeHead;
    for (i = 0; i < m_nCount; ++i) {
        if (p->data == data) {
            break;
        }
        p = p->next;
    }

    return i;
}

template <typename T>
int DList<T>::AddHead(const T& data)
{
    Node<T> *p = new Node<T>(data);
    p->next = m_pNodeHead;
    p->prior = m_pNodeHead->prior;
    m_pNodeHead->prior = p;
    m_pNodeHead = p;

    return 1;
}

template <typename T>
int DList<T>::AddTail(const T& data)
{
    return AddHead(data);
}

template <typename T>
int DList<T>::InsertBefore(const T& data, const int pos)
{
    if (pos > m_nCount) {
        // error
        return 0;
    }

    Node<T> *p = m_pNodeHead;
    for (int i = 0; i < pos; ++i) {
        p = p->next;
    }

    Node<T> *q = new Node<T>(data);
    q->next = p;
    q->prior = p->prior;
    p->prior = q;

    return 1;
}

template <typename T>
int DList<T>::InsertAfter(const T& data, const int pos)
{
    if (pos > m_nCount) {
        // error
        return 0;
    }

    Node<T> *p = m_pNodeHead;
    for (int i = 0; i < pos; ++i) {
        p = p->next;
    }

    Node<T> *q = new Node<T>(data);
    q->prior = p;
    q->next = p->next;
    p->next = q;

    return 1;
}

template <typename T>
void DList<T>::RemoveAt(const int pos, T& ret)
{
    if (pos > m_nCount) {
        // error
        return 0;
    }

    Node<T> *p = m_pNodeHead;
    for (int i = 0; i < pos; ++i) {
        p = p->next;
    }

    p->prior->next = p->next;
    p->next->prior = p->prior;
    ret = p->data;
    delete p;
}

template <typename T>
void DList<T>::RemoveHead(T& ret)
{
    if (m_pNodeHead == nullptr) {
        // error
        return;
    }

    ret = m_pNodeHead->data;
    Node<T> *p = m_pNodeHead->next;
    p->prior = m_pNodeHead->prior;
    m_pNodeHead->prior->next = p;
    delete m_pNodeHead;
    m_pNodeHead = p;
}

template <typename T>
void DList<T>::RemoveTail(T& ret)
{
    if (m_pNodeHead == nullptr) {
        // error
        return;
    }

    Node<T> *p = m_pNodeHead->prior;
    ret = p->data;
    m_pNodeHead->prior = p->prior;
    p->prior->next = m_pNodeHead;
    delete p;
}

template <typename T>
void DList<T>::RemoveAll()
{
    Node<T> *p = m_pNodeHead;
    for (int i = 0; i < m_nCount; ++i) {
        p = m_pNodeHead;
        m_pNodeHead = m_pNodeHead->next;
        delete p;
    }

    m_pNodeHead = nullptr;
}
