/**********************************************************
* File Name: Duck.cpp
* Created by: Zard 2025/03/14
* Description: Test code of Head First Design Patterns
* Modified:
*     1:
**********************************************************/

#include "Duck.hpp"

FlyBehavior::FlyBehavior() {
    /* Do nothing */
}

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

QuackBehavior::QuackBehavior() {
    /* Do nothing */
}

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

Duck::Duck() {
    /* Do nothing */
}

Duck::~Duck() {
    /* Do nothing */
}

void Duck::performFly() {
    pflyBehavior->fly();
}

void Duck::performQuack() {
    pquackBehavior->quack();
}

void Duck::setFlyBehavior(FlyBehavior *fb){
    pflyBehavior = fb;
}

void Duck::setQuackBehavior(QuackBehavior *qb){
    pquackBehavior = qb;
}

void Duck::swim() {
    std::cout << "All ducks float, even decoys!" << std::endl;
}

MallardDuck::MallardDuck() {
    pflyBehavior = new FlyWithWings();
    pquackBehavior = new Quack();
}

MallardDuck::~MallardDuck() {
    /* Do nothing */
}

void MallardDuck::display() {
    std::cout << "I'm a real Mallard duck." << std::endl;
}

ModelDuck::ModelDuck() {
    pflyBehavior = new FlyNoWay();
    pquackBehavior = new MuteQuack();
}

ModelDuck::~ModelDuck() {
    /* Do nothing */ 
}

void ModelDuck::display() {
    std::cout << "I'm a model duck." << std::endl;
}
