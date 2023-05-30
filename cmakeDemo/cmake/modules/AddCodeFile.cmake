
##list (APPEND CMAKE_MODULE_PATH "${}")
#INCLUDE(AddCodeFile)
##使用
##SET (ALL_SOURCES ${RESOURCE} "")
#ADD_INCLUDE_FILE_LIST(ALL_SOURCES ${/modeldb_script})
#ADD_SOURCE_FILE_LIST(ALL_SOURCES ${CMAKE_CURRENT_SOURCE_DIR})

MACRO(_ADD_INCLUDE_FILE_LIST  group  dirnameList targetdir)
	 set(INCLUDE_FILES "")
	 file(GLOB INCLUDE_FILES "${targetdir}/*.h")
	 source_group(${group} FILES ${INCLUDE_FILES})
	 list(APPEND ${dirnameList} ${INCLUDE_FILES})
	 
	 
	 file(GLOB children "${targetdir}/*")
	 foreach(child ${children})
	     file(RELATIVE_PATH child_name ${targetdir} ${child})
		 if(IS_DIRECTORY ${child})
		   _ADD_INCLUDE_FILE_LIST("${group}//${child_name}"  ${dirnameList} ${child}/)
		  endif()
	 endforeach()
ENDMACRO(_ADD_INCLUDE_FILE_LIST group dirnameList targetdir)



MACRO(ADD_INCLUDE_FILE_LIST dirnameList targetdir)
      _ADD_INCLUDE_FILE_LIST("public"  ${dirnameList} ${targetdir})
ENDMACRO(ADD_INCLUDE_FILE_LIST dirnameList targetdir)



MACRO(_ADD_SOURCE_FILE_LIST headGroup cppGroup  dirnameList targetdir)
     file(GLOB HEADERS "${targetdir}/*.h")
	 source_group(${headGroup} FILES ${HEADERS})
	 list(APPEND ${dirnameList} ${HEADERS})
	 
	 AUX_SOURCE_DIRECTORY(${targetdir} SOURCES)
	 source_group(${cppGroup} FILES ${SOURCES})
	 list(APPEND ${dirnameList} ${SOURCES})
	 
	 file(GLOB children "${targetdir}/*")
	 foreach(child ${children})
	     file(RELATIVE_PATH child_name ${targetdir} ${child})
		 if(IS_DIRECTORY ${child})
		   _ADD_SOURCE_FILE_LIST("${headGroup}//${child_name}" "${cppGroup}//${child_name}" ${dirnameList} ${child}/)
		  endif()
	 endforeach()
ENDMACRO(_ADD_SOURCE_FILE_LIST headGroup cppGroup dirnameList targetdir)



MACRO(ADD_SOURCE_FILE_LIST dirnameList targetdir)
      _ADD_SOURCE_FILE_LIST("include" "source" ${dirnameList} ${targetdir})
ENDMACRO(ADD_SOURCE_FILE_LIST dirnameList targetdir)