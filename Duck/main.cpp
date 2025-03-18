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
    MallardDuck* pMallard = new MallardDuck();
    ModelDuck* pModel = new ModelDuck();

    std::cout << "<< Mallard duck >>" << std::endl;
    pMallard->performFly();
    pMallard->performQuack();

    std::cout << "<< Model duck >>" << std::endl;
    pModel->performFly();
    pModel->performQuack();

    std::cout << "<< Opt Model duck >>" << std::endl;
    pModel->setFlyBehavior(new FlyRocketPowered());
    pModel->setQuackBehavior(new QuackHorn());

    pModel->performFly();
    pModel->performQuack();

    return 0;
}
