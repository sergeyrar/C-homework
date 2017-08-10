#include "msg.h"
#include "secure_msg.h"
#include "plain_msg.h"
#include "msg_admin.h"

/* Local functions */
static int get_plain_msg_info(Msg *msg_ptr)
{
	size_t user_input;	
	PlainMsg *plain_msg_ptr = dynamic_cast <PlainMsg*> (msg_ptr);

	
	cout << "Please enter your message:" << endl;
	cin >> msg_ptr->body_text;
	cout << "Please specify owner class, possible range 0-4" << endl;
	cin >> user_input;	

	owner_t owner_class = static_cast <owner_t> (user_input);			
	plain_msg_ptr->set_owner_class(owner_class);
	
	return 0;
}

static int get_secure_msg_info(Msg *msg_ptr)
{
	size_t user_input;	
	SecureMsg *secure_msg_ptr = dynamic_cast <SecureMsg*> (msg_ptr);
	
	
	cout << "Please enter your message:" << endl;
	cin >> msg_ptr->body_text;
	cout << "Please specify security type, possible range 0-3" << endl;
	cin >> user_input;
				
    sec_type_t security_type = static_cast <sec_type_t> (user_input);						
	secure_msg_ptr->set_security_type(security_type);
	
	cout << "Please specify key strength, possible range 0-3" << endl;
	cin >> user_input;
	
	str_t key_strength = static_cast <str_t> (user_input);
	secure_msg_ptr->set_key_strenght(key_strength);
	
	return 0;
}

static void get_msg_num(size_t *num)
{
	cout << "How many messages do you want to evaluate?" << endl;
	cin >> *num;
	
	cout << "For each message please specify if it's a plain message or a secure one" << endl 
		 << "Plain message (0) , Secure message(1)" << endl	
		 << "In case of a plain message you will also be required to specify owner class" << endl
		 << "ownerclass options : A(0),B(1),C(2),D(3),E(4). A(least secure) , E(most secure)" << endl	
		 << "In case of a secure message you will also be required to specify security type and key strength" << endl
	     << "security type options: PWD(0), AES(1), PKI(2), SSL(3).  PWD(least secure), SSL(most secure)" << endl
	     << "key strength options: LOW(0), NORM(1), MID(2), HIGH(3). LOW(least secure), HIGH(most secure)" << endl << endl << endl;
}

static void clear_mem(Msg **msg_ptr, size_t num)
{
	size_t i;
	
	for (i = 0; i < num; i ++)
	{
		delete(msg_ptr[i]);
	}
}


/* MAIN */
int main()
{
	size_t num = 0;
	size_t i;
	size_t msg_type;
	
	MsgAdmin msg_arr;

	get_msg_num(&num);
	
	Msg *msg_ptr[num] = {};	
	
	for (i = 0; i < num ; i++)
	{	
		cout << "What is the security level of the message " << i << "?  possible range 0-1" << endl;
		cin >> msg_type;
					
		switch(msg_type)
		{
			case PLAIN_MSG:
			{
				msg_ptr[i] = new PlainMsg;
				
				if (get_plain_msg_info(msg_ptr[i]) < 0)
				{
					cout << "Error getting plain message info" << endl;
				}
				break;
			}
			
			case SECURE_MSG:
			{
				msg_ptr[i] = new SecureMsg;
				
				if (get_secure_msg_info(msg_ptr[i]) < 0)
				{
					cout << "Error getting secure message info" << endl;
				}
				break;				
			}
		
			default:
			{
				cout << "Wrong message type\n"<< endl;
				i--;
				continue;
			}
		}		
				
		msg_arr.push(msg_ptr[i]);
	}
	
	msg_arr.show_all_msgs();
		
	Msg &safest_msg = msg_arr.find_safest();	
	cout <<"The safest message is: " << endl;
	safest_msg.show();	
		
	Msg &safest_plain = msg_arr.find_safest(PLAIN_MSG);		
	cout <<"The safest palin message is: " << endl;
	safest_plain.show();
			
	Msg &safest_secure = msg_arr.find_safest(SECURE_MSG);		
	cout <<"The safest secure message is: " << endl;
	safest_secure.show();

	clear_mem(msg_ptr, num);
	
	return 0;
}
