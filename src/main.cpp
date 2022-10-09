/*
 *	Author: Pier Luigi Manfrini
 *	
 *	A simple program to interface with the HackRF One
 *
 *
 */
#include "../includes/utils.hpp"

int main(int argc, char** argv){

/* PRINT BANNER */
print_banner(); 

/*CLI PARSING */
check_cli_arguments(argc, argv);

/*INITIALIZE HACKRF LIBRARY*/
initialize_libhackrf();

/*FIND HACKRF DEVICES AVAILABLE IN THE SYSTEM*/
hackrf_device_list_t* list_of_devices = nullptr;
list_of_devices = hackrf_device_list();
print_list_of_attached_hackrf_devices(list_of_devices);

/*INITIALIZE RADIO */
HackRF_One* radio = initialize_radio();



// To do inside the hackrf class!
// HACKRF OPEN
hackrf_device* device = nullptr;
int open_return =  hackrf_open(&device);
open_return ++;



return EXIT_SUCCESS;
}

