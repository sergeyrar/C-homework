CXX=g++
CFLAGS= -Wall
OFILES= main.o msg.o secure_msg.o plain_msg.o msg_admin.o


all: main

main: $(OFILES)
	$(CXX) $(OFILES) -o main
	
main.o: main.cpp
	$(CXX) -c main.cpp $(CFLAGS)

msg.o: msg.cpp
	$(CXX) -c msg.cpp $(CFLAGS)

secure_msg.o: secure_msg.cpp
	$(CXX) -c secure_msg.cpp $(CFLAGS)
	
plain_msg.o: plain_msg.cpp
	$(CXX) -c plain_msg.cpp $(CFLAGS) 
	
msg_admin.o: msg_admin.cpp
	$(CXX) -c msg_admin.cpp $(CFLAGS) 

clean:
	rm -f main $(OFILES)
