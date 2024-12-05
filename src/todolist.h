#ifndef TODOLIST_H
#define TODOLIST_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Hold_Browser.H>
#include <vector>
#include <string>

// Class representing a To-Do List application using FLTK for the GUI
class ToDoList : public Fl_Window {
public:
    // Constructor to initialize the window and widgets
    ToDoList(int width, int height, const char* title);
    
    // Destructor to clean up allocated resources
    ~ToDoList();

private:
    Fl_Input *task_input;               // Input field for entering new tasks
    Fl_Button *add_button;              // Button to add a new task
    Fl_Button *delete_button;           // Button to delete the selected task
    Fl_Hold_Browser *task_list_browser; // List browser to display tasks

    std::vector<std::string> tasks;     // Vector to store tasks

    // Static callback functions for the buttons
    static void add_task_cb(Fl_Widget* widget, void* data);
    static void delete_task_cb(Fl_Widget* widget, void* data);

    // Member functions to handle adding and deleting tasks
    void add_task();
    void delete_task();
    void update_task_list(); // Function to update the task list display
};

#endif // TODOLIST_H
