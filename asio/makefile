.SUFFIXES:
.PHONY: all clean

CXX := g++
CXXFLAGS := -o2 -std=c++14 -Wall -g 
INCLUDES := -I/usr/include/boost 
#LIBS :=  -lboost_system -lboost_filesystem -lboost_thread 
LIBS :=  -lboost_system  -lpthread
TARGET := demo 

SRCDIR := src
TESTDIR := test
SRCOBJS := $(patsubst %.cpp, %.o, $(wildcard $(SRCDIR)/*.cpp))
TESTOBJS := $(patsubst %.cpp, %.o, $(wildcard $(TESTDIR)/*.cpp))
OBJS := $(SRCOBJS) $(TESTOBJS)

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) $^ -o $@

$(OBJS): %.o: %.cpp
		$(CXX) $(CXXFLAGS) $(INCLUDES) $< -c -o $@

clean:
		-@rm -f $(TARGET)
		-@rm -f $(OBJS)
