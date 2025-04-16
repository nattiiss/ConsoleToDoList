#include <iostream>
#include <string>
#include <list>
#include <ctime>


class ToDoTask {
private:
    int id;
    std::string taskDescription;
    bool done;
public:
    ToDoTask() : id(0), taskDescription(""), done(false) {}
    ~ToDoTask() = default;

    bool create(std::string new_taskDescription) {
        id = rand() % 100; 
        taskDescription = new_taskDescription;
        return true;
    }

    int getID() { return id;  }
    std::string getTaskDescription() { return taskDescription; }
    bool taskDone() { return done; }

    void setDone(bool val) { done = val; }
};

int main()
{
    char chooseOption;
    std::string inputDescription;
    int taskIdDone;
    std::list<ToDoTask>  ToDoTasks;
    std::list<ToDoTask>::iterator it;

    ToDoTasks.clear();

    while (1) {
        system("cls");
        std::cout << "ToDo List\n";
        std::cout << std::endl << std::endl;

        for (it = ToDoTasks.begin(); it != ToDoTasks.end(); it++) {
            std::string done = it->taskDone() ? "done" : "not done";

            std::cout << it->getID() << "|" << it ->getTaskDescription() <<"|" 
                << done << std::endl;
        }
        if (ToDoTasks.empty()) {
            std::cout << "Add your todo! And Good Luck with it!\n";
        }

        std::cout << std::endl << std::endl;

        std::cout << "[a]dd Task/ToDo\n";
        std::cout << "[c]omplete a Task/ToDo\n";
        std::cout << "[q]uit\n";

        std::cout << "choice: ";
        std::cin >> chooseOption;

        if (chooseOption == 'q') {
            std::cout << "Good luck and have a nice day! See you later:)\n";
            break;
        } 
        else if (chooseOption == 'a') {
            std::cout << "Add a new Task/ToDo!\n";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, inputDescription);

            ToDoTask newTask;
            newTask.create(inputDescription);
            ToDoTasks.push_back(newTask);
        }
        else if (chooseOption == 'c') {
            std::cout << "Enter Task ID, that have been completed!\n";
            std::cin >> taskIdDone;

            for (it = ToDoTasks.begin(); it != ToDoTasks.end(); it++) {
                if (taskIdDone == it->getID()) {
                    it->setDone(true);
                    break;
                }
            }
        }

    }
    return 0;
}