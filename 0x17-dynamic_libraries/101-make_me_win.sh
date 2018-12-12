#!/bin/bash
wget -O ~/libinjection.so https://github.com/BennettDixon/holbertonschool-low_level_programming/raw/master/0x17-dynamic_libraries/libinjection.so
export LD_PRELOAD=~/libinjection.so
