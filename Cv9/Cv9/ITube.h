#pragma once
#ifndef ITUBE_H
#define ITUBE_H
#include <stdexcept>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct ATubeNode;
struct ITube {
    virtual ~ITube();
    virtual const ATubeNode* getNode(int x, int y) const = 0;
    virtual bool isTubeOK() const = 0;
    virtual const int getSize() const = 0;
};

struct ATubeNode {
    virtual ~ATubeNode();
    virtual bool isCorrect(const ITube* Tube) const = 0;
    int x;
    int y;
    int type;
};

class Tube : public ITube {
private:
    ATubeNode*** matrix;
    int size;
public:
    Tube(const int size);
    ~Tube();
    void addNode(ATubeNode* Node);
    const ATubeNode* getNode(int x, int y) const;
    bool isTubeOK() const;
    const int getSize() const;
};

std::ifstream& operator >> (std::ifstream& output, Tube& a);

class Node : public ATubeNode {
public:
    Node();
    Node(const int x, const int y, int type);
    ~Node();
    bool isCorrect(const ITube* Tube) const;
};

#endif // !ITUBE_H
