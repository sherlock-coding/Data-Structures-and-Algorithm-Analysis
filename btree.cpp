/*
 * =====================================================================================
 *
 *       Filename:  btree.cpp
 *
 *    Description:  二叉树
 *
 *        Version:  1.0
 *        Created:  2015年03月27日 20时20分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "btree.h"

template<typename T>
BTree<T>::BTree():m_pRoot(nullptr){}

template<typename T>
BTree<T>::BTree(const T& initdata)
{
    m_pRoot = new BTNode<T>(initdata);
}

template<typename T>
BTree<T>::~BTree()
{
    Destroy();
}

template<typename T>
BTNode<T>* BTree<T>::GetRoot() const
{
    return m_pRoot;
}

template<typename T>
BTNode<T>* BTree<T>::GetLeftChild(const BTNode<T>* p) const
{
    return p->left;
}

template<typename T>
BTNode<T>* BTree<T>::GetRightChild(const BTNode<T>* p) const
{
    return p->right;
}

template<typename T>
int BTree<T>::IsEmpty() const
{
    if (m_pRoot == nullptr)
        return 1;
    else
        return 0;
}

template<typename T>
void BTree<T>::Destroy()
{
    DestroyNode(m_pRoot);
}

template<typename T>
void BTree<T>::PreOrderTraverse(void (*visit)(const T& data)) const
{
    PreOrderTraverse(m_pRoot, visit);
}

template<typename T>
void BTree<T>::InOrderTraverse(void (*visit)(const T& data)) const
{
    InOrderTraverse(m_pRoot, visit);
}

template<typename T>
void BTree<T>::PostOrderTraverse(void (*visit)(const T& data)) const
{
    PostOrderTraverse(m_pRoot, visit);
}

template<typename T>
unsigned int BTree<T>::GetNodesCount() const
{
    unsigned int count = 0;
    GetNodesCount(m_pRoot, count);
    return count;
}

template<typename T>
unsigned int BTree<T>::GetLeafCount() const
{
    unsigned int count = 0;
    GetLeafCount(m_pRoot, count);
    return count;
}

template<typename T>
unsigned int BTree<T>::GetDepth() const
{
    unsigned int depth = 0;
    GetDepth(m_pRoot, depth);
    return depth;
}

template<typename T>
void BTree<T>::DestroyNode(BTNode<T> *p)
{
    if (p == nullptr)
        return;
    DestroyNode(p->left);
    DestroyNode(p->right);
    delete p;
}

template<typename T>
void BTree<T>::PreOrderTraverse(const BTNode<T> *p, void (*visit)(const T& data)) const
{
    if (p == nullptr)
        return;
    visit(p->data);
    PreOrderTraverse(p->left, visit);
    PreOrderTraverse(p->right, visit);
}

template<typename T>
void BTree<T>::InOrderTraverse(const BTNode<T> *p, void (*visit)(const T& data)) const
{
    if (p == nullptr)
        return;
    InOrderTraverse(p->left, visit);
    visit(p->data);
    InOrderTraverse(p->right, visit);
}

template<typename T>
void BTree<T>::PostOrderTraverse(const BTNode<T> *p, void (*visit)(const T& data)) const
{
    if (p == nullptr)
        return;
    PostOrderTraverse(p->left, visit);
    PostOrderTraverse(p->right, visit);
    visit(p->data);
}

template<typename T>
void BTree<T>::GetNodesCount(const BTNode<T> *p, unsigned int &count) const
{
    if (p == nullptr)
        return;
    ++count;
    GetNodesCount(p->left, count);
    GetNodesCount(p->right, count);
}

template<typename T>
void BTree<T>::GetLeafCount(const BTNode<T> *p, unsigned int &count) const
{
    if (p == nullptr)
        return;
    if (p->left == nullptr && p->right == nullptr){
        ++count;
        return;
    }
    GetLeafCount(p->left, count);
    GetLeafCount(p->right, count);
}

template<typename T>
void BTree<T>::GetDepth(const BTNode<T> *p, unsigned int &depth) const
{
    if (p == nullptr)
        return;
    unsigned depthl = 0, depthr = 0;
    GetDepth(p->left, depthl);
    GetDepth(p->right, depthr);
    if (depthl > depthr)
        depth += depthl;
    else
        depth += depthr;
    ++depth;
}


