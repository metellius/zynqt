set(zynaddsubfxgui_output_SRCS
	Recorder.C
)

if(AlsaMidiOutput)
	FIND_PACKAGE(Alsa)
	set(zynaddsubfxgui_output_SRCS
		${zynaddsubfxgui_output_SRCS}
		OSSaudiooutput.C
		)
endif(AlsaMidiOutput)

if(JackOutput)
	FIND_PACKAGE(JACK)
	include_directories(${JACK_INCLUDE_DIR})
	set(zynaddsubfxgui_output_SRCS
		${zynaddsubfxgui_output_SRCS}
		JACKaudiooutput.C
		)
endif(JackOutput)


add_library(zynaddsubfxgui_output STATIC
	${zynaddsubfxgui_output_SRCS} 
	)

target_link_libraries(zynaddsubfxgui_output 
	${ASOUND_LIBRARY}
	${JACK_LIBRARIES}
	)
