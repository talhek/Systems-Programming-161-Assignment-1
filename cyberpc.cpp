#include "../include/cyberpc.h"
#include <string>
#include <iostream>

using namespace std;

CyberPC::CyberPC(std::string cyber_pc_os, std::string cyber_pc_name):cyber_pc_os_(cyber_pc_os), cyber_pc_name_(cyber_pc_name){

  cyber_pc_time_to_infect_=0;
}

 string CyberPC::getName() const
{
  return cyber_pc_name_;
}

string CyberPC::getOs()const 
{
  return cyber_pc_os_;
}

int CyberPC::getTimeInfect() {
  return cyber_pc_time_to_infect_ ;
}

void CyberPC::SetTimeToInfect(){
  cyber_pc_time_to_infect_--;
}
string CyberPC::getPcWormName(){
  return (*cyber_worm_).getName();
}

vector<std::string> CyberPC::getLinkedPCs() const{
  return cyber_pc_connections_;
}

void CyberPC::AddConnection(std::string  second_pc)
{
cout <<"	" << cyber_pc_name_ <<" now connected to  " << second_pc<< endl; 
      
   cyber_pc_connections_.push_back(second_pc);

}
void CyberPC:: Infect(CyberWorm & worm) {
     if (worm.getOs() == cyber_pc_os_){
      if (cyber_worm_ !=NULL){
	  delete cyber_worm_;
	  cyber_worm_ = NULL;
      }
         cyber_worm_ = &worm;

   cout<< "		" << cyber_pc_name_ << " infected by " << worm.getName() <<endl;

         cyber_pc_time_to_infect_= worm.getDormTime();
   }
else{
        cout<<"		Worm "<< worm.getName()  << " is incompatible with " << cyber_pc_name_ <<endl;
	delete &worm;
   }
  
}
void CyberPC::Run(const CyberDNS & server){
  if (cyber_worm_ != NULL) {
    cout<< "	" << cyber_pc_name_ << " infecting... "  <<endl;

    for(std::vector<string>::iterator it = cyber_pc_connections_.begin(); it != cyber_pc_connections_.end(); ++it) {
         server.GetCyberPC(*it).Infect(*(new CyberWorm(*cyber_worm_))); 

    }
  }	
  
}
bool CyberPC:: checkInfected()
{
  return cyber_worm_ != NULL;
}

void CyberPC::Disinfect() {
  if(cyber_worm_==NULL)
    return;
  cout << "	Worm " << (*cyber_worm_).getName() << " successfully removed from " << cyber_pc_name_ <<endl; 
    delete cyber_worm_;
  cyber_worm_ = NULL;
}

 CyberPC::~CyberPC(){
   if (checkInfected())
     delete cyber_worm_;
 }