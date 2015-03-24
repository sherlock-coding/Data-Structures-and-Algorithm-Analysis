/*
 * =====================================================================================
 *
 *       Filename:  slist.cpp
 *
 *    Description:  单链表
 *
 *        Version:  1.0
 *        Created:  2015年03月19日 20时03分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sherlock-coding 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "slist.h"

template <typename T>
SList<T>::SList():m_nCount(0), m_pNodeHead(nullptr) {}

template <typename T>
SList<T>::SList(const T& initdata):m_nCount(0), m_pNodeHead(nullptr)
{
    AddHead(initdata);
}

template <typename T>
SList<T>::~SList()
{
    RemoveAll();
}

template <typename T>
inline int  SList<T>::IsEmpty()
{
    return 0 == m_nCount;
}

template <typename T>
inline int SList<T>::GetCount() const
{
    return m_nCount;
}

template <typename T>
T& SList<T>::GetTail()
{
    Node<T> *p = m_pNodeHead;
    for (int i = 1; i < m_nCount; ++i) {
        p = p->next;
    }

    return p->data;
}

template <typename T>
const T& SList<T>::GetTail() const
{
    Node<T> *p = m_pNodeHead;
    for (int i = 1; i < m_nCount; ++i) {
        p = p->next;
    }

    return p->data;
}

template <typename T>
T& SList<T>::GetHead()
{
    return m_pNodeHead->data;
}

template <typename T>
const T& SList<T>::GetHead() const 
{
    return m_pNodeHead->data;
}

template <typename T>
T& SList<T>::GetAt(const int pos)
{
    if (pos > m_nCount) {
        // error
    }

    Node<T> *p = m_pNodeHead;
    for (int i = 0; i < pos; ++i) {
        p = p->next;
    }
/usr/lib/gcc/i686-linux-gnu/4.9/../../../i386-linux-gnu/crt1.o：在函数‘_start’中：
/build/buildd/glibc-2.19/csu/../sysdeps/i386/start.S:111：对‘main’未定义的引用
collect2: error: ld returned 1 exit status
    return p->data;
}

template <typename T>
const T& SList<T>::GetAt(const int pos) const 
{
    if (pos > m_nCount) {
        // error
    }

    Node<T> *p = m_pNodeHead;
    for (int i=0; i < pos; ++i) {
        p = p->next;
    }

    return p->data;
}

template <typename T>
void SList<T>::SetAt(const int pos, const T& data)
{
    if (pos > m_nCount) {
        // error
    }

    Node<T> *p = m_pNodeHead;
    for (int i=0; i < pos; ++i) {
        p = p->next;
    }
    
    p->data = data;
}

template <typename T>
int SList<T>::Find(const T& data)
{
    Node<T> *p = m_pNodeHead;
    for (int i = 0; i < m_nCount; ++i) {
        if (p->data == data)
            return i;
        p = p->next;
    }

    return -1;
}

template <typename T>
int SList<T>::AddHead(const T& data)
{
    Node<T> *p = new Node<T>(data, m_pNodeHead);
    ++m_nCount;
    return 0;
}

template <typename T>
int SList<T>::AddTail(const T& data)
{
    Node<T> *p = m_pNodeHead;
    while (p != nullptr) {
        p = p->next;
    }

    p->next = new Node<T>(data);
    ++m_nCount;
    return m_nCount-1;
}

template <typename T>
int SList<T>::InsertBefore(const T& data, const int pos)
{
    if (0 == pos) {
        return InsertHead(data);
    }

    Node<T> *p = m_pNodeHead;
    for (int i = 1; i < pos; ++i) {
        p = p->next;
    }

    Node<T> *q = new Node<T>(data, p->next);
    p->next = q;
    ++m_nCount;
    return pos-1;
}

template <typename T>
int SList<T>::InsertAfter(const T& data, const int pos)
{
    if (pos == m_nCount-1) {
        return InsertTail(data);
    }

    Node<T>* p = m_pNodeHead;
    for (int i = 0; i < pos; ++i) {
        p = p->next;
    }

    Node<T> *q = new Node<T>(data, p->next);
    p->next = q;
    ++m_nCount;
    return pos+1;
}

template <typename T>
void SList<T>::RemoveAt(const int pos, T& ret)
{
    if (pos >= m_nCount || pos < 0) {
        // error
    }

    if (pos == 0) {
        RemoveHead(ret);
        return;
    }

    if (pos == m_nCount-1) {
        RemoveTail(ret);
        return ;
    }

    Node<T> *p = m_pNodeHead;
    Node<T> *q = p;
    for (int i = 0; i < pos; ++i) {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    ret = p->data;
    delete p;
    --m_nCount;
}

template <typename T>
void SList<T>::RemoveHead(T& ret)
{
    if (m_nCount == 1) {
        RemoveHead(ret);
        return;
    }
    Node<T> *p = m_pNodeHead;
    m_pNodeHead = p;
    ret = p->data;
    delete p;
    --m_nCount;
}

template <typename T>
void SList<T>::RemoveTail(T& ret)
{
    if (m_nCount == 1) {
        RemoveAll(ret);
        return;
    }
    Node<T> *p = m_pNodeHead;
    Node<T> *q = p;
    while (p->next != nullptr) {
        q = p;
        p = p->next;
    }

    q->next = nullptr;
    delete p;
    --m_nCount;
}

template <typename T>
void SList<T>::RemoveAll()
{
    Node<T> *p = m_pNodeHead;
    Node<T> *q = p;
    
    while (p != nullptr) {
        q = p->next;
        delete p;
        p = q;
    }
    m_pNodeHead = nullptr;
    m_nCount = 0;
}

