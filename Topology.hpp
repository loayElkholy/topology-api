#pragma once
#include <iostream>
#include "Component.hpp"
#include <vector>

using namespace std;

class Topology
{
    friend class TopologyList;
    string TopologyId;
    vector <Component> component_list;
public:
    Topology(string id);
    void addComponent(Component comp);
    string get_id();
    vector <Component> get_component_list();

};