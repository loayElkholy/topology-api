#include "Topology.hpp"

using TP = Topology;

TP::Topology(string id) : TopologyId(id)
{
}
void TP::addComponent(Component comp)
{
    component_list.push_back(comp);
}

string TP::get_id()
{
    return TopologyId;
}
vector <Component> TP::get_component_list()
{
    return component_list;

}
