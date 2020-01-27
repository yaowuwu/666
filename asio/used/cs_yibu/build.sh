#!/bin/bash
g++ -o2 -std=c++14 -lboost_system  -lpthread client_daytime.cpp -o client
g++ -o2 -std=c++14 -lboost_system  -lpthread service_daytime.cpp -o service
