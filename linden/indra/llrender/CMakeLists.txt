# -*- cmake -*-

project(llrender)

include(00-Common)
include(FreeType)
include(LLCommon)
include(LLImage)
include(LLMath)
include(LLRender)
include(LLWindow)

include_directories(
    ${FREETYPE_INCLUDE_DIRS}
    ${LLCOMMON_INCLUDE_DIRS}
    ${LLIMAGE_INCLUDE_DIRS}
    ${LLMATH_INCLUDE_DIRS}
    ${LLRENDER_INCLUDE_DIRS}
    ${LLWINDOW_INCLUDE_DIRS}
    )

set(llrender_SOURCE_FILES
    llcubemap.cpp
    llfont.cpp
    llfontgl.cpp
    llgldbg.cpp
    llglslshader.cpp
    llimagegl.cpp
    llpostprocess.cpp
    llrender.cpp
    llrendersphere.cpp
    llrendertarget.cpp
    llshadermgr.cpp
    llvertexbuffer.cpp
    )
    
set(llrender_HEADER_FILES
    CMakeLists.txt

    llcubemap.h
    llfontgl.h
    llfont.h
    llgl.h
    llgldbg.h
    llglheaders.h
    llglslshader.h
    llglstates.h
    llgltypes.h
    llimagegl.h
    llpostprocess.h
    llrender.h
    llrendersphere.h
    llrendertarget.h
    llshadermgr.h
    llvertexbuffer.h
    )

set_source_files_properties(${llrender_HEADER_FILES}
                            PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND llrender_SOURCE_FILES ${llrender_HEADER_FILES})

if (SERVER AND NOT WINDOWS AND NOT DARWIN)
  copy_server_sources(
      llgl
      )


  set_source_files_properties(
    ${server_SOURCE_FILES}
    PROPERTIES
    COMPILE_FLAGS "-DLL_MESA=1 -DLL_MESA_HEADLESS=1"
    )
  add_library (llrenderheadless
    ${llrender_SOURCE_FILES}
    ${server_SOURCE_FILES}
    )
else (SERVER AND NOT WINDOWS AND NOT DARWIN)
  list(APPEND llrender_SOURCE_FILES
      llgl.cpp
      )
endif (SERVER AND NOT WINDOWS AND NOT DARWIN)
add_library (llrender ${llrender_SOURCE_FILES})
