cmake_minimum_required(VERSION 3.5.0)
project(sample VERSION 0.1.0 LANGUAGES C CXX)

add_executable(sample 
    main.cpp
    FSMState.h
    StateA.h
    StateB.h
    StateC.h
    FSMSample.h
    )

