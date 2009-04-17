SET (AlsaMidiOutput On CACHE BOOL "Include ALSA Midi output")

set(zynaddsubfxgui_output_SRCS
	Recorder.C
)

if(AlsaMidiOutput)
	FIND_PACKAGE(Alsa)
	set(zynaddsubfxgui_output_SRCS
		${zynaddsubfxgui_output_SRCS}
		OSSaudiooutput.C
		)
	message("Alsa midi output enabled")
endif(AlsaMidiOutput)

add_library(zynaddsubfxgui_output STATIC
	${zynaddsubfxgui_output_SRCS} 
	)

target_link_libraries(zynaddsubfxgui_output ${ASOUND_LIBRARY})
