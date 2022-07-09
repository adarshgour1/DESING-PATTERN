CXX      := g++
CXXFLAGS := -Wall -Wextra -g3
LDFLAGS  := -L/usr/lib -lstdc++ -lm -lpthread
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
INCLUDE  := -Iinclude
SRC      := $(shell find src/* -maxdepth 1 | grep -v main)

CURRENT_TIME = $(shell date "+%Y%m%d-%H.%M.%S")

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES \
         := $(OBJECTS:.o=.d) \
         := $(BIN:.bin=.d)



$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $(PWD)/$< -MMD -o $@

all:$(OBJECTS)
	@tput setaf 3
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(APP_DIR)/ABST_FACT_DESN $(PWD)/src/abstract_factory_design_main.cpp $(OBJECTS) $(LDFLAGS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(APP_DIR)/SING_FACT $(PWD)/src/singletone_pattern_design_main.cpp $(OBJECTS) $(LDFLAGS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(APP_DIR)/FACT_DESN $(PWD)/src/factory_design_main.cpp $(OBJECTS) $(LDFLAGS)
	@tput setaf 7

-include $(DEPENDENCIES)

.PHONY: all build clean debug release info run

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

clean:
	@tput setaf 1
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*
	@tput setaf 7

info:
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"
