# MAKEFILE for the HACKRF_ONE_DEVELOPMENT
# General rule format:
# target : prerequisites
# 	recipe
#
# Note: $@ identifies the target, 
# 	$^ identifies all the prerequisites, 
# 	$^ identifies the first prerequisite,
# 	$(@D) is the directory part of the target's path with the trailing / removed
#
# Author: Pier Luigi Manfrini



CXX 		:= g++
CXX_FLAGS 	:= -Wall -Wextra -Werror
LD_FLAGS 	:= -L/usr/local/lib -L/home/pier/hackrf/host/libhackrf/src/ -lhackrf -usb -pthread
INCLUDE 	:= -Iincludes/
BUILD 		:= ./build
OBJ_DIR 	:= $(BUILD)/objects
APP_DIR 	:= $(BUILD)/app
TARGET 		:= main
SRC 		:= $(wildcard src/*.cpp) $(wildcard src/*.c)
OBJECTS 	:= $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES 	:= $(OBJECTS:.o=.d)


# Default Rule
all: build $(APP_DIR)/$(TARGET)
	@echo "Build Finished!"
 
$(OBJ_DIR)/%.o: %.cpp
	@echo "Compiling Source Code"
	@mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) $(INCLUDE) -c $^ -o $@


$(APP_DIR)/$(TARGET): $(OBJECTS)
	@echo "Linking Objects"
	$(CXX) $(CXX_FLAGS) -o $@ $^ $(LD_FLAGS)
build: 
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)
	
clean: 
	-@rm -rfv $(OBJ_DIR)/* 
	-@rm -rfv $(APP_DIR)/*

info:
	@echo "[*] Application directory:	${APP_DIR} 	"
	@echo "[*] Objects directory:		${OBJ_DIR}	"
	@echo "[*] Sources directory: 		${SRC}		"
	@echo "[*] Objects: 			${OBJECTS} 	"
	@echo "[*] Dependencies: 		${DEPENDENCIES} "


