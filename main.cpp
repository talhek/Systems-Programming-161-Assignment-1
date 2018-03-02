#include "../include/Parser.h"
#include "../include/cyberpc.h"
#include "../include/cyberdns.h"
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
  CyberDNS hash_map;
    parseComputersXml(hash_map);
   cout<<" " << endl;
   
   parseNetworkXml(hash_map);
   cout<<" " << endl;
   
   parseEventsXml(hash_map);
   

}