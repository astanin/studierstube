FILE(GLOB stbvideo_SOURCES *.cpp *.cxx)
INCLUDE_DIRECTORIES(../../../include)

# Coin:
INCLUDE_DIRECTORIES(${COIN_INCLUDE_DIR})
ADD_DEFINITIONS(${COIN_DEFINITIONS})
LINK_DIRECTORIES(${COIN_LINK_DIRECTORIES})

# ACE:
INCLUDE_DIRECTORIES(${ACE_INCLUDE_DIR})
ADD_DEFINITIONS(${ACE_DEFINITIONS})
LINK_DIRECTORIES(${ACE_LINK_DIRECTORIES})

# openvideo:
INCLUDE_DIRECTORIES(${OPENVIDEO_INCLUDE_DIR})
LINK_DIRECTORIES(${OPENVIDEO_LINK_DIRECTORIES})
ADD_DEFINITIONS(-DOV_IS_LINUX)

ADD_LIBRARY(stbvideo SHARED ${stbvideo_SOURCES})
TARGET_LINK_LIBRARIES(stbvideo ${COIN_LIBRARIES} ${ACE_LIBRARIES} ${OPENVIDEO_LIBRARIES})
SET_TARGET_PROPERTIES(stbvideo PROPERTIES VERSION ${CPACK_PACKAGE_VERSION} SOVERSION ${CPACK_PACKAGE_VERSION_MAJOR})
INSTALL(TARGETS stbvideo DESTINATION ${CMAKE_INSTALL_LIBDIR})
