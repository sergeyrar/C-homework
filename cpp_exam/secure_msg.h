#ifndef _SECURE_MSG_H
#define _SECURE_MSG_H

#include "msg.h"

typedef enum {
	PWD,
	AES,
	PKI,
	SSL
}sec_type_t;


typedef enum {
	LOW,
	NORM,
	MID,
	HIGH
}str_t;

class SecureMsg: public Msg {
	
	public:
		/* functions */
		virtual ~SecureMsg();
		virtual void show();
		void set_key_strenght(str_t key_strength);
		void set_security_type(sec_type_t security_type);
		
	protected:
		/* variables */
		str_t key_strength;
		sec_type_t security_type;
		
		/* functions */
		virtual void update_safe_factor();
};



#endif

