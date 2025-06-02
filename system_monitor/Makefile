CXX = g++
CXXFLAGS = -I. -I./imgui -I./imgui/backends -I/usr/include/SDL2 -D_REENTRANT
LDFLAGS = -lSDL2 -lGL -ldl
SRCS = main.cpp \
       imgui/imgui.cpp \
       imgui/imgui_demo.cpp \
       imgui/imgui_draw.cpp \
       imgui/imgui_tables.cpp \
       imgui/imgui_widgets.cpp \
       imgui/backends/imgui_impl_sdl2.cpp \
       imgui/backends/imgui_impl_opengl3.cpp

all: system_monitor

system_monitor: $(SRCS)
	$(CXX) $(SRCS) $(CXXFLAGS) $(LDFLAGS) -o system_monitor
