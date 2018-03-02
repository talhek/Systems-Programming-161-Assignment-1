#include "../include/cyberpc.h"
#include "../include/Parser.h"
#include "../include/cyberdns.h"
#include "../include/cyberexpert.h"
#include "../include/cyberworm.h"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/xml_parser.hpp"
#include "boost/foreach.hpp"
#include <string>
#include <iostream>

void parseComputersXml(CyberDNS & hash_map){
  const std::string XML_PATH1 = "./computers.xml";
    boost::property_tree::ptree pt1;
    boost::property_tree::read_xml(XML_PATH1, pt1);

            BOOST_FOREACH( boost::property_tree::ptree::value_type const& v ,pt1) {
                if (v.first == "computer"){
                   string computerName = v.second.get<std::string>("name");
                   string  computerOS = v.second.get<std::string>("os");
 		  CyberPC* pc = new CyberPC (  computerOS,  computerName);
		  hash_map.AddPC(*pc);
		}
            }
}


void parseNetworkXml(CyberDNS & hash_map){
  const std::string XML_PATH1 = "./network.xml";
    boost::property_tree::ptree pt2;
    boost::property_tree::read_xml(XML_PATH1, pt2);

            BOOST_FOREACH( boost::property_tree::ptree::value_type const& v ,pt2) {
                if (v.first == "wire"){
            string pointA = v.second.get<std::string>("pointA");
		   string pointB = v.second.get<std::string>("pointB");
		    cout << "Connecting " << pointA <<" to " << pointB << endl; 
		    hash_map.GetCyberPC(pointA).AddConnection(pointB);
		    hash_map.GetCyberPC(pointB).AddConnection(pointA);
                }
            }

}

  std::vector<CyberExpert*> cyber_experts;
  
  
void parseEventsXml(CyberDNS &hash_map){
  const std::string XML_PATH1 = "./events.xml";
    boost::property_tree::ptree pt3;
    boost::property_tree::read_xml(XML_PATH1, pt3);
    int days = 0;

     int totalDays = pt3.get<int>("termination.time");


            BOOST_FOREACH( boost::property_tree::ptree::value_type const& v ,pt3) {
	        cout <<"Day : " << days<< endl;

		    if (v.first == "clock-in"){
                    string name = v.second.get<std::string>("name");
                    int workTime = v.second.get<int>("workTime");
		    int restTime = v.second.get<int>("restTime");
	            int efficiency = v.second.get<int>("efficiency");
		    CyberExpert* cyber_pc_expert = new CyberExpert(name, workTime,restTime, efficiency);
		    cyber_experts.push_back(cyber_pc_expert);
		    cout << "Clock-In: " << name <<" began working " << endl;


                }

                 else if (v.first == "hack"){
                    string computer = v.second.get<std::string>("computer");
                    string wormName = v.second.get<std::string>("wormName");
		    int wormDormancy = v.second.get<int>("wormDormancy");
	            string wormOs = v.second.get<std::string>("wormOs");
		    cout << " " << endl;
		    cout <<"	Hack occured on " << computer << endl;
		    CyberWorm* attack_worm = new CyberWorm(wormOs, wormName , wormDormancy );
		    hash_map.GetCyberPC(computer).Infect(*(new CyberWorm(*attack_worm)));
	
 		    delete attack_worm;
		    }
		    ++days;
 		    keep_cleaning(hash_map);
 		    hash_map.keep_infecting();
	  
	      }
		
		while (days <= totalDays ){
		cout <<"Day : " << days<< endl;
		  ++days;	 
 		  keep_cleaning(hash_map);
		  hash_map.keep_infecting();
		}
		
		   
			
  		for(std::vector<CyberExpert*>::iterator it = cyber_experts.begin(); it != cyber_experts.end(); ++it) {
 		  delete *it; }
}

void keep_cleaning(CyberDNS & hash_map){
  
  for (unsigned i = 0; i<cyber_experts.size(); i++){
       (*cyber_experts.at(i)).expertDoJob(hash_map);
  }
		
}
