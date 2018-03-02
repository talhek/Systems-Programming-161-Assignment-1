#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include "../include/cyberdns.h"
#include "../include/cyberexpert.h"
#include <set>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void parseComputersXml(CyberDNS & hash_map);

void parseNetworkXml(CyberDNS & hash_map);

void  parseEventsXml(CyberDNS & hash_map);
void keep_cleaning(CyberDNS & hash_map);