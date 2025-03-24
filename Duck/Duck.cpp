/**********************************************************
* File Name: Duck.cpp
* Created by: Zard 2025/03/14
* Description: Test code of Head First Design Patterns
* Modified:
*     1:
**********************************************************/

#include <iostream>
#include "Duck.hpp"

// FlyBehavior::FlyBehavior() {
//     /* Do nothing */
// }

FlyBehavior::~FlyBehavior() {
    /* Do nothing */
}

FlyWithWings::FlyWithWings() {
    /* Do nothing */
}

FlyWithWings::~FlyWithWings() {
    /* Do nothing */
}

void FlyWithWings::fly() {
    std::cout << "I'm flying!!!" << std::endl;
}

FlyNoWay::FlyNoWay() {
    /* Do nothing */
}

FlyNoWay::~FlyNoWay() {
    /* Do nothing */
}

void FlyNoWay::fly() {
    std::cout << "I can't fly." <<std::endl;
}

FlyRocketPowered::FlyRocketPowered() {
    /* Do nothing */
}

FlyRocketPowered::~FlyRocketPowered() {
    /* Do nothing */
}

void FlyRocketPowered::fly() {
    std::cout << "I'm fly with a roket!!!" << std::endl;
}

// QuackBehavior::QuackBehavior() {
//     /* Do nothing */
// }

QuackBehavior::~QuackBehavior() {
    /* Do nothing */
}

Quack::Quack() {
    /* Do nothing */
}

Quack::~Quack() {
    /* Do nothing */
}

void Quack::quack() {
    std::cout << "Quack" << std::endl;
}

MuteQuack::MuteQuack() {
    /* Do nothing */
}

MuteQuack::~MuteQuack() {
    /* Do nothing */
}

void MuteQuack::quack() {
    std::cout << "<< Silence >>" << std::endl;
}

Squeak::Squeak() {
    /* Do nothing */
}

Squeak::~Squeak() {
    /* Do nothing */
}

void Squeak::quack() {
    std::cout << "Squeak" << std::endl;
}

QuackHorn::QuackHorn() {
    /* Do nothing */
}

QuackHorn::~QuackHorn() {
    /* Do nothing */
}

void QuackHorn:: quack() {
    std::cout << "I'm quack with a horn." << std::endl;
}

// Duck::Duck() {
//     /* Do nothing */
// }

Duck::~Duck() {
    /* Do nothing */
}

void Duck::performFly() {
    if (pflyBehavior) //check ptr valid
        pflyBehavior->fly();
}

void Duck::performQuack() {
    if (pquackBehavior) //check ptr valid
        pquackBehavior->quack();
}

void Duck::setFlyBehavior(std::unique_ptr<FlyBehavior> fb){
    pflyBehavior = std::move(fb);
}

void Duck::setQuackBehavior(std::unique_ptr<QuackBehavior> qb){
    pquackBehavior = std::move(qb);
}

void Duck::swim() {
    std::cout << "All ducks float, even decoys!" << std::endl;
}

MallardDuck::MallardDuck() {
    pflyBehavior = std::make_unique<FlyWithWings>();
    pquackBehavior =  std::make_unique<Quack>();
}

MallardDuck::~MallardDuck() {
    /* Do nothing */
}

void MallardDuck::display() {
    std::cout << "I'm a real Mallard duck." << std::endl;
}

ModelDuck::ModelDuck() {
    pflyBehavior = std::make_unique<FlyNoWay>();
    pquackBehavior = std::make_unique<MuteQuack>();
}

ModelDuck::~ModelDuck() {
    /* Do nothing */ 
}

void ModelDuck::display() {
    std::cout << "I'm a model duck." << std::endl;
}
