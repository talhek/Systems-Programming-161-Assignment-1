#include "../include/cyberdns.h"
#include "../include/cyberpc.h"
#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

CyberDNS::CyberDNS(){
std::map<const std::string, CyberPC &> cyber_DNS_;
  
}

 void CyberDNS::AddPC(CyberPC & cyber_pc_) {
       cout << "Adding to server: " << cyber_pc_.getName() <<endl;
       cout << cyber_pc_.getName() << " connected to server" <<endl;
      cyber_DNS_.insert(std::pair<const std::string, CyberPC &> (cyber_pc_.getName(),cyber_pc_));
 }



CyberPC&  CyberDNS::GetCyberPC(const std::string & cyber_pc_name) const
{
  return (*cyber_DNS_.find(cyber_pc_name)).second;

}

std::map<const std::string, CyberPC &>  CyberDNS::getMap(){
  return cyber_DNS_;
}

	  
 std::vector<std::string> CyberDNS::GetCyberPCList(){	
    std::vector  <std::string> pcList;

    for( std::map<const std::string, CyberPC &>:: iterator it = cyber_DNS_.begin(); it != cyber_DNS_.end(); ++it ) {
    	pcList.push_back( it->second.getName() );
    }
    return pcList;
}

void CyberDNS::keep_infecting(){
      for( std::map<const std::string, CyberPC &>:: reverse_iterator it = cyber_DNS_.rbegin(); it != cyber_DNS_.rend(); ++it ) {

		if (it->second.getTimeInfect()==0 && it->second.checkInfected() ==true ){  
	  it->second.Run(*this); }
	if (it->second.getTimeInfect() > 0 && it->second.checkInfected() == true) {
	  cout<< "	" << it->second.getName()  << ":Worm "<< it->second.getPcWormName() << " is dormant" <<endl;  
	  it->second.SetTimeToInfect();
      }
	
    }
}

CyberDNS::~CyberDNS() {
         for( std::map<const std::string, CyberPC &>:: iterator it = cyber_DNS_.begin(); it != cyber_DNS_.end(); ++it ) {
	      CyberPC *pcToDelete = &(it->second);
	      delete pcToDelete;
	 }
	  cyber_DNS_.clear();
}


	  


