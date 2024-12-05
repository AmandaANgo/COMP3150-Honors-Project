#include "todolist.h"
#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <sstream>

// Constructor to initialize the window and widgets
ToDoList::ToDoList(int width, int height, const char* title)
    : Fl_Window(width, height, title), tasks() {

    // Set the minimum size for the window
    size_range(400, 400);

    // Set the initial size of the window
    this->size(600, 450);

    // Create and configure the task input field
    task_input = new Fl_Input(75, 20, 350, 40, "New Task:");
    task_input->textsize(25);  // Set text size for input (increased by 5)

    // Create and configure the add button
    add_button = new Fl_Button(450, 20, 100, 40, "Add");
    add_button->labelsize(20);  // Set text size for button label (increased by 5)

    // Create and configure the delete button
    delete_button = new Fl_Button(450, 70, 100, 40, "Delete");
    delete_button->labelsize(20);  // Set text size for button label (increased by 5)

    // Create and configure the task list browser
    task_list_browser = new Fl_Hold_Browser(50, 120, 500, 240, "Tasks:");
    task_list_browser->textsize(25);  // Set text size for browser (increased by 5)

    // Set the callback functions for the buttons
    add_button->callback(add_task_cb, this);
    delete_button->callback(delete_task_cb, this);

    end();  // End the window setup
}

// Destructor to clean up allocated resources
ToDoList::~ToDoList() {
    delete task_input;
    delete add_button;
    delete delete_button;
    delete task_list_browser;
}

// Static callback function for the add button
void ToDoList::add_task_cb(Fl_Widget* widget, void* data) {
    ToDoList* toDoList = (ToDoList*)data;
    toDoList->add_task();
}

// Static callback function for the delete button
void ToDoList::delete_task_cb(Fl_Widget* widget, void* data) {
    ToDoList* toDoList = (ToDoList*)data;
    toDoList->delete_task();
}

// Member function to add a task
void ToDoList::add_task() {
    const char* new_task = task_input->value();
    if (new_task && *new_task) {
        tasks.push_back(std::string(new_task));  // Add the new task to the vector
        task_input->value("");  // Clear the input field
        update_task_list();  // Update the task list display
    } else {
        fl_alert("Please enter a task.");  // Show an alert if the input field is empty
    }
}

// Member function to delete the selected task
void ToDoList::delete_task() {
    int selected = task_list_browser->value();
    if (selected > 0 && selected <= tasks.size()) {
        tasks.erase(tasks.begin() + (selected - 1));  // Remove the selected task from the vector
        update_task_list();  // Update the task list display
    } else {
        fl_alert("Please select a task to delete.");  // Show an alert if no task is selected
    }
}

// Member function to update the task list display
void ToDoList::update_task_list() {
    task_list_browser->clear();  // Clear the current list
    for (const auto& task : tasks) {
        task_list_browser->add(task.c_str());  // Add each task to the list browser
    }
}
