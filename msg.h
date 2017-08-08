#ifndef _MSG_H
#define _MSG_H

#include <iostream>
using namespace std;

class Msg{
	
	public:
		string body_text;
		virtual void show() = 0;
		bool operator >(const Msg& p) const;
	
	protected:
		double safe_factor;
		virtual void update_safe_factor() = 0;
		
};




#endif
