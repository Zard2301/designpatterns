/**********************************************************
* File Name: main.cpp
* Created by: Zard 2025/03/14
* Description: Test code of Head First Design Patterns
* Modified:
*     1:
**********************************************************/

#include <iostream>
#include "Duck.hpp"

int main()
{
    MallardDuck* pmallard = new MallardDuck();
    pmallard->performFly();
    pmallard->performQuack();

    return 0;
}
