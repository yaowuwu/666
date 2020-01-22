#!/bin/sh

set -x #跟踪命令

SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-build}

mkdir -p $BUILD_DIR/ 
cd $BUILD_DIR/ 
cmake  $SOURCE_DIR 
make $* 


