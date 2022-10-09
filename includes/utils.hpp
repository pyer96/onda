#pragma once

#include <cstdlib>
#include <getopt.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <strings.h>
#include <libhackrf/hackrf.h>
#include "HackRF_One.hpp"

#define BANNER_FILENAME "includes/banner"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


void check_cli_arguments(int argc, char** argv);
void initialize_libhackrf();

HackRF_One* initialize_radio(hackrf_device*);
void print_banner();
void print_list_of_attached_hackrf_devices(struct hackrf_device_list* list);
