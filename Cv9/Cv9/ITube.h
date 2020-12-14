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
public:
    virtual ~ITube();
    virtual void addNode(ATubeNode* prvek) const = 0;
    virtual const ATubeNode* getNode(int x, int y) const = 0;
    virtual bool isTubeOK() const = 0;
};

struct ATubeNode {
    virtual ~ATubeNode();
    virtual bool isCorrect(const ITube* Tube) const = 0;
    int x;
    int y;
    int type;
};

struct Tube : ITube {
private:
    ATubeNode*** matrix;
    int size;
public:
    Tube();
    Tube(const int size);
    ~Tube();
    void addNode(ATubeNode* Node) const override;
    const ATubeNode* getNode(int x, int y) const override;
    bool isTubeOK() const override;
};

struct Node : ATubeNode {
    Node();
    Node(const int x, const int y, int type);
    ~Node();
    bool isCorrect(const ITube* Tube) const override;
};

#endif // !ITUBE_H