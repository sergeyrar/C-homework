#include "msg.h"



bool Msg::operator> (const Msg& rhs) const
{
	return ((this->safe_factor > rhs.safe_factor) ? 1 : 0);
}



