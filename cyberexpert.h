#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include "../include/cyberpc.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CyberExpert
{
private:
    const std::string 	cyber_expert_name_;
    const int cyber_expert_work_time_;
    const int cyber_expert_rest_time_;
    const int cyber_expert_efficiency_;
    bool isWorking;
    int tmp_curr_rest;
    int tmp_curr_worked;
    CyberExpert(); // Prevent the use of an empty constructor
 
public:
    CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
 	void Clean(CyberPC & cyber_pc); 
	void expertDoJob(CyberDNS & add);
	std::string getName()const;
      int getTimeRested() const;
      int getWorkTime() const;
      virtual ~CyberExpert();
      int getWorkEfficiency() const;
};
#endif