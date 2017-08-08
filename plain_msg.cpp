#include <iostream>
#include "plain_msg.h"

using namespace std;

static string owner_string[] = { 
	[A]="A",
	[B]="B",
	[C]="C",
	[D]="D",
	[E]="E"
};

void PlainMsg::show()
{
	cout << "----------------------------------------" << endl << endl;
	cout << "Plain message:" << endl;
	cout << "Safe Factor: "  << this->safe_factor << endl;
	cout << "Msg Length: " << this->body_text.size() << endl;
	cout << "Owner Class: " << owner_string[this->owner_class] << endl;
	cout << "----------------------------------------" << endl << endl;
}


void PlainMsg::update_safe_factor()
{
	cout<<"plainmsg update_safe_factor"<<endl;
	safe_factor = 0.7 * owner_class + 0.3 * (1.0 / body_text.size());
	cout<<"safe factor =" << safe_factor << endl;
}


void PlainMsg::set_owner_class(owner_t owner_class)
{
	this->owner_class = owner_class;
	this->update_safe_factor();
}
