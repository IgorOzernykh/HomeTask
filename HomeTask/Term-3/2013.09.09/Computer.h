#pragma once

/** Computer class has inherited classes that contain information
    about OS, chance to be infect by virus and if they are infected */

enum OS
{
    Windows = 0,
    Mac,
    Linux
};

class Computer
{
public:
    Computer() : isInfected(false) {}
    int getInfectChance()
    {
        return infectChance;
    }
    bool getInfectStatus()
    {
        return isInfected;
    }
    void setInfectStatus (bool newInfectStatus)
    {
        isInfected = newInfectStatus;
    }

protected:
    int infectChance;
    bool isInfected;
    OS os;
};

class WindowsComputer : public Computer
{
public:
    WindowsComputer()
    {
        infectChance = 80;
        os = Windows;
    }
    ~WindowsComputer();
};

class MacComputer : public Computer
{
public:
    MacComputer()
    {
        infectChance = 45;
        os = Mac;
    }
    ~MacComputer();
};

class LinuxComputer : public Computer
{
public:
    LinuxComputer()
    {
        infectChance = 10;
        os = Linux;
    }
    ~LinuxComputer();
};
