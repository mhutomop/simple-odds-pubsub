# Simple OpenDDS Publisher & Subscriber

This is a service which implements OpenDDS, acts as publisher and subscriber.

## Version

1.0.0

## Maintained by

CMS BackEnd Development Team
- Email: [leniot@len.co.id](mailto:leniot@len.co.id)

## Table of Contents

- [BE Sea Eagle Data Handler](#be-sea-eagle-data-handler)
    - [Version](#version)
    - [Maintained by](#maintained-by)
    - [Table of Contents](#table-of-contents)
    - [Getting Started](#getting-started)
        - [Prerequisites](#prerequisites)
        - [Installing](#installing)
    - [Scripts](#scripts)
    - [Dependencies](#dependencies)
    - [Dev Dependencies](#dev-dependencies)
    - [Feedback and Contributions](#feedback-and-contributions)

## Getting Started

These instructions will help you set up and run the project on your local machine for development and testing purposes.

### Prerequisites

Ensure that you have Linux environment and below components installed to build and run the service:
1. GCC 11
2. CMAKE
3. VS Code with CMAKE integrated
4. VCPKG
5. OpenDDS

### Installing

Follow these steps to get a development environment running:

1. Clone the repo:

    ```bash
    git clone https://github.com/mhutomop/simple-odds-pubsub.git
    ```

2. Navigate to the project directory:

    ```bash
    cd simple-opendds-pubsub
    ```

3. Install all dependencies using VCPKG:

    ```bash
    ./vcpkg install [dependency]
    ```

4. Create a new file "CMakeLists.txt":

    ```text
    cmake_minimum_required(VERSION 3.21.0)
    project(be-sea-eagle-data-handler VERSION 1.0.0 LANGUAGES C CXX)

    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    set(CMAKE_CXX_STANDARD 17)

    include(CTest)
    enable_testing()

    include_directories(
        "[vcpkg root directory]/installed/x64-linux/include"
        "[OpenDDS root directory]"
        "[OpenDDS root directory]/ACE_wrappers"
        "[OpenDDS root directory]/ACE_wrappers/TAO"
    )
    link_directories(
        "[vcpkg root directory]/installed/x64-linux/lib"
        "[OpenDDS root directory]/lib"
        "[OpenDDS root directory]/ACE_wrappers/lib"
    )

    file(GLOB_RECURSE SOURCES src/*.cpp src/*.cc src/*.h src/*.hpp)
    list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/app.cpp)
    add_library(shared-objects OBJECT ${SOURCES})

    add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/app.cpp $<TARGET_OBJECTS:shared-objects>)

    target_link_libraries(${PROJECT_NAME} PRIVATE OpenDDS_Dcps TAO_Valuetype TAO ACE)
    find_package(Boost REQUIRED COMPONENTS thread)
    target_link_libraries(${PROJECT_NAME} PRIVATE Boost::boost Boost::thread)
    find_package(spdlog CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

    set(CPACK_PROJECT_NAME ${PROJECT_NAME})
    set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
    include(CPack)
    ```

5. Build the project using that "CMakeLists.txt", the executable file now exists in directory "build".

6. Export environment variables from .env file:

    ```bash
    export $(grep -v '^#' .env | xargs)
    ```

7. Run the application:

    ```bash
    cd build
    ./simple-odds-pubsub
    ```

The application should now be running and using several ports for:
1. OpenDDS

## Scripts


## Dependencies

Main libraries and frameworks used in this project:

- OpenDDS (v3.26.1) - Data Distribution Service (DDS)
- Boost (v1.83.0) - Set of libraries (asio, algorithm are used in this project)
- spdlog (v1.14.1) - Fast C++ logging library

## Dev Dependencies

Development tools and libraries used:

- CMAKE - Builder for C++
- SonarLint - Code linting tool

## Feedback and Contributions

Your feedback is highly appreciated! If you find any bugs or have suggestions for improvements, feel free to open an issue or create a pull request.

If you wish to contribute, please follow the existing coding style and ensure all tests pass before submitting your pull request.
