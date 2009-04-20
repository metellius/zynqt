set(zynaddsubfxgui_output_SRCS
	Recorder.C
)

if(AlsaMidiOutput)
	FIND_PACKAGE(Alsa)
	set(zynaddsubfxgui_output_SRCS
		${zynaddsubfxgui_output_SRCS}
		OSSaudiooutput.C
		)
	add_definitions(-DOSSAUDIOOUT)
endif(AlsaMidiOutput)

if(JackOutput)
	FIND_PACKAGE(JACK)
	include_directories(${JACK_INCLUDE_DIR})
	set(zynaddsubfxgui_output_SRCS
		${zynaddsubfxgui_output_SRCS}
		JACKaudiooutput.C
		)
	add_definitions(-DJACKAUDIOOUT)
endif(JackOutput)

if(PortAudioOutput)
	FIND_PACKAGE(PortAudio)
	include_directories(${PORTAUDIO_INCLUDE_DIR})
	set(zynaddsubfxgui_output_SRCS
		${zynaddsubfxgui_output_SRCS}
		PAaudiooutput.C
		)
	add_definitions(-PAAUDIOOUT)
endif(PortAudioOutput)

add_library(zynaddsubfxgui_output STATIC
	${zynaddsubfxgui_output_SRCS} 
	)

target_link_libraries(zynaddsubfxgui_output 
	${ASOUND_LIBRARY}
	${JACK_LIBRARIES}
	${PORTAUDIO_LIBRARIES}
	)
