FIND_PACKAGE(Qt4)
INCLUDE(${QT_USE_FILE})


#settings
SET (FFTW_VERSION 3 CACHE STRING "Version number of FFTW")
SET (AlsaMidiOutput Off CACHE BOOL "set ALSA Midi output")
SET (JackOutput Off CACHE BOOL "set Jack Output")
SET (PortAudioOutput On CACHE BOOL "set Jack Output")

add_definitions(-DFFTW_VERSION_${FFTW_VERSION}
	 -DOS_LINUX
	 -DALSAMIDIIN
	 -DASM_F2I_YES
	 -DPAAUDIOOUT
	 )


include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}/NewUI
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






