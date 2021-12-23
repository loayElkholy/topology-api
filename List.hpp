#pragma once
#include <iostream>
#include "Topology.hpp"
#include "Component.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace std;
template<typename T> 
class List
{
    int id;
    vector<T> list;
};