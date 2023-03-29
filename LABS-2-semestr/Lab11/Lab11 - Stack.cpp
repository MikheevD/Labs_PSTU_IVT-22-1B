#include <iostream>
using namespace std;

struct StackElem
{
    int data;
    StackElem* next;
};

struct Stack {
    StackElem* top;
    int size;

    void init() {
        top = nullptr;
        size = 0;
    }
    void push(int data) {
        auto* curr = new StackElem;
        curr->data = data;
        curr->next = top;
        top = curr;
        size++;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    int pop() {
        int value = top->data;
        StackElem* tmp = top;
        top = top->next;
        size--;
        delete tmp;
        return value;
    }

};

Stack create_stack(int n)
{
    Stack stack{};
    stack.init();
    int data;
    for (int i = 0; i < n; i++)
    {
        data = rand() % 100;
        stack.push(data);
    }
    return stack;
}

void add_elem(Stack& stack, int pos) {
    Stack new_stack{};
    new_stack.init();
    int data;

    data = rand() % 100;
    if (pos == 1) {
        stack.push(data);
    }
    else {
        for (int i = 1; i < pos; i++) {
            new_stack.push(stack.pop());
        }
        stack.push(data);
        for (int i = 1; i < pos; i++) {
            stack.push(new_stack.pop());
        }
    }
}

void add_elems(Stack& stack, int pos, int k) {
    for (int i = 0; i < k; i++) {
        add_elem(stack, pos + i);
    }
}

void delete_elems(Stack& stack, int pos, int k) {
    Stack new_stack{};
    new_stack.init();
    if (pos == 1) {
        int tmp = stack.pop();
    }
    else {
        for (int i = 1; i < pos; i++) {
            new_stack.push(stack.pop());
        }
        int tmp = 0;
        for (int i = 0; i < k; i++) {
            tmp = stack.pop();
        }
        for (int i = 1; i < pos; i++) {
            stack.push(new_stack.pop());
        }
    }
}

int find_elem(Stack& stack, int value) {
    Stack new_stack{};
    new_stack.init();
    int pos = 0;
    while (stack.top->data != value && stack.top != nullptr) {
        new_stack.push(stack.pop());
        pos++;
    }
    if (stack.top->data == value) {
        for (int i = 0; i < pos; i++) {
            stack.push(new_stack.pop());
        }
        return pos + 1;
    }
    else {
        for (int i = 0; i < pos; i++) {
            stack.push(new_stack.pop());
        }
        return -1;
    }
}

void print_stack(Stack& stack) {
    Stack new_stack{};
    new_stack.init();
    int value = 0;
    int size = stack.size;
    for (int i = 0; i < size; i++) {
        value = stack.pop();
        cout << value << ' ';
        new_stack.push(value);
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        stack.push(new_stack.pop());
    }
}

void delete_stack(Stack& stack) {
    while (stack.size > 0) {
        stack.pop();
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    Stack beg = create_stack(NULL);
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
            beg = create_stack(n);
            print_stack(beg);
            break;
        }
        case 2:
        {
            print_stack(beg);
            int pos;
            int k;
            cout << "Введите номер: ";
            cin >> pos;
            cout << "Кол-во";
            cin >> k;
            delete_elems(beg, pos, k);
            print_stack(beg);
            break;

        }
        case 3:
        {
            print_stack(beg);
            int pos;
            cout << "Введите номер: ";
            cin >> pos;
            int k;
            cout << "Сколько элементов добавить: ";
            cin >> k;
            add_elems(beg, pos, k);
            print_stack(beg);
            break;
        }
        case 4:
        {
            print_stack(beg);
            break;
        }

        }
        if (oper != 0)
            system("pause");
    } while (oper != 0);

}