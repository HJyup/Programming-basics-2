using namespace std;

class booleanVector {
    // Атрибути класу
    int size;
    string value;

    // Форматування введення атрибутів для класу
    void formatAttributes();

public:
    // Конструктори класу
    booleanVector(int, string);

    explicit booleanVector(string);

    booleanVector();

    // Геттер та сеттер для значення вектору
    string getValue();

    void setValue(string);

    // Геттер та сеттер для визначення розміру вектору
    int getSize() const;

    void setSize(int);

    // Визначення ваги вектора
    int vectorWeight();

    // Перевантаження операторів ~ , !
    booleanVector *operator~();

    booleanVector operator&(const booleanVector &);
};