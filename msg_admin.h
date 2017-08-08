#ifndef _MSG_ADMIN_H
#define _MSG_ADMIN_H

#include <vector>
#include "msg.h"


using std::vector;

class MsgAdmin {
	public:
		void show_all_msgs();
		void push(Msg *msg);
		void pop();
		bool is_empty();
		bool is_full();
	
	protected:
		vector <Msg*> msg_arr;
};



#endif

