#include <iostream>
#include <string>
#include <thread>   // used along with chrono to set the time lapse
#include <chrono>
#include <cctype>   // used for isdigit() in main.cpp
using namespace std;
const int DEFID = 12345;


class Table{
public:
    friend class Restaurant;
    friend class Queue;
    Table():m_id(DEFID), m_name(""), m_reserved(false), m_next(nullptr) {}
    Table(int id, string name):m_id(id), m_name(name), m_reserved(false), m_next(nullptr) {}


private:
// all tables will be of 4
    int m_id;
    string m_name;
    bool m_reserved;    // i set this to true in the Restaurant class when I reserve it in there
    Table *m_next;
};




class Queue{
public:
    Queue(){
        m_front = nullptr;
        m_back = nullptr;
        m_size = 0;
        m_key = "";
    }
    ~Queue(){
        while(!empty()){    // while not empty just
            dequeue();  // delete the front
        }
    }
    void displayTable(Table &t){
        cout << "\033[43m" << t.m_id << ":" + t.m_name << "\033[0m" << endl;
        cout << " ___RES___      " << endl;
        cout << "*|___|___|*     " << endl;
        cout << "*|___|_4_|*     " << endl;
        cout << endl;
    }
    void display(){
        if(empty()){
            cout << "EMPTY QUEUE" << endl;
            return;
        }

        Table *temp = m_front;
        while(temp){
            if(temp->m_next){
                cout << "\033[32m" << temp->m_name + "\033[0m -> ";
            }
            else{
                cout << "\033[32m" << temp->m_name + "\033[0m->0";
            }
            temp = temp->m_next;
        }
        cout << endl;
        cout << "Size of the queue is: " << m_size << endl;

        // uncomment the following lines for better display of tables
        // temp = m_front;
        // while(temp){
        //     if(temp->m_reserved)
        //         cout << " ___RES___           ";
        //     else
        //         cout << " _________           ";
        //     temp = temp->m_next;
        // }
        // cout << endl;
        // temp = m_front;
        // while(temp){
        //     cout << "*|___|___|*          ";
        //     temp = temp->m_next;
        // }
        // cout << endl;
        // temp = m_front;
        // while(temp){
        //     cout << "*|___|_4_|*          ";
        //     temp = temp->m_next;
        // }
        cout << endl;

    }
    bool empty(){ return m_front == nullptr; }
    void enqueue(int id, string name){
        Table *newT = new Table(id, name);
        newT->m_reserved = true;
        if(empty()){
            m_front = newT;
            m_back = newT;
        }
        else{
            m_back->m_next = newT;
            m_back = newT;
        }
        m_size++;
        // cout << "\033[32mINSERTED\033[0m" << endl;
    }
    void dequeue(){
        if(empty()){ return; }
        Table *temp = m_front;    // get the front of  the queue
        m_front = temp->m_next;
        if(!m_front){   // if there's no front, meaning there was only one element in queue, we set the back to nptr as well
            m_back = nullptr;   // this means the queue is now empty
        }
        delete temp;
        temp = nullptr;
        m_size--;
    }
    Table* peek(){
        if(empty()){
            return nullptr;
        }
        return m_front;
    }

private:
    Table *m_front;
    Table *m_back;
    string m_key;
    int m_size;
};




class Restaurant{
public:
    Restaurant(int tt):m_totalTables(tt){
        m_tables = new Queue*[m_totalTables]();
        for(int i=0; i<m_totalTables; i++){
            m_tables[i] = new Queue();
        }
        m_currentTables = 0;
        // m_reservations = new Reserve*[100]();
    }
    ~Restaurant(){
        for(int i=0; i<m_totalTables; i++){
            delete m_tables[i];
            m_tables[i] = nullptr;
        }
        delete [] m_tables;
        m_tables = nullptr;
    }
    bool reserveTable(int position, string name, int id){
        if(position > 0 && position <= m_totalTables){
            if(m_tables[position]->empty()){
                cout << "You have successfully reserved your table" << endl;
                m_tables[position]->enqueue(id, name);
                m_currentTables++;
            }
            else{
                cout << "You have been successfully been put on the waitlist for this table" << endl;
                m_tables[position]->enqueue(id, name);
            }
            // displayTableQueue(position);
            return true;
        }
        return false;
    }
    void displayGeneral(){
        cout << "[";
        for(int i=1; i<m_totalTables; i++){
            if(i != m_totalTables-1){
                if(!m_tables[i]->empty()){
                    cout << "\033[32m" << i << "\033[0m, ";
                }
                else{
                    cout << i << ", ";
                }
            }
            else
                if(!m_tables[i]->empty()){
                    cout << "\033[32m" << i << "\033[0m";
                }
                else{
                    cout << i;
                }
        }
        cout << "]" << endl;
        cout << "The current tables reserved is: " << m_currentTables << endl;
    }
    void displayTableQueue(int tableIndex){
        // assuming it's valid
        cout << "\033[41mDISPLAYING QUEUE for index: " << tableIndex << "\033[0m" << endl;
        m_tables[tableIndex]->display();
    }
    void claimTable(int position, string name, int id){
        if(position > 0 && position <= m_totalTables){
            if(m_tables[position]->empty()){
                cout << "No one has reserved this Table" << endl;
                return;
            }
            // grab the first Table in Queue
            Table *peekQueue = m_tables[position]->peek();
            // if it matches the information of the user...
            if(peekQueue->m_id == id && peekQueue->m_name == name){
                cout << "I have found your table, let me take you to it..." << endl;
                cout << "You can now dine at your table. For ... ";
                std::this_thread::sleep_for(std::chrono::seconds(3));
                cout << "3 seconds." << endl;
                // we can dequeue
                m_tables[position]->dequeue();  // we remove it from the queue after a cooldown
                if(m_tables[position]->empty()){    // if I dequeue all to the point where it's now empty, we decrement the number of reserved tables
                    m_currentTables--;
                }
                // the cooldown is equivalent to the user eating at the restaurant after claiming their table
                displayTableQueue(position);
            }
            else{
                cout << "Either you're on the queue for this table or you haven't reserved the table" << endl;
            }

        }
    }

private:
    int m_totalTables;
    Queue **m_tables;
    int m_currentTables;
};
