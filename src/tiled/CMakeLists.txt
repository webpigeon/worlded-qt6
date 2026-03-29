cmake_minimum_required( VERSION 3.16 )

project( TileZed LANGUAGES CXX )
set ( CMAKE_BUILD_TYPE Release )

#add_definitions ( -Wall )
add_definitions( -DQT_NO_CAST_FROM_ASCII -DQT_NO_CAST_TO_ASCII )

find_package ( Qt6 REQUIRED COMPONENTS Core Gui Widgets OpenGLWidgets )

#set ( EXECUTABLE_OUTPUT_PATH ../../bin )
set ( Tiled_HDRS
	addremovelayer.h
	addremovemapobject.h
	addremovetileset.h
	automapperwrapper.h
	automappingutils.h
	brushitem.h
	changemapobject.h
	changeimagelayerproperties.h
	changeobjectgroupproperties.h
	changepolygon.h
	changeproperties.h
	changetileselection.h
	commandlineparser.h
	erasetiles.h
	filltiles.h
	imagelayeritem.h
	languagemanager.h
	macsupport.h
	mapobjectitem.h
	mapreaderinterface.h
	mapwriterinterface.h
	movelayer.h
	movemapobject.h
	movemapobjecttogroup.h
	movetileset.h
	objectgroupitem.h
	objecttypes.h
	offsetlayer.h
	painttilelayer.h
	pluginmanager.h
	propertiesview.h
	rangeset.h
	renamelayer.h
	resizelayer.h
	resizemap.h
	resizemapobject.h
	selectionrectangle.h
	tilelayeritem.h
	tilepainter.h
	tmxmapreader.h
	tmxmapwriter.h
	undocommands.h
	utils.h

	zgriditem.h
	ztilelayergroupitem.h
	)

set ( Tiled_SRCS
bmpclipboard.cpp
bmpclipboard.h
bmptool.cpp
bmptool.h
bmptooldialog.cpp
bmptooldialog.h
bmptooldialog.ui
picktiletool.cpp
picktiletool.h
roomdeftool.cpp
roomdeftool.h
tilelayerspanel.cpp
tilelayerspanel.h
worldlottool.cpp
worldlottool.h
tilesetstxtfile.cpp
tilesetstxtfile.h
ZomboidScene.cpp
ZomboidScene.h
bmpblender.cpp
bmpblender.h

tiledeftextfile.cpp
tiledeftextfile.h

shortcut/actionmanager.cpp
shortcut/actionmanager.h
shortcut/keyboardshortcutfile.cpp
shortcut/keyboardshortcutfile.h
shortcut/keyboardshortcutwindow.cpp
shortcut/keyboardshortcutwindow.h
shortcut/keyboardshortcutwindow.ui
shortcut/shortcuteditordelegate.cpp
shortcut/shortcuteditordelegate.h
shortcut/shortcuteditormodel.cpp
shortcut/shortcuteditormodel.h
shortcut/shortcuteditorwidget.cpp
shortcut/shortcuteditorwidget.h

tiledefcompare.h
tiledefcompare.cpp
tiledefcompare.ui

texturepacker.cpp
texturepacker.h

packviewer.h
packviewer.cpp
packviewer.ui

roomdefecator.h
roomdefecator.cpp

luaconsole.cpp
luaconsole.h
luaconsole.ui
luamapsdialog.cpp
luamapsdialog.h
luamapsdialog.ui

luatooldialog.ui
luatooldialog.cpp
luatooldialog.h
luatooloptions.cpp
luatooloptions.h

luatiletool.h
luatiletool.cpp
luatiled.cpp
luatiled.h

snoweditor.h
snoweditor.cpp
snoweditor.ui

threads.h
threads.cpp

packcompare.cpp
packcompare.h
packcompare.ui

tileoverlayfile.cpp
tileoverlayfile.h

enflatulatordialog.ui
enflatulatordialog.h
enflatulatordialog.cpp

containeroverlayfile.cpp
containeroverlayfile.h
containeroverlayview.cpp
containeroverlayview.h
containeroverlaydialog.cpp
containeroverlaydialog.h

checkmapswindow.cpp
checkmapswindow.h
checkmapswindow.ui

bmpruleview.cpp
bmpruleview.h

bmpblendview.cpp
bmpblendview.h
mapbuildings.cpp
mapbuildings.h

luatable.cpp
luatable.h

packextractdialog.h
packextractdialog.ui
packextractdialog.cpp

roomdefnamedialog.cpp
roomdefnamedialog.h
roomdefnamedialog.ui

createpackdialog.cpp
createpackdialog.ui
createpackdialog.h

texturepackfile.cpp
texturepackfile.h

tilesetmanager.cpp
tilesetmanager.h
newmapbinaryfile.cpp
newmapbinaryfile.h

luaworlddialog.h
luaworlddialog.cpp
luaworlddialog.ui

rearrangetiles.h
rearrangetiles.cpp
rearrangetiles.ui

worldeddock.cpp
worldeddock.h
worldeddock.ui

tilesetstxtfile.h
tilesetstxtfile.cpp

checkbuildingswindow.cpp
checkbuildingswindow.h
checkbuildingswindow.ui

tileoverlaydialog.cpp
tileoverlaydialog.h

	aboutdialog.cpp
	abstractobjecttool.cpp
	abstracttiletool.cpp
	abstracttool.cpp
	addremovelayer.cpp
	addremovemapobject.cpp
	addremovetileset.cpp
	addtilesetsdialog.cpp
	automapper.cpp
	automapperwrapper.cpp
	automappingmanager.cpp
	automappingutils.cpp
	brushitem.cpp
	bucketfilltool.cpp
	changemapobject.cpp
	changeimagelayerproperties.cpp
	changeobjectgroupproperties.cpp
	changepolygon.cpp
	changeproperties.cpp
	changetileselection.cpp
	clipboardmanager.cpp
	colorbutton.cpp
	commandbutton.cpp
	command.cpp
	commanddatamodel.cpp
	commanddialog.cpp
	commandlineparser.cpp
	createobjecttool.cpp
	documentmanager.cpp
	editpolygontool.cpp
	eraser.cpp
	erasetiles.cpp
	filesystemwatcher.cpp
	filltiles.cpp
	imagelayeritem.cpp
	imagelayerpropertiesdialog.cpp
	languagemanager.cpp
	layerdock.cpp
	layermodel.cpp
	main.cpp
	mainwindow.cpp
	mapdocumentactionhandler.cpp
	mapdocument.cpp
	mapobjectitem.cpp
	mapobjectmodel.cpp
	mapscene.cpp
	mapsdock.cpp
	mapview.cpp
	movelayer.cpp
	movemapobject.cpp
	movemapobjecttogroup.cpp
	movetileset.cpp
	newmapdialog.cpp
	newtilesetdialog.cpp
	objectgroupitem.cpp
	objectgrouppropertiesdialog.cpp
	objectpropertiesdialog.cpp
	objectsdock.cpp
	objectselectiontool.cpp
	objecttypes.cpp
	objecttypesmodel.cpp
	offsetlayer.cpp
	offsetmapdialog.cpp
	painttilelayer.cpp
	pluginmanager.cpp
	preferences.cpp
	preferencesdialog.cpp
	propertiesdialog.cpp
	propertiesmodel.cpp
	propertiesview.cpp
	quickstampmanager.cpp
	renamelayer.cpp
	resizedialog.cpp
	resizehelper.cpp
	resizelayer.cpp
	resizemap.cpp
	resizemapobject.cpp
	saveasimagedialog.cpp
	selectionrectangle.cpp
	stampbrush.cpp
	tiledapplication.cpp
	tilelayeritem.cpp
	tilepainter.cpp
	tileselectionitem.cpp
	tileselectiontool.cpp
	tilesetdock.cpp
	tilesetmanager.cpp
	tilesetmodel.cpp
	tilesetview.cpp
	tmxmapreader.cpp
	tmxmapwriter.cpp
	toolmanager.cpp
	undodock.cpp
	utils.cpp
	zoomable.cpp

	converttolotdialog.cpp
	convertorientationdialog.cpp
	mapcomposite.cpp
	mapimagemanager.cpp
	mapmanager.cpp
	minimap.cpp
	tiledefdialog.cpp
	tiledeffile.cpp
	tilemetainfodialog.cpp
	tilemetainfomgr.cpp
	zgriditem.cpp
	zlevelsdock.cpp
	zlevelsmodel.cpp
	zlotmanager.cpp
	ZomboidScene.cpp
	zprogress.cpp
	ztilelayergroupitem.cpp
    shortcut/actionmanager.cpp
	)

set ( Tiled_UIS
	aboutdialog.ui
	addtilesetsdialog.ui
	commanddialog.ui
	converttolotdialog.ui
	convertorientationdialog.ui
	mainwindow.ui
	newimagelayerdialog.ui
	newmapdialog.ui
	newtilesetdialog.ui
	objectpropertiesdialog.ui
	offsetmapdialog.ui
	preferencesdialog.ui
	propertiesdialog.ui
	resizedialog.ui
	saveasimagedialog.ui
	tiledefdialog.ui
	tilemetainfodialog.ui
	)

set ( Tiled_MOCS
	aboutdialog.h
	abstractobjecttool.h
	abstracttiletool.h
	abstracttool.h
	addtilesetsdialog.h
	automapper.h
	automappingmanager.h
	bucketfilltool.h
	clipboardmanager.h
	colorbutton.h
	commandbutton.h
	commanddatamodel.h
	commanddialog.h
	command.h
	createobjecttool.h
	documentmanager.h
	editpolygontool.h
	eraser.h
	filesystemwatcher.h
	imagelayerpropertiesdialog.h
	layerdock.h
	layermodel.h
	mainwindow.h
	mapdocumentactionhandler.h
	mapdocument.h
	mapobjectmodel.h
	mapscene.h
	mapsdock.h
	mapview.h
	newmapdialog.h
	newtilesetdialog.h
	objectgrouppropertiesdialog.h
	objectpropertiesdialog.h
	objectsdock.h
	objectselectiontool.h
	objecttypesmodel.h
	offsetmapdialog.h
	preferencesdialog.h
	preferences.h
	propertiesdialog.h
	propertiesmodel.h
	quickstampmanager.h
	resizedialog.h
	resizehelper.h
	saveasimagedialog.h
	stampbrush.h
	tiledapplication.h
	tileselectionitem.h
	tileselectiontool.h
	tilesetdock.h
	tilesetmanager.h
	tilesetmodel.h
	tilesetview.h
	toolmanager.h
	undodock.h
	zoomable.h

	converttolotdialog.h
	convertorientationdialog.h
	mapcomposite.h
	mapimagemanager.h
	mapmanager.h
	minimap.h
	tiledefdialog.h
	tiledeffile.h
	tilemetainfodialog.h
	tilemetainfomgr.h
	zlevelsdock.h
	zlevelsmodel.h
	zlotmanager.h
	ZomboidScene.h
	zprogress.h
	)

set(ALL_HDRS ${Tiled_HDRS} ${Tiled_MOCS})

add_subdirectory( BuildingEditor )

qt_add_resources( TileZed_res
    tiled.qrc
    breeze/breeze.qrc
    qdarkstyle/dark/darkstyle.qrc
    qdarkstyle/light/lightstyle.qrc
)

qt_add_executable (TileZed
    ${Tiled_SRCS}
    ${Tiled_HDRS}
    ${Tiled_MOCS}
    ${Tiled_UIS}
    ${TileZed_res}
    tiled.rc
)

target_include_directories(TileZed PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries ( TileZed PRIVATE 
    libtiled
    BuildingEd
    worlded
    tolua
    qtsingleapplication
    Qt6::Core 
    Qt6::Gui 
    Qt6::Widgets 
    Qt6::OpenGLWidgets)

INSTALL(TARGETS TileZed DESTINATION ".")

set(LUATILED_GENERATED ${CMAKE_CURRENT_BINARY_DIR}/luatiled.tolua.cpp)

add_custom_command(
    OUTPUT ${LUATILED_GENERATED}
    COMMAND $<TARGET_FILE:tolua_generator> -n tiled -o ${LUATILED_GENERATED} ${CMAKE_CURRENT_SOURCE_DIR}/luatiled.pkg
    DEPENDS
        tolua_generator
        ${CMAKE_CURRENT_SOURCE_DIR}/luatiled.pkg
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    VERBATIM
)

target_sources(TileZed PRIVATE
    ${LUATILED_GENERATED}
)
