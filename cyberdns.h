

#ifndef CYBERDNS_H
#define CYBERDNS_H
#include <string>
#include <vector>
#include "../include/cyberpc.h"
#include <iostream>
#include <map>
using namespace std;
class CyberPC; //Forward deceleration

class CyberDNS
{
private:
    std::map<const std::string, CyberPC &> cyber_DNS_;	//Hash map to hold PC names and pointers

 
public:
    CyberDNS();
	void AddPC(CyberPC & cyber_pc_);
	CyberPC & GetCyberPC(const std::string & cyber_pc_name) const;	
	  void keep_infecting();
	  std::map<const std::string, CyberPC &> getMap();
	std::vector<std::string> GetCyberPCList();// Return list of PC's as a vector of strings.		
  virtual ~CyberDNS();
	
};

#endif
