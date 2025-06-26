// https://leetcode.com/problems/design-linked-list

class MyLinkedList {
    int val;
    MyLinkedList* next;
public:
    MyLinkedList() {
        next = nullptr;
        val = 0;
    }
    
    int get(int index) {
        MyLinkedList *head = next;
        int i = 0;
        while(head != nullptr)
        {
            if(i==index)
                return head->val;
            head = head->next;
            i++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        cout << "pass1" << endl;
        MyLinkedList* nouv = new MyLinkedList();
        nouv->val = val;
        nouv->next = next;
        next = nouv;
    }
    
    void addAtTail(int val) {
        cout << "pass2" << endl;
        if(next == nullptr)
        {
            addAtHead(val);
            return;
        }
        MyLinkedList *head = next;
        while(head->next != nullptr)
            head = head->next;
        MyLinkedList* nouv = new MyLinkedList();
        nouv->next = nullptr;
        nouv->val = val;
        head->next = nouv;
    }
    
    void addAtIndex(int index, int val) {
        cout << "pass3" << endl;
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        MyLinkedList * parc = next,*prev = nullptr;
        int size = 0;
        while(parc != nullptr)
        {
            parc = parc->next;
            size++;
        }
        if(index > size) return;
        if(index == size)
        {
            addAtTail(val);
            return;
        }
        int i = 0;
        parc = next;
        while(parc->next != nullptr && i < index)
        {
            prev = parc;
            parc = parc->next;
            i++;
        }
        MyLinkedList* nouv = new MyLinkedList();
        nouv->val  = val;
        prev->next = nouv;
        nouv->next = parc;
    }
    

    
    void deleteAtIndex(int index) {
        if(index == 0)
        {
            next = next->next;
            return;
        }
        MyLinkedList *parc = next,*prev = nullptr;
        int i = 0;
        while(i < index && parc->next != nullptr)
        {
            prev = parc;
            parc = parc->next;
            i++;
        }
        if(i == index)
        prev->next = parc->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */