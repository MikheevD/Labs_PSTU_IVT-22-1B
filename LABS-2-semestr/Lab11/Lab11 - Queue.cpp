#include <iostream>
using namespace std;

struct QueueElem
{
    int data;
    QueueElem* next;
    QueueElem* prev;
};

struct Queue {
    QueueElem* front;
    QueueElem* back;
    int size;

    void init() {
        front = nullptr;
        back = front;
        size = 0;
    }
    void push(int data) {
        auto* curr = new QueueElem;
        curr->data = data;
        curr->next = nullptr;
        curr->prev = back;
        if (back != nullptr) {
            back->next = curr;
        }
        if (front == nullptr) {
            front = curr;
        }
        back = curr;
        size++;
    }
    bool isEmpty() {
        return front == nullptr;
    }

    int pop() {
        int value = front->data;
        QueueElem* tmp = front;
        if (size == 1) {
            back = nullptr;
        }
        front = front->next;
        size--;
        delete tmp;
        return value;
    }

};
Queue create_queue(int n)
{
    Queue queue{};
    queue.init();
    int data;
    for (int i = 0; i < n; i++)
    {
        data = rand() % 100;
        queue.push(data);
    }
    return queue;
}

void add_elem(Queue& queue, int pos) {
    Queue new_queue{};
    new_queue.init();
    int data;
    int size = queue.size;
    data = rand() % 100;
    if (pos == 1) {
        queue.push(data);
    }
    else {
        for (int i = 0; i < pos - 1; i++) {
            new_queue.push(queue.pop());
        }
        new_queue.push(data);
        for (int i = 0; i < size - pos + 1; i++) {
            new_queue.push(queue.pop());
        }
        queue = new_queue;
    }
}

void add_elems(Queue& queue, int pos, int k) {
    for (int i = 0; i < k; i++) {
        add_elem(queue, pos + i);
    }
}

void delete_elems(Queue& queue, int pos, int k) {
    Queue new_queue{};
    new_queue.init();
    int size = queue.size;
    if (pos == 1) {
        queue.pop();
    }
    else {
        for (int i = 0; i < pos - 1; i++) {
            new_queue.push(queue.pop());
        }
        for (int i = 0; i < k; i++) {
            queue.pop();
        }
        for (int i = 0; i < size - pos - k + 1; i++) {
            new_queue.push(queue.pop());
        }
        queue = new_queue;
    }
}

int find_elem(Queue& queue, int value) {
    Queue new_queue{};
    new_queue.init();
    int pos = 0;
    while (queue.front->data != value && queue.front != nullptr) {
        new_queue.push(queue.pop());
        pos++;
    }
    if (queue.front->data == value) {
        for (int i = 0; i < pos; i++) {
            queue.push(new_queue.pop());
        }
        return pos + 1;
    }
    else {
        for (int i = 0; i < pos; i++) {
            queue.push(new_queue.pop());
        }
        return -1;
    }
}

void print_queue(Queue& queue) {
    Queue new_queue{};
    new_queue.init();
    int value = 0;
    int size = queue.size;
    for (int i = 0; i < size; i++) {
        value = queue.pop();
        cout << value << ' ';
        new_queue.push(value);
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        queue.push(new_queue.pop());
    }
}

void delete_queue(Queue& queue) {
    while (queue.size > 0) {
        queue.pop();
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    Queue beg = create_queue(NULL);
    int oper;
    do
    {
        system("cls");
        cout << "1.Создать список" << endl;
        cout << "2.Удалить элемент с заданным номером" << endl;
        cout << "3.Вставка элементов" << endl;
        cout << "4.Вывод списка" << endl;
        cout << "0.Выход" << endl;
        cin >> oper;
        switch (oper)
        {

        case 1:
        {
            int n;
            cout << "Введите кол-во эл-тов списка = ";
            cin >> n;
            beg = create_queue(n);
            print_queue(beg);
            break;
        }
        case 2:
        {
            print_queue(beg);
            int pos;
            int k;
            cout << "Введите номер: ";
            cin >> pos;
            cout << "Кол-во";
            cin >> k;
            delete_elems(beg, pos, k);
            print_queue(beg);
            break;

        }
        case 3:
        {
            print_queue(beg);
            int pos;
            cout << "Введите номер: ";
            cin >> pos;
            int k;
            cout << "Сколько элементов добавить: ";
            cin >> k;
            add_elems(beg, pos, k);
            print_queue(beg);
            break;
        }
        case 4:
        {
            print_queue(beg);
            break;
        }

        }
        if (oper != 0)
            system("pause");
    } while (oper != 0);

}