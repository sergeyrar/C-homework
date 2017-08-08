#include <iostream>
#include "secure_msg.h"

using namespace std;



static string sec_string[] = { 
	[LOW]="LOW",
	[NORM]="NORM",
	[MID]="MID",
	[HIGH]="HIGH"
};

static string key_string[] = { 
	[PWD]="PWD",
	[AES]="AES",
	[PKI]="PKI",
	[SSL]="SSL"
};



void SecureMsg::show()
{
	cout << "----------------------------------------" << endl << endl;
	cout << "Secure message:" << endl;
	cout << "Safe Factor: "  << this->safe_factor << endl;
	cout << "Msg Length: " << this->body_text.size() << endl;
	cout << "Security type: " << sec_string[this->security_type] << "    " 
		 <<	"Key strength: " << key_string[this->key_strength]<< endl;
	cout << "----------------------------------------" << endl << endl;
}


void SecureMsg::update_safe_factor()
{
	cout<<"secure_msg update_safe_factor"<<endl;
	safe_factor = 0.4 * security_type + 0.3 * key_strength + 0.3 * (1.0 / body_text.size());
	cout<<"safe factor =" << safe_factor << endl;
}



void SecureMsg::set_key_strenght(str_t key_strength)
{
	this->key_strength = key_strength;
	this->update_safe_factor();
}


void SecureMsg::set_security_type(sec_type_t security_type)
{
	this->security_type = security_type;
	this->update_safe_factor();
}
