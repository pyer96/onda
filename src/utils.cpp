#include "../includes/utils.hpp"

void check_cli_arguments(int argc ,char** argv){
	if(argc==1 & argv[1]==NULL){
	}else{
		exit(EXIT_FAILURE);
	}
}


void print_banner() {
  std::string line;
  std::ifstream banner(BANNER_FILENAME);
  if (banner.is_open()) {
    std::cout << BOLDBLUE  <<std::endl;
    while (getline(banner, line)) {
      std::cout << line << std::endl;
    }
    std::cout << RESET <<std::endl;
    banner.close();
  } else {
    std::cout << "Unable to open the HackRf One banner\n";
  }
}

void initialize_libhackrf(){
	printf(BOLDGREEN "> INITIALIZE LIBHACKRF...\n" RESET);
	int ret = hackrf_init();
	if (ret == 0){
		printf(GREEN "Successful!\n" RESET);
	}else{
		std::cout << "Exiting... Unable to initialize hackrf library" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void print_list_of_attached_hackrf_devices(struct hackrf_device_list* list){
	printf(BOLDGREEN "> FINDING ALL HACKRF DEVICES ATTACHED ON THIS SYSTEM...\n" RESET);
	for(int i = 0; i < list->devicecount; i++ ){	
		printf(GREEN "HACKRF DEVICE %d\n", i + 1);
		printf(GREEN "> serial number: %s\n" RESET, list->serial_numbers[i]);
	}

}

HackRF_One* initialize_radio(hackrf_device* radio_pointer){

}
