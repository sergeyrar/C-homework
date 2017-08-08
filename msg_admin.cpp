#include <iostream>
#include "msg_admin.h"
#include "plain_msg.h"
#include "secure_msg.h"
#include <assert.h>

using namespace std;



void MsgAdmin::show_all_msgs()
{
	size_t i;
	cout << "-------------Administrating the following messages-----------" << endl << endl << endl;
	
	for (i = 0; i < msg_arr.size(); i++)
	{
		msg_arr[i]->show();
	}
}

Msg& MsgAdmin::find_safest()
{
	size_t i;
	Msg *msg_max = msg_arr[0];
	
	for (i = 0; i < msg_arr.size(); i++)
	{
		if (*msg_arr[i] > *msg_max)
		{
			msg_max = msg_arr[i];
		}
	}
	
	return *msg_max;		
}

Msg& MsgAdmin::find_safest(msg_type_t msg_type)
{
	size_t i;
	Msg *msg_max = 0;
	
	switch(msg_type)
	{
		case PLAIN_MSG:
		{
			for (i = 0; i < msg_arr.size(); i++)
			{	
				if (dynamic_cast <PlainMsg*> (msg_arr[i]))
				{
					msg_max = msg_arr[i];
					break;
				} 
			}		
			
			for (i = 0; i < msg_arr.size(); i++)
			{
				if (dynamic_cast <PlainMsg*> (msg_arr[i]))
				{
					if (*msg_arr[i] > *msg_max)
					{
						msg_max = msg_arr[i];
					}
				}
			}
			
			return *msg_max;	
		}	
			
		case SECURE_MSG:		
		{			
			for (i = 0; i < msg_arr.size(); i++)
			{	
				if (dynamic_cast <SecureMsg*> (msg_arr[i]))
				{
					msg_max = msg_arr[i];
					break;
				} 
			}		
			
			for (i = 0; i < msg_arr.size(); i++)
			{
				if (dynamic_cast <SecureMsg*> (msg_arr[i]))
				{
					if (*msg_arr[i] > *msg_max)
					{
						msg_max = msg_arr[i];
					}
				}
			}
			
			return *msg_max;	
		}	
	
		default: assert(0); //shouldn't happen
	}	
		
}

void MsgAdmin::push(Msg *msg)
{
	msg_arr.push_back(msg);
}

void MsgAdmin::pop()
{
	cout<<"pop message"<<endl;
}

bool MsgAdmin::is_empty()
{
	cout<<"is empty"<<endl;
	return 1;
}

bool MsgAdmin::is_full()
{
	cout<<"is full"<<endl;
	return 1;
}




