#include <iostream>
#include <conio.h>
#include <list>
#include <string>

using namespace std;

struct Task 
{
    string description;
    bool completed;
};

class ToDoList 
{
public:
    list <Task> Task_List;

public:
    void addTask(string description) 
	{
    Task new_task = {description, false};
     Task_List.push_back(new_task);
   cout << "\nTask Added: " << description << endl;
    }
	
    void viewTasks() 
	{
	cout << "Task List" << endl;
    cout << "---------" << endl;
    if (Task_List.empty()) 
	{
    cout << "No Tasks in the List." << endl;
   } 
else 
{
  int index = 1;
  for (list <Task> :: iterator it = Task_List.begin(); it != Task_List.end(); it++) 
{
   cout << index << ". " << it->description << " [";
   if (it->completed)
{
   cout << "Completed";
   }
else
{
   cout << "Incomplete";
   }
   cout << "]" << endl;
   index++;
   }
   }
    }

    void markTaskComplete(int index) 
	{
if (index >= 1 && index <= Task_List.size())
{
	list <Task> :: iterator it = Task_List.begin();
advance(it, index-1);
it->completed = true;
   cout << "\nTask Marked as Complete: " << it->description << endl;
}
else
{
   cout << "\nInvalid Task Index!!!" << endl;
    }
    }

   void markTaskIncomplete(int index) 
	{
if (index >= 1 && index <= Task_List.size())
{
list <Task> :: iterator it = Task_List.begin();
advance(it, index-1);
	it->completed = false;
   cout << "\nTask Marked as Incomplete: " << it->description << endl;
}
else
{
   cout << "\nInvalid Task Index!!!" << endl;
   }
  }
   void removeTask(int index) 
	{
	if (index >= 1 && index <= Task_List.size())
	{
	list <Task> :: iterator it = Task_List.begin();
advance(it, index-1);
cout << "\nRemoved task: " << it->description << endl;
   Task_List.erase(it);
}
else 
{
   cout << "\nInvalid Task Index!!!" << endl;
   }
  }
};

int main() 
{
    ToDoList toDoList;
    int choice;

    do 
	{
system("cls");
   cout << "To-Do List Menu" << endl;
   cout << "---------------" << endl;
   cout << "1. Add Task" << endl;
   cout << "2. View Tasks" << endl;
   cout << "3. Mark Task as Complete" << endl;
   cout << "4. Mark Task as Incomplete" << endl;
   cout << "5. Remove Task" << endl;
   cout << "6. Exit" << endl;
   cout << "Enter your choice (1-6): ";
   cin >> choice;
system("cls");
   switch (choice)
{
    case 1:
{
   cin.ignore();
   string description;
   cout << "ADD TASK" << endl;
   cout << "--------" << endl;
    cout << "\nEnter Task Description: ";
   getline(cin, description);
   toDoList.addTask(description);
   break;
   }
   case 2:
   toDoList.viewTasks();
   break;
   case 3: 
{
toDoList.viewTasks();
   if (!toDoList.Task_List.empty())
   {
	int index;
cout << "\nEnter Task Number to Mark as Complete: ";
cin >> index;
	toDoList.markTaskComplete(index);
	}
	break;
}
   case 4: 
	{
	toDoList.viewTasks();
	if (!toDoList.Task_List.empty())
	{
	int index;
cout << "\nEnter Task Number to Mark as Incomplete: ";
cin >> index;
	toDoList.markTaskIncomplete(index);
	}
  break;
    }
    case 5: 
	{
	toDoList.viewTasks();
	if (!toDoList.Task_List.empty())
	{
	int index;
	cout << "\nEnter Task Number to Remove: ";
 	cin >> index;
  	toDoList.removeTask(index);
	}
   break;
  }
  case 6:
   {
	cout << "\nExiting program..." << endl;
    break;	
	}
   default:
   cout << "Invalid choice!!! Please try again." << endl;
  }
   cout << "\nPress any key to continue...";
getch();
		
    } while (choice != 6);

    return 0;
}

