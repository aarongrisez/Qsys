SET(SOURCES
        ../library/src/test.cpp)

SET(INCLUDE
        ../library/include/HamHelper.h
        ../library/include/json.hpp)


include_directories(../library/include)
include_directories(EIGEN3_INCLUDE_DIR)

add_executable(QSys ${SOURCES} ${INCLUDE} )
target_link_libraries(QSys Eigen3::Eigen)
