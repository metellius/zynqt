include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(zynaddsubfxguilib_SRCS
	dial.cpp
	masterui.C
	)

SET( zynaddsubfxguilib_MOC_HDRS
	masterui.h
)

SET( zynaddsubfxguilib_UIS
	masterUI.ui
)

qt4_wrap_ui(zynaddsubfxguilib_UIS_HDRS ${zynaddsubfxguilib_UIS} )
qt4_automoc(${zynaddsubfxguilib_SRCS})

include_directories()
add_library(zynaddsubfxguilib STATIC
	${zynaddsubfxguilib_SRCS}
	${zynaddsubfxguilib_UIS}
	)
target_link_libraries(zynaddsubfxguilib)
