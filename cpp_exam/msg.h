#ifndef _MSG_H
#define _MSG_H

#include <iostream>
using namespace std;

class Msg{
	
	public:
		/* variables */
		string body_text;
		
		/* functions */
		virtual ~Msg(){ };
		virtual void show() = 0;
		bool operator >(const Msg& p) const;
	
	protected:
		/* variables */
		double safe_factor;
		
		/* functions */
		virtual void update_safe_factor() = 0;
		
};




#endif
