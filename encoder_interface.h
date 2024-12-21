#include <iostream> 
#include "SerialCAN.h"

static CSerialCAN mySerialCAN(CSerialCAN()); 

class Interface{
private: 
	CANAPIT_OpMode_t opmode = {}; 
	CANAPI_Bitrate_t bitrate = {};  
	CANAPIT_Return_t ret_val= 0; 
	CANAPI_Message_t message; 
	std::string_view serial_port = "/dev/ttyS3"; 
public: 
	Interface(CANAPI_Bitrate_t baudrate, CANAPIT_OpMode_t opmode, std::string_view serial_port); 
	CANAPI_Reuturn_t initialize_channel(); 
	CANAPI_Return_t read_message(); 
	void begin_read_loop(int timeout); 
	CANAPI_Return_t teardown_channel(); 
}