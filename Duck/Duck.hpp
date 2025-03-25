/**********************************************************
* File Name: Duck.hpp
* Created by: Zard 2025/03/14
* Description: Test code of Head First Design Patterns
* Modified:
*     1:
**********************************************************/

#ifndef _A_DUCK_H_
#define _A_DUCK_H_

#include <memory>

class FlyBehavior{
public:
    // FlyBehavior(); Base class doesn't require a constructor
    virtual ~FlyBehavior(); // Base class destructor is a virtual function

    virtual void fly() = 0;
};

class FlyWithWings: public FlyBehavior{
public:
    FlyWithWings();
    ~FlyWithWings();

    void fly() override;
};

class FlyNoWay: public FlyBehavior{
public:
    FlyNoWay();
    ~FlyNoWay();

    void fly() override;
};

class FlyRocketPowered: public FlyBehavior{
public:
    FlyRocketPowered();
    ~FlyRocketPowered();

    void fly() override;
};

class QuackBehavior{
public:
    //QuackBehavior(); Base class doesn't require a constructor
    virtual ~QuackBehavior(); // Base class destructor is a virtual function

    virtual void quack() = 0;
};

class Quack: public QuackBehavior{
public:
    Quack();
    ~Quack();

    void quack() override;
};

class MuteQuack: public QuackBehavior{
public:
    MuteQuack();
    ~MuteQuack();

    void quack() override;
};

class Squeak: public QuackBehavior{
public:
    Squeak();
    ~Squeak();

    void quack() override;
};

class QuackHorn: public QuackBehavior{
public:
    QuackHorn();
    ~QuackHorn();

    void quack() override;
};

class Duck {
public:
    Duck() = default; //Is it should be retain?
    virtual ~Duck(); // Base class destructor is a virtual function
    /* Duck's display */
    virtual void display() = 0;

    void performFly();
    void performQuack();
    void setFlyBehavior(std::unique_ptr<FlyBehavior> fb);
    void setQuackBehavior(std::unique_ptr<QuackBehavior> qb);

    void swim();

protected:
    /* Duck's behavior */
    std::unique_ptr<FlyBehavior> pflyBehavior;
    std::unique_ptr<QuackBehavior> pquackBehavior;
};

class MallardDuck: public Duck {
public:
    MallardDuck();
    ~MallardDuck();

    void display() override;
};

class ModelDuck: public Duck {
public:
    ModelDuck();
    ~ModelDuck();

    void display() override;
};

#endif
