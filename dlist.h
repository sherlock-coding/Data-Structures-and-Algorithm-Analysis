/*
 * =====================================================================================
 *
 *       Filename:  dlist.h
 *
 *    Description:  双向链表
 *
 *        Version:  1.0
 *        Created:  2015年03月20日 10时34分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sherlock-coding 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _DOUBLE_LIST_H_
#define _DOUBLE_LIST_H_

template <typename T>
class Node {
public:
    Node() : data(T()), prior(nullptr), next(nullptr) {}
    Node(const T& initdata) : data(initdata), prior(nullptr), next(nullptr) {}
   ~Node() {}

    Node<T> *prior;
    Node<T> *next;
    T data;
};

template <typename T>
class DList {
public:
    DList();
    DList(const T& initdata);
    ~DList();

    int IsEmpty() const;
    int GetCount() const;
    T&  GetHead();
    const T& GetHead() const;
    T&  GetTail();
    const T& GetTail() const;
    T&  GetAt();
    const T& GetAt(const int pos) const;
    void SetAt(const int pos, const T& data);
    int Find(const T& data);

    int AddHead(const T& data);
    int AddTail(const T& data);
    int InsertBefore(const T& data, const int pos);
    int InsertAfter(const T& data, const int pos);
    void RemoveAt(const int pos, T& ret);
    void RemoveHead(T& ret);
    void RemoveTail(T& ret);
    void RemoveAll();
private:
    Node<T> *m_pNodeHead;
    int      m_nCount;
};

#endif
