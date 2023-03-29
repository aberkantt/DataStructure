/** 
* @file YoneticiListesi.cpp
* @description 
* @course 2-A
* @assignment 1
* @date  12/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#include "YoneticiListesi.hpp"

YoneticiNode* YoneticiListesi::FindPreviousByPosition(int index)throw (NoSuchElement){
	if(index < 0 || index > size) throw NoSuchElement("No Such Element");
    YoneticiNode *prv = head;
    int i = 1;
    for (YoneticiNode *itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
        prv = prv->next;
    }
    return prv;
}
YoneticiNode* YoneticiListesi::FindPosition(int index)throw (NoSuchElement) {
    if (index < 0 || index >= size) throw NoSuchElement("No Such Element");
    return this->FindPreviousByPosition(index + 1);

}
YoneticiListesi::YoneticiListesi() {
    head = NULL;
    size = 0;
}
int YoneticiListesi::Count()const {
    return size;
}
bool YoneticiListesi::isEmpty()const {
    return size == 0;
}
void YoneticiListesi::add(SatirListesi*& item) {
    insert(size, item);
}
void YoneticiListesi::insert(int index, SatirListesi*& item) {
    if (index < 0 || index > size) throw "Index out of Range";
    if (index == 0) {
        head = new YoneticiNode(item, head);
        if (head->next != NULL) head->next->prev = head;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(index);
        prv->next = new YoneticiNode(item, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}
SatirListesi*& YoneticiListesi::first()throw (NoSuchElement) {
    if (isEmpty()) throw NoSuchElement("No Such Element");
    return head->data;
}

SatirListesi*& YoneticiListesi::last()throw (NoSuchElement) {
    if (isEmpty()) throw NoSuchElement("No Such Element");
    return FindPreviousByPosition(size)->data;
}
int YoneticiListesi::indexOf(SatirListesi*& item)throw (NoSuchElement) {
    int index = 0;
    for (YoneticiNode *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == item) return index;
        index++;
    }
    throw NoSuchElement("No Such Element");
}
void YoneticiListesi::remove(SatirListesi*& item) {
    int index = indexOf(item);
    removeAt(index);
}
void YoneticiListesi::randomRemoveAtSatirListesi(int index, int inlineIndex)throw (IndexOutOfBounds, NoSuchElement) {

    int count = this->Count();
    if (index < 0 || index >= count)
        throw IndexOutOfBounds("Index out of bounds");

    SatirListesi* satirListesi = this->elementAt(index);

    satirListesi->removeAt(inlineIndex);
    hesaplaAverage(index);

}

void YoneticiListesi::hesaplaAverage(int index) {
    YoneticiNode* yoneticiNode = this->FindPosition(index);

    if (yoneticiNode == NULL) {

        throw "hata";
    }
	    double sonuc = 0;
    if (yoneticiNode->data->isEmpty()) {

        yoneticiNode->average = sonuc;
        return;
    }


    int count = yoneticiNode->data->Count();
    for (int i = 0; i < count; ++i) {
        sonuc += yoneticiNode->data->elementAt(i);
    }
    yoneticiNode->average = sonuc / count;

}
int YoneticiListesi::randomGenerator(int index)throw (IndexOutOfBounds, NoSuchElement) {
    int count = this->Count();

    if (index < 0 || index >= count)
        throw IndexOutOfBounds("Index out of bounds");

    srand(time(NULL));
    SatirListesi* satirListesi = this->elementAt(index);

    int range = satirListesi->Count();
    if (range == 0) {
        throw NoSuchElement("No Such Element");
    }
    int randSatir = rand() % range;

    return randSatir;
}
void YoneticiListesi::removeAt(int index) {
    if (index < 0 || index >= size) throw "Index out of Range";
    YoneticiNode *del;
    if (index == 0) {
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}
void YoneticiListesi::moveNode(int from, int to)throw (IndexOutOfBounds) {
    if (from < 0 || from >= size) throw IndexOutOfBounds("index out of bound");
    YoneticiNode *del;
    if (from == 0) {
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(from);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    if (to < 0 || to > size) throw "Index out of Range";
    if (to == 0) {

        del->next = head;
        del->prev = NULL;
        head = del;
        if (head->next != NULL) head->next->prev = head;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(to);

        del->next = prv->next;
        del->prev = prv;
        prv->next = del;
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}
bool YoneticiListesi::find(SatirListesi*& item) {
    for (YoneticiNode *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == item) return true;
    }
    return false;
}

void YoneticiListesi::reverse() {
    for (YoneticiNode *itr = head; itr != NULL;) {
        YoneticiNode *tmp = itr->next;
        itr->next = itr->prev;
        itr->prev = tmp;
        if (tmp == NULL) {
            head = itr;
            break;
        }
        itr = tmp;
    }
}
void YoneticiListesi::sortByAverage() {
    if (this->size <= 1)
        return;

    for (int step = 0; step < size; ++step) {


        for (int i = 0; i < size - step - 1; ++i) {
            YoneticiNode *tmp = this->FindPosition(i);
            YoneticiNode *tmp2 = tmp->next;

            if (tmp->average > tmp2->average) {


                this->moveNode(i + 1, i);
            }
        }
    }
}
SatirListesi*& YoneticiListesi::elementAt(int index)throw (NoSuchElement) {
    if (index < 0 || index >= size) throw NoSuchElement("No Such Element");
    if (index == 0) return head->data;
    return FindPreviousByPosition(index)->next->data;
}

void YoneticiListesi::clear() {
    while (!isEmpty())
        removeAt(0);
}
void YoneticiListesi::printIndex(int index, int x, int y) {
    YoneticiNode *node = this->FindPosition(index);
    CmdPos.gotoxy(x, y);
    cout << fixed << setprecision(2);
    cout << node << "\n";
    CmdPos.gotoxy(x, y + 1);
    cout << "-----------\n";
    CmdPos.gotoxy(x, y + 2);
    cout << "|" << node->prev << setw(3) << "|\n";
    CmdPos.gotoxy(x, y + 3);
    cout << "-----------\n";
    CmdPos.gotoxy(x, y + 4);
    cout << "|" << setw(3) << node->average << setw(5) << "|" << endl;
    CmdPos.gotoxy(x, y + 5);
    cout << "-----------\n";
    CmdPos.gotoxy(x, y + 6);
    cout << "|" << node->next << setw(3) << "|\n";
    CmdPos.gotoxy(x, y + 7);
    cout << "-----------\n\n";

}

YoneticiListesi::~YoneticiListesi() {
    clear();
}