INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${LUA_INCLUDE_DIR})

SET(sources
    lua_lpack.c
    lua_bit.c
		session.c
)

ADD_LIBRARY(luasupp SHARED ${sources})
TARGET_LINK_LIBRARIES(luasupp ${LUA_LIBRARIES})

INSTALL(TARGETS luasupp LIBRARY DESTINATION lib${LIB_SUFFIX}/vega-ppp)
