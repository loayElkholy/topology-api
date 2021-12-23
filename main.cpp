#include <iostream>
#include "TopologyList.hpp"
#include "Topology.hpp"
#include "Component.hpp"

using namespace std;

int main()
{
    TopologyList tpl;
    string name;
    // do
    // {
    //     cout <<"enter file name : ";
    //     cin >> name;
    // } while (!tpl.readJSON("topology.json"));
    tpl.readJSON("topology.json");
    tpl.writeJSON("top1");
    return 0;
}