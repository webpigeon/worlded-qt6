set ( BuildingEd_UIS
    buildingeditorwindow.ui
    buildingfloorsdialog.ui
    buildinglayersdock.ui
    buildingpreferencesdialog.ui
    buildingtemplatesdialog.ui
    buildingtilesdialog.ui
    buildingtilesetdock.ui
    choosebuildingtiledialog.ui
    choosetemplatesdialog.ui
    listofstringsdialog.ui
    newbuildingdialog.ui
    resizebuildingdialog.ui
    roomsdialog.ui
    templatefrombuildingdialog.ui
)

set ( BuildingEd_HDRS
    simplefile.h
    building.h
    buildingfloor.h
    buildingundoredo.h
    buildingobjects.h
    buildingwriter.h
    buildingreader.h
    buildingtmx.h
    horizontallinedelegate.h
    listofstringsdialog.h
)

set ( BuildingEd_SRCS
    building.cpp
    buildingdocument.cpp
    buildingdocumentmgr.cpp
    buildingeditorwindow.cpp
    buildingfloor.cpp
    buildingfloorsdialog.cpp
    buildingfurnituredock.cpp
    buildingisoview.cpp
    buildingkeyvaluesdialog.cpp
    buildinglayersdock.cpp
    buildingmap.cpp
    buildingobjects.cpp
    buildingorthoview.cpp
    buildingpreferences.cpp
    buildingpreferencesdialog.cpp
    buildingpropertiesdialog.cpp
    buildingreader.cpp
    buildingroomdef.cpp
    buildingtemplates.cpp
    buildingtemplatesdialog.cpp
    buildingtileentryview.cpp
    buildingtiles.cpp
    buildingtilesdialog.cpp
    buildingtilesetdock.cpp
    buildingtiletools.cpp
    buildingtmx.cpp
    buildingtools.cpp
    buildingundoredo.cpp
    buildingwriter.cpp
    categorydock.cpp
    choosebuildingtiledialog.cpp
    choosetemplatesdialog.cpp
    editmodestatusbar.cpp
    embeddedmainwindow.cpp
    fancytabwidget.cpp
    furnituregroups.cpp
    furnitureview.cpp
    horizontallinedelegate.cpp
    imode.cpp
    listofstringsdialog.cpp
    mixedtilesetview.cpp
    newbuildingdialog.cpp
    objecteditmode.cpp
    resizebuildingdialog.cpp
    roofhiding.cpp
    roomsdialog.cpp
    simplefile.cpp
    templatefrombuildingdialog.cpp
    tilecategoryview.cpp
    tileeditmode.cpp
    welcomemode.cpp

    utils/stylehelper.cpp
    utils/styledbar.cpp
)

set ( BuildingEd_MOCS
    buildingdocument.h
    buildingeditorwindow.h
    buildingfloorsdialog.h
    buildingfurnituredock.h
    buildingisoview.h
    buildinglayersdock.h
    buildingmap.h
    buildingorthoview.h
    buildingpreferences.h
    buildingpreferencesdialog.h
    buildingtemplates.h
    buildingtemplatesdialog.h
    buildingtiletools.h
    buildingtiles.h
    buildingtilesdialog.h
    buildingtilesetdock.h
    buildingtools.h
    choosebuildingtiledialog.h
    choosetemplatesdialog.h
    furnituregroups.h
    furnitureview.h
    mixedtilesetview.h
    newbuildingdialog.h
    resizebuildingdialog.h
    roomsdialog.h
    templatefrombuildingdialog.h
    tilecategoryview.h

    buildingdocumentmgr.h
    imode.h
    welcomemode.h
    objecteditmode.h
    tileeditmode.h

    utils/stylehelper.h
    utils/styledbar.h
)

#qt_wrap_cpp ( localMOCS ${BuildingEd_MOCS} )

# Because these resources are part of a static library, the macro 
# Q_INIT_RESOURCES must be placed in the C++ main() function, otherwise the
# resources won't get linked in.
qt_add_resources ( localRSCS buildingeditor.qrc )

# Find generated ui_xxx.h files in the build directory
#include_directories ( ${CMAKE_CURRENT_BINARY_DIR} )

qt_add_library( BuildingEd STATIC 
    ${BuildingEd_SRCS} 
    ${BuildingEd_HDRS}
    ${BuildingEd_MOCS}
    ${BuildingEd_UIS}
    ${localRSCS}
)

target_include_directories(BuildingEd PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries( BuildingEd 
    Qt6::Core 
    Qt6::Gui 
    Qt6::Widgets 
    qtlockedfile
    libtiled
)


file ( COPY BuildingFurniture.txt BuildingTemplates.txt BuildingTiles.txt
          TMXConfig.txt DESTINATION ${CMAKE_BINARY_DIR}/Debug )

file ( COPY BuildingFurniture.txt BuildingTemplates.txt BuildingTiles.txt
          TMXConfig.txt DESTINATION ${CMAKE_BINARY_DIR}/Release )

install ( FILES BuildingFurniture.txt BuildingTemplates.txt BuildingTiles.txt
          TMXConfig.txt DESTINATION . )

install ( DIRECTORY manual/ DESTINATION docs/BuildingEd )
