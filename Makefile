main: array_sketch_menu.o help_menu.o new_sketch.o main.o state_manager.o application.o window_manager.o event_manager.o array.o button.o main_menu.o panel.o sketch_container.o state_element.o state.o text_form.o
	g++ array_sketch_menu.o help_menu.o new_sketch.o main.o application.o window_manager.o event_manager.o array.o button.o main_menu.o panel.o sketch_container.o state_element.o state_manager.o state.o text_form.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
main.o: 
	g++ -Isrc/include -c main.cpp

application.o: application.cpp include/application.hpp window_manager.o state_manager.o event_manager.o
	g++ -Isrc/include -c application.cpp

window_manager.o: window_manager.cpp include/window_manager.hpp
	g++ -Isrc/include -c window_manager.cpp

event_manager.o: event_manager.cpp include/event_manager.hpp
	g++ -Isrc/include -c event_manager.cpp

state_manager.o: state_manager.cpp include/state_manager.hpp event_manager.o main_menu.o help_menu.o array_sketch_menu.o
	g++ -Isrc/include -c state_manager.cpp

array.o: array.cpp include/array.hpp panel.o sketch_container.o
	g++ -Isrc/include -c array.cpp

button.o: button.cpp include/button.hpp state_element.o
	g++ -Isrc/include -c button.cpp

main_menu.o: main_menu.cpp include/main_menu.hpp state.o button.o new_sketch.o help_menu.o
	g++ -Isrc/include -c main_menu.cpp

panel.o: panel.cpp include/panel.hpp state_element.o
	g++ -Isrc/include -c panel.cpp
	
sketch_container.o: sketch_container.cpp include/sketch_container.hpp panel.o state_element.o
	g++ -Isrc/include -c sketch_container.cpp

state_element.o: state_manager.o state_element.cpp include/state_element.hpp
	g++ -Isrc/include -c state_element.cpp

state.o: state.cpp include/state.hpp state_manager.o text_form.o sketch_container.o
	g++ -Isrc/include -c state.cpp
	
text_form.o: text_form.cpp include/text_form.hpp state_element.o
	g++ -Isrc/include -c text_form.cpp

new_sketch.o: new_sketch.cpp include/new_sketch.hpp button.o panel.o state.o
	g++ -Isrc/include -c new_sketch.cpp

help_menu.o: help_menu.cpp include/help_menu.hpp button.o panel.o state.o
	g++ -Isrc/include -c help_menu.cpp
	
array_sketch_menu.o: array_sketch_menu.cpp include/array_sketch_menu.hpp button.o panel.o state.o array.o
	g++ -Isrc/include -c array_sketch_menu.cpp

run:
	./main

clear:
	rm *.o 