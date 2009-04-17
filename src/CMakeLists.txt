FIND_PACKAGE(Qt4)
INCLUDE(${QT_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/NewUI)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_subdirectory(Misc)
add_subdirectory(Input)
add_subdirectory(Output)
add_subdirectory(NewUI)

set(zynaddsubfxgui_SRCS
	main.cpp
	)



add_executable(zynaddsubfxgui 
	${zynaddsubfxgui_SRCS}
)

target_link_libraries(zynaddsubfxgui zynaddsubfxgui_input
	zynaddsubfxgui_output zynaddsubfxgui_misc zynaddsubfxguilib)






