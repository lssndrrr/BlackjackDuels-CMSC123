#include "header.hpp"
#include "leaderboard.hpp"

Leaderboard::Leaderboard(){
    head = tail = NULL;
    length = 0;
}

Leaderboard::~Leaderboard(){
    deleteRecords();
}

int Leaderboard::size(){
    return length;
}

void Leaderboard::insort(string username, int points)
{
    Record* n = new Record(username, points), *tmp = head;
    if(head == NULL){
        insertHead(n);
        return;
    }else if(n->points > head->points){
        insertHead(n);
        return;
    }

    while(tmp != NULL){
        if(tmp == tail){
            insertTail(n);
            return;
        }else if(n->points > tmp->next->points){
            n->next = tmp->next;
            tmp->next = n;
            length++;
            return;
        }
        tmp = tmp->next;
    }
}

void Leaderboard::insertHead(Record *n){
    if(head == NULL){
        head = tail = n;
    } else{
        n->next = head;
        head = n;
    }
    length++;
}

void Leaderboard::insertTail(Record *n){
    if(head == NULL){
        head = tail = n;
    } else{
        tail->next = n;
        tail = n;
    }
    length++;
}

void Leaderboard::deleteRecords(){
    Record* toDel;
    while(head != NULL){
        toDel = head;
        head = head->next;
        delete toDel;
    }
}

void Leaderboard::readData(){
    ifstream file("Leaderboards.txt");
    int i, rounds, points, size;
    string line, name;

    // number of entries in leaderboard
    file >> size;
    for(size; size; size--){
        file >> line;

        // tokenize line per '/'
        // index of delimiters
        i = line.find_first_of(',');
        
        // tokenized strings
        name = line.substr(0,i);

        cout << line.substr(i+1) << endl;

        points = stoi(line.substr(i+1));
        
        Record *n = new Record(name, points);
        insertTail(n);
    }
    file.close();
}

void Leaderboard::writeData(){
    ofstream file("Leaderboards.txt");
    Record* tmp = head;

    file << length << std::endl;
    int count = 0;
    while(tmp != NULL){
        if(count == 10)
            return;
        file << tmp->username << ',' << tmp->points << std::endl;
        tmp = tmp->next;
    } file.close();
}

Record* Leaderboard::operator[](int index){
    if(length == 0)
        throw "Cannot index when leaderboard size is 0";
    Record* tmp = head;

    for(int i = 0; i < index; i++){
        tmp = tmp->next;
    }

    return tmp;
}

Record::Record(){
    username = "";
    points =  0;
}

Record::Record(string username, int point){
    this->username = username;
    this->points = point;
    next = NULL;
}

string Record::getUsername(){
    return this->username;
}

string Record::getPoints(){
    return std::to_string(this->points);
}