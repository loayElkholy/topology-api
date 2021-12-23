#include "Component.hpp"
using cmp = Component;

cmp::Component(string ComponentId, string type) : ComponentId(ComponentId), type(type)
{
}
void cmp::add_netlist(map<string,string> &netlist)
{
    this->netlist = netlist;
}
void cmp::add_property(Properties p)
{
    properties =p;
}
map<string,string> cmp::get_netlist()
{
    return netlist;
}
Properties cmp::get_property(Properties p)
{
    return properties;
}
