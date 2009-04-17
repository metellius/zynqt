FIND_PACKAGE(Qt4)
INCLUDE(${QT_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/NewUI)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_subdirectory(Misc)
add_subdirectory(Input)
add_subdirectory(Output)
add_subdirectory(NewUI)
add_subdirectory(Synth)
add_subdirectory(Seq)
add_subdirectory(Effects)
add_subdirectory(Params)
add_subdirectory(DSP)

set(zynaddsubfxgui_SRCS
	main.cpp
	)



add_executable(zynaddsubfxgui 
	${zynaddsubfxgui_SRCS}
)

target_link_libraries(zynaddsubfxgui
	zynaddsubfxgui_input
	zynaddsubfxgui_output
	zynaddsubfxgui_misc
	zynaddsubfxgui_synth
	zynaddsubfxgui_seq
	zynaddsubfxgui_effect
	zynaddsubfxgui_params
	zynaddsubfxgui_dsp
	zynaddsubfxguilib)






