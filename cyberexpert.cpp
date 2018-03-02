#include "../include/cyberexpert.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


   CyberExpert:: CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_):
   cyber_expert_name_(cyber_expert_name_) , cyber_expert_work_time_(cyber_expert_work_time_) , cyber_expert_rest_time_(cyber_expert_rest_time_), cyber_expert_efficiency_(cyber_expert_efficiency_)
   {
           tmp_curr_rest=0;
           tmp_curr_worked=cyber_expert_work_time_;
	   isWorking=true;
   }
   
	
	  
  
	void CyberExpert::expertDoJob(CyberDNS & hash_map){
	  
	    if(tmp_curr_worked>0){
		for(int i=0 ; i<cyber_expert_efficiency_;++i){
		    bool stop=false;
		    for ( int j = (((hash_map.GetCyberPCList()).size())-1); (j >=0)&&(stop==false); j--){
		      stop=true;
		      cout<<cyber_expert_name_<<" examining "<<hash_map.GetCyberPCList().at(j-i)<<endl;
		      this->Clean(hash_map.GetCyberPC(hash_map.GetCyberPCList().at(j-i)));  
		      }
	 
		  }
		  tmp_curr_worked--;
		  if(tmp_curr_worked==0) {
		    isWorking=false;
		    tmp_curr_rest++;
		    cout<<cyber_expert_name_<<" is taking a break"<<endl;
		  }
     }
     else {
     if(tmp_curr_rest==cyber_expert_rest_time_) {
         
	 isWorking=true;
	 tmp_curr_worked=cyber_expert_work_time_;
	 tmp_curr_rest=0;
	 if(tmp_curr_worked==cyber_expert_work_time_)
	 {
	   cout<<cyber_expert_name_<<" is back to work"<<endl;
	 }
     }
     else
     {
       tmp_curr_rest++;
     }
     
    }
	  
	}
    void CyberExpert::Clean(CyberPC & cyber_pc)
    {
      cyber_pc.Disinfect();
    }
  string CyberExpert::getName()const
 {
   return cyber_expert_name_;
 }
  int CyberExpert::getTimeRested()const
  {
    return cyber_expert_rest_time_;
  }
  int CyberExpert::getWorkTime() const
  {
    return cyber_expert_work_time_;
  }
    int CyberExpert::getWorkEfficiency() const
  {
    return cyber_expert_efficiency_;
  }
  
   CyberExpert::~CyberExpert(){}
  