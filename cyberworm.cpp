#include "../include/cyberworm.h"
#include <string>
#include <iostream>
using namespace std;
 CyberWorm::CyberWorm(std::string cyber_worm_os, std::string cyber_worm_name, int cyber_worm_dormancy_time): cyber_worm_os_(cyber_worm_os), cyber_worm_name_(cyber_worm_name), cyber_worm_dormancy_time_(cyber_worm_dormancy_time)
 {
   
}

 CyberWorm:: CyberWorm(const CyberWorm& other):cyber_worm_os_(other.cyber_worm_os_),cyber_worm_name_(other.cyber_worm_name_), cyber_worm_dormancy_time_(other.cyber_worm_dormancy_time_)
 {

 }
string CyberWorm::getName() const{
  return cyber_worm_name_;
}
string CyberWorm::getOs() const{
  return cyber_worm_os_;
}
int CyberWorm::getDormTime(){
  return cyber_worm_dormancy_time_;
}
