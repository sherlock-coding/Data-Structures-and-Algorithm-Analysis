/*
 * =====================================================================================
 *
 *       Filename:  pascaltriangel.cpp
 *
 *    Description:  杨辉三角
 *
 *        Version:  1.0
 *        Created:  2015年03月25日 20时39分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;

int getElem(int row, int col) 
{
    if (col == 1 || row == col) {
        return 1;
    }

    return getElem(row-1,col) + getElem(row-1, col-1);
}

void triangel(int n)
{
    for(int row = 1; row <=n; ++row) {
        for (int col = 1; col <=row; ++col) {
            cout << getElem(row, col) << " ";
        }
        cout << endl;
    }
}


int main()
{
    int n = 5;
    triangel(5);

    return 0;
}

