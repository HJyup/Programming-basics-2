using namespace std;

#include <vector>

// Class TTriad
class TTriad {
protected:
    vector<int> numbers;

    virtual void format_numbers() = 0;

    static void checkIndex(int &index);
public:
    TTriad(int num1, int num2, int num3);

    vector<int> get_values();

    void set_values(int newNum1, int newNum2, int newNum3);

    void addValue(int value, int index);

    void minValue(int value, int index);

    virtual string string_numbers();

};

// Class TTime
class TTime : public TTriad {
protected:
    void format_numbers() override;

public:
    TTime(int seconds, int minutes, int hours);

    string string_numbers() override;

};

// Class TDate
class TDate : public TTriad {
private:
    void checkDays();

    static bool isLeapYear(int yrs);

protected:
    void format_numbers() override;

public:
    TDate(int days, int months, int years);

    string string_numbers() override;
};
