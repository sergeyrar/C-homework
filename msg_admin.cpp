#include <iostream>
#include "msg_admin.h"

using namespace std;

void MsgAdmin::show_all_msgs()
{
	size_t i;
	cout << "-------------Administrating the following messages-----------" << endl << endl << endl;
	
	for (i=0; i<msg_arr.size(); i++)
	{
		msg_arr[i]->show();
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


