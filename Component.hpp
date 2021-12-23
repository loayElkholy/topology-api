#pragma once
#include <iostream>
#include <map>
using namespace std;

typedef struct
{
    string name;
    float default_value;
    float min;
    float max;
} Properties;
class Component
{
    friend class TopologyList;
    friend class Topology;
    string ComponentId;
    string type;
    Properties properties;
    map<string, string> netlist;

public:
    Component(string ComponentId, string type);
    void add_netlist(map<string, string> &netlist);
    void add_property(Properties p);
    map<string,string> get_netlist();
    Properties get_property(Properties p);
};