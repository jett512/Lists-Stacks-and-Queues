// Run in repl.it:
// clang++-7 -pthread -std=c++17 -o call call.cpp; ./call < call_test1.in

#include <iostream>
#include <string>
#include <cassert>

#include "dlist.h"

/*
 * Format of input line:
 *
 *  <timestamp> <Name> <status> <duration>
 *
 * Note: first four fields terminated by whitespace
 *       request terminated by newline.
 *
 * Format of input file:
 * 
 * A single line with the number of requests
 * zero or more input lines followed by EOF.
 */

enum Status {
  NONE = 0, SILVER = 1, GOLD = 2, PLATINUM = 3
};

struct reqNode {
  int         timestamp;
  std::string name;
  Status      status;
  int         duration;
};

/**** INSTRUCTOR NOTE: DO NOT MODIFY ABOVE THIS LINE ****/

/***************************************************
 * INSTRUCTOR NOTE: Implement the functions below. *
 **************************************************/


/*		
		Algorithm ObtainRequests
	*****Psuedocode*****
		define count
		recieve input and store in count
		
		for i less than count loop
			new pointer temp
			define timestamp
			define name
			define status
			define duration
				
			recieve input for timestamp, name, status, duration
			temp-> timestamp = timestamp;
			temp-> name = name
			temp->status = Status
			temp-> duration = duration
			
			push temp to back
		
	*****Comments*****
	We must obtain all of the data from the user, and utilize pointers to store their values into memory.
	First the user must input the total number of callers to be used, this is stored at count.
	
	A for loop is created for the user to enter the information, and will stop once the loop has ran once for each data set.
	create a new reqNode pointer temp to be used.
	Define all of the variables to be stored. They are unassigned because the user will enter these values.
	Take input for the variables in question. It is assumed that the user will enter them correctly for this function.
	
	Then each variable needs to be kept track of with a pointer, this allows use of the values in other parts of the programm.
	Finally, each data set is entered in the back of our list.
	This is because our dlist is a queue, so every person must enter from the back, and be removed from the front. 
	Once the loop has ended, all of the data has been entered.
	
*/
// EFFECTS: Reads and parses each request from the standard input stream
// std::cin. For each request, creates a reqNode struct and enqueues their
// pointers in the requests queue, which is a Dlist of pointers to reqNode
// structs. 
void ObtainRequests(Dlist<reqNode*> &requests) {
  // Implement this function.
 	int count;
	std::cin >> count;

  	for(int i = 0;i < count; i++)
	{
		reqNode* temp = new reqNode; //create new pointer

		//Define all of the variables to be stored
		int timestamp;
		std::string name;
		std::string status;
		int duration;
	
		//Take input for the variables
		std::cin >> timestamp >> name >> status >> duration;

		//pointer for each variable
		temp-> timestamp = timestamp;
		temp-> name = name;
		temp->status = NONE, SILVER, GOLD, PLATINUM ;
		temp-> duration = duration;

		requests.InsertBack(temp);//enqueue each person
	}	
}



/*		
		Algorithm InsertRequests
	*****Psuedocode*****
		while request list not empty
			pointer temp = removefront elem
			if temp's timestamp != clock
				push temp to back
				break loop
			else
				if temp's status = none
					print call from info
					push temp to back of regular queue
				else if temp's status = silver
					print call from info
					push temp to back of silver queue
				else if temp's status = gold
					print call from info
					push temp to back of gold queue
				else
					print call from info
					push temp to back of platinum queue
					
	*****Comments*****
	first we must create a new node to be used, and call ObtainRequests to get the user info
	Then a while loop is created to loop through the requests so long as they arent empty.
	
	pointer temp is set equal the popped front element, because this is the first person in the queue.
	if temp's timestamp isnt equal to clock, then the current timestamp is not ready to be answered.
	When thats the case, temp is pushed in the back of the queue and the loop is broken.
	
	Else, temp's timestamp is equal to clock, therefore the current tick matches the call order. 
	Now the callers will be catagorized by their current statues, regular, silver, gold, or platinum.
	This is done by else if statments to check if temp's status is equal to the respecive status
	If it is equal, puch temp to the back of the respective status queues to be removed later.
	Then print to user the information associated with each user that falls into each status catagory.
*/
// EFFECTS: Insert any callers with timestamps equal to the tick number
// (the clock param) into their appropriate queues. When a caller is
// inserted, you should print a message that exactly matches the following 
// example (with the correct name and status):
// 
// Call from Jeff a silver member
//
// You can get the appropriate status by calling status_names[status]. 
// Note: If two (or more) calls have the same timestamp, they should be
// printed in input file-order, not in priority-order.
void InsertRequests(Dlist<reqNode*> &requests, Dlist<reqNode*> queues[], int clock, std::string status_names[]) {
  // Implement this function.
  
  reqNode* temp = new reqNode;
  ObtainRequests(queues[clock]);//get input from user
	while(requests.IsEmpty() == false)//loop through the requests so long as they arent empty.
  	{
    		temp = requests.RemoveFront();//first person in the queue
    		if(temp->timestamp != clock )//current timestamp is notready
      		{
        		requests.InsertBack(temp);//return to end of queue
        		break;

      		}
      		else//current tick matches the call order
      		{
            	//catagorize status into 4 different queues
				//one for each status type
				
        		if(temp->status = NONE)//regular status
        		{
				
          			queues[0].InsertBack(temp);//push to back of regular queue
          			std::cout <<"Call from " << temp->name << " a " << status_names[temp->status] << " member" ;
          			std::cout  << '\n';
				
        		}	
        		else if(temp->status = SILVER)//silver status
        		{
				
          			queues[1].InsertBack(temp);//push to back of silver queue
          			std::cout <<"Call from " << temp->name << " a " << status_names[temp->status] << " member" ;
          			std::cout  << '\n';
        		}	
        		else if(temp->status = GOLD)//gold status
        		{
          			queues[2].InsertBack(temp);//push to back of gold queue
          			std::cout <<"Call from " << temp->name << " a " << status_names[temp->status] << " member" ;
          			std::cout  << '\n';
        		}
        		else//must be platinum
        		{
          			queues[3].InsertBack(temp);////push to back of platinum queue
          			std::cout <<"Call from " << temp->name << " a " << status_names[temp->status]<< " member" ;
          			std::cout  << '\n';
        		}	
      		}
	}


}



/*		
		Algorithm SimulateAgent
	*****Psuedocode*****
	if time agent busy = 0

		if status = platinum
			print answering from
			remove front of platinum queue
		else if status = gold
			print answering from
			remove front of gold queue
		else if status = silver
			print answering from
			remove front of silver queue
		else if status = none
			print answering from
			remove front of none queue
		else
			no more calls
			return true
	else
		decrement time agent busy
	return false
		
	*****Comments*****
	Begin by checking if the current time the agent is busy is zero, if so the agent can answer a call
	Else the agent is busy for this tick, then time budy should decrement each time they are busy. 

	Once inside if statment, multiple nested ifs are in place to check the callers status. 
	The order is based on the status ranking, from highest to lowest
	If true for a certain status, the output print statement to user, and removes the front of the queue for the respective queue.
	This dequeues the person in the front and answers their call. They remain on the call until time agent busy is decremented to zero.
	temp's duration is equal to time agent busy, as each calls duration is how long the agent will be busy

	Outside else means there is no status, therefore the agent isnt busy and there is no more calls, so return true that session is over. 
	
*/
// EFFECTS: Simulate the actions of the agent at this tick. The agent must
// follow these rules:
// 1. If the agent is not busy, the agent checks each queue, in priority order
// from Platinum to None. If the agent finds a call, the agent answers the
// call, and you should print a message that exactly matches the following 
// example (with the correct name):
// 
// Answering call from Jeff
// 
// You will need to decrement time_agent_busy by 1. 
// 
// 2. If the agent was already busy at the beginning of this tick, the agent
// continues servicing the current client. You will need to decrement
// time_agent_busy by 1. 
// 
// 3. If the agent is not busy, and there are no current calls, the agent
// does nothing. 
//
// If all calls have been placed, answered, and completed, then return true
// to end the program. Otherwise, return false.
bool SimulateAgent(Dlist<reqNode*> &requests, Dlist<reqNode*> queues[], int &time_agent_busy) {
  // Implement this function.
	
	
	reqNode* temp = new reqNode; 
	if(time_agent_busy = 0)//agent is free to answer calls
	{
		//check the callers status

		if(temp->status == PLATINUM)//if platinum status
		{
			std::cout << "Answering call from" << queues[3].RemoveFront() <<'\n';
			temp->duration = time_agent_busy; //how long agent is busy
		}
		 else if(temp->status = GOLD)//if gold status
                {
			std::cout << "Answering call from"<< queues[2].RemoveFront() << '\n' ;
			temp->duration = time_agent_busy;//how long agent is busy
                }
		 else if(temp->status = SILVER)//if silver status
                {
			std::cout << "Answering call from" << queues[1].RemoveFront() << '\n';
			temp->duration = time_agent_busy;//how long agent is busy
                }
		 else if(temp->status = NONE)//if no status
                {
			std::cout << "Answering call from"<< queues[0].RemoveFront() << '\n';
			temp->duration = time_agent_busy;//how long agent is busy
                }
		else//no status given, no more calls
		{
			return true;//no more calls
		}	
	}
	else //agent is busy
	{
		time_agent_busy--;//each tick decrements time busy
	}
  return false;//more calls remaining
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

int main() {
  // The current time, starting at tick 0. 
  int clock = 0;

  // The remaining time that the agent is busy with the current
  // caller, or 0 if the agent is not busy. 
  int time_agent_busy = 0;

  // An array of four queues, one for each status: regular, silver,
  // gold, platinum. Each queue is a DList of pointers to reqNode
  // structs. 
  Dlist<reqNode*> queues[4]; 

  // A queue of requests matching the input. The queue is a DList of 
  // pointers to reqNode structs.
  Dlist<reqNode*> requests;

  // Flag for whether or not the program should terminate. 
  bool done = false;

  // Array of status name strings for each Status. 
  std::string status_names[4];
  status_names[NONE] = "regular";
  status_names[SILVER] = "silver";
  status_names[GOLD] = "gold";
  status_names[PLATINUM] = "platinum";

  // Run call center simulation.
  ObtainRequests(requests);
  while (!done) {
    std::cout << "Starting tick #" << clock << std::endl;
    InsertRequests(requests, queues, clock, status_names);
    done = SimulateAgent(requests, queues, time_agent_busy);
    clock++;
  }

  return 0;
}



