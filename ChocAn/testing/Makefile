CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = test
SRC_FILES = Registration_testing.cpp ../Registration.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ_FILES)

