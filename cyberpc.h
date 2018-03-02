#ifndef CYBER_PC
#define CYBER_PC
#include <iostream>
#include <string>
#include "../include/cyberworm.h"
#include "../include/cyberdns.h"

class CyberDNS; // Forward decleration

class CyberPC
{
private:
    const std::string cyber_pc_os_;
    const std::string cyber_pc_name_;
    std::vector<std::string> cyber_pc_connections_;
    CyberWorm * cyber_worm_ = NULL;
    int cyber_pc_time_to_infect_;
    CyberPC(); // Prevent the use of an empty constructor
    
public:
    CyberPC(std::string cyber_pc_os, std::string cyber_pc_name);// Only use this constructor
     std::string getName()const ;
     std::string getOs() const;
     int getTimeInfect() ;
     std::vector<std::string> getLinkedPCs() const;
	void AddConnection(std::string  second_pc);					// Add a connection to this PC
	void Infect(CyberWorm & worm); 						// Add a worm to this PC
	void Run(const CyberDNS & server); // Activate PC and infect others if worm is active	
	void Disinfect();							// called by cyber expert, disinfect PC
       virtual ~CyberPC();
      bool checkInfected();
      void SetTimeToInfect();
      string getPcWormName();
};


#endif