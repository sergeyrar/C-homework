#ifndef _PLAIN_MSG_H
#define _PLAIN_MSG_H

#include "msg.h"

typedef enum {
	A, B, C, D, E
}owner_t;

class PlainMsg : public Msg {
	
	public:
		/* functions */
		virtual ~PlainMsg();
		virtual void show();
		void set_owner_class(owner_t owner_class);
		
	protected:
		/* variables */
		owner_t owner_class;
		/* functions */
		virtual void update_safe_factor();
};



#endif
