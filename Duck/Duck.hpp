/**********************************************************
* File Name: Duck.hpp
* Created by: Zard 2025/03/14
* Description: Test code of Head First Design Patterns
* Modified:
*     1:
**********************************************************/

#ifndef _A_DUCK_H_
#define _A_DUCK_H_

#include <iostream>

class FlyBehavior{
public:
    FlyBehavior();
    ~FlyBehavior();

    virtual void fly() = 0;
};

class FlyWithWings: public FlyBehavior{
public:
    FlyWithWings();
    ~FlyWithWings();

    void fly();
};

class FlyNoWay: public FlyBehavior{
public:
    FlyNoWay();
    ~FlyNoWay();

    void fly();
};

class QuackBehavior{
public:
    QuackBehavior();
    ~QuackBehavior();

    virtual void quack() = 0;
};

class Quack: public QuackBehavior{
public:
    Quack();
    ~Quack();

    void quack();
};

class MuteQuack: public QuackBehavior{
public:
    MuteQuack();
    ~MuteQuack();

    void quack();
};

class Squeak: public QuackBehavior{
public:
    Squeak();
    ~Squeak();

    void quack();
};

class Duck {
public:
    Duck();
    ~Duck();
    /* Duck's display */
    virtual void display() = 0;

    /* Duck's behavior */
    FlyBehavior* pflyBehavior;
    QuackBehavior* pquackBehavior;

    void performFly();
    void performQuack();

    void swim();
};

class MallardDuck: public Duck{
public:
    MallardDuck();
    ~MallardDuck();

    void display();
};

#endif
