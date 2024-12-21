#include "encoder_interface.h"
#include <iostream>



Interface::Interface(CANAPI_Bitrate_t baudrate = CANBTR_INDEX_250K , CANAPIT_OpMode_t opmode = CANMODE_DEFAULT, std::string_view serial_port = "/dev/ttyS3"){
	this->bitrate.index = baudrate; 
	this->opmode.byte = opmode;
	this-> serial_port = serial_port; 
}; 

CANAPI_Reuturn_t Interface::initialize_channel(){
	if((ret_val = mySerialCAN.InitializeChannel(serial_port,opmode)) != CSerialCAN::NoError){
		std::cerr << "[x] interface could not be initialzed"<<endl; 
	}
	else{
		std::cout<<" [o] initialized channel at "<<serial_port<<". \n";
		std::cout<<" [o] starting interface... \n"; 
		if((ret_val = mySerialCAN.StartController(bitrate))!= CSerialCAN::NoError){
			std::cerr <<"[x] interface could not be started, tearing down... \n"; 
			teardown_channel(); 
		}
		else{
			std::cout<<"[o] interface started \n Press Ctrl+c to abort.."; 
		}
	}
	return ret_val; 
}

void Interface::begin_read_loop(int timeout){
	
}



CANAPIT_Return_t Interface::teardown_channel(){ 
	if((ret_val = mySerialCAN.TeardownChannel())!= CSerialCAN::NoError){
		std::cerr <<"[x] interface could not be shutdown" <<std::endl;
	}
	else{
		std::cout<<"[o] interface shutdown successfuly"
	}
}

