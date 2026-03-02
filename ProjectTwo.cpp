#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>

using namespace std;

// ==============================
// Course Structure
// ==============================
struct Course {
    string courseNumber;
    string title;
    vector<string> prerequisites;
};

// ==============================
// Binary Search Tree Node
// ==============================
struct Node {
    Course data;
    Node* left;
    Node* right;

    Node(Course course) {
        data = course;
        left = nullptr;
        right = nullptr;
    }
};

// ==============================
// Binary Search Tree Class
// ==============================
class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    Node* InsertNode(Node* node, Course item);
    void Insert(Course item);
    Node* SearchNode(Node* node, string courseNumber);
    Course Search(string courseNumber);
    void InOrder(Node* node);
    void PrintInOrder();
};

// ==============================
// BST Insert
// ==============================
Node* Tree::InsertNode(Node* node, Course item) {

    if (node == nullptr) {
        return new Node(item);
    }

    if (item.courseNumber < node->data.courseNumber) {
        node->left = InsertNode(node->left, item);
    }
    else if (item.courseNumber > node->data.courseNumber) {
        node->right = InsertNode(node->right, item);
    }

    return node;
}

void Tree::Insert(Course item) {
    root = InsertNode(root, item);
}

// ==============================
// BST Search
// ==============================
Node* Tree::SearchNode(Node* node, string courseNumber) {

    if (node == nullptr) {
        return nullptr;
    }

    if (node->data.courseNumber == courseNumber) {
        return node;
    }

    if (courseNumber < node->data.courseNumber) {
        return SearchNode(node->left, courseNumber);
    }

    return SearchNode(node->right, courseNumber);
}

Course Tree::Search(string courseNumber) {

    Node* foundNode = SearchNode(root, courseNumber);

    if (foundNode == nullptr) {
        return Course();
    }

    return foundNode->data;
}

// ==============================
// InOrder Traversal
// ==============================
void Tree::InOrder(Node* node) {
    if (node == nullptr) return;

    InOrder(node->left);
    cout << node->data.courseNumber << ", "
        << node->data.title << endl;
    InOrder(node->right);
}

void Tree::PrintInOrder() {
    if (root == nullptr) {
        cout << "No courses available." << endl;
        return;
    }
    InOrder(root);
}

// ==============================
// Load Courses
// ==============================
Tree loadCourses(string filePath) {

    Tree catalog;
    vector<vector<string>> rawLines;
    set<string> allCourseNumbers;

    ifstream file(filePath);

    if (!file.is_open()) {
        cout << "ERROR: Cannot open file." << endl;
        return catalog;
    }

    string line;

    while (getline(file, line)) {

        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 2) {
            cout << "ERROR: Invalid line format." << endl;
            return catalog;
        }

        string courseNum = tokens[0];
        courseNum.erase(remove_if(courseNum.begin(),
            courseNum.end(),
            ::isspace),
            courseNum.end());
        transform(courseNum.begin(),
            courseNum.end(),
            courseNum.begin(),
            ::toupper);

        if (allCourseNumbers.count(courseNum)) {
            cout << "ERROR: Duplicate course number found." << endl;
            return catalog;
        }

        allCourseNumbers.insert(courseNum);
        rawLines.push_back(tokens);
    }

    file.close();

    for (auto tokens : rawLines) {

        Course item;

        item.courseNumber = tokens[0];
        item.courseNumber.erase(remove_if(item.courseNumber.begin(),
            item.courseNumber.end(),
            ::isspace),
            item.courseNumber.end());
        transform(item.courseNumber.begin(),
            item.courseNumber.end(),
            item.courseNumber.begin(),
            ::toupper);

        item.title = tokens[1];

        for (int i = 2; i < tokens.size(); i++) {

            string prereq = tokens[i];
            prereq.erase(remove_if(prereq.begin(),
                prereq.end(),
                ::isspace),
                prereq.end());

            if (prereq.empty()) continue;

            transform(prereq.begin(),
                prereq.end(),
                prereq.begin(),
                ::toupper);

            if (!allCourseNumbers.count(prereq)) {
                cout << "ERROR: Invalid prerequisite." << endl;
                return catalog;
            }

            item.prerequisites.push_back(prereq);
        }

        catalog.Insert(item);
    }

    cout << "Data loaded successfully." << endl;
    return catalog;
}

// ==============================
// MAIN MENU
// ==============================
int main() {

    Tree catalog;
    bool dataLoaded = false;
    int choice = 0;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {

        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "What would you like to do? ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl << endl;
            continue;
        }

        if (choice == 1) {

            string fileName;
            cout << "Enter file name: ";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, fileName);

            catalog = loadCourses(fileName);

            if (catalog.root != nullptr) {
                dataLoaded = true;
            }
        }
        else if (choice == 2) {

            if (!dataLoaded) {
                cout << "No data loaded. Please load file first." << endl;
            }
            else {
                cout << "Here is a sample schedule:" << endl;
                catalog.PrintInOrder();
            }
        }
        else if (choice == 3) {

            if (!dataLoaded) {
                cout << "No data loaded. Please load file first." << endl;
            }
            else {

                string courseNumber;
                cout << "What course do you want to know about? ";
                cin >> courseNumber;

                transform(courseNumber.begin(),
                    courseNumber.end(),
                    courseNumber.begin(),
                    ::toupper);

                Course course = catalog.Search(courseNumber);

                if (course.courseNumber.empty()) {
                    cout << "Course not found." << endl;
                }
                else {

                    cout << course.courseNumber << ", "
                        << course.title << endl;

                    if (course.prerequisites.empty()) {
                        cout << "Prerequisites: None" << endl;
                    }
                    else {
                        cout << "Prerequisites: ";

                        for (int i = 0; i < course.prerequisites.size(); i++) {

                            Course prereq =
                                catalog.Search(course.prerequisites[i]);

                            cout << prereq.courseNumber << ", "
                                << prereq.title;

                            if (i < course.prerequisites.size() - 1) {
                                cout << "; ";
                            }
                        }
                        cout << endl;
                    }
                }
            }
        }
        else if (choice == 9) {
            cout << "Thank you for using the course planner!" << endl;
        }
        else {
            cout << choice << " is not a valid option." << endl;
        }

        cout << endl;
    }

    return 0;
}