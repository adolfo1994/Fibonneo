//
// Created by adolfo on 10/04/16.
//

#ifndef FIBONNEO_MESSAGE_H
#define FIBONNEO_MESSAGE_H


class Message {

public:

    Message(int counter, int note_1, int note_2, char *hash) : counter(counter), note_1(note_1), note_2(note_2),
                                                               hash(hash) { }

    Message() {
        hash = new char [32];
    }

    virtual ~Message() {
        delete [] hash;
    }

    int getCounter() const {
        return counter;
    }

    void setCounter(int counter) {
        Message::counter = counter;
    }

    int getNote_1() const {
        return note_1;
    }

    void setNote_1(int note_1) {
        Message::note_1 = note_1;
    }

    int getNote_2() const {
        return note_2;
    }

    void setNote_2(int note_2) {
        Message::note_2 = note_2;
    }

    const char *getHash() const {
        return hash;
    }

    char* buildString();

private:

    int counter;
    int note_1;
    int note_2;
    char* hash;

};


#endif //FIBONNEO_MESSAGE_H
