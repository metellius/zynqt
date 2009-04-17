set(zynaddsubfxguilib_SRCS
	dial.cpp
	mainwindow.cpp
	)

SET( zynaddsubfxguilib_MOC_HDRS
)

SET( zynaddsubfxguilib_UIS
)

qt4_wrap_ui(zynaddsubfxguilib_UIS_HDRS ${zynaddsubfxguilib_UIS} )
qt4_automoc(${zynaddsubfxguilib_SRCS})

include_directories()
add_library(zynaddsubfxguilib STATIC
	${zynaddsubfxguilib_SRCS}
	)
target_link_libraries(zynaddsubfxguilib)
