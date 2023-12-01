CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
TARGET_REGISTRATION = test_registration
TARGET_TERMINAL = test_filesystem
TARGET_SYSTEM = test_system
SRC_FILES_REGISTRATION = Registration_testing.cpp ../Registration.cpp
SRC_FILES_TERMINAL = Filesystem_testing.cpp ../Filesystem.cpp
SRC_FILES_SYSTEM = System_testing.cpp ../DataCenter.cpp ../Filesystem.cpp ../Reports.cpp ../Terminal.cpp ../Registration.cpp
OBJ_FILES_REGISTRATION = $(SRC_FILES_REGISTRATION:.cpp=.o)
OBJ_FILES_TERMINAL = $(SRC_FILES_TERMINAL:.cpp=.o)
OBJ_FILES_SYSTEM = $(SRC_FILES_SYSTEM:.cpp=.o)

all: $(TARGET_REGISTRATION) $(TARGET_TERMINAL) $(TARGET_SYSTEM)

$(TARGET_REGISTRATION): $(OBJ_FILES_REGISTRATION)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TARGET_TERMINAL): $(OBJ_FILES_TERMINAL)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TARGET_SYSTEM): $(OBJ_FILES_SYSTEM)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET_REGISTRATION) $(TARGET_TERMINAL) $(TARGET_SYSTEM)\
	$(OBJ_FILES_REGISTRATION) $(OBJ_FILES_TERMINAL) \
	$(OBJ_FILES_SYSTEM) $(OBJ_FILES_SYSTEM)

