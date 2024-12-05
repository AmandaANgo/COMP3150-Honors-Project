// COMP 3150 HW 6 Amanda Ngo 12/4/2024

#include "todolist.h"
#include <FL/Fl.H>

int main() {
    // Create the main window for the To-Do List application
    ToDoList window(600, 450, "To-Do List");

    // Show the window
    window.show();

    // Run the FLTK event loop
    return Fl::run();
}
