#include<iostream>
#include<iomanip>
#include<fstream>
#include<ctype.h>
using namespace std;

class NodeDoctor{
    public:
        string name, docID, profession;
        int age;
        NodeDoctor(string n, string id, string p, int a){
            name = n;
            docID = id;
            profession = p;
            age = a;
        }
        NodeDoctor *left, *right;
        NodeDoctor(){
            left = NULL;
            right = NULL;
        }
};

class Tree{
    NodeDoctor *root;

    public:
        Tree(){
            root = NULL;
        }

        bool isEmpty(){
            return (root == NULL);
        }

        void Insert(NodeDoctor*& tree, string n, string id, string p, int a){
            if(tree == NULL){
                tree = new NodeDoctor;
                tree->name = n;
                tree->docID = id;
                tree->profession = p;
                tree->age = a;
            }
            else if(id < tree->docID){
                Insert(tree->left, n, id, p, a);
            }
            else Insert(tree->right, n, id, p, a);
        }

        void InsertItem(string n, string id, string p, int a){
            Insert(root, n, id, p, a);
        }

        void DeleteItem(string id){
            Delete(root, id);
        }

        void GetSuccessor(NodeDoctor* &tree, string &id){
            if(tree->left == NULL){
                id = tree->docID;
                DeleteNode(tree, id);
            }
            else{
                GetSuccessor(tree->left, id);
            }
        }

        void Delete(NodeDoctor*& tree, string id){ 
            if (tree == NULL)
                cout << "\nNode not found" << endl;
            else  if(id < tree->docID)       
                // search the node on left subtree
                Delete(tree->left, id);
            else if(id > tree->docID)  
                // search the node on right subtree
                Delete(tree->right, id);
            else                        
            // the node is found and going to be 
            // deleted
                DeleteNode(tree, id);
        }


        void DeleteNode(NodeDoctor*& tree, string id){
            NodeDoctor* temp;
            // delete node with one child at right
            temp = tree;
            if(tree->left == NULL){ //right child
                tree = tree->right;
                delete temp;
            }
            // delete node with one child at left
            else if(tree->right == NULL){ // left child
                tree = tree->left;
                delete temp;
            }
            // delete node with two children
            else{
                GetSuccessor(tree->right, id);
                tree->docID = id;
            }
        }

        void printTree(){
            Print(root);
        }

        void Print(NodeDoctor *tree){
            if(tree != NULL){
                Print(tree->left);
                cout << left << setw(25) << tree->name << setw(15) << tree->docID << setw(20) << tree->profession << tree->age << endl;
                Print(tree->right);
            }
        }

};

class NodePatient{
    public:
        string name, phone, IC, patientID;
        int age;
        char gender;
        NodePatient *next;

        NodePatient(string _name, int _age, string _phone, string _IC, string _patientID, char _gender){
            name = _name;
            age = _age;
            phone = _phone;
            IC = _IC;
            patientID = _patientID;
            gender = _gender;
        }

        NodePatient(){
            next = NULL;
        }

};

class Queue{
    NodePatient *back;

    public:
        void createQueue(){
            back = NULL;
        }

        bool isEmpty(){
            return (back == NULL);
        }

        void enQueue(string n, string p, string ic, string id, int a, char g){
            NodePatient *newNode = new NodePatient;
            NodePatient *tmp = back;
            
            newNode->name = n;
            newNode->phone = p;
            newNode->IC = ic;
            newNode->patientID = id;
            newNode->age = a;
            newNode->gender = g;

            if(isEmpty()){
                back = newNode;
                back->next = back;
            }
            else{
                newNode->next = back->next;
                back->next = newNode;
                back = newNode;
            }
        }

        void deQueue(){
            if(isEmpty()){
                cout << "Queue is Empty ! " << endl;
                return;
            }

            NodePatient *tmp = back->next;

            if(back->next == back){
                back = NULL;
            }
            else{
                back->next = tmp->next;
                tmp->next = NULL;
            }
            delete tmp;
        }

        void searchID(string id){
            NodePatient *tmp = back;
            int flag = 1;

            if(isEmpty()){
                cout << "Nothing to search !" << endl;
            }
            else{
                if(id == tmp->patientID){
                    cout << endl;
                    cout << left << setw(16) << "Patient ID" << setw(21) << "Name" << setw(8) << "Age" << setw(18) << "IC" << setw(15) << "Phone" << "Gender" << endl;
                    cout << "=====================================================================================" << endl;
                    cout << left << setw(16) << tmp->patientID << setw(21) << tmp->name << setw(8) << tmp->age << setw(17) << tmp->IC << setw(16) << tmp->phone << tmp->gender << endl;
                    cout << endl;
                    flag = 0;
                     return;
                }
                else{
                    while(tmp->next != back){
                        if(id == tmp->patientID){
                            cout << endl;
                            cout << left << setw(16) << "Patient ID" << setw(21) << "Name" << setw(8) << "Age" << setw(18) << "IC" << setw(15) << "Phone" << "Gender" << endl;
                            cout << "=====================================================================================" << endl;
                            cout << left << setw(16) << tmp->patientID << setw(21) << tmp->name << setw(8) << tmp->age << setw(17) << tmp->IC << setw(16) << tmp->phone << tmp->gender << endl;
                            cout << endl;
                            flag = 0;
                            return;
                        }
                        else flag = 1;
                        tmp = tmp->next;
                    }
                }

                if(flag != 0){
                cout << "\nError !" << endl << endl;
                return;
                }
            }
        }

        bool searchIDbool(string id){
            NodePatient *tmp = back;
            //int flag = 1;
            bool flag = true;

            if(isEmpty()){
                cout << "Nothing to search !" << endl;
            }
            else{
                if(id == tmp->patientID){
                    flag = false;
                }
                else{
                    while(tmp->next != back){
                        if(id == tmp->patientID){
                            flag = false;
                        }
                        else flag = false;
                        tmp = tmp->next;
                    }
                }

            }
            return flag;
        }

        void searchName(string name){
            NodePatient *tmp = back;
            int flag = 1;

            if(isEmpty()){
                cout << "Nothing to search !" << endl;
            }
            else{
                if(name == tmp->name){
                    cout << endl;
                    cout << left << setw(16) << "Patient ID" << setw(21) << "Name" << setw(8) << "Age" << setw(18) << "IC" << setw(15) << "Phone" << "Gender" << endl;
                    cout << "=====================================================================================" << endl;
                    cout << left << setw(16) << tmp->patientID << setw(21) << tmp->name << setw(8) << tmp->age << setw(17) << tmp->IC << setw(16) << tmp->phone << tmp->gender << endl;
                    cout << endl;
                    flag = 0;
                    return;
                }
                else{
                    while(tmp->next != back){
                        if(name == tmp->name){
                            cout << endl;
                            cout << left << setw(16) << "Patient ID" << setw(21) << "Name" << setw(8) << "Age" << setw(18) << "IC" << setw(15) << "Phone" << "Gender" << endl;
                            cout << "=====================================================================================" << endl;
                            cout << left << setw(16) << tmp->patientID << setw(21) << tmp->name << setw(8) << tmp->age << setw(17) << tmp->IC << setw(16) << tmp->phone << tmp->gender << endl;
                            cout << endl;
                            flag = 0;
                            return;
                        }
                        else flag = 1;
                        tmp = tmp->next;
                    }
                }
                
            }

            if(flag != 0){
                cout << "\nNothing found !" << endl << endl;
                return;
            }    
        }

        /*void BubbleSortName(){
            NodePatient *current = back;
            NodePatient *tmp = NULL;

            if(isEmpty()){
                cout << "List is empty !" << endl;
            }
            else{
                while(current->next != back){
                    tmp = current->next;
                    while(tmp != back){
                        if(tmp->name > tmp->next->name){
                            swap(tmp->name, tmp->next-> name);
                            swap(tmp->age, tmp->next->age);
                            swap(tmp->gender, tmp->next->gender);
                            swap(tmp->IC, tmp->next->IC);
                            swap(tmp->patientID, tmp->next->patientID);
                            swap(tmp->phone, tmp->next->phone);
                        }
                        tmp = tmp->next;
                    }
                    current = current->next;
                }
                tmp = current->next->next;

                while(tmp != back){
                    if(tmp->name > tmp->next->name){
                        swap(tmp->name, tmp->next->name);
                        swap(tmp->age, tmp->next->age);
                        swap(tmp->gender, tmp->next->gender);
                        swap(tmp->IC, tmp->next->IC);
                        swap(tmp->patientID, tmp->next->patientID);
                        swap(tmp->phone, tmp->next->phone);
                    }
                    tmp = tmp->next;
                }
            }
        }

        void BubbleSortID(){
            NodePatient *current = back;
            NodePatient *tmp = NULL;

            if(isEmpty()){
                cout << "List is empty !" << endl;
            }
            else{
                while(current->next != back){
                    tmp = current->next;
                    while(tmp != back){
                        if(tmp->patientID >   tmp->next->patientID){
                            swap(tmp->name, tmp->next-> name);
                            swap(tmp->age, tmp->next->age);
                            swap(tmp->gender, tmp->next->gender);
                            swap(tmp->IC, tmp->next->IC);
                            swap(tmp->patientID, tmp->next->patientID);
                            swap(tmp->phone, tmp->next->phone);
                        }
                        tmp = tmp->next;
                    }
                    current = current->next;
                }
                tmp = current->next->next;

                while(tmp != back){
                    if(tmp->patientID > tmp->next->patientID){
                        swap(tmp->name, tmp->next->name);
                        swap(tmp->age, tmp->next->age);
                        swap(tmp->gender, tmp->next->gender);
                        swap(tmp->IC, tmp->next->IC);
                        swap(tmp->patientID, tmp->next->patientID);
                        swap(tmp->phone, tmp->next->phone);
                    }
                    tmp = tmp->next;
                }
            }
        }*/

        void print(){
            if(isEmpty()){
                cout << "Queue is Empty !" << endl;
            }
            else{
                NodePatient *tmp = back->next;
                cout << endl;
                cout << left << setw(16) << "Patient ID" << setw(21) << "Name" << setw(8) << "Age" << setw(18) << "IC" << setw(15) << "Phone" << "Gender" << endl;
                cout << "=====================================================================================" << endl;
                while(tmp != back){
                    cout << left << setw(16) << tmp->patientID << setw(21) << tmp->name << setw(8) << tmp->age << setw(17) << tmp->IC << setw(16) << tmp->phone << tmp->gender << endl;
                    tmp = tmp->next;
                }
                cout << left << setw(16) << tmp->patientID << setw(21) << tmp->name << setw(8) << tmp->age << setw(17) << tmp->IC << setw(16) << tmp->phone << tmp->gender << endl;
            }
        }
       
};

void patientMenu(){
    cout << ":: PATIENT ::" << endl;
    cout << "[1] Add a new patient" << endl;
    cout << "[2] Take the patient to doctor" << endl;
    cout << "[3] Search patient" << endl;
    cout << "[4] View the patient list" << endl;
    cout << "[5] Exit to menu" << endl;
    cout << "==========================" << endl;
    cout << "Enter your option : ";
}

void doctorMenu(){
    cout << ":: DOCTOR ::" << endl;
    cout << "[1] Add a new doctor" << endl;
    cout << "[2] Delete a doctor" << endl;
    cout << "[3] View the doctor list" << endl;
    cout << "[4] Exit to menu" << endl;
    cout << "==========================" << endl;
    cout << "Enter your option : ";
}

void searchMenu(){
    cout << "\n:: SEARCHING ::" << endl;
    cout << "[1] Search by patient ID" << endl;
    cout << "[2] Search by name" << endl;
    cout << "==========================" << endl;
    cout << "Enter your option : ";
}

int main(){
    int option, choice1, choice2, choice5;
    string name, IC, phone, patientID, doctorID, profession;
    int age;
    char gender;
    string searchkey;

    Queue qPatient;
    qPatient.createQueue();

    Tree treeDoctor;

    ifstream input("patient.txt");
    ifstream input1("doctor.txt");

    if(!input1){
        cout << "The file cannot open !" << endl;
        return 0; 
    }
    else{
        while(getline(input1, name, ',')){
            getline(input1, doctorID, ',');
            input1 >> age;
            getline(input1, profession);

            treeDoctor.InsertItem(name, doctorID, profession, age);
        }
    }

    input1.close();

    if(!input){
        cout << "The file cannot open !" << endl;
        return 0;
    }
    else{
        while(getline(input, name, ',')){
            getline(input, patientID, ',');
            input >> age;
            input >> gender;
            getline(input, phone, ',');
            getline(input, IC);

            qPatient.enQueue(name, phone, IC, patientID, age, gender);
        }
    }

    input.close();

A:  cout << ":: MENU ::" << endl;
    cout << "[1] Patient" << endl;
    cout << "[2] Doctor" << endl;
    cout << "[3] Exit the program" << endl;
    cout << "==========================" << endl;
    cout << "Enter your option : ";
    cin >> option;
    cout << endl;
 
    while(option > 0 && option < 4){
        switch(option){
            case 1:
            {
                B: patientMenu();
                cin >> choice1;
                if(choice1 == 1){
                    cout << "\n:: DETAILS ::" << endl;
                    cin.ignore();
                    cout << "Patient ID : ";
                    getline(cin, patientID);
                    
                    if((qPatient.searchIDbool(patientID))){
                        cout << "\n[Patient ID already exists]\n" << endl;
                        goto B;
                    } 
                    
                    cout << "Name : ";
                    getline(cin, name);
                    cout << "Age : ";
                    cin >> age;
                    cin.ignore();
                    cout << "IC Number (XXXXXX-XX-XXXX) : ";
                    getline(cin, IC);
                    cout << "Phone Number (XXX-XXXXXXXX) : ";
                    getline(cin, phone);
                    cout << "Gender (M/F) : ";
                    cin >> gender;
                    cout << endl;

                    qPatient.enQueue(name, phone, IC, patientID, age, gender);
                }
                else if(choice1 == 2){
                    qPatient.deQueue();
                    cout << "\n[The first patient went to see a doctor]" << endl;
                    cout << endl;
                }
                else if(choice1 == 3){
                    searchMenu();
                    cin >> choice2;

                    switch(choice2){
                        case 1:
                        {
                            cout << "\nEnter the patient ID : ";
                            cin.ignore();
                            getline(cin, searchkey);
                            qPatient.searchID(searchkey);
                            break;
                        }
 
                        case 2:
                        {
                            cout << "\nEnter the name : ";
                            cin.ignore();
                            getline(cin, searchkey);
                            qPatient.searchName(searchkey);
                            break;
                        }

                        default: 
                        {
                            cout << endl;
                            goto B;
                        }
                    }
                    
                }
                else if(choice1 == 4){
                    qPatient.print();
                    cout << endl;
                }
                else if(choice1 == 5){
                    cout << endl;
                    goto A;
                }
                else{
                    cout << endl;  
                    goto B;
                }
                break;
            }

            case 2:
            {
                C: doctorMenu();
                cin >> choice5;
                if(choice5 == 1){
                    cout << "\n:: DETAILS ::" << endl;
                    cin.ignore();
                    cout << "Doctor ID : ";
                    getline(cin, doctorID);
                    cout << "Name : ";
                    getline(cin, name);
                    cout << "Age : ";
                    cin >> age;
                    cin.ignore();
                    cout << "Profession : ";
                    getline(cin, profession);
                    cout << endl;
                    treeDoctor.InsertItem(name, doctorID, profession, age);
                }
                else if(choice5 == 2){
                    cout << "\nEnter the Doctor ID : ";
                    cin.ignore();
                    getline(cin, doctorID);
                    treeDoctor.DeleteItem(doctorID);
                    cout << endl;
                    cout << left << setw(25) << "Doctor Name" << setw(15) << "Doctor ID" << setw(20) << "Profession" << "Age" << endl;
                    cout << "===============================================================" << endl;
                    treeDoctor.printTree();
                    cout << endl;
                }
                else if(choice5 == 3){
                    cout << endl;
                    cout << left << setw(25) << "Doctor Name" << setw(15) << "Doctor ID" << setw(20) << "Profession" << "Age" << endl;
                    cout << "===============================================================" << endl;
                    treeDoctor.printTree();
                    cout << endl;
                }
                else if(choice5 == 4){
                    cout << endl;
                    goto A;
                }
                else{
                    cout << endl;
                    goto C;
                }
                
                break;
            }

            case 3:
            {
                cout << "Thank you for using our system!" << endl;
                system("pause");
                exit(1);
                break;
            }
        }
    }
    
    if(!(option > 0 && option < 4)){
        cout << "Wrong Option! Please enter again!" << endl << endl;
        goto A;
    }

    system("pause");
    return 0;
};