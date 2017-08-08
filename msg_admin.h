#ifndef _MSG_ADMIN_H
#define _MSG_ADMIN_H

#include <vector>
#include "msg.h"

using std::vector;



typedef enum {	
	PLAIN_MSG,	
	SECURE_MSG	
}msg_type_t;


class MsgAdmin {
	public:
		/* functions */
		void show_all_msgs();
		void push(Msg *msg);
		void pop();
		bool is_empty();
		bool is_full();
		Msg& find_safest();
		Msg& find_safest(msg_type_t msg_type);
	
	protected:
		/* variables */
		vector <Msg*> msg_arr;
};



#endif

