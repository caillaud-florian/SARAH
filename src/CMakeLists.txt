file(GLOB_RECURSE all_files *)

IF(SFML_FOUND)

	#Ajouter la librairie dynamique "kernel"
	include_directories(Kernel)
	add_subdirectory(Kernel)

	#Ajouter la librairie dynamique "modeling"
	include_directories(Modeling)
	add_subdirectory(Modeling)

	#Ajouter la librairie dynamique "reader"
	include_directories(Reader)
	add_subdirectory(Reader)

	#Ajouter la librairie dynamique "utilities"
	include_directories(Utilities)
	add_subdirectory(Utilities)

	#Ajouter la librairie dynamique "window"
	include_directories(Window)
	add_subdirectory(Window)

	################################################

	#Ajouter la librairie dynamique "my_application"
	include_directories(MyApplication)
	add_subdirectory(MyApplication)

	#Ajouter la librairie dynamique "test"
	include_directories(Test)
	add_subdirectory(Test)

ELSE(SFML_FOUND)
	MESSAGE("Impossible to build SARAH : SFML unfound.")
ENDIF(SFML_FOUND)